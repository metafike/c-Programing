#include "Model.h"

void Model::setModelName(const string& monm)   //�������� 
{
	ModelName = monm; 
}

void Model::setVersion(const string& vs)      //���ð汾
{
	Version = vs;	
} 

void Model::setIsfree(const string& isf)      //���ü۸���Ϣ
{
	price = isf;	
} 

const string Model::getModelName()  //�������
{
	return ModelName;
} 

const string Model::getVersion()   //��ð汾
{
	return Version;	
} 

const string Model::getIsfree()    //��ü۸���Ϣ
{
	return price;	
} 
