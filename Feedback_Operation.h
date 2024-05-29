#ifndef FEEDBACKOPERATION_H
#define FEEDBACKOPERATION_H
#include "Operation.h"
#include "Feedback_Manage.h"
#include "Feedback.h"

//反馈操作类 ,用户交互，直接将管理中的方法封装起来 
class FeedbackOperation : public Operation<Feedback> 
{
	private:
		FeedbackManage feedbackmanage;                  //嵌套反馈管理类对象，在操作类内部，调用方法，封闭管理类 
	public:
		//登录用户使用 
		void AddOperation(Feedback& feedback);          //添加操作 
		//未登录用户使用
		void DisplayOperation();                        //显示功能
		void SearchOperation(const string&);            //查询操作（主要查询反馈时间，反馈时效性强） 
		//删除，修改均不能使用
		void ChangeOperation(const string&, const string&);
		void DelOperation(const string&);      
};
#endif 
