#ifndef MANAGEMODELSOPERATION_H
#define MANAGEMODELSOPERATION_H
#include "Operation.h"
#include "Model_Manage.h"
#include "Model.h" 

//模型管理操作类 
class ModelManageOperation : public Operation<Model> 
{
	private:
		ModelManage modelmanage;                              //嵌套模型类对象，传入模型信息后，在内部使用模型管理类对象，操作，实现方法封闭 
	public:
		void SearchOperation(const string&);                  //查询操作
		void DisplayOperation();  //显示操作
		//登录用户可以使用以下操作
		void AddOperation(Model& model);                      //添加操作
		void ChangeOperation(const string&, const string&);   //修改操作 
		//不能使用删除操作
		void DelOperation(const string&);                     //抽象基类，定义 
};
#endif 
