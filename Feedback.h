#ifndef STORAGE_H
#define STORAGE_H
#include <string>
using namespace std;
//用户反馈类  
class Feedback 
{
	private:
		string context;    //反馈内容
		string time;       //反馈日期 
	public: 
		void setContext(const string& ctext);       //设置反馈内容
		void setTime(const string& tm);             //设置反馈日期 
		string getContext();                        //获得反馈内容
		string getTime();                           //获得反馈日期 
}; 
#endif
