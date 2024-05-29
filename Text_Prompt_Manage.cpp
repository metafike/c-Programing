#include <iostream>
#include <fstream>
using namespace std;
#include "Text_Prompt_Manage.h"
#include <vector>
#include <iomanip>

//�����ı��ļ�����ɾ����������麯�����붨�� 
void TextPromptManage::del(const string& k) {}; 

//δ��¼�û�����ʹ�ò�ѯ����ʾ 
//��ѯ�����ı���ʾ�� 
void TextPromptManage::search(const string& keyword)     
{
	ifstream in;
	string line; 
	in.open("publicTextprompt.txt");
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
void TextPromptManage::display()
{
	string show;
	ifstream in;
	in.open("publicTextprompt.txt"); 
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
//�����ı���ʾ����� 
void TextPromptManage::add(TextPrompt& txpmpt)
{
	ofstream out;
	out.open("publicTextprompt.txt", ios::app);  //׷��д��
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	out << txpmpt.getTime() << "," << txpmpt.getScene() << ","
		<< txpmpt.getRole() << "," << txpmpt.getWordNum() << ","
		<< txpmpt.getLanguage() << "," << txpmpt.getContext() << endl;
	out.close(); 
	cout << setfill(' ') << setw(40) << "\n��ӹ����ı���ʾ�ʳɹ���" << endl << endl;
} 

//�����ı���ʾ���޸�
void TextPromptManage::change(const string& keyword, const string& newKeyWord)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("publicTextprompt.txt");
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
	out.open("publicTextprompt.txt");
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
		cout << setfill(' ') << setw(40) << "\n�޸Ĺ�����ʾ�ʳɹ���" << endl << endl;
	}
} 

//�����ļ�
//��Ӹ����ı���ʾ�� 
void TextPromptManage::persontextadd(TextPrompt& textprompt)            
{
	ofstream out;
	out.open("personTextpmt.txt", ios::app);  //׷��д�� 
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	} 
	//���ʻ���prompt˽�г�Ա���ýӿڣ� 
	out << textprompt.getTime() << "," << textprompt.getScene() << ","
		<< textprompt.getRole() << "," << textprompt.getWordNum() << ","
		<< textprompt.getLanguage() << "," << textprompt.getContext() << endl;
	out.close();
	cout << "\n��ӳɹ�\n";
} 

//��ѯ�����ı���ʾ�� 
void TextPromptManage::persontextsearch(const string& keyword)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("personTextpmt.txt");
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
		if (line.find(keyword) != string::npos)  //ʹ��find�������в��� 
		{
			cout << line << endl;
			flag = true;
		}
	}
	in.close();
	if (!flag) 
	{
		cout << "û�и���ʾ��\n";
	}
}

//�޸ĸ����ı���ʾ�� 
void TextPromptManage::persontextchange(const string& keyword, const string& newkeyword)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("personTextpmt.txt");
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
	out.open("personTextpmt.txt");
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

//ɾ�������ı���ʾ�� 
void TextPromptManage::persontextdel(const string& keyword) 
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("personTextpmt.txt");
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
	out.open("personTextpmt.txt");
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

//��ʾ�����ı���ʾ�� 
void TextPromptManage::persontextdisplay()
{
	string line;
	ifstream in;
	in.open("personTextpmt.txt");
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
		cout << line << endl;
	}
	in.close();
} 
 
