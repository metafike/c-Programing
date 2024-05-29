#ifndef TEXTPROMPTMANAGEOPERATION_H
#define TEXTPROMPTMANAGEOPERATION_H

#include "Operation.h"
#include "Text_Prompt.h"
#include "Text_Prompt_Manage.h"

//�ı���ʾ�ʲ�����
class TextPromptManageOperation : public Operation<TextPrompt>
{
	private:
		TextPromptManage textpromptmanage;                  //Ƕ����ʾ�ʹ�������󣬷�չ����� 
	public:
		void SearchOperation(const string&);                //��ѯ����
		void DisplayOperation();                            //��ʾ����
		//��¼�û�����ʹ�����²���
		void AddOperation(TextPrompt& textprompt);          //��Ӳ���
		void ChangeOperation(const string&, const string&); //�޸Ĳ��� 
		//����ʹ��ɾ������
		void DelOperation(const string&);                   //������࣬����
		//�����ļ�����
		void persontextadd(TextPrompt&);                            //��� 
		void persontextsearch(const string&);                       //��ѯ 
		void persontextdel(const string& );                         //ɾ�� 
		void persontextchange(const string& , const string& );      //�޸� 
		void persontextdisplay();                                   //��ʾ 
};
#endif 
