#ifndef TEXTPROMPTMANAGE_H
#define TEXTPROMPTMANAGE_H

#include <string>
using namespace std;
#include "Manage.h"
#include "Text_Prompt.h"

//��ʾ�ʹ��� 
// �Թ����ļ�����ز�����  
class TextPromptManage : public Manage<TextPrompt>
{
	public:	
		//δ��¼���û�ֻ��ʹ�ò�ѯ���ܣ���ʾ���� 
		void search(const string&);                   //��ѯ���� 
		void display();                               //��ʾ���� 
		
		//��¼���û��ſ���ʹ�����¹��� 
		void add(TextPrompt&);                        //��ӹ���
        void change(const string&, const string&);    //�޸Ĺ���
        //�����Ƿ��¼������ɾ�������ļ� 
        void del(const string&);                      //�����еĳ����࣬Ҫ���� 
        
        //��Ӧ���Ǹ����ı���ʾ���ļ��Ĳ��� 
		void persontextadd(TextPrompt&);                            //��� 
		void persontextsearch(const string&);                       //��ѯ 
		void persontextdel(const string& );                         //ɾ�� 
		void persontextchange(const string& , const string& );      //�޸� 
		void persontextdisplay();                                   //��ʾ 
};
#endif
