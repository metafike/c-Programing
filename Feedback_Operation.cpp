#include "Feedback_Operation.h"
//��¼�û��� 
void FeedbackOperation::AddOperation(Feedback& feedback) //���
{
	feedbackmanage.add(feedback);	
} 

//δ��¼�û� 
void FeedbackOperation::DisplayOperation()  //��ʾ
{
	feedbackmanage.display(); 
} 

void  FeedbackOperation::SearchOperation(const string& keyword)  //��ѯ 
{
	feedbackmanage.search(keyword);
}

//������ʹ��,����ɾ�����޸Ĺ����������ļ� �����Բ��ܵ��������ַ��� 
void FeedbackOperation::ChangeOperation(const string &, const string&){}
void FeedbackOperation::DelOperation(const string&) {} 
