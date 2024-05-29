#include "Feedback_Manage.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <vector> 

//�û������޸ģ���ɾ�������ļ� 
void FeedbackManage::change(const string&, const string&) {}
void FeedbackManage::del(const string&) {}

//��¼�û�����ʹ�ã���� 
//��ӷ��� 
void FeedbackManage::add(Feedback& feedback)
{
	ofstream out;
	out.open("Feedback.txt", ios::app);  //׷��
	if (out.fail())
	{
		cout << "�ļ���ʧ��\n";
		return;
	} 
	out << feedback.getTime() << "," 
		<< feedback.getContext() << endl;
	cout << "\n��ӳɹ���\n";
	out.close();
}

//�ÿ�ֻ��ʹ�ã���ѯ����ʾ���� 
//��ѯ���� (������䲻������ֻ��������ص�һ���֣������ѯ����5�¼��ţ�ʱ��û��������Ϳ�������5.������صĶ������) 
void FeedbackManage::search(const string& keyword)
{
	ifstream in;
	string line;
	in.open("Feedback.txt");
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
		cout << "û����ط�������\n";
	}
} 

//��ʾ����
void FeedbackManage::display()
{
	string show;
	ifstream in;
	in.open("Feedback.txt");
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
