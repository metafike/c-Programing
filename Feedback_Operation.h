#ifndef FEEDBACKOPERATION_H
#define FEEDBACKOPERATION_H
#include "Operation.h"
#include "Feedback_Manage.h"
#include "Feedback.h"

//���������� ,�û�������ֱ�ӽ������еķ�����װ���� 
class FeedbackOperation : public Operation<Feedback> 
{
	private:
		FeedbackManage feedbackmanage;                  //Ƕ�׷�������������ڲ������ڲ������÷�������չ����� 
	public:
		//��¼�û�ʹ�� 
		void AddOperation(Feedback& feedback);          //��Ӳ��� 
		//δ��¼�û�ʹ��
		void DisplayOperation();                        //��ʾ����
		void SearchOperation(const string&);            //��ѯ��������Ҫ��ѯ����ʱ�䣬����ʱЧ��ǿ�� 
		//ɾ�����޸ľ�����ʹ��
		void ChangeOperation(const string&, const string&);
		void DelOperation(const string&);      
};
#endif 
