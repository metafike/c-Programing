#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <string>
using namespace std; 
//模型基类 
class Model
{
	private:
		string ModelName;        //名称 
		string Version;          //版本 
		string price;            //价格信息 
	public:
		void setModelName(const string&);     //设置名称 
		void setVersion(const string&);       //设置版本
		void setIsfree(const string&);        //设置价格信息 
		const string getModelName();          //获得名称 
		const string getVersion();            //获得版本
		const string getIsfree();             //获得价格信息 
};
#endif
