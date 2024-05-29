#include "Model_Manage.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <iomanip>

//删除不能使用,虚函数要定义 
void ModelManage::del(const string& k) {};
 
//未登录用户可以使用查询和修改
//查询模型
void ModelManage::search(const string& keyword)
{
	ifstream in;
	string line;
	in.open("Model.txt");
	bool flag = false;
	if (in.fail())
	{
		cout << "文件打开失败\n";
		return; 
	}
	while (in)
	{
		getline(in, line);    //读取string类型必须使用全局getline()函数 
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
		cout << "没有该模型\n";
	}
} 

//显示模型信息
void ModelManage::display()
{
	string show;
	ifstream in;
	in.open("Model.txt");
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

//登录用户可以添加，修改
//添加功能
void ModelManage::add(Model& model)
{
	ofstream out;
	out.open("Model.txt", ios::app);  //追加 
	if (out.fail())
	{
		cout << "文件打开失败\n";
		return;	
	} 
	out << model.getModelName() << "," << model.getVersion() << "," << model.getIsfree() << endl;
	out.close();
	cout << setfill(' ') << setw(40) << "\n添加成功！" << endl << endl;
}

//修改功能
void ModelManage::change(const string& keyword, const string& newKeyWord)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("Model.txt");
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
	out.open("Model.txt");
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
		cout << "没有该模型\n";
	}
	else 
	{
		cout << "修改成功\n";
	}
} 
