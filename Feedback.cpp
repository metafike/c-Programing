#include "Feedback.h"

//���÷������� 
void Feedback::setContext(const string& ctext)
{
	context = ctext;
}

//���÷���ʱ�� 
void Feedback::setTime(const string& tm)
{
	time = tm;
}

//��÷�������
string Feedback::getContext()
{
	return context;	
} 

//��÷���ʱ��
string Feedback::getTime()
{
	return time;
} 
