#include "Feedback_Operation.h"
//登录用户： 
void FeedbackOperation::AddOperation(Feedback& feedback) //添加
{
	feedbackmanage.add(feedback);	
} 

//未登录用户 
void FeedbackOperation::DisplayOperation()  //显示
{
	feedbackmanage.display(); 
} 

void  FeedbackOperation::SearchOperation(const string& keyword)  //查询 
{
	feedbackmanage.search(keyword);
}

//均不能使用,不能删除，修改公开反馈类文件 ，所以不能调用这两种方法 
void FeedbackOperation::ChangeOperation(const string &, const string&){}
void FeedbackOperation::DelOperation(const string&) {} 
