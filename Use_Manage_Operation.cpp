#include "Use_Manage_Operation.h"
//��Ӳ��� 
void UseManageOperation::AddOperation(User& user)
{
	usemanage.add(user);
}

//ɾ��������ע���û�
void UseManageOperation::DelOperation(const char* name)
{
	usemanage.del(name);
}

//��ѯ����
User UseManageOperation::SearchOperation(const char* name)
{
	return usemanage.search(name);
}

//�޸Ĳ������޸���Ϣ�����룩
void UseManageOperation::ChangeOperation(User& newuser, const char* name)
{
	usemanage.change(newuser, name);
}

//��ʾ����
void UseManageOperation::DisplayOperation() {}

//�ж��Ƿ��¼����
bool UseManageOperation::IsLog(const char* nm, const char* pword)
{
	return usemanage.isLog(nm, pword);	
} 
