#include "Text_Prompt_Manage_Operation.h"

//��¼�û� 
void TextPromptManageOperation::AddOperation(TextPrompt& textprompt) //��Ӳ��� 
{
	textpromptmanage.add(textprompt); 
}

//δ��¼�û� 
void TextPromptManageOperation::SearchOperation(const string& keyword) //��ѯ
{
	textpromptmanage.search(keyword); 
} 

void TextPromptManageOperation::DisplayOperation()                    //��ʾ���� 
{
	textpromptmanage.display();
}

void TextPromptManageOperation::ChangeOperation(const string& keyword, const string& newkeyword)  //�޸Ĳ��� 
{
	textpromptmanage.change(keyword, newkeyword);
}

void  TextPromptManageOperation::DelOperation(const string&) {}                                  //ɾ������������ʹ�ã�����ɾ�������ļ�
 
//�����ļ�����
void TextPromptManageOperation::persontextadd(TextPrompt& textprompt)     //��� 
{
	textpromptmanage.persontextadd(textprompt); 
}                         
                
void TextPromptManageOperation::persontextsearch(const string& keyword)   //��ѯ 
{
	textpromptmanage.persontextsearch(keyword);
}              

void TextPromptManageOperation::persontextdel(const string& keyword)       //ɾ�� 
{
	textpromptmanage.persontextdel(keyword);
}

void TextPromptManageOperation::persontextchange(const string& keyword, const string& newkeyword)  //�޸� 
{
	textpromptmanage.persontextchange(keyword, newkeyword);
}

void TextPromptManageOperation::persontextdisplay()                          //��ʾ 
{
	textpromptmanage.persontextdisplay();
}
