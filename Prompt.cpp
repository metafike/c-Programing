#include "Prompt.h"
#include <string.h>

void Prompt::setContext(const string& ctext)  //�������� 
{
	context = ctext;	
}

void Prompt::setTime(const string& tm)        //����ʱ�� 
{
	time = tm;
} 

void Prompt::setScene(const string& se)       //���ó��� 
{
	scene = se;
} 

void Prompt::setRole(const string& ro)        //���ý�ɫ 
{
	role = ro;	
} 

string Prompt::getContext()   //��ȡ����
{
	return context; 
} 

string Prompt::getTime()      //��ȡ����ʱ�� 
{
	return time;	
} 

string Prompt::getScene()     //��ȡ���� 
{
	return scene;
}

string Prompt::getRole()      //��ȡ��ɫ 
{
	return role;
} 
