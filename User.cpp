#include "User.h"
#include <string.h>

User::User() {} 

User::User(const char *nm)
{
	strcpy(name, nm);	
}
//����ѡ��û���ظ����������ɾ���������޸ģ�ʵ����ֱ�Ӵ��������  
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

//  get��ȡ���� 
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

//���������, ��Ҫ��Ϊ���޸��û���Ϣ��ֵ��Ȼ����������һ��Ҫ�޸ĵ�����
User& User::operator =(const User& right)
{
	strcpy(this->name, right.name); 
	strcpy(this->password, right.password); 
	strcpy(this->sex, right.sex);
	strcpy(this->telephone, right.telephone); 
	strcpy(this->gmail, right.gmail); 
	return *this;
}
//���л� 
void User::serialize(ofstream& out) const
{
	out.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
//�����л� 
void User::deserialize(ifstream& in)
{
	in.read(reinterpret_cast<char*>(this), sizeof(*this));
}
