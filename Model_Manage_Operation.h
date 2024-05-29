#ifndef MANAGEMODELSOPERATION_H
#define MANAGEMODELSOPERATION_H
#include "Operation.h"
#include "Model_Manage.h"
#include "Model.h" 

//ģ�͹�������� 
class ModelManageOperation : public Operation<Model> 
{
	private:
		ModelManage modelmanage;                              //Ƕ��ģ������󣬴���ģ����Ϣ�����ڲ�ʹ��ģ�͹�������󣬲�����ʵ�ַ������ 
	public:
		void SearchOperation(const string&);                  //��ѯ����
		void DisplayOperation();  //��ʾ����
		//��¼�û�����ʹ�����²���
		void AddOperation(Model& model);                      //��Ӳ���
		void ChangeOperation(const string&, const string&);   //�޸Ĳ��� 
		//����ʹ��ɾ������
		void DelOperation(const string&);                     //������࣬���� 
};
#endif 
