#ifndef VIDEOPROMPTMANAGEOPERATION_H
#define VIDEOPROMPTMANAGEOPERATION_H

#include "Operation.h"
#include "Video_Prompt.h"
#include "Video_Prompt_Manage.h"

//�ı���ʾ�ʲ�����
class VideoPromptManageOperation : public Operation<VideoPrompt>
{
	private:
		VideoPromptManage videopromptmanage;   //Ƕ����ʾ�ʹ�������󣬷�չ����� 
	public:
		void SearchOperation(const string&);                  //��ѯ����
		void DisplayOperation();                              //��ʾ����
		//��¼�û�����ʹ�����²���
		void AddOperation(VideoPrompt& videoprompt);          //��Ӳ���
		void ChangeOperation(const string&, const string&);   //�޸Ĳ��� 
		//����ʹ��ɾ������
		void DelOperation(const string&);                     //������࣬����
		//�Ը����ļ����� 
        void personVideoAdd(VideoPrompt&);                                //���	
		void personVideoSearch(const string&);                            //��ѯ
		void personVideoDel(const string&);                               //ɾ�� 
		void personVideoChange(const string& , const string& );           //�޸�
		void personVideoDisplay();                                        //��ʾ 
};
#endif 
