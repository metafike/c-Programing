#include "User.h"
#include <string.h>

User::User() {} 

User::User(const char *nm)
{
	strcpy(name, nm);	
}
//两种选择，没有重复，上面如果删除，或者修改，实例化直接传入参数，  
void User::setName(char *nm)
{
	strcpy(name, nm);	
} 

void User::setPword(char *pword)
{
	strcpy(password, pword);	
} 

void User::setSex(char *sx)
{
	strcpy(sex, sx);
}

void User::setTphone(char *tphone)
{
	strcpy(telephone, tphone);
}

void User::setGmail(char *gm)
{
	strcpy(gmail, gm);
}

//  get获取函数 
const char* User::getName()
{
	return name;	
} 

const char* User::getPword()
{
	return password;
}

const char* User::getSex()
{
	return sex;
}

const char* User::getTphone()
{
	return telephone;
}

const char* User::getGamil()
{
	return gmail;
}

//运算符重载, 主要是为了修改用户信息赋值，然后重新设置一个要修改的属性
User& User::operator =(const User& right)
{
	strcpy(this->name, right.name); 
	strcpy(this->password, right.password); 
	strcpy(this->sex, right.sex);
	strcpy(this->telephone, right.telephone); 
	strcpy(this->gmail, right.gmail); 
	return *this;
}
//序列化 
void User::serialize(ofstream& out) const
{
	out.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
//反序列化 
void User::deserialize(ifstream& in)
{
	in.read(reinterpret_cast<char*>(this), sizeof(*this));
}
