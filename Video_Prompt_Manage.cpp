#include <iostream>
#include <fstream>
using namespace std;
#include "Video_Prompt_Manage.h"
#include <vector>
#include <iomanip>

//公开视频文件不能删除，基类的虚函数必须定义 
void VideoPromptManage::del(const string&) {}; 

//未登录用户可以使用查询，显示 
//查询公开视频提示词 
void VideoPromptManage::search(const string& keyword)     
{
	ifstream in;
	string line;
	in.open("publicVideoprompt.txt");
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
		cout << setfill(' ') << setw(40) << "\n没有该提示词！" << endl << endl;
	}
} 

//显示功能
void VideoPromptManage::display()
{
	string show;
	ifstream in;
	in.open("publicVideoprompt.txt"); 
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

//登录用户可使用添加，修改 
//公开视频提示词添加 
void VideoPromptManage::add(VideoPrompt& videopmpt)
{
	ofstream out;
	out.open("publicVideoprompt.txt", ios::app);  //追加写入
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	out << videopmpt.getTime() << "," 
		<< videopmpt.getScene() << ","
		<< videopmpt.getRole() << "," 
		<< videopmpt.getVideoLen() << ","
		<< videopmpt.getContext() << endl;
	out.close(); 
	cout << setfill(' ') << setw(40) << "\n添加公开视频提示词成功！" << endl << endl;
} 

//公开视频提示词修改
void VideoPromptManage::change(const string& keyword, const string& newKeyWord)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("publicVideoprompt.txt");
	if (in.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	//存储到内存中进行修改
	vector<string> lines;
	 
	while (in) 
	{
		getline(in, line);
		if (!in)
		{
			break;
		}
		if (line.find(keyword) != string::npos)
		{
			line.replace(line.find(keyword), keyword.size(), newKeyWord);
			flag = true;
		}
		lines.push_back(line);
	}
	in.close();
	
	//重新写入文件
	ofstream out;
	out.open("publicVideoprompt.txt");
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		out << lines[i] << endl;    
	}
	out.close();
	if (!flag)
	{
		cout << setfill(' ') << setw(40) << "\n没有该提示词！" << endl << endl;
	}
	else 
	{
		cout << setfill(' ') << setw(40) << "\n修改成功！" << endl << endl;
	}
} 

//个人文件操作

//添加视频提示词 
void VideoPromptManage::personVideoAdd(VideoPrompt& videoprompt)          
{
	ofstream out;
	out.open("personVideopmt.txt", ios::app);  //追加写入 
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	out << videoprompt.getTime() << "," << videoprompt.getScene() << ","
		<< videoprompt.getRole() << "," << videoprompt.getVideoLen() << "," << videoprompt.getContext() << endl;
	out.close();
	cout << "添加成功\n";
} 

//查询视频提示词
void VideoPromptManage::personVideoSearch(const string& keyword)
{
	string line;
	ifstream in;
	in.open("personVideopmt.txt");
	bool flag = false;         //判断是否查到 
	if (in.fail())
	{
		cout << "文件打开失败";
		return;
	}
	while (in) 
	{
		getline(in, line); 
		if (!in)
		{
			break;
		}
		if (line.find(keyword) != string::npos)  //使用find函数进行查找 
		{
			cout << line << endl;
			flag = true; 
		}
	}
	if (!flag)
	{
		cout << "没有该提示词\n";
	}
	in.close();
} 

//修改视频提示词
void VideoPromptManage::personVideoChange(const string& keyword, const string& newkeyword) 
{
	string line;
	ifstream in;
	in.open("personVideopmt.txt");
	bool flag = false; 
	if (in.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	//存储到内存中进行修改
	vector<string> lines;
	 
	while (in) 
	{
		getline(in, line);
		if (!in)
		{
			break;
		}
		if (line.find(keyword) != string::npos)
		{
			line.replace(line.find(keyword), keyword.size(), newkeyword);
			flag = true;
		}
		lines.push_back(line);
	}
	in.close();
	
	//重新写入文件
	ofstream out;
	out.open("personVideopmt.txt");
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		out << lines[i] << endl;    
	}
	out.close();
	
	if (!flag)
	{
		cout << "没有该提示词\n";
	}
	else 
	{
		cout << "修改成功\n";
	}
}

//删除视频提示词
void VideoPromptManage::personVideoDel(const string& keyword)
{
	string line;
	ifstream in;
	bool flag = false; 
	in.open("personVideopmt.txt");
	if (in.fail())
	{
		cout << "文件打开失败";
		return;
	}
	//存储到内存中进行修改
	vector<string> lines;
	 
	while (in) 
	{
		getline(in, line);
		if (!in)
		{
			break;
		}
		if (line.find(keyword) != string::npos)
		{
			flag = true;
			continue;
		}
		lines.push_back(line);
	}
	in.close();
	
	//重新写入文件
	ofstream out;
	out.open("personVideopmt.txt");
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		out << lines[i] << endl;      
	}
	out.close();
	
	if (!flag)
	{
		cout << "没有该提示词\n";
	}
	else 
	{
		cout << "删除成功\n";
	}
} 

//显示视频提示词 
void VideoPromptManage::personVideoDisplay()
{
	string show;
	ifstream in;
	in.open("personVideopmt.txt");
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
