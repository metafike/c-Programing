#include "Use_Manage_Operation.h"
//添加操作 
void UseManageOperation::AddOperation(User& user)
{
	usemanage.add(user);
}

//删除操作，注销用户
void UseManageOperation::DelOperation(const char* name)
{
	usemanage.del(name);
}

//查询操作
User UseManageOperation::SearchOperation(const char* name)
{
	return usemanage.search(name);
}

//修改操作（修改信息，密码）
void UseManageOperation::ChangeOperation(User& newuser, const char* name)
{
	usemanage.change(newuser, name);
}

//显示操作
void UseManageOperation::DisplayOperation() {}

//判断是否登录操作
bool UseManageOperation::IsLog(const char* nm, const char* pword)
{
	return usemanage.isLog(nm, pword);	
} 
