#include "Feedback_Manage.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector> 

//用户不能修改，或删除反馈文件 
void FeedbackManage::change(const string&, const string&) {}
void FeedbackManage::del(const string&) {}

//登录用户可以使用：添加 
//添加反馈 
void FeedbackManage::add(Feedback& feedback)
{
	ofstream out;
	out.open("Feedback.txt", ios::app);  //追加
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	} 
	out << feedback.getTime() << "," 
		<< feedback.getContext() << endl;
	cout << "\n添加成功！\n";
	out.close();
}

//访客只能使用：查询，显示功能 
//查询功能 (如果记忆不完整，只记忆了相关的一部分，比如查询具体5月几号，时间没记清楚，就可以输入5.所有相关的都会输出) 
void FeedbackManage::search(const string& keyword)
{
	ifstream in;
	string line;
	in.open("Feedback.txt");
	bool flag = false;
	if (in.fail())
	{
		cout << "文件打开失败\n";
		return; 
	}
	while (in)
	{
		getline(in, line);   
		if (!in)
		{
			break;
		}
		if (line.find(keyword) != string::npos)
		{
			cout << line << endl;
			flag = true;
		} 
	}
	in.close();
	if (!flag)
	{
		cout << "没有相关反馈内容\n";
	}
} 

//显示功能
void FeedbackManage::display()
{
	string show;
	ifstream in;
	in.open("Feedback.txt");
	if (in.fail())
	{
		cout << "文件打开失败\n";
		return; 
	}
	while (in)
	{
		getline(in, show);
		if (!in)
		{
			break;
		}
		cout << show << endl;
	}
	in.close();
} 
