#include <iostream>
#include <fstream>
using namespace std;
#include "Text_Prompt_Manage.h"
#include <vector>
#include <iomanip>

//公开文本文件不能删除，基类的虚函数必须定义 
void TextPromptManage::del(const string& k) {}; 

//未登录用户可以使用查询，显示 
//查询公开文本提示词 
void TextPromptManage::search(const string& keyword)     
{
	ifstream in;
	string line; 
	in.open("publicTextprompt.txt");
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
void TextPromptManage::display()
{
	string show;
	ifstream in;
	in.open("publicTextprompt.txt"); 
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
//公开文本提示词添加 
void TextPromptManage::add(TextPrompt& txpmpt)
{
	ofstream out;
	out.open("publicTextprompt.txt", ios::app);  //追加写入
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	}
	out << txpmpt.getTime() << "," << txpmpt.getScene() << ","
		<< txpmpt.getRole() << "," << txpmpt.getWordNum() << ","
		<< txpmpt.getLanguage() << "," << txpmpt.getContext() << endl;
	out.close(); 
	cout << setfill(' ') << setw(40) << "\n添加公开文本提示词成功！" << endl << endl;
} 

//公开文本提示词修改
void TextPromptManage::change(const string& keyword, const string& newKeyWord)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("publicTextprompt.txt");
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
	out.open("publicTextprompt.txt");
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
		cout << setfill(' ') << setw(40) << "\n修改公开提示词成功！" << endl << endl;
	}
} 

//个人文件
//添加个人文本提示词 
void TextPromptManage::persontextadd(TextPrompt& textprompt)            
{
	ofstream out;
	out.open("personTextpmt.txt", ios::app);  //追加写入 
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;
	} 
	//访问基类prompt私有成员，用接口， 
	out << textprompt.getTime() << "," << textprompt.getScene() << ","
		<< textprompt.getRole() << "," << textprompt.getWordNum() << ","
		<< textprompt.getLanguage() << "," << textprompt.getContext() << endl;
	out.close();
	cout << "\n添加成功\n";
} 

//查询个人文本提示词 
void TextPromptManage::persontextsearch(const string& keyword)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("personTextpmt.txt");
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
		if (line.find(keyword) != string::npos)  //使用find函数进行查找 
		{
			cout << line << endl;
			flag = true;
		}
	}
	in.close();
	if (!flag) 
	{
		cout << "没有该提示词\n";
	}
}

//修改个人文本提示词 
void TextPromptManage::persontextchange(const string& keyword, const string& newkeyword)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("personTextpmt.txt");
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
	out.open("personTextpmt.txt");
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

//删除个人文本提示词 
void TextPromptManage::persontextdel(const string& keyword) 
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("personTextpmt.txt");
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
	out.open("personTextpmt.txt");
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

//显示个人文本提示词 
void TextPromptManage::persontextdisplay()
{
	string line;
	ifstream in;
	in.open("personTextpmt.txt");
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
		cout << line << endl;
	}
	in.close();
} 
 
