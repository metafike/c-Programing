#include "Text_Prompt_Manage_Operation.h"

//登录用户 
void TextPromptManageOperation::AddOperation(TextPrompt& textprompt) //添加操作 
{
	textpromptmanage.add(textprompt); 
}

//未登录用户 
void TextPromptManageOperation::SearchOperation(const string& keyword) //查询
{
	textpromptmanage.search(keyword); 
} 

void TextPromptManageOperation::DisplayOperation()                    //显示操作 
{
	textpromptmanage.display();
}

void TextPromptManageOperation::ChangeOperation(const string& keyword, const string& newkeyword)  //修改操作 
{
	textpromptmanage.change(keyword, newkeyword);
}

void  TextPromptManageOperation::DelOperation(const string&) {}                                  //删除操作，不能使用，不能删除公开文件
 
//个人文件操作
void TextPromptManageOperation::persontextadd(TextPrompt& textprompt)     //添加 
{
	textpromptmanage.persontextadd(textprompt); 
}                         
                
void TextPromptManageOperation::persontextsearch(const string& keyword)   //查询 
{
	textpromptmanage.persontextsearch(keyword);
}              

void TextPromptManageOperation::persontextdel(const string& keyword)       //删除 
{
	textpromptmanage.persontextdel(keyword);
}

void TextPromptManageOperation::persontextchange(const string& keyword, const string& newkeyword)  //修改 
{
	textpromptmanage.persontextchange(keyword, newkeyword);
}

void TextPromptManageOperation::persontextdisplay()                          //显示 
{
	textpromptmanage.persontextdisplay();
}
