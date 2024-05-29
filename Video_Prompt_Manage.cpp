#include <iostream>
#include <fstream>
using namespace std;
#include "Video_Prompt_Manage.h"
#include <vector>
#include <iomanip>

//������Ƶ�ļ�����ɾ����������麯�����붨�� 
void VideoPromptManage::del(const string&) {}; 

//δ��¼�û�����ʹ�ò�ѯ����ʾ 
//��ѯ������Ƶ��ʾ�� 
void VideoPromptManage::search(const string& keyword)     
{
	ifstream in;
	string line;
	in.open("publicVideoprompt.txt");
	bool flag = false; 
	if (in.fail()) 
	{
		cout << "�ļ���ʧ��\n"; 
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
		cout << setfill(' ') << setw(40) << "\nû�и���ʾ�ʣ�" << endl << endl;
	}
} 

//��ʾ����
void VideoPromptManage::display()
{
	string show;
	ifstream in;
	in.open("publicVideoprompt.txt"); 
	if (in.fail())
	{
		cout << "�ļ���ʧ��\n";
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

//��¼�û���ʹ����ӣ��޸� 
//������Ƶ��ʾ����� 
void VideoPromptManage::add(VideoPrompt& videopmpt)
{
	ofstream out;
	out.open("publicVideoprompt.txt", ios::app);  //׷��д��
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	out << videopmpt.getTime() << "," 
		<< videopmpt.getScene() << ","
		<< videopmpt.getRole() << "," 
		<< videopmpt.getVideoLen() << ","
		<< videopmpt.getContext() << endl;
	out.close(); 
	cout << setfill(' ') << setw(40) << "\n��ӹ�����Ƶ��ʾ�ʳɹ���" << endl << endl;
} 

//������Ƶ��ʾ���޸�
void VideoPromptManage::change(const string& keyword, const string& newKeyWord)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("publicVideoprompt.txt");
	if (in.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	//�洢���ڴ��н����޸�
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
	
	//����д���ļ�
	ofstream out;
	out.open("publicVideoprompt.txt");
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		out << lines[i] << endl;    
	}
	out.close();
	if (!flag)
	{
		cout << setfill(' ') << setw(40) << "\nû�и���ʾ�ʣ�" << endl << endl;
	}
	else 
	{
		cout << setfill(' ') << setw(40) << "\n�޸ĳɹ���" << endl << endl;
	}
} 

//�����ļ�����

//�����Ƶ��ʾ�� 
void VideoPromptManage::personVideoAdd(VideoPrompt& videoprompt)          
{
	ofstream out;
	out.open("personVideopmt.txt", ios::app);  //׷��д�� 
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	out << videoprompt.getTime() << "," << videoprompt.getScene() << ","
		<< videoprompt.getRole() << "," << videoprompt.getVideoLen() << "," << videoprompt.getContext() << endl;
	out.close();
	cout << "��ӳɹ�\n";
} 

//��ѯ��Ƶ��ʾ��
void VideoPromptManage::personVideoSearch(const string& keyword)
{
	string line;
	ifstream in;
	in.open("personVideopmt.txt");
	bool flag = false;         //�ж��Ƿ�鵽 
	if (in.fail())
	{
		cout << "�ļ���ʧ��";
		return;
	}
	while (in) 
	{
		getline(in, line); 
		if (!in)
		{
			break;
		}
		if (line.find(keyword) != string::npos)  //ʹ��find�������в��� 
		{
			cout << line << endl;
			flag = true; 
		}
	}
	if (!flag)
	{
		cout << "û�и���ʾ��\n";
	}
	in.close();
} 

//�޸���Ƶ��ʾ��
void VideoPromptManage::personVideoChange(const string& keyword, const string& newkeyword) 
{
	string line;
	ifstream in;
	in.open("personVideopmt.txt");
	bool flag = false; 
	if (in.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	//�洢���ڴ��н����޸�
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
	
	//����д���ļ�
	ofstream out;
	out.open("personVideopmt.txt");
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		out << lines[i] << endl;    
	}
	out.close();
	
	if (!flag)
	{
		cout << "û�и���ʾ��\n";
	}
	else 
	{
		cout << "�޸ĳɹ�\n";
	}
}

//ɾ����Ƶ��ʾ��
void VideoPromptManage::personVideoDel(const string& keyword)
{
	string line;
	ifstream in;
	bool flag = false; 
	in.open("personVideopmt.txt");
	if (in.fail())
	{
		cout << "�ļ���ʧ��";
		return;
	}
	//�洢���ڴ��н����޸�
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
	
	//����д���ļ�
	ofstream out;
	out.open("personVideopmt.txt");
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		out << lines[i] << endl;      
	}
	out.close();
	
	if (!flag)
	{
		cout << "û�и���ʾ��\n";
	}
	else 
	{
		cout << "ɾ���ɹ�\n";
	}
} 

//��ʾ��Ƶ��ʾ�� 
void VideoPromptManage::personVideoDisplay()
{
	string show;
	ifstream in;
	in.open("personVideopmt.txt");
	if (in.fail())
	{
		cout << "�ļ���ʧ��\n";	
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
