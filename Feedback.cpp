#include "Feedback.h"

//设置反馈内容 
void Feedback::setContext(const string& ctext)
{
	context = ctext;
}

//设置反馈时间 
void Feedback::setTime(const string& tm)
{
	time = tm;
}

//获得反馈内容
string Feedback::getContext()
{
	return context;	
} 

//获得反馈时间
string Feedback::getTime()
{
	return time;
} 
