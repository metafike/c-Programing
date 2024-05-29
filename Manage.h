#ifndef MANAGE_H
#define MANAGE_H
#include <string>
//�������,������  ,ʹ��ģ�壬��ӹ����У���ͬ������������ӵĶ���ͬ��ʹ�ò�ͬ��ģ����Խ���ͬ�Ķ�����Ϊ���� 
template <class T>   
class Manage 
{
	public:  
		virtual void add(T&) = 0;                               //������� 
		virtual void del(const string&) = 0;                    //����ɾ�� (delete�ǹؼ���)
		virtual void change(const string&, const string&) = 0;  //�����޸� 
		virtual void search(const string&) = 0;                 //�����ѯ 
		virtual void display() = 0;                             //��ʾ���� 
};
#endif 
