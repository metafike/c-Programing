#ifndef USEMANAGE_H
#define USEMANAGE_H
#include "Manage.h" 
#include "User.h" 
#include <vector> 

//用户管理类,没有继承管理类 
//功能：添加用户，删除用户，验证用户是否登录，用户注册，二进制文件完成 
class UseManage
{
	private:
		vector<User> users;    //容器，动态数组，  对同一个容器操作，在合适的时机的时候清空 
	public: 
		void add(User& us);                          //添加用户 
		void del(const char* name);                  //删除用户 
		User search(const char* name);               //查询用户 
		void change(User& newuser, const char* name);               //修改信息，（可以"修改密码",新用户用原先的用户赋值，然后用set接口改密码 ） 
		//序列化 ,序列化使用string类有风险，比较麻烦，所以用字符数组实现 
		void serialize(ofstream& out) const;
		//反序列化 
		void deserialize(ifstream& in); 
		bool isLog(const char* nm, const char* pword);              //验证用户是否登录，在用户类中调用这个函数 	
		//个人用途 
		void display(); 
};
#endif
