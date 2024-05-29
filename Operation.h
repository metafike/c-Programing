#ifndef OPERATION
#define OPERATION

#include <string>
using namespace std;
//�������� 
template <class T>
class Operation 
{
	public:
		virtual void SearchOperation(const string&) = 0;                  //��ѯ����
		virtual void DisplayOperation() = 0;                              //��ʾ����
		virtual void AddOperation(T&) = 0;                                //��Ӳ���
		virtual void ChangeOperation(const string&, const string&) = 0;   //�޸Ĳ��� 	
		virtual void DelOperation(const string&) = 0;                     //ɾ������ 
}; 
#endif
