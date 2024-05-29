#ifndef MODELMANAGE_H
#define MODELMANAGE_H

#include <string>
using namespace std;
#include "Manage.h"
#include "Model.h" 
//ģ�͹�����
//��ģ����Ϣд�빫���ļ������Բ鿴
//��¼�û��������ģ����Ϣ���޸�ģ����Ϣ ������ɾ�� 
class ModelManage : public Manage<Model>
{
	public:
		void search(const string&);                //��ѯ���� 
		void display();                            //��ʾ����
		//��¼���û��ſ���ʹ�����¹���
		void add(Model& model);                    //���
		void change(const string&, const string&); //�޸�
		//���ܽ���ɾ������
		void del(const string&);                   //��������࣬Ҫ���� 
};
#endif 
