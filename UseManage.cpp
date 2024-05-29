#include <iostream>
using namespace std;
#include "UseManage.h"
#include <stdlib.h>
#include <string.h>
#include <iomanip>

//序列化 
void UseManage::serialize(ofstream& out) const
{
	out.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
//反序列化 
void UseManage::deserialize(ifstream& in)
{
	in.read(reinterpret_cast<char*>(this), sizeof(*this));
}

//添加功能，将用户信息写入二进制文件
void UseManage::add(User& us)       
{
	ofstream out1;             //写入文件 ，采取追加 
	out1.open("userInformation.dat", ios::binary | ios::app);       
	if(out1.fail()) 
	{
		cout << "文件打开失败\n";
		return;	
	}
	//将User对象us序列化到文件中 
	us.serialize(out1);
	out1.close();
    cout << setfill(' ') << setw(40) << "\n注册成功！" << endl << endl;
} 

//删除功能，读取到内存中，然后删除，最后再写入文件 
void UseManage::del(const char* name)
{
	ifstream in1;
	in1.open("userInformation.dat", ios::binary);
	if (!in1)
	{
		cout << "文件打开失败\n";
		return;	
	} 
	while (in1)
	{
		User u;                
		u.deserialize(in1);    //将文件中的东西，反序列化到这个内存中
		
		if(!in1)           
		{
			break;
		}		
		users.push_back(u);   //添加到动态数组中 
	}
	in1.close(); 
	
	//删除信息，采用erase函数
	bool flag = 0;                               //判断是否删除用户信息 
	for (int i = 0; i < users.size(); i++) 
	{
		if (strcmp(users[i].getName(), name) == 0) 
		{
			users.erase(users.begin() + i);      //erase函数，将信息从容器中删除
			i--;
			flag = 1;	
		}	
	} 
	if (flag) 
	{
		cout << setfill(' ') << setw(40) << "\n注销成功！" << endl << endl;
	}
	else 
	{
    	cout << setfill(' ') << setw(40) << "\n没有找到该用户！" << endl << endl;
	}
	
	//将删除后的信息写入文件中
	ofstream out;
	out.open("userInformation.dat", ios::binary | ios::trunc); 
	if (!out)
	{
		cout << "文件打开失败\n";
		return;	
	} 
	for (int i = 0; i < users.size(); i++) 
	{
		users[i].serialize(out); 
	}
	out.close();
	users.clear();             //清空容器 
} 

//查询用户信息 : 1.查个人信息，2.判断注册账户时用户名是否已经注册 
User UseManage::search(const char* name)
{
	ifstream in;
	bool flag = false;
	User u;
	in.open("userInformation.dat", ios::binary);
	if (!in)
	{
		cout << "文件打开失败\n";
		return User(); //返回空用户 
	}
	while (in) 
	{
		u.deserialize(in);
		if (!in)
		{
			break;
		}
		if (strcmp(u.getName(), name) == 0)
		{
			//输出对应的用户信息，不输出密码
			flag = true;
			in.close();
			return u;
		}
	}
	in.close();
	return User();  //返回空用户 
} 

//修改用户信息，必须存储到动态数组中，改变后，在存进去 
void UseManage::change(User& newuser, const char* name)
{
	ifstream in1;
	in1.open("userInformation.dat", ios::binary);
	if (!in1)
	{
		cout << "文件打开失败\n";
		return;	
	} 
	while (in1)
	{
		User u;                
		u.deserialize(in1);    //将文件中的东西，反序列化到这个内存中
		
		if(!in1)               
		{
			break;
		}		
		users.push_back(u);   //添加到动态数组中 
	}
	in1.close(); 
	
	bool flag = 0;
	for (int i = 0; i < users.size(); i++) 
	{
		if (strcmp(users[i].getName(), name) == 0) 
		{
			//修改信息 
			users[i] = newuser; 
			flag = 1;	
		}	
	} 
	
	if (flag) 
	{
		cout << setfill(' ') << setw(40) << "\n信息修改成功！" << endl << endl;
	}
	else 
	{
		cout << "没有找到该用户\n"; 
	}
	//重新将修改后的容器写入文件 
	ofstream out;
	out.open("userInformation.dat", ios::binary | ios::trunc); //写入，不追加
	if (!out)
	{
		cout << "文件打开失败\n";
		return;	
	} 
	for (int i = 0; i < users.size(); i++) 
	{
		users[i].serialize(out); 
	}
	out.close();
	users.clear();             //清空容器 
} 

//验证用户是否登录成功, 在已有的文件中找对应的信息 
bool UseManage::isLog(const char* nm, const char* pword)
{
	ifstream in;
	bool flag = false;
	in.open("userInformation.dat", ios::binary);
	if (!in)
	{
		cout << "文件打开失败\n";
		return false;      
	}
	while (in) 
	{
		User u;
		u.deserialize(in);     //反序列读取到内存中 
		if (!in)
		{
			break;
		}
		if (strcmp(u.getName(), nm) == 0 && strcmp(u.getPword(), pword) == 0)
		{
			flag = true;
		}
	}
	in.close();
	return flag;
} 

//显示功能个人使用
void UseManage::display()
{
	ifstream in;
	in.open("userInformation.dat", ios::binary);
	if (!in)
	{
		cout << "文件打开失败\n";
		return;
	}
	while (in) 
	{
		User u;
		u.deserialize(in);
		if (!in)
		{
			break;
		}
		cout << u.getName() << " " 
			 << u.getPword() << " "
			 << u.getSex() << " " 
			 << u.getTphone() << " " 
			 << u.getGamil() << endl;
	}
	in.close();
 } 
