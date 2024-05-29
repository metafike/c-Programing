#include "UserInterface.h"
#include <iostream>
using namespace std;
#include <iomanip> 
#include <string.h> 

const int width = 50;          //下面居中对齐 
void UserInterface::MainMenu() //主菜单 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("主菜单")) / 2) << "主菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout <<  "*1 -> 注册界面" << endl
		 <<  "*2 -> 登录界面" << endl
		 <<  "*3 -> 访客界面" << endl
		 <<  "*0 -> 结束程序" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; // 添加底部分隔线
    cout << setfill(' ') << setw(40) << "请选择: ";
}

void UserInterface::BrowserMenu()  //选择访客后，会显示这个菜单 ，公开文件查询和显示功能都要写 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("访客菜单")) / 2) << "访客菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 显示模型信息" << endl
		 << "*2 -> 查询模型信息" << endl
		 << "*3 -> 显示公开文本提示词信息" << endl
		 << "*4 -> 查询公开文本提示词信息" << endl
		 << "*5 -> 显示公开视频提示词信息" << endl
		 << "*6 -> 查询公开视频提示词信息" << endl
		 << "*7 -> 显示反馈文件信息" << endl  
		 << "*8 -> 查询反馈文件信息" << endl        //假设文件内容多，反馈的时效性又比较强，所以查询可以查询具体时间段的 
		 << "*9 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; // 添加底部分隔线
    cout << setfill(' ') << setw(40) << "请选择: ";
}

void UserInterface::LoginMenu()  //选择登录，显示这个菜单 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("用户菜单")) / 2) << "用户菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 公开文件操作" << endl
		 << "*2 -> 个人文件操作" << endl
		 << "*3 -> 查看个人信息" << endl
		 << "*4 -> 修改个人信息" << endl
		 << "*5 -> 分享平台" << endl
		 << "*6 -> 注销账号" << endl
		 << "*7 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; // 添加底部分隔线
    cout << setfill(' ') << setw(40) << "请选择: ";
}

void UserInterface::PersonalMenu()   //个人文件操作菜单 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("个人文件操作菜单")) / 2) << "个人文件操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout <<  "*1 -> 个人文本提示词文件操作" << endl
		 <<  "*2 -> 个人视频提示词文件操作" << endl
		 <<  "*3 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
}

void UserInterface::PublicMenu()  //公开文件操作菜单 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("公开文件操作菜单")) / 2) << "公开文件操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 公开文本提示词文件操作" << endl
		 << "*2 -> 公开视频提示词文件操作" << endl
		 << "*3 -> 公开模型文件操作" << endl
		 << "*4 -> 公开反馈文件操作" << endl
		 << "*5 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
} 

void UserInterface::PublicTextMenu() //公开文本提示词操作 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("公开文本提示词操作菜单")) / 2) << "公开文本提示词操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 添加文本提示词" << endl
		 << "*2 -> 查询文本提示词" << endl
		 << "*3 -> 修改文本提示词" << endl
		 << "*4 -> 显示文本提示词" << endl
		 << "*5 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
}

void UserInterface::PublicVideoMenu() //公开视频提示词操作
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("公开视频提示词操作菜单")) / 2) << "公开视频提示词操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 添加视频提示词" << endl
		 << "*2 -> 查询视频提示词" << endl
		 << "*3 -> 修改视频提示词" << endl
		 << "*4 -> 显示视频提示词" << endl
		 << "*5 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw(40) << "请选择: ";
} 

void UserInterface::PublicModelMenu() //模型操作菜单
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("模型操作菜单")) / 2) << "模型操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 添加模型信息" << endl
		 << "*2 -> 查询模型信息" << endl
		 << "*3 -> 修改模型信息" << endl
		 << "*4 -> 显示模型信息" << endl
		 << "*5 -> 返回" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
} 

void UserInterface::PublicFeedbackMenu() //公开反馈操作菜单
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("反馈操作菜单")) / 2) << "反馈操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 显示反馈信息" << endl
		 << "*2 -> 查询反馈信息" << endl
		 << "*3 -> 添加反馈信息" << endl
		 << "*4 -> 返回" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
} 

void UserInterface::PersonTextMenu() //个人文本提示词操作
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("个人文本提示词操作菜单")) / 2) << "个人文本提示词操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 添加文本提示词" << endl
		 << "*2 -> 查询文本提示词" << endl
		 << "*3 -> 删除文本提示词" << endl
		 << "*4 -> 修改文本提示词" << endl
		 << "*5 -> 显示文本提示词" << endl
		 << "*6 -> 返回" << endl;

	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
} 

void UserInterface::PersonVideoMenu() //个人视频提示词操作
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("个人视频提示词操作菜单")) / 2) << "个人视频提示词操作菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> 添加视频提示词" << endl
		 << "*2 -> 查询视频提示词" << endl
		 << "*3 -> 删除视频提示词" << endl
		 << "*4 -> 修改视频提示词" << endl
		 << "*5 -> 显示视频提示词" << endl
		 << "*6 -> 返回" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
} 

void UserInterface::Changepersonal() //修改个人信息菜单
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("修改个人信息菜单")) / 2) << "修改个人信息菜单" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
    cout << "*1 -> 修改用户名" << endl
		 << "*2 -> 修改密码" << endl
		 << "*3 -> 修改性别" << endl
		 << "*4 -> 修改电话号" << endl
		 << "*5 -> 修改电子邮箱" << endl
		 << "*6 -> 返回" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "请选择: ";
} 
