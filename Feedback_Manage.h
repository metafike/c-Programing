#ifndef FEEDBACKMANAGE_H
#define FEEDBACKMANAGE_H
#include <string>
using namespace std;
#include "Manage.h"
#include "Feedback.h" 

//反馈管理类，文件公开 
class FeedbackManage : public Manage<Feedback> 
{
	public:
		//登录用户可以使用 
		void add(Feedback& feedback);          //添加功能
		//未登录用户可以使用 
		void display();                        //显示功能
		void search(const string&);            //查询功能（这个类中；主要查询反馈时间，因为反馈内容时效性较强） 
		//删除和修改功能都不能使用 
		void change(const string&, const string&);
		void del(const string&); 
};
#endif
