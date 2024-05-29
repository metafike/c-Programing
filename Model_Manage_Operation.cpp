#include "Model_Manage_Operation.h"

void ModelManageOperation::AddOperation(Model& model)            //添加操作 
{
	modelmanage.add(model); 
}

void ModelManageOperation::SearchOperation(const string& keyword) //查询操作
{
	modelmanage.search(keyword);	
} 

void ModelManageOperation::DisplayOperation()                     //显示操作
{
	modelmanage.display();
} 

void ModelManageOperation::ChangeOperation(const string& keyword, const string& newkeyword) //修改操作
{
	modelmanage.change(keyword, newkeyword);
}

void ModelManageOperation::DelOperation(const string&) {}                                   //删除不能使用,不能删除公开文件 
