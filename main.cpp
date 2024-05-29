#include <iostream>
using namespace std;
#include <iomanip>
#include <string.h>
#include "User.h"
#include "Use_Manage_Operation.h"
#include "UserInterface.h"
#include "Text_Prompt_Manage_Operation.h"
#include "Text_Prompt.h" 
#include "Video_Prompt_Manage_Operation.h"
#include "Video_Prompt.h"
#include "Model_Manage_Operation.h"
#include "Feedback_Operation.h"
#include "Feedback.h"
#include "Model.h"
#include "Share.h"
#include <conio.h>
// 每个菜单对应的选项都是数字，没有写关于输入错误处理的方法，例如输入6，如果输入6.16界面会无限循环 
const int width = 50;  //菜单居中对齐使用        
const int width2 = 23; //注册登录相关信息需要 

UserInterface userinterface;  //调用菜单
UseManageOperation usemanageoperation;
char name[20];
char password[20];    //不能超过19位 
char subpassword[20]; //确认密码 
char sex[5];
char telephone[12];   //不能超过11位 
char gmail[15];       //不能超过14位 
int choice1 = 4;
int choice2 = 20; 
int choice3 = 20;
int choice4 = 20;
char pword[20];
bool flag1 = false;   //标志1，注销账户返回两级菜单  
bool flag2 = false;   //标志2，修改密码返回两级菜单 ， 重新登录 

void regist();    //注册菜单（139行-173行）  1.用户名不重复   2.信息写入二进制文件 

void Login();     //登录菜单 （176-349行） 
void personFileOperation(); //登录后个人文件操作菜单 （351-532行）
void pulicFileOperation();  //登录后公开文件操作菜单 （533-835行） 

void fangke();    //访客菜单 （835-917行） 

void process();           //操作后处理函数（按任意键继续） （130行-134行） 
void yanzheng();          //验证两次密码是否输入一致的函数 1.注册用到 2.修改密码用 （114-128行） 
const char* mima(int i);  //输入密码显示 * 函数（86-112行） 

int main()
{
	while (choice1) 
	{
		system("cls");  //清屏函数 
		UseManageOperation usemanageoperation;  //操作用户管理调用对应的方法；
		userinterface.MainMenu();
		
		cin >> choice1;
		switch(choice1) 
		{
			case 1: {
				system("cls"); 
				regist();           //注册界面 
				process();
				break;
			}		
			case 2: {
				Login();            //登录界面 
				choice2 = 20;
				break;
			}
			case 3: {
				fangke();           //访客界面
				choice2 = 20;
				break;
			}	
			case 0:
				break;				 
		}
	} 
	return 0;
} 

const char* mima(int i)          //用户输入显示 *函数 
{
	char ch; 
	while (1) 
	{
		ch = getch();
		if (ch == '\r')         //检查是否是回车键 
		{
			pword[i] = '\0';
			break; 
		}
		else if (ch == '\b')
		{
			if (i > 0)
			{
				i--;
				cout << "\b \b"; //退格，删除一个* 
			}
		}
		else 
		{
			pword[i++] = ch;
			cout << '*';	
		} 
	} 
	return pword;
}

void yanzheng() {  //验证两次密码是否一秩  1.注册使用，  2.修改密码使用 
	do {
		cout << setfill(' ') << setw(width2) << "输入密码：" ;
		strcpy(password, mima(0));
		cout << endl;
		
		cout << setfill(' ') << setw(width2) << "确认密码：" ;
		strcpy(subpassword, mima(0));
		cout << endl;
		
		if (strcmp(password, subpassword) != 0) {
			cout << setfill(' ') << setw(width2) << "密码不一致" << endl; 
		}
	} while (strcmp(password, subpassword) != 0);
} 

void process() {  //操作后处理函数 
	cout << setfill(' ') << setw(30) << "\n按任意键键继续\n";
	_getch();    // 该函数会等待用户按下任意键
	cout << endl;
}

//注册界面,加密输入， 确保用户名不重复 
void regist() {
	User user;
	cout << setw(width) << setfill('-') << "" << endl;
	cout << setfill(' ') << setw((width + strlen("注册操作")) / 2) << "注册操作" << endl;
    
	cout <<  setw(50) << setfill('-') << "" << endl;
	User u;
	do {
		cout << setfill(' ') << setw(width2) << "用户名：";
		cin >> name;
		cin.ignore();
		u = usemanageoperation.SearchOperation(name);
		if (strcmp(u.getName(), name) == 0) {
			cout << setfill(' ') << setw(width2) << "用户名已存在！" << endl; //确保文件中没有相同的用户名 
		}
	} while (strcmp(u.getName(), name) == 0);
	
	user.setName(name);
	
	yanzheng();  //验证用户两次输入密码是否一致 
	user.setPword(password);
	cout << setfill(' ') << setw(width2) << "输入性别：";
	cin >> sex;
	cin.ignore();
	user.setSex(sex);
	cout << setfill(' ') << setw(width2) << "输入电话号码：";
	cin >> telephone;
	cin.ignore();
	user.setTphone(telephone);
	cout << setfill(' ') << setw(width2) << "输入邮箱：";
	cin >> gmail;
	cin.ignore();
	user.setGmail(gmail); 
	usemanageoperation.AddOperation(user); 
} 

//登录界面 
void Login() {  
	User user;
	User newuser;
	bool flag;
	system("cls"); 
	cout << setw(width) << setfill('-') << "" << endl;
	cout << setfill(' ') << setw((width + strlen("登录操作")) / 2) << "登录操作" << endl;
	cout <<  setw(50) << setfill('-') << "" << endl;
	do {
		cout << setfill(' ') << setw(23) << "用户名：";
		cin >> name;
		cin.ignore(); 
		cout << setfill(' ') << setw(23) << "输入密码：";
		strcpy(password, mima(0));
		flag = usemanageoperation.IsLog(name, password);       //查询和验证分开，否则注销和改密码，还可以用旧帐户登录 
		if (!flag) {
			cout << setfill(' ') << setw(40) << "\n用户名或密码错误！" << endl << endl;
		} 
	} while (!flag);
	user = usemanageoperation.SearchOperation(name);           //查询和验证分开，否则注销和改密码，还可以用旧帐户登录 
	if (flag) {
		while (choice2 != 7) 
		{	
			if (flag1 == true || flag2 == true) {
				flag1 = false;
				flag2 = false;
				system("cls");
				break;
			}
			system("cls");
			cout << setfill(' ') << setw(40) << "\n登录成功！" << endl << endl; 
			userinterface.LoginMenu();
			cin >> choice2;
			switch(choice2)
			{
				case 1: {
					pulicFileOperation(); //公开文件操作菜单 
					choice3 = 20; 
					break;
				}
				case 2: {
					personFileOperation(); //个人文件操作 
					choice3 = 20; 
					break;
				}	
				case 3: {
					//查看个人信息，前面调用了查询函数 
					cout << "*****************************************************************\n";
					cout << user.getName() << " " 
						 << user.getPword() << " "
						 << user.getSex() << " " 
						 << user.getTphone() << " " 
						 << user.getGamil();
					cout << "\n*****************************************************************\n";
					process();   //操作后等待 
					break;
				}
				case 4: {
					//修改个人信息
					newuser = user;  //运算符重载 
					
					while (choice3 != 6) 
					{
						if (flag2 == true) {
							break;
						}
						system("cls"); 
						
						userinterface.Changepersonal();
						cin >> choice3;
						switch(choice3) {
							case 1: {
								//修改用户名 
								User u; 
								do {
									cout << setfill(' ') << setw(width2) << "新用户名：";
									cin >> name;
									cin.ignore();
									u = usemanageoperation.SearchOperation(name);
									if (strcmp(u.getName(), name) == 0) {
										cout << setfill(' ') << setw(width2) << "用户名已存在！" << endl; //确保文件中没有相同的用户名 
									}
								} while (strcmp(u.getName(), name) == 0);
								
								newuser.setName(name);
								usemanageoperation.ChangeOperation(newuser, user.getName());              //根据原先用户名查找到对应的信息 
								process();        
								break;
							}
							case 2: {
								//修改用户密码
								cout <<  setw(50) << setfill('-') << "" << endl;
								do {
									cout << setfill(' ') << setw(width2) << "旧密码：";
									strcpy(password, mima(0));
									if (strcmp(password, newuser.getPword()) != 0) {
										cout << setfill(' ') << setw(width2) << "\n密码错误！" << endl; 
									} 
								} while (strcmp(password, newuser.getPword()) != 0);
								cout << endl; 
								
								yanzheng();  //验证两次输入密码是否一致 
								 
								newuser.setPword(password);
								user.setPword(password);  //清空内存中的信息 
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //根据原先用户名查找到对应的信息
								flag2 = true; 
								process();
								break;
							} 
							case 3: {
								//修改性别
								cout <<  setw(50) << setfill('-') << "" << endl;
								cout << setfill(' ') << setw(width2) << "修改后性别：";
								cin >> sex;
								newuser.setSex(sex);
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //根据原先用户名查找到对应的信息
								process();       //操作后等待 
								break;
							} 
							case 4: {
								//修改电话号 
								cout <<  setw(50) << setfill('-') << "" << endl;
								cout << setfill(' ') << setw(width2) << "新电话号：";
								cin >> telephone;
								newuser.setTphone(telephone);
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //根据原先用户名查找到对应的信息
								process();       //操作后等待
								break;
							} 
							case 5: {
								//修改邮箱 
								cout <<  setw(50) << setfill('-') << "" << endl;
								cout << setfill(' ') << setw(width2) << "新邮箱：";
								cin >> gmail;
								newuser.setGmail(gmail);
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //根据原先用户名查找到对应的信息
								process();       //操作后等待
								break;
							} 
							case 6: {
								//返回上级菜单
								system("cls"); 
								break;
							} 
						}
					}
					user = newuser; 
					choice3 = 20;
					break;
				} 
				case 5: {
					//分享功能
					Share share;
					share.get();
					process();   //操作后等待 
					break;
				}
				case 6: {
					//注销账户
					usemanageoperation.DelOperation(name);
					flag1 = true; 
					//直接输入登录进来的个人信息 
					process();   //操作后等待 
					break;
				}	 
				case 7:
					//返回上一级 
					system("cls"); 
					break; 
			}
		}
	}
}
// 登录后个人文件操作
void personFileOperation() {
	string time;  
	string context;
	string scene;
	string role;
	
	string keyword;   //查询，删除，修改用
	string newkeyword;
	while (choice3 != 3) 
	{
		system("cls"); 
		userinterface.PersonalMenu();
		cin >> choice3;
		switch(choice3)
		{
			case 1:
				//个人文本提示词文件操作,菜单 
				system("cls");
				while (choice4 != 6)
				{
					userinterface.PersonTextMenu();
					TextPromptManageOperation textpromptmanageoperation;  //调用方法 
					TextPrompt textprompt;  //文本提示词对象 
					string wordNum;            //
					string language;
					
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//添加个人文本提示词
							cout << setfill(' ') << left; // 设置为左对齐
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "创建时间：";
							cin >> time;
							textprompt.setTime(time);
							cout << setfill(' ') << setw(width2) << "相关场景：";
							cin >> scene;
							textprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "相关角色：";
							cin >> role;
							cin.ignore();
							textprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "字数要求：";
							cin >> wordNum;
							textprompt.setWordNum(wordNum);
							cout << setfill(' ') << setw(width2) << "语言要求：";
							cin >> language;
							textprompt.setLanguage(language);
							cout << setfill(' ') << setw(width2) << "内容要求：";
							cin >> context;
							textprompt.setContext(context);
							textpromptmanageoperation.persontextadd(textprompt); 
							process(); //操作后处理函数 
							break;
						}
						case 2: {
							//查询个人文本提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							textpromptmanageoperation.persontextsearch(keyword);
							process(); //操作后处理函数 
							break;
						}
						case 3: {
							//删除个人文本提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							textpromptmanageoperation.persontextdel(keyword);
							process(); //操作后处理函数 
							break;
						}
						case 4: {
							//修改个人文本提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "修改后：";
							cin >>  newkeyword;
							textpromptmanageoperation.persontextchange(keyword, newkeyword);
							process(); //操作后处理函数 
							break;
						}
						case 5: {
							//显示个人文本提示词
							textpromptmanageoperation.persontextdisplay();
							process(); //操作后处理函数 
							break;
						}
						case 6:
							//返回上一级菜单 
							system("cls"); 
							break;	
					}	
				} 
				choice4 = 20; 
				break; 
			case 2:
				//个人视频提示词文件操作菜单
				system("cls");
				while (choice4 != 6)
				{
					userinterface.PersonVideoMenu();
					VideoPromptManageOperation videopromptmanageoperation; //调用操作方法 
					VideoPrompt videoprompt;   //视频提示词对象
					string video_length;       //视频长度 
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//添加个人视频提示词
							cout << setfill(' ') << left; // 设置为左对齐
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "创建时间：";
							cin >> time;
							videoprompt.setTime(time); 
							cout << setfill(' ') << setw(width2) << "相关场景：";
							cin >> scene;
							videoprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "相关角色：";
							cin >> role;
							cin.ignore();
							videoprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "视频长度：";
							cin >> video_length;
							cin.ignore();
							videoprompt.setVideoLen(video_length); 
							cout << setfill(' ') << setw(width2) << "内容要求：";
							cin >> context;
							videoprompt.setContext(context);
							videopromptmanageoperation.personVideoAdd(videoprompt);
							process(); //操作后处理函数 
							break;
						}
						case 2: {
							//查询个人视频提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							videopromptmanageoperation.personVideoSearch(keyword);
							process(); //操作后处理函数
							break;
						}
						case 3: {
							//删除个人视频提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							videopromptmanageoperation.personVideoDel(keyword);
							process(); //操作后处理函数 
							break;
						}
						case 4: {
							//修改个人视频提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "修改后：";
							cin >>  newkeyword;
							videopromptmanageoperation.personVideoChange(keyword, newkeyword);
							process(); //操作后处理函数 
							break;
						}
						case 5: {
							videopromptmanageoperation.personVideoDisplay();
							process(); //操作后处理函数 
							break;
						}
						case 6:
							system("cls");  //返回上一级菜单
							break;	
					}	
				} 
				choice4 = 20;  
				break;
			case 3: 
			  	system("cls"); //返回上一级菜单
				break; 
		}
	}
} 
//登录后公开文件操作菜单 
void pulicFileOperation() { 
	while (choice3 != 5) 
	{   
		//这四个公开文本提示词，视频提示词都可能用到 
		string time;  
		string context;
		string scene;
		string role;
		//查询，删除，修改用
		string keyword;
		string newkeyword;
		 
		system("cls");
		userinterface.PublicMenu(); 
		cin >> choice3;
		switch(choice3)
		{
			case 1: {
				//公开文本提示词文件操作菜单
				system("cls");
				while (choice4 != 5)
				{
					userinterface.PublicTextMenu();
					
					TextPromptManageOperation textpromptmanageoperation;  //调用方法 
					TextPrompt textprompt;  //文本提示词对象 
					string wordNum; 
					string language;
																	
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//添加公开文本提示词 
							cout << setfill(' ') << left; // 设置为左对齐
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "创建时间：";
							cin >> time;
							textprompt.setTime(time);
							cout << setfill(' ') << setw(width2) << "相关场景：";
							cin >> scene;
							textprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "相关角色：";
							cin >> role;
							cin.ignore();
							textprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "字数要求：";
							cin >> wordNum;
							textprompt.setWordNum(wordNum);
							cout << setfill(' ') << setw(width2) << "语言要求：";
							cin >> language;
							textprompt.setLanguage(language);
							cout << setfill(' ') << setw(width2) << "内容要求：";
							cin >> context;
							textprompt.setContext(context);
							textpromptmanageoperation.AddOperation(textprompt);
							process(); //操作后处理函数 
							break;
						}
						case 2: {
							//查询公开文本提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							textpromptmanageoperation.SearchOperation(keyword);
							process(); //操作后处理函数
							break;
						}
						case 3: {
							//修改公开文本提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "修改后：";
							cin >>  newkeyword;
							textpromptmanageoperation.ChangeOperation(keyword, newkeyword);
							process(); //操作后处理函数 
							break;
						}
						case 4: {
							//显示公开文本提示词														
							textpromptmanageoperation.DisplayOperation();
							process(); //操作后处理函数
							break;
						}
						case 5:
							system("cls");  //返回上级菜单
							break;	
					} 
				}
				choice4 = 20; 
				break; 
			}
				
			case 2: {
				//公开视频提示词文件操作菜单 
				system("cls");
				while (choice4 != 5)
				{	
					userinterface.PublicVideoMenu();
					VideoPromptManageOperation videopromptmanageoperation; //调用操作方法 
					VideoPrompt videoprompt;   //视频提示词对象
					string video_length;       //视频长度 
					
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//添加公开视频提示词 
							cout << setfill(' ') << left; // 设置为左对齐
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "创建时间：";
							cin >> time;
							videoprompt.setTime(time); 
							cout << setfill(' ') << setw(width2) << "相关场景：";
							cin >> scene;
							videoprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "相关角色：";
							cin >> role;
							cin.ignore();
							videoprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "视频长度：";
							cin >> video_length;
							cin.ignore();
							videoprompt.setVideoLen(video_length); 
							cout << setfill(' ') << setw(width2) << "内容要求：";
							cin >> context;
							videoprompt.setContext(context);
							videopromptmanageoperation.AddOperation(videoprompt);
							process(); //操作后处理函数 
							break;
						}
						case 2: {
							//查询公开视频提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							videopromptmanageoperation.SearchOperation(keyword);
							process(); //操作后处理函数
							break;
						}
						case 3: {
							//修改公开视频提示词
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "修改后：";
							cin >>  newkeyword;
							videopromptmanageoperation.ChangeOperation(keyword, newkeyword);
							process(); //操作后处理函数
							break;
						}
						case 4: {
							//显示公开视频提示词
							videopromptmanageoperation.DisplayOperation();
							process(); //操作后处理函数
							break;
						}
						case 5:
							//返回上级菜单
							system("cls"); 
							break;	
					} 
				}
				choice4 = 20;
				break;
			}		
			case 3: {
				//公开模型文件操作菜单 
				system("cls");
				while (choice4 != 5)
				{
					string ModelName;
					string Version;
					string MakeCompany;
					string price;
					
					userinterface.PublicModelMenu();
					ModelManageOperation modelmanageoperation; //调用方法
					Model model; //模型信息
					 
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//添加模型信息
							cout << setfill(' ') << left; // 设置为左对齐
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "模型名称：";
							cin >> ModelName;
							model.setModelName(ModelName);
							
							cout << setfill(' ') << setw(width2) << "模型版本：";
							cin >> Version;
							model.setVersion(Version);
							
							cout << setfill(' ') << setw(width2) << "价格信息：";
							cin >> price;
							model.setIsfree(price); 
							modelmanageoperation.AddOperation(model);
							process(); //操作后处理函数
							break;
						}
						case 2: {
							//查询模型信息	
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							modelmanageoperation.SearchOperation(keyword);
							process(); //操作后处理函数													
							break;
						}
						case 3: {
							//修改模型信息
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "修改后：";
							cin >>  newkeyword;
							modelmanageoperation.ChangeOperation(keyword, newkeyword);
							process(); //操作后处理函数
							break;
						}
						case 4: {
							//显示模型信息
							modelmanageoperation.DisplayOperation();
							process(); //操作后处理函数
							break;
						}
						case 5:
							system("cls"); //返回上级菜单
							break;	
					} 
				}
				choice4 = 20;
				break; 
			} 
			case 4: {
				//公开反馈文件操作菜单 
				system("cls");
				while (choice4 != 4)
				{
					userinterface.PublicFeedbackMenu();
					//反馈相关信息 
					string context;
					string time;
					
					FeedbackOperation feedbackOperation;  //调用方法 
					Feedback feedback;                    //设置信息 
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//显示反馈信息 
							feedbackOperation.DisplayOperation(); 
							process(); //操作后处理函数
							break;
						}
						case 2: {
							//查询反馈信息
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "关键词：";
							cin >>  keyword;
							feedbackOperation.SearchOperation(keyword);
							process(); //操作后处理函数	
							break;
						}
						case 3: {
							//添加反馈信息
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "反馈时间：";
							cin >>  time;
							feedback.setTime(time);
							cout << setfill(' ') << setw(width2) << "反馈内容：";
							cin >>  context;
							feedback.setContext(context);
							feedbackOperation.AddOperation(feedback);
							process(); //操作后处理函数
							break;
						}
						case 4:
							system("cls"); //返回上级菜单
							break;	
					} 
				}
				choice4 = 20;
				break;
			}
				
			case 5: 
				system("cls"); //返回上一级 
				break; 
		}
	}
}

//访客界面 
void fangke() {
	while (choice2 != 9) 
	{
		system("cls"); 
		userinterface.BrowserMenu();
		
		ModelManageOperation modelmanageoperation;
		TextPromptManageOperation textpromptmanageoperation;
		VideoPromptManageOperation videopromptmanageoperation;
		FeedbackOperation feedbackOperation;
		string keyword;
		 
		cin >> choice2;
		switch(choice2)
		{
			case 1: {
				//显示模型信息
				modelmanageoperation.DisplayOperation();
				process(); //操作后处理函数
				break;
			}
			case 2: {
				//查询模型信息 
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "关键词：";
				cin >>  keyword;
				modelmanageoperation.SearchOperation(keyword);
				process(); //操作后处理函数	
				break;
			}
			case 3: {
				//显示公开文本提示词功能 
				textpromptmanageoperation.DisplayOperation();
				process(); //操作后处理函数
				break;
			}
			case 4: {
				//查询公开文本提示词功能 
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "关键词：";
				cin >>  keyword;
				textpromptmanageoperation.SearchOperation(keyword);
				process(); //操作后处理函数
				break;
			}
			case 5: {
				//显示公开视频提示词功能
				videopromptmanageoperation.DisplayOperation();
				process(); //操作后处理函数
				break;
			}
			case 6: {
				//查询公开视频提示词功能
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "关键词：";
				cin >>  keyword;
				videopromptmanageoperation.SearchOperation(keyword);
				process(); //操作后处理函数
				break;
			}
			case 7: {
				//显示反馈功能
				feedbackOperation.DisplayOperation();
				process(); //操作后处理函数
				break;
			}
			case 8: {
				//查询反馈功能（反馈时效性强，查询最近时间的）
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "关键词：";
				cin >>  keyword;
				feedbackOperation.SearchOperation(keyword);
				process(); //操作后处理函数	
				break;
			}	
			case 9:
				system("cls"); //返回上一级 
				break;
		}
	}
}

