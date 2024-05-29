#ifndef FEEDBACKMANAGE_H
#define FEEDBACKMANAGE_H
#include <string>
using namespace std;
#include "Manage.h"
#include "Feedback.h" 

//���������࣬�ļ����� 
class FeedbackManage : public Manage<Feedback> 
{
	public:
		//��¼�û�����ʹ�� 
		void add(Feedback& feedback);          //��ӹ���
		//δ��¼�û�����ʹ�� 
		void display();                        //��ʾ����
		void search(const string&);            //��ѯ���ܣ�������У���Ҫ��ѯ����ʱ�䣬��Ϊ��������ʱЧ�Խ�ǿ�� 
		//ɾ�����޸Ĺ��ܶ�����ʹ�� 
		void change(const string&, const string&);
		void del(const string&); 
};
#endif
