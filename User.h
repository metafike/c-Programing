#ifndef USER_H
#define USER_H
#include <fstream> 
using namespace std;

//用户类
class User 
{
	private:
		char name[20];         //姓名  ,,后面将这个改成指针成员 
		char password[20];     //密码  
		char sex[5];           //性别 
		char telephone[12];    //电话号码
		char gmail[15];        //邮箱（用户绑定，验证），验证功能没有实现
	public:
		//构造函数重载 
		User();                                  //默认构造函数
		User(const char *nm);                    //只传入姓名的构造函数，（方便查询，删除，多一种选择） 
		void setName(char *nm);                  //设置姓名
		void setPword(char *pword);              //设置密码 
		void setSex(char *sx);                   //设置性别
		void setTphone(char *tphone);            //设置电话号 
		void setGmail(char *gm);                 //设置邮箱
		//下面获取函数主要是在对应管理中，私有成员写入文件中，并且可以直接存储在容器里进行操作（删除，修改），序列化，反序列化 
		const char* getName();                      //获取姓名
		const char* getPword();                     //获取密码
		const char* getSex();                       //获取性别
		const char* getTphone();                    //获取电话号
		const char* getGamil();                     //获取邮箱
		void serialize(ofstream& out) const;
		//反序列化 
		void deserialize(ifstream& in); 
	    User& operator = (const User& right);       //对象赋值，重载=运算符 , 主要在修改用户信息时可以用到（修改密码），给新对象赋值，用setpassword()设置新密码，
}; 
#endif
