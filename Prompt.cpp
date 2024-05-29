#include "Prompt.h"
#include <string.h>

void Prompt::setContext(const string& ctext)  //设置内容 
{
	context = ctext;	
}

void Prompt::setTime(const string& tm)        //设置时间 
{
	time = tm;
} 

void Prompt::setScene(const string& se)       //设置场景 
{
	scene = se;
} 

void Prompt::setRole(const string& ro)        //设置角色 
{
	role = ro;	
} 

string Prompt::getContext()   //获取内容
{
	return context; 
} 

string Prompt::getTime()      //获取创建时间 
{
	return time;	
} 

string Prompt::getScene()     //获取场景 
{
	return scene;
}

string Prompt::getRole()      //获取角色 
{
	return role;
} 
