#ifndef USER_H
#define USER_H
#include <fstream> 
using namespace std;

//�û���
class User 
{
	private:
		char name[20];         //����  ,,���潫����ĳ�ָ���Ա 
		char password[20];     //����  
		char sex[5];           //�Ա� 
		char telephone[12];    //�绰����
		char gmail[15];        //���䣨�û��󶨣���֤������֤����û��ʵ��
	public:
		//���캯������ 
		User();                                  //Ĭ�Ϲ��캯��
		User(const char *nm);                    //ֻ���������Ĺ��캯�����������ѯ��ɾ������һ��ѡ�� 
		void setName(char *nm);                  //��������
		void setPword(char *pword);              //�������� 
		void setSex(char *sx);                   //�����Ա�
		void setTphone(char *tphone);            //���õ绰�� 
		void setGmail(char *gm);                 //��������
		//�����ȡ������Ҫ���ڶ�Ӧ�����У�˽�г�Աд���ļ��У����ҿ���ֱ�Ӵ洢����������в�����ɾ�����޸ģ������л��������л� 
		const char* getName();                      //��ȡ����
		const char* getPword();                     //��ȡ����
		const char* getSex();                       //��ȡ�Ա�
		const char* getTphone();                    //��ȡ�绰��
		const char* getGamil();                     //��ȡ����
		void serialize(ofstream& out) const;
		//�����л� 
		void deserialize(ifstream& in); 
	    User& operator = (const User& right);       //����ֵ������=����� , ��Ҫ���޸��û���Ϣʱ�����õ����޸����룩�����¶���ֵ����setpassword()���������룬
}; 
#endif
