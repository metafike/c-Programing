#include "Model_Manage.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <iomanip>

//ɾ������ʹ��,�麯��Ҫ���� 
void ModelManage::del(const string& k) {};
 
//δ��¼�û�����ʹ�ò�ѯ���޸�
//��ѯģ��
void ModelManage::search(const string& keyword)
{
	ifstream in;
	string line;
	in.open("Model.txt");
	bool flag = false;
	if (in.fail())
	{
		cout << "�ļ���ʧ��\n";
		return; 
	}
	while (in)
	{
		getline(in, line);    //��ȡstring���ͱ���ʹ��ȫ��getline()���� 
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
		cout << "û�и�ģ��\n";
	}
} 

//��ʾģ����Ϣ
void ModelManage::display()
{
	string show;
	ifstream in;
	in.open("Model.txt");
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

//��¼�û�������ӣ��޸�
//��ӹ���
void ModelManage::add(Model& model)
{
	ofstream out;
	out.open("Model.txt", ios::app);  //׷�� 
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;	
	} 
	out << model.getModelName() << "," << model.getVersion() << "," << model.getIsfree() << endl;
	out.close();
	cout << setfill(' ') << setw(40) << "\n��ӳɹ���" << endl << endl;
}

//�޸Ĺ���
void ModelManage::change(const string& keyword, const string& newKeyWord)
{
	string line;
	ifstream in;
	bool flag = false;
	in.open("Model.txt");
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
	out.open("Model.txt");
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
		cout << "û�и�ģ��\n";
	}
	else 
	{
		cout << "�޸ĳɹ�\n";
	}
} 
