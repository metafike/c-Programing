#ifndef TEXTPROMPT_H
#define TEXTPROMPT_H

#include "Prompt.h"

//�ı���ʾ���࣬�̳���ʾ����
class TextPrompt : public Prompt 
{
	private:
		string wordNum;        //����Ҫ��
		string language;       //���ԣ���ͬ�����Խ��лش� 
	public:	
		TextPrompt();                         //���캯��������Ĭ��100�֣�����Ĭ��Ӣ�� 
		void setWordNum(const string&);       //��������
		void setLanguage(const string& la);   //��������
		string getWordNum();                  //�������
		string getLanguage();                 //�������
};
#endif 
