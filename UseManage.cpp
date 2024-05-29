#include <iostream>
using namespace std;
#include "UseManage.h"
#include <stdlib.h>
#include <string.h>
#include <iomanip>

//���л� 
void UseManage::serialize(ofstream& out) const
{
	out.write(reinterpret_cast<const char*>(this), sizeof(*this));
}
//�����л� 
void UseManage::deserialize(ifstream& in)
{
	in.read(reinterpret_cast<char*>(this), sizeof(*this));
}

//��ӹ��ܣ����û���Ϣд��������ļ�
void UseManage::add(User& us)       
{
	ofstream out1;             //д���ļ� ����ȡ׷�� 
	out1.open("userInformation.dat", ios::binary | ios::app);       
	if(out1.fail()) 
	{
		cout << "�ļ���ʧ��\n";
		return;	
	}
	//��User����us���л����ļ��� 
	us.serialize(out1);
	out1.close();
    cout << setfill(' ') << setw(40) << "\nע��ɹ���" << endl << endl;
} 

//ɾ�����ܣ���ȡ���ڴ��У�Ȼ��ɾ���������д���ļ� 
void UseManage::del(const char* name)
{
	ifstream in1;
	in1.open("userInformation.dat", ios::binary);
	if (!in1)
	{
		cout << "�ļ���ʧ��\n";
		return;	
	} 
	while (in1)
	{
		User u;                
		u.deserialize(in1);    //���ļ��еĶ����������л�������ڴ���
		
		if(!in1)           
		{
			break;
		}		
		users.push_back(u);   //��ӵ���̬������ 
	}
	in1.close(); 
	
	//ɾ����Ϣ������erase����
	bool flag = 0;                               //�ж��Ƿ�ɾ���û���Ϣ 
	for (int i = 0; i < users.size(); i++) 
	{
		if (strcmp(users[i].getName(), name) == 0) 
		{
			users.erase(users.begin() + i);      //erase����������Ϣ��������ɾ��
			i--;
			flag = 1;	
		}	
	} 
	if (flag) 
	{
		cout << setfill(' ') << setw(40) << "\nע���ɹ���" << endl << endl;
	}
	else 
	{
    	cout << setfill(' ') << setw(40) << "\nû���ҵ����û���" << endl << endl;
	}
	
	//��ɾ�������Ϣд���ļ���
	ofstream out;
	out.open("userInformation.dat", ios::binary | ios::trunc); 
	if (!out)
	{
		cout << "�ļ���ʧ��\n";
		return;	
	} 
	for (int i = 0; i < users.size(); i++) 
	{
		users[i].serialize(out); 
	}
	out.close();
	users.clear();             //������� 
} 

//��ѯ�û���Ϣ : 1.�������Ϣ��2.�ж�ע���˻�ʱ�û����Ƿ��Ѿ�ע�� 
User UseManage::search(const char* name)
{
	ifstream in;
	bool flag = false;
	User u;
	in.open("userInformation.dat", ios::binary);
	if (!in)
	{
		cout << "�ļ���ʧ��\n";
		return User(); //���ؿ��û� 
	}
	while (in) 
	{
		u.deserialize(in);
		if (!in)
		{
			break;
		}
		if (strcmp(u.getName(), name) == 0)
		{
			//�����Ӧ���û���Ϣ�����������
			flag = true;
			in.close();
			return u;
		}
	}
	in.close();
	return User();  //���ؿ��û� 
} 

//�޸��û���Ϣ������洢����̬�����У��ı���ڴ��ȥ 
void UseManage::change(User& newuser, const char* name)
{
	ifstream in1;
	in1.open("userInformation.dat", ios::binary);
	if (!in1)
	{
		cout << "�ļ���ʧ��\n";
		return;	
	} 
	while (in1)
	{
		User u;                
		u.deserialize(in1);    //���ļ��еĶ����������л�������ڴ���
		
		if(!in1)               
		{
			break;
		}		
		users.push_back(u);   //��ӵ���̬������ 
	}
	in1.close(); 
	
	bool flag = 0;
	for (int i = 0; i < users.size(); i++) 
	{
		if (strcmp(users[i].getName(), name) == 0) 
		{
			//�޸���Ϣ 
			users[i] = newuser; 
			flag = 1;	
		}	
	} 
	
	if (flag) 
	{
		cout << setfill(' ') << setw(40) << "\n��Ϣ�޸ĳɹ���" << endl << endl;
	}
	else 
	{
		cout << "û���ҵ����û�\n"; 
	}
	//���½��޸ĺ������д���ļ� 
	ofstream out;
	out.open("userInformation.dat", ios::binary | ios::trunc); //д�룬��׷��
	if (!out)
	{
		cout << "�ļ���ʧ��\n";
		return;	
	} 
	for (int i = 0; i < users.size(); i++) 
	{
		users[i].serialize(out); 
	}
	out.close();
	users.clear();             //������� 
} 

//��֤�û��Ƿ��¼�ɹ�, �����е��ļ����Ҷ�Ӧ����Ϣ 
bool UseManage::isLog(const char* nm, const char* pword)
{
	ifstream in;
	bool flag = false;
	in.open("userInformation.dat", ios::binary);
	if (!in)
	{
		cout << "�ļ���ʧ��\n";
		return false;      
	}
	while (in) 
	{
		User u;
		u.deserialize(in);     //�����ж�ȡ���ڴ��� 
		if (!in)
		{
			break;
		}
		if (strcmp(u.getName(), nm) == 0 && strcmp(u.getPword(), pword) == 0)
		{
			flag = true;
		}
	}
	in.close();
	return flag;
} 

//��ʾ���ܸ���ʹ��
void UseManage::display()
{
	ifstream in;
	in.open("userInformation.dat", ios::binary);
	if (!in)
	{
		cout << "�ļ���ʧ��\n";
		return;
	}
	while (in) 
	{
		User u;
		u.deserialize(in);
		if (!in)
		{
			break;
		}
		cout << u.getName() << " " 
			 << u.getPword() << " "
			 << u.getSex() << " " 
			 << u.getTphone() << " " 
			 << u.getGamil() << endl;
	}
	in.close();
 } 
