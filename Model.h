#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <string>
using namespace std; 
//ģ�ͻ��� 
class Model
{
	private:
		string ModelName;        //���� 
		string Version;          //�汾 
		string price;            //�۸���Ϣ 
	public:
		void setModelName(const string&);     //�������� 
		void setVersion(const string&);       //���ð汾
		void setIsfree(const string&);        //���ü۸���Ϣ 
		const string getModelName();          //������� 
		const string getVersion();            //��ð汾
		const string getIsfree();             //��ü۸���Ϣ 
};
#endif
