#ifndef TEXTPROMPT_H
#define TEXTPROMPT_H

#include "Prompt.h"

//文本提示词类，继承提示词类
class TextPrompt : public Prompt 
{
	private:
		string wordNum;        //字数要求
		string language;       //语言（不同的语言进行回答） 
	public:	
		TextPrompt();                         //构造函数，字数默认100字，语言默认英语 
		void setWordNum(const string&);       //设置字数
		void setLanguage(const string& la);   //设置语言
		string getWordNum();                  //获得字数
		string getLanguage();                 //获得语言
};
#endif 
