#include "Model_Manage_Operation.h"

void ModelManageOperation::AddOperation(Model& model)            //��Ӳ��� 
{
	modelmanage.add(model); 
}

void ModelManageOperation::SearchOperation(const string& keyword) //��ѯ����
{
	modelmanage.search(keyword);	
} 

void ModelManageOperation::DisplayOperation()                     //��ʾ����
{
	modelmanage.display();
} 

void ModelManageOperation::ChangeOperation(const string& keyword, const string& newkeyword) //�޸Ĳ���
{
	modelmanage.change(keyword, newkeyword);
}

void ModelManageOperation::DelOperation(const string&) {}                                   //ɾ������ʹ��,����ɾ�������ļ� 
