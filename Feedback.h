#ifndef STORAGE_H
#define STORAGE_H
#include <string>
using namespace std;
//�û�������  
class Feedback 
{
	private:
		string context;    //��������
		string time;       //�������� 
	public: 
		void setContext(const string& ctext);       //���÷�������
		void setTime(const string& tm);             //���÷������� 
		string getContext();                        //��÷�������
		string getTime();                           //��÷������� 
}; 
#endif
