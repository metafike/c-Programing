#include <iostream>
#include <fstream>
using namespace std;
#include "Text_Prompt.h"
#include <string>
#include <vector>

TextPrompt::TextPrompt()                                //构造函数，默认值 
{
	wordNum = "100";
	language = "english";       	
} 

void TextPrompt::setWordNum(const string& n)            //设置字数 
{
	wordNum = n;
}

void TextPrompt::setLanguage(const string& la)          //设置语言 
{
	language = la;            
}

string TextPrompt::getWordNum()                         //获得字数 
{
	return wordNum;
}

string TextPrompt::getLanguage()                        //获得语言 
{
	return language;
}
