#ifndef OPERATION
#define OPERATION

#include <string>
using namespace std;
//操作基类 
template <class T>
class Operation 
{
	public:
		virtual void SearchOperation(const string&) = 0;                  //查询操作
		virtual void DisplayOperation() = 0;                              //显示操作
		virtual void AddOperation(T&) = 0;                                //添加操作
		virtual void ChangeOperation(const string&, const string&) = 0;   //修改操作 	
		virtual void DelOperation(const string&) = 0;                     //删除操作 
}; 
#endif
