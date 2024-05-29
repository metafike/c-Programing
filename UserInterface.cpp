#include "UserInterface.h"
#include <iostream>
using namespace std;
#include <iomanip> 
#include <string.h> 

const int width = 50;          //������ж��� 
void UserInterface::MainMenu() //���˵� 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("���˵�")) / 2) << "���˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout <<  "*1 -> ע�����" << endl
		 <<  "*2 -> ��¼����" << endl
		 <<  "*3 -> �ÿͽ���" << endl
		 <<  "*0 -> ��������" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; // ��ӵײ��ָ���
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
}

void UserInterface::BrowserMenu()  //ѡ��ÿͺ󣬻���ʾ����˵� �������ļ���ѯ����ʾ���ܶ�Ҫд 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�ÿͲ˵�")) / 2) << "�ÿͲ˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> ��ʾģ����Ϣ" << endl
		 << "*2 -> ��ѯģ����Ϣ" << endl
		 << "*3 -> ��ʾ�����ı���ʾ����Ϣ" << endl
		 << "*4 -> ��ѯ�����ı���ʾ����Ϣ" << endl
		 << "*5 -> ��ʾ������Ƶ��ʾ����Ϣ" << endl
		 << "*6 -> ��ѯ������Ƶ��ʾ����Ϣ" << endl
		 << "*7 -> ��ʾ�����ļ���Ϣ" << endl  
		 << "*8 -> ��ѯ�����ļ���Ϣ" << endl        //�����ļ����ݶ࣬������ʱЧ���ֱȽ�ǿ�����Բ�ѯ���Բ�ѯ����ʱ��ε� 
		 << "*9 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; // ��ӵײ��ָ���
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
}

void UserInterface::LoginMenu()  //ѡ���¼����ʾ����˵� 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�û��˵�")) / 2) << "�û��˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> �����ļ�����" << endl
		 << "*2 -> �����ļ�����" << endl
		 << "*3 -> �鿴������Ϣ" << endl
		 << "*4 -> �޸ĸ�����Ϣ" << endl
		 << "*5 -> ����ƽ̨" << endl
		 << "*6 -> ע���˺�" << endl
		 << "*7 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; // ��ӵײ��ָ���
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
}

void UserInterface::PersonalMenu()   //�����ļ������˵� 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�����ļ������˵�")) / 2) << "�����ļ������˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout <<  "*1 -> �����ı���ʾ���ļ�����" << endl
		 <<  "*2 -> ������Ƶ��ʾ���ļ�����" << endl
		 <<  "*3 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
}

void UserInterface::PublicMenu()  //�����ļ������˵� 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�����ļ������˵�")) / 2) << "�����ļ������˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> �����ı���ʾ���ļ�����" << endl
		 << "*2 -> ������Ƶ��ʾ���ļ�����" << endl
		 << "*3 -> ����ģ���ļ�����" << endl
		 << "*4 -> ���������ļ�����" << endl
		 << "*5 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 

void UserInterface::PublicTextMenu() //�����ı���ʾ�ʲ��� 
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�����ı���ʾ�ʲ����˵�")) / 2) << "�����ı���ʾ�ʲ����˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> ����ı���ʾ��" << endl
		 << "*2 -> ��ѯ�ı���ʾ��" << endl
		 << "*3 -> �޸��ı���ʾ��" << endl
		 << "*4 -> ��ʾ�ı���ʾ��" << endl
		 << "*5 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
}

void UserInterface::PublicVideoMenu() //������Ƶ��ʾ�ʲ���
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("������Ƶ��ʾ�ʲ����˵�")) / 2) << "������Ƶ��ʾ�ʲ����˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> �����Ƶ��ʾ��" << endl
		 << "*2 -> ��ѯ��Ƶ��ʾ��" << endl
		 << "*3 -> �޸���Ƶ��ʾ��" << endl
		 << "*4 -> ��ʾ��Ƶ��ʾ��" << endl
		 << "*5 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 

void UserInterface::PublicModelMenu() //ģ�Ͳ����˵�
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("ģ�Ͳ����˵�")) / 2) << "ģ�Ͳ����˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> ���ģ����Ϣ" << endl
		 << "*2 -> ��ѯģ����Ϣ" << endl
		 << "*3 -> �޸�ģ����Ϣ" << endl
		 << "*4 -> ��ʾģ����Ϣ" << endl
		 << "*5 -> ����" << endl;
	
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 

void UserInterface::PublicFeedbackMenu() //�������������˵�
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("���������˵�")) / 2) << "���������˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> ��ʾ������Ϣ" << endl
		 << "*2 -> ��ѯ������Ϣ" << endl
		 << "*3 -> ��ӷ�����Ϣ" << endl
		 << "*4 -> ����" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 

void UserInterface::PersonTextMenu() //�����ı���ʾ�ʲ���
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�����ı���ʾ�ʲ����˵�")) / 2) << "�����ı���ʾ�ʲ����˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> ����ı���ʾ��" << endl
		 << "*2 -> ��ѯ�ı���ʾ��" << endl
		 << "*3 -> ɾ���ı���ʾ��" << endl
		 << "*4 -> �޸��ı���ʾ��" << endl
		 << "*5 -> ��ʾ�ı���ʾ��" << endl
		 << "*6 -> ����" << endl;

	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 

void UserInterface::PersonVideoMenu() //������Ƶ��ʾ�ʲ���
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("������Ƶ��ʾ�ʲ����˵�")) / 2) << "������Ƶ��ʾ�ʲ����˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
	cout << "*1 -> �����Ƶ��ʾ��" << endl
		 << "*2 -> ��ѯ��Ƶ��ʾ��" << endl
		 << "*3 -> ɾ����Ƶ��ʾ��" << endl
		 << "*4 -> �޸���Ƶ��ʾ��" << endl
		 << "*5 -> ��ʾ��Ƶ��ʾ��" << endl
		 << "*6 -> ����" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 

void UserInterface::Changepersonal() //�޸ĸ�����Ϣ�˵�
{
	cout << setw(width) << setfill('-') << "" << endl;
    cout << setfill(' ') << setw((width + strlen("�޸ĸ�����Ϣ�˵�")) / 2) << "�޸ĸ�����Ϣ�˵�" << endl;
    cout << setw(width) << setfill('-') << "" << endl;
    
    cout << "*1 -> �޸��û���" << endl
		 << "*2 -> �޸�����" << endl
		 << "*3 -> �޸��Ա�" << endl
		 << "*4 -> �޸ĵ绰��" << endl
		 << "*5 -> �޸ĵ�������" << endl
		 << "*6 -> ����" << endl;
		 
	cout << setw(50) << setfill('-') << "" << endl; 
    cout << setfill(' ') << setw(40) << "��ѡ��: ";
} 
