#ifndef VIDEOPROMPTMANAGE_H
#define VIDEOPROMPTMANAGE_H

#include <string>
using namespace std;
#include "Manage.h"
#include "Video_Prompt.h" 

//提示词管理 
// 对公开，个人文件的相关操作，  
class VideoPromptManage : public Manage<VideoPrompt>
{
	public:
		//未登录的用户只能使用查询功能，显示功能 
		void search(const string&);                   //查询功能 
		void display();                               //显示功能 
		//登录的用户才可以使用以下功能 
		void add(VideoPrompt&);                       //添加功能
        void change(const string&, const string&);    //修改功能
        void del(const string&);                      //基类中的抽象类，用户登录不能删除公开文件，
        //对个人文件操作 
        void personVideoAdd(VideoPrompt&);                                //添加	
		void personVideoSearch(const string&);                            //查询
		void personVideoDel(const string&);                               //删除 
		void personVideoChange(const string& , const string& );           //修改
		void personVideoDisplay();                                        //显示 
};
#endif
