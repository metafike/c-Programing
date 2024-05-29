#ifndef TEXTPROMPTMANAGEOPERATION_H
#define TEXTPROMPTMANAGEOPERATION_H

#include "Operation.h"
#include "Text_Prompt.h"
#include "Text_Prompt_Manage.h"

//文本提示词操作类
class TextPromptManageOperation : public Operation<TextPrompt>
{
	private:
		TextPromptManage textpromptmanage;                  //嵌套提示词管理类对象，封闭管理方法 
	public:
		void SearchOperation(const string&);                //查询操作
		void DisplayOperation();                            //显示操作
		//登录用户可以使用以下操作
		void AddOperation(TextPrompt& textprompt);          //添加操作
		void ChangeOperation(const string&, const string&); //修改操作 
		//不能使用删除操作
		void DelOperation(const string&);                   //抽象基类，定义
		//个人文件操作
		void persontextadd(TextPrompt&);                            //添加 
		void persontextsearch(const string&);                       //查询 
		void persontextdel(const string& );                         //删除 
		void persontextchange(const string& , const string& );      //修改 
		void persontextdisplay();                                   //显示 
};
#endif 
