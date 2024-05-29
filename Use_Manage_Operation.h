#ifndef USEMANAGEOPERATION_H
#define USEMANAGEOPERATION_H

#include "Operation.h"
#include "User.h"
#include "UseManage.h"
//用户管理操作类,没有继承管理类，参数类型不同太多 
class UseManageOperation 
{
	private:
		UseManage usemanage;                                   //嵌套对象 ，封闭方法 
	public:
		void AddOperation(User& user);                         //添加
		void DelOperation(const char* name);                   //删除
		User SearchOperation(const char* name);                //查询
		void ChangeOperation(User& newuser, const char* name); //修改
		void DisplayOperation();                               //显示 
		bool IsLog(const char* nm, const char* pword);         //判断登录 
};
#endif 
