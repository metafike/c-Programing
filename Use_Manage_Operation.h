#ifndef USEMANAGEOPERATION_H
#define USEMANAGEOPERATION_H

#include "Operation.h"
#include "User.h"
#include "UseManage.h"
//�û����������,û�м̳й����࣬�������Ͳ�̫ͬ�� 
class UseManageOperation 
{
	private:
		UseManage usemanage;                                   //Ƕ�׶��� ����շ��� 
	public:
		void AddOperation(User& user);                         //���
		void DelOperation(const char* name);                   //ɾ��
		User SearchOperation(const char* name);                //��ѯ
		void ChangeOperation(User& newuser, const char* name); //�޸�
		void DisplayOperation();                               //��ʾ 
		bool IsLog(const char* nm, const char* pword);         //�жϵ�¼ 
};
#endif 
