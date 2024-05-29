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
// ÿ���˵���Ӧ��ѡ������֣�û��д�������������ķ�������������6���������6.16���������ѭ�� 
const int width = 50;  //�˵����ж���ʹ��        
const int width2 = 23; //ע���¼�����Ϣ��Ҫ 

UserInterface userinterface;  //���ò˵�
UseManageOperation usemanageoperation;
char name[20];
char password[20];    //���ܳ���19λ 
char subpassword[20]; //ȷ������ 
char sex[5];
char telephone[12];   //���ܳ���11λ 
char gmail[15];       //���ܳ���14λ 
int choice1 = 4;
int choice2 = 20; 
int choice3 = 20;
int choice4 = 20;
char pword[20];
bool flag1 = false;   //��־1��ע���˻����������˵�  
bool flag2 = false;   //��־2���޸����뷵�������˵� �� ���µ�¼ 

void regist();    //ע��˵���139��-173�У�  1.�û������ظ�   2.��Ϣд��������ļ� 

void Login();     //��¼�˵� ��176-349�У� 
void personFileOperation(); //��¼������ļ������˵� ��351-532�У�
void pulicFileOperation();  //��¼�󹫿��ļ������˵� ��533-835�У� 

void fangke();    //�ÿͲ˵� ��835-917�У� 

void process();           //������������������������� ��130��-134�У� 
void yanzheng();          //��֤���������Ƿ�����һ�µĺ��� 1.ע���õ� 2.�޸������� ��114-128�У� 
const char* mima(int i);  //����������ʾ * ������86-112�У� 

int main()
{
	while (choice1) 
	{
		system("cls");  //�������� 
		UseManageOperation usemanageoperation;  //�����û�������ö�Ӧ�ķ�����
		userinterface.MainMenu();
		
		cin >> choice1;
		switch(choice1) 
		{
			case 1: {
				system("cls"); 
				regist();           //ע����� 
				process();
				break;
			}		
			case 2: {
				Login();            //��¼���� 
				choice2 = 20;
				break;
			}
			case 3: {
				fangke();           //�ÿͽ���
				choice2 = 20;
				break;
			}	
			case 0:
				break;				 
		}
	} 
	return 0;
} 

const char* mima(int i)          //�û�������ʾ *���� 
{
	char ch; 
	while (1) 
	{
		ch = getch();
		if (ch == '\r')         //����Ƿ��ǻس��� 
		{
			pword[i] = '\0';
			break; 
		}
		else if (ch == '\b')
		{
			if (i > 0)
			{
				i--;
				cout << "\b \b"; //�˸�ɾ��һ��* 
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

void yanzheng() {  //��֤���������Ƿ�һ��  1.ע��ʹ�ã�  2.�޸�����ʹ�� 
	do {
		cout << setfill(' ') << setw(width2) << "�������룺" ;
		strcpy(password, mima(0));
		cout << endl;
		
		cout << setfill(' ') << setw(width2) << "ȷ�����룺" ;
		strcpy(subpassword, mima(0));
		cout << endl;
		
		if (strcmp(password, subpassword) != 0) {
			cout << setfill(' ') << setw(width2) << "���벻һ��" << endl; 
		}
	} while (strcmp(password, subpassword) != 0);
} 

void process() {  //���������� 
	cout << setfill(' ') << setw(30) << "\n�������������\n";
	_getch();    // �ú�����ȴ��û����������
	cout << endl;
}

//ע�����,�������룬 ȷ���û������ظ� 
void regist() {
	User user;
	cout << setw(width) << setfill('-') << "" << endl;
	cout << setfill(' ') << setw((width + strlen("ע�����")) / 2) << "ע�����" << endl;
    
	cout <<  setw(50) << setfill('-') << "" << endl;
	User u;
	do {
		cout << setfill(' ') << setw(width2) << "�û�����";
		cin >> name;
		cin.ignore();
		u = usemanageoperation.SearchOperation(name);
		if (strcmp(u.getName(), name) == 0) {
			cout << setfill(' ') << setw(width2) << "�û����Ѵ��ڣ�" << endl; //ȷ���ļ���û����ͬ���û��� 
		}
	} while (strcmp(u.getName(), name) == 0);
	
	user.setName(name);
	
	yanzheng();  //��֤�û��������������Ƿ�һ�� 
	user.setPword(password);
	cout << setfill(' ') << setw(width2) << "�����Ա�";
	cin >> sex;
	cin.ignore();
	user.setSex(sex);
	cout << setfill(' ') << setw(width2) << "����绰���룺";
	cin >> telephone;
	cin.ignore();
	user.setTphone(telephone);
	cout << setfill(' ') << setw(width2) << "�������䣺";
	cin >> gmail;
	cin.ignore();
	user.setGmail(gmail); 
	usemanageoperation.AddOperation(user); 
} 

//��¼���� 
void Login() {  
	User user;
	User newuser;
	bool flag;
	system("cls"); 
	cout << setw(width) << setfill('-') << "" << endl;
	cout << setfill(' ') << setw((width + strlen("��¼����")) / 2) << "��¼����" << endl;
	cout <<  setw(50) << setfill('-') << "" << endl;
	do {
		cout << setfill(' ') << setw(23) << "�û�����";
		cin >> name;
		cin.ignore(); 
		cout << setfill(' ') << setw(23) << "�������룺";
		strcpy(password, mima(0));
		flag = usemanageoperation.IsLog(name, password);       //��ѯ����֤�ֿ�������ע���͸����룬�������þ��ʻ���¼ 
		if (!flag) {
			cout << setfill(' ') << setw(40) << "\n�û������������" << endl << endl;
		} 
	} while (!flag);
	user = usemanageoperation.SearchOperation(name);           //��ѯ����֤�ֿ�������ע���͸����룬�������þ��ʻ���¼ 
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
			cout << setfill(' ') << setw(40) << "\n��¼�ɹ���" << endl << endl; 
			userinterface.LoginMenu();
			cin >> choice2;
			switch(choice2)
			{
				case 1: {
					pulicFileOperation(); //�����ļ������˵� 
					choice3 = 20; 
					break;
				}
				case 2: {
					personFileOperation(); //�����ļ����� 
					choice3 = 20; 
					break;
				}	
				case 3: {
					//�鿴������Ϣ��ǰ������˲�ѯ���� 
					cout << "*****************************************************************\n";
					cout << user.getName() << " " 
						 << user.getPword() << " "
						 << user.getSex() << " " 
						 << user.getTphone() << " " 
						 << user.getGamil();
					cout << "\n*****************************************************************\n";
					process();   //������ȴ� 
					break;
				}
				case 4: {
					//�޸ĸ�����Ϣ
					newuser = user;  //��������� 
					
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
								//�޸��û��� 
								User u; 
								do {
									cout << setfill(' ') << setw(width2) << "���û�����";
									cin >> name;
									cin.ignore();
									u = usemanageoperation.SearchOperation(name);
									if (strcmp(u.getName(), name) == 0) {
										cout << setfill(' ') << setw(width2) << "�û����Ѵ��ڣ�" << endl; //ȷ���ļ���û����ͬ���û��� 
									}
								} while (strcmp(u.getName(), name) == 0);
								
								newuser.setName(name);
								usemanageoperation.ChangeOperation(newuser, user.getName());              //����ԭ���û������ҵ���Ӧ����Ϣ 
								process();        
								break;
							}
							case 2: {
								//�޸��û�����
								cout <<  setw(50) << setfill('-') << "" << endl;
								do {
									cout << setfill(' ') << setw(width2) << "�����룺";
									strcpy(password, mima(0));
									if (strcmp(password, newuser.getPword()) != 0) {
										cout << setfill(' ') << setw(width2) << "\n�������" << endl; 
									} 
								} while (strcmp(password, newuser.getPword()) != 0);
								cout << endl; 
								
								yanzheng();  //��֤�������������Ƿ�һ�� 
								 
								newuser.setPword(password);
								user.setPword(password);  //����ڴ��е���Ϣ 
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //����ԭ���û������ҵ���Ӧ����Ϣ
								flag2 = true; 
								process();
								break;
							} 
							case 3: {
								//�޸��Ա�
								cout <<  setw(50) << setfill('-') << "" << endl;
								cout << setfill(' ') << setw(width2) << "�޸ĺ��Ա�";
								cin >> sex;
								newuser.setSex(sex);
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //����ԭ���û������ҵ���Ӧ����Ϣ
								process();       //������ȴ� 
								break;
							} 
							case 4: {
								//�޸ĵ绰�� 
								cout <<  setw(50) << setfill('-') << "" << endl;
								cout << setfill(' ') << setw(width2) << "�µ绰�ţ�";
								cin >> telephone;
								newuser.setTphone(telephone);
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //����ԭ���û������ҵ���Ӧ����Ϣ
								process();       //������ȴ�
								break;
							} 
							case 5: {
								//�޸����� 
								cout <<  setw(50) << setfill('-') << "" << endl;
								cout << setfill(' ') << setw(width2) << "�����䣺";
								cin >> gmail;
								newuser.setGmail(gmail);
								usemanageoperation.ChangeOperation(newuser, newuser.getName());  //����ԭ���û������ҵ���Ӧ����Ϣ
								process();       //������ȴ�
								break;
							} 
							case 6: {
								//�����ϼ��˵�
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
					//������
					Share share;
					share.get();
					process();   //������ȴ� 
					break;
				}
				case 6: {
					//ע���˻�
					usemanageoperation.DelOperation(name);
					flag1 = true; 
					//ֱ�������¼�����ĸ�����Ϣ 
					process();   //������ȴ� 
					break;
				}	 
				case 7:
					//������һ�� 
					system("cls"); 
					break; 
			}
		}
	}
}
// ��¼������ļ�����
void personFileOperation() {
	string time;  
	string context;
	string scene;
	string role;
	
	string keyword;   //��ѯ��ɾ�����޸���
	string newkeyword;
	while (choice3 != 3) 
	{
		system("cls"); 
		userinterface.PersonalMenu();
		cin >> choice3;
		switch(choice3)
		{
			case 1:
				//�����ı���ʾ���ļ�����,�˵� 
				system("cls");
				while (choice4 != 6)
				{
					userinterface.PersonTextMenu();
					TextPromptManageOperation textpromptmanageoperation;  //���÷��� 
					TextPrompt textprompt;  //�ı���ʾ�ʶ��� 
					string wordNum;            //
					string language;
					
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//��Ӹ����ı���ʾ��
							cout << setfill(' ') << left; // ����Ϊ�����
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "����ʱ�䣺";
							cin >> time;
							textprompt.setTime(time);
							cout << setfill(' ') << setw(width2) << "��س�����";
							cin >> scene;
							textprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "��ؽ�ɫ��";
							cin >> role;
							cin.ignore();
							textprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> wordNum;
							textprompt.setWordNum(wordNum);
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> language;
							textprompt.setLanguage(language);
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> context;
							textprompt.setContext(context);
							textpromptmanageoperation.persontextadd(textprompt); 
							process(); //���������� 
							break;
						}
						case 2: {
							//��ѯ�����ı���ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							textpromptmanageoperation.persontextsearch(keyword);
							process(); //���������� 
							break;
						}
						case 3: {
							//ɾ�������ı���ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							textpromptmanageoperation.persontextdel(keyword);
							process(); //���������� 
							break;
						}
						case 4: {
							//�޸ĸ����ı���ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "�޸ĺ�";
							cin >>  newkeyword;
							textpromptmanageoperation.persontextchange(keyword, newkeyword);
							process(); //���������� 
							break;
						}
						case 5: {
							//��ʾ�����ı���ʾ��
							textpromptmanageoperation.persontextdisplay();
							process(); //���������� 
							break;
						}
						case 6:
							//������һ���˵� 
							system("cls"); 
							break;	
					}	
				} 
				choice4 = 20; 
				break; 
			case 2:
				//������Ƶ��ʾ���ļ������˵�
				system("cls");
				while (choice4 != 6)
				{
					userinterface.PersonVideoMenu();
					VideoPromptManageOperation videopromptmanageoperation; //���ò������� 
					VideoPrompt videoprompt;   //��Ƶ��ʾ�ʶ���
					string video_length;       //��Ƶ���� 
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//��Ӹ�����Ƶ��ʾ��
							cout << setfill(' ') << left; // ����Ϊ�����
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "����ʱ�䣺";
							cin >> time;
							videoprompt.setTime(time); 
							cout << setfill(' ') << setw(width2) << "��س�����";
							cin >> scene;
							videoprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "��ؽ�ɫ��";
							cin >> role;
							cin.ignore();
							videoprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "��Ƶ���ȣ�";
							cin >> video_length;
							cin.ignore();
							videoprompt.setVideoLen(video_length); 
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> context;
							videoprompt.setContext(context);
							videopromptmanageoperation.personVideoAdd(videoprompt);
							process(); //���������� 
							break;
						}
						case 2: {
							//��ѯ������Ƶ��ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							videopromptmanageoperation.personVideoSearch(keyword);
							process(); //����������
							break;
						}
						case 3: {
							//ɾ��������Ƶ��ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							videopromptmanageoperation.personVideoDel(keyword);
							process(); //���������� 
							break;
						}
						case 4: {
							//�޸ĸ�����Ƶ��ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "�޸ĺ�";
							cin >>  newkeyword;
							videopromptmanageoperation.personVideoChange(keyword, newkeyword);
							process(); //���������� 
							break;
						}
						case 5: {
							videopromptmanageoperation.personVideoDisplay();
							process(); //���������� 
							break;
						}
						case 6:
							system("cls");  //������һ���˵�
							break;	
					}	
				} 
				choice4 = 20;  
				break;
			case 3: 
			  	system("cls"); //������һ���˵�
				break; 
		}
	}
} 
//��¼�󹫿��ļ������˵� 
void pulicFileOperation() { 
	while (choice3 != 5) 
	{   
		//���ĸ������ı���ʾ�ʣ���Ƶ��ʾ�ʶ������õ� 
		string time;  
		string context;
		string scene;
		string role;
		//��ѯ��ɾ�����޸���
		string keyword;
		string newkeyword;
		 
		system("cls");
		userinterface.PublicMenu(); 
		cin >> choice3;
		switch(choice3)
		{
			case 1: {
				//�����ı���ʾ���ļ������˵�
				system("cls");
				while (choice4 != 5)
				{
					userinterface.PublicTextMenu();
					
					TextPromptManageOperation textpromptmanageoperation;  //���÷��� 
					TextPrompt textprompt;  //�ı���ʾ�ʶ��� 
					string wordNum; 
					string language;
																	
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//��ӹ����ı���ʾ�� 
							cout << setfill(' ') << left; // ����Ϊ�����
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "����ʱ�䣺";
							cin >> time;
							textprompt.setTime(time);
							cout << setfill(' ') << setw(width2) << "��س�����";
							cin >> scene;
							textprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "��ؽ�ɫ��";
							cin >> role;
							cin.ignore();
							textprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> wordNum;
							textprompt.setWordNum(wordNum);
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> language;
							textprompt.setLanguage(language);
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> context;
							textprompt.setContext(context);
							textpromptmanageoperation.AddOperation(textprompt);
							process(); //���������� 
							break;
						}
						case 2: {
							//��ѯ�����ı���ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							textpromptmanageoperation.SearchOperation(keyword);
							process(); //����������
							break;
						}
						case 3: {
							//�޸Ĺ����ı���ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "�޸ĺ�";
							cin >>  newkeyword;
							textpromptmanageoperation.ChangeOperation(keyword, newkeyword);
							process(); //���������� 
							break;
						}
						case 4: {
							//��ʾ�����ı���ʾ��														
							textpromptmanageoperation.DisplayOperation();
							process(); //����������
							break;
						}
						case 5:
							system("cls");  //�����ϼ��˵�
							break;	
					} 
				}
				choice4 = 20; 
				break; 
			}
				
			case 2: {
				//������Ƶ��ʾ���ļ������˵� 
				system("cls");
				while (choice4 != 5)
				{	
					userinterface.PublicVideoMenu();
					VideoPromptManageOperation videopromptmanageoperation; //���ò������� 
					VideoPrompt videoprompt;   //��Ƶ��ʾ�ʶ���
					string video_length;       //��Ƶ���� 
					
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//��ӹ�����Ƶ��ʾ�� 
							cout << setfill(' ') << left; // ����Ϊ�����
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "����ʱ�䣺";
							cin >> time;
							videoprompt.setTime(time); 
							cout << setfill(' ') << setw(width2) << "��س�����";
							cin >> scene;
							videoprompt.setScene(scene);
							cout << setfill(' ') << setw(width2) << "��ؽ�ɫ��";
							cin >> role;
							cin.ignore();
							videoprompt.setRole(role);
							cout << setfill(' ') << setw(width2) << "��Ƶ���ȣ�";
							cin >> video_length;
							cin.ignore();
							videoprompt.setVideoLen(video_length); 
							cout << setfill(' ') << setw(width2) << "����Ҫ��";
							cin >> context;
							videoprompt.setContext(context);
							videopromptmanageoperation.AddOperation(videoprompt);
							process(); //���������� 
							break;
						}
						case 2: {
							//��ѯ������Ƶ��ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							videopromptmanageoperation.SearchOperation(keyword);
							process(); //����������
							break;
						}
						case 3: {
							//�޸Ĺ�����Ƶ��ʾ��
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "�޸ĺ�";
							cin >>  newkeyword;
							videopromptmanageoperation.ChangeOperation(keyword, newkeyword);
							process(); //����������
							break;
						}
						case 4: {
							//��ʾ������Ƶ��ʾ��
							videopromptmanageoperation.DisplayOperation();
							process(); //����������
							break;
						}
						case 5:
							//�����ϼ��˵�
							system("cls"); 
							break;	
					} 
				}
				choice4 = 20;
				break;
			}		
			case 3: {
				//����ģ���ļ������˵� 
				system("cls");
				while (choice4 != 5)
				{
					string ModelName;
					string Version;
					string MakeCompany;
					string price;
					
					userinterface.PublicModelMenu();
					ModelManageOperation modelmanageoperation; //���÷���
					Model model; //ģ����Ϣ
					 
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//���ģ����Ϣ
							cout << setfill(' ') << left; // ����Ϊ�����
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "ģ�����ƣ�";
							cin >> ModelName;
							model.setModelName(ModelName);
							
							cout << setfill(' ') << setw(width2) << "ģ�Ͱ汾��";
							cin >> Version;
							model.setVersion(Version);
							
							cout << setfill(' ') << setw(width2) << "�۸���Ϣ��";
							cin >> price;
							model.setIsfree(price); 
							modelmanageoperation.AddOperation(model);
							process(); //����������
							break;
						}
						case 2: {
							//��ѯģ����Ϣ	
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							modelmanageoperation.SearchOperation(keyword);
							process(); //����������													
							break;
						}
						case 3: {
							//�޸�ģ����Ϣ
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							cout << setfill(' ') << setw(width2) << "�޸ĺ�";
							cin >>  newkeyword;
							modelmanageoperation.ChangeOperation(keyword, newkeyword);
							process(); //����������
							break;
						}
						case 4: {
							//��ʾģ����Ϣ
							modelmanageoperation.DisplayOperation();
							process(); //����������
							break;
						}
						case 5:
							system("cls"); //�����ϼ��˵�
							break;	
					} 
				}
				choice4 = 20;
				break; 
			} 
			case 4: {
				//���������ļ������˵� 
				system("cls");
				while (choice4 != 4)
				{
					userinterface.PublicFeedbackMenu();
					//���������Ϣ 
					string context;
					string time;
					
					FeedbackOperation feedbackOperation;  //���÷��� 
					Feedback feedback;                    //������Ϣ 
					cin >> choice4;
					switch(choice4)
					{
						case 1: {
							//��ʾ������Ϣ 
							feedbackOperation.DisplayOperation(); 
							process(); //����������
							break;
						}
						case 2: {
							//��ѯ������Ϣ
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
							cin >>  keyword;
							feedbackOperation.SearchOperation(keyword);
							process(); //����������	
							break;
						}
						case 3: {
							//��ӷ�����Ϣ
							cout <<  setw(50) << setfill('-') << "" << endl;
							cout << setfill(' ') << setw(width2) << "����ʱ�䣺";
							cin >>  time;
							feedback.setTime(time);
							cout << setfill(' ') << setw(width2) << "�������ݣ�";
							cin >>  context;
							feedback.setContext(context);
							feedbackOperation.AddOperation(feedback);
							process(); //����������
							break;
						}
						case 4:
							system("cls"); //�����ϼ��˵�
							break;	
					} 
				}
				choice4 = 20;
				break;
			}
				
			case 5: 
				system("cls"); //������һ�� 
				break; 
		}
	}
}

//�ÿͽ��� 
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
				//��ʾģ����Ϣ
				modelmanageoperation.DisplayOperation();
				process(); //����������
				break;
			}
			case 2: {
				//��ѯģ����Ϣ 
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
				cin >>  keyword;
				modelmanageoperation.SearchOperation(keyword);
				process(); //����������	
				break;
			}
			case 3: {
				//��ʾ�����ı���ʾ�ʹ��� 
				textpromptmanageoperation.DisplayOperation();
				process(); //����������
				break;
			}
			case 4: {
				//��ѯ�����ı���ʾ�ʹ��� 
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
				cin >>  keyword;
				textpromptmanageoperation.SearchOperation(keyword);
				process(); //����������
				break;
			}
			case 5: {
				//��ʾ������Ƶ��ʾ�ʹ���
				videopromptmanageoperation.DisplayOperation();
				process(); //����������
				break;
			}
			case 6: {
				//��ѯ������Ƶ��ʾ�ʹ���
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
				cin >>  keyword;
				videopromptmanageoperation.SearchOperation(keyword);
				process(); //����������
				break;
			}
			case 7: {
				//��ʾ��������
				feedbackOperation.DisplayOperation();
				process(); //����������
				break;
			}
			case 8: {
				//��ѯ�������ܣ�����ʱЧ��ǿ����ѯ���ʱ��ģ�
				cout <<  setw(50) << setfill('-') << "" << endl;
				cout << setfill(' ') << setw(width2) << "�ؼ��ʣ�";
				cin >>  keyword;
				feedbackOperation.SearchOperation(keyword);
				process(); //����������	
				break;
			}	
			case 9:
				system("cls"); //������һ�� 
				break;
		}
	}
}

