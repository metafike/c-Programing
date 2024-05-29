#ifndef VIDEOPROMPTMANAGEOPERATION_H
#define VIDEOPROMPTMANAGEOPERATION_H

#include "Operation.h"
#include "Video_Prompt.h"
#include "Video_Prompt_Manage.h"

//文本提示词操作类
class VideoPromptManageOperation : public Operation<VideoPrompt>
{
	private:
		VideoPromptManage videopromptmanage;   //嵌套提示词管理类对象，封闭管理方法 
	public:
		void SearchOperation(const string&);                  //查询操作
		void DisplayOperation();                              //显示操作
		//登录用户可以使用以下操作
		void AddOperation(VideoPrompt& videoprompt);          //添加操作
		void ChangeOperation(const string&, const string&);   //修改操作 
		//不能使用删除操作
		void DelOperation(const string&);                     //抽象基类，定义
		//对个人文件操作 
        void personVideoAdd(VideoPrompt&);                                //添加	
		void personVideoSearch(const string&);                            //查询
		void personVideoDel(const string&);                               //删除 
		void personVideoChange(const string& , const string& );           //修改
		void personVideoDisplay();                                        //显示 
};
#endif 
