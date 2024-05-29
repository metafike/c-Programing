#ifndef USERINTERFACE_H
#define USERINTERFACE_H

//用户界面类，主要是几个菜单 
class UserInterface 
{
	public:
		void MainMenu();     //主菜单 
		void BrowserMenu();  //访客菜单 
		void LoginMenu();    //登录菜单 
		void PersonalMenu(); //登录后的个人文件操作菜单 
		void PublicMenu();   //公开文件操作菜单
		void PersonTextMenu();     //个人文本文件操作菜单
		void PersonVideoMenu();    //个人视频提示词操作菜单 
		void PublicVideoMenu();    //公开视频提示词操作菜单
		void PublicTextMenu();     //公开文本提示词操作菜单
		void PublicModelMenu();    //公开模型操作菜单
		void PublicFeedbackMenu(); //公开反馈文件操作菜单 
		void Changepersonal();     //修改个人信息菜单 
};
#endif
