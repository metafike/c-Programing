#include "Video_Prompt_Manage_Operation.h"

//��¼�û� 
void VideoPromptManageOperation::AddOperation(VideoPrompt& vidoeprompt)                 //��Ӳ��� 
{
	videopromptmanage.add(vidoeprompt); 
}

//δ��¼�û� 
void VideoPromptManageOperation::SearchOperation(const string& keyword)                 //��ѯ
{
	videopromptmanage.search(keyword); 
} 

void VideoPromptManageOperation::DisplayOperation()                                     //��ʾ���� 
{
	videopromptmanage.display();
}

void VideoPromptManageOperation::ChangeOperation(const string& keyword, const string& newkeyword)  //�޸Ĳ��� 
{
	videopromptmanage.change(keyword, newkeyword);
}

void  VideoPromptManageOperation::DelOperation(const string&) {}//ɾ������������ʹ�ã�����ɾ�������ļ�

// �����ļ����� 
void VideoPromptManageOperation::personVideoAdd(VideoPrompt& videoprompt)    //��� 
{
	videopromptmanage.personVideoAdd(videoprompt);
}

void VideoPromptManageOperation::personVideoSearch(const string& keyword)     //��ѯ 
{
	videopromptmanage.personVideoSearch(keyword);
}

void VideoPromptManageOperation::personVideoDel(const string& keyword)        //ɾ�� 
{
	videopromptmanage.personVideoDel(keyword);
}

void VideoPromptManageOperation::personVideoChange(const string& keyword, const string& newkeyword)  //�޸� 
{
	videopromptmanage.personVideoChange(keyword, newkeyword);
}

void VideoPromptManageOperation::personVideoDisplay()                                                //��ʾ 
{
	videopromptmanage.personVideoDisplay();
} 
