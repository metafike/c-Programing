#ifndef TEXTPROMPTMANAGE_H
#define TEXTPROMPTMANAGE_H

#include <string>
using namespace std;
#include "Manage.h"
#include "Text_Prompt.h"

//提示词管理 
// 对公开文件的相关操作，  
class TextPromptManage : public Manage<TextPrompt>
{
	public:	
		//未登录的用户只能使用查询功能，显示功能 
		void search(const string&);                   //查询功能 
		void display();                               //显示功能 
		
		//登录的用户才可以使用以下功能 
		void add(TextPrompt&);                        //添加功能
        void change(const string&, const string&);    //修改功能
        //不管是否登录都不能删除公开文件 
        void del(const string&);                      //基类中的抽象类，要定义 
        
        //对应的是个人文本提示词文件的操作 
		void persontextadd(TextPrompt&);                            //添加 
		void persontextsearch(const string&);                       //查询 
		void persontextdel(const string& );                         //删除 
		void persontextchange(const string& , const string& );      //修改 
		void persontextdisplay();                                   //显示 
};
#endif
