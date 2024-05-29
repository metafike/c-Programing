#include "Model.h"

void Model::setModelName(const string& monm)   //设置名称 
{
	ModelName = monm; 
}

void Model::setVersion(const string& vs)      //设置版本
{
	Version = vs;	
} 

void Model::setIsfree(const string& isf)      //设置价格信息
{
	price = isf;	
} 

const string Model::getModelName()  //获得名称
{
	return ModelName;
} 

const string Model::getVersion()   //获得版本
{
	return Version;	
} 

const string Model::getIsfree()    //获得价格信息
{
	return price;	
} 
