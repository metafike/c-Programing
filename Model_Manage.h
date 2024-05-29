#ifndef MODELMANAGE_H
#define MODELMANAGE_H

#include <string>
using namespace std;
#include "Manage.h"
#include "Model.h" 
//模型管理类
//将模型信息写入公开文件，可以查看
//登录用户可以添加模型信息，修改模型信息 ，不能删除 
class ModelManage : public Manage<Model>
{
	public:
		void search(const string&);                //查询功能 
		void display();                            //显示功能
		//登录的用户才可以使用以下功能
		void add(Model& model);                    //添加
		void change(const string&, const string&); //修改
		//不能进行删除操作
		void del(const string&);                   //基类抽象类，要定义 
};
#endif 
