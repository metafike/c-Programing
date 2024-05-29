#ifndef PROMPT_H
#define PROMPT_H

#include <string>
using namespace std;
//��ʾ�ʻ���
//��������Ƶ��ʾ�ʣ��ı���ʾ��
class Prompt 
{
	private:
		string context;             //��ʾ������ (��ʾ�ʹ����и�����������ѯ)
		string time;                //��������
		string scene;               //��ͬ����
		string role;                //��ͬ��ɫ 
	public: 
		void setTime(const string&);    //���ô���ʱ�� 
		void setScene(const string&);   //���ó���
		void setRole(const string&);    //���ý�ɫ 
		void setContext(const string&); //�������� 
		string getTime();            //��ô�������
		string getScene();           //��ó���
		string getRole();            //��ý�ɫ 
		string getContext();         //�����ʾ������ 
};
#endif 
