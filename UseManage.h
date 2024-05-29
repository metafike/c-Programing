#ifndef USEMANAGE_H
#define USEMANAGE_H
#include "Manage.h" 
#include "User.h" 
#include <vector> 

//�û�������,û�м̳й����� 
//���ܣ�����û���ɾ���û�����֤�û��Ƿ��¼���û�ע�ᣬ�������ļ���� 
class UseManage
{
	private:
		vector<User> users;    //��������̬���飬  ��ͬһ�������������ں��ʵ�ʱ����ʱ����� 
	public: 
		void add(User& us);                          //����û� 
		void del(const char* name);                  //ɾ���û� 
		User search(const char* name);               //��ѯ�û� 
		void change(User& newuser, const char* name);               //�޸���Ϣ��������"�޸�����",���û���ԭ�ȵ��û���ֵ��Ȼ����set�ӿڸ����� �� 
		//���л� ,���л�ʹ��string���з��գ��Ƚ��鷳���������ַ�����ʵ�� 
		void serialize(ofstream& out) const;
		//�����л� 
		void deserialize(ifstream& in); 
		bool isLog(const char* nm, const char* pword);              //��֤�û��Ƿ��¼�����û����е���������� 	
		//������; 
		void display(); 
};
#endif
