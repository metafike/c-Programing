#include <iostream>
#include <fstream>
using namespace std;
#include "Text_Prompt.h"
#include <string>
#include <vector>

TextPrompt::TextPrompt()                                //���캯����Ĭ��ֵ 
{
	wordNum = "100";
	language = "english";       	
} 

void TextPrompt::setWordNum(const string& n)            //�������� 
{
	wordNum = n;
}

void TextPrompt::setLanguage(const string& la)          //�������� 
{
	language = la;            
}

string TextPrompt::getWordNum()                         //������� 
{
	return wordNum;
}

string TextPrompt::getLanguage()                        //������� 
{
	return language;
}
