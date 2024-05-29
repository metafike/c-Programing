#ifndef MANAGE_H
#define MANAGE_H
#include <string>
//管理基类,抽象类  ,使用模板，添加功能中，不同的派生类中添加的对象不同，使用不同的模板可以将不同的对象作为参数 
template <class T>   
class Manage 
{
	public:  
		virtual void add(T&) = 0;                               //管理添加 
		virtual void del(const string&) = 0;                    //管理删除 (delete是关键词)
		virtual void change(const string&, const string&) = 0;  //管理修改 
		virtual void search(const string&) = 0;                 //管理查询 
		virtual void display() = 0;                             //显示功能 
};
#endif 
