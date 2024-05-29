#include "Video_Prompt_Manage_Operation.h"

//登录用户 
void VideoPromptManageOperation::AddOperation(VideoPrompt& vidoeprompt)                 //添加操作 
{
	videopromptmanage.add(vidoeprompt); 
}

//未登录用户 
void VideoPromptManageOperation::SearchOperation(const string& keyword)                 //查询
{
	videopromptmanage.search(keyword); 
} 

void VideoPromptManageOperation::DisplayOperation()                                     //显示操作 
{
	videopromptmanage.display();
}

void VideoPromptManageOperation::ChangeOperation(const string& keyword, const string& newkeyword)  //修改操作 
{
	videopromptmanage.change(keyword, newkeyword);
}

void  VideoPromptManageOperation::DelOperation(const string&) {}//删除操作，不能使用，不能删除公开文件

// 个人文件操作 
void VideoPromptManageOperation::personVideoAdd(VideoPrompt& videoprompt)    //添加 
{
	videopromptmanage.personVideoAdd(videoprompt);
}

void VideoPromptManageOperation::personVideoSearch(const string& keyword)     //查询 
{
	videopromptmanage.personVideoSearch(keyword);
}

void VideoPromptManageOperation::personVideoDel(const string& keyword)        //删除 
{
	videopromptmanage.personVideoDel(keyword);
}

void VideoPromptManageOperation::personVideoChange(const string& keyword, const string& newkeyword)  //修改 
{
	videopromptmanage.personVideoChange(keyword, newkeyword);
}

void VideoPromptManageOperation::personVideoDisplay()                                                //显示 
{
	videopromptmanage.personVideoDisplay();
} 
