#ifndef VIDEOPROMPTMANAGE_H
#define VIDEOPROMPTMANAGE_H

#include <string>
using namespace std;
#include "Manage.h"
#include "Video_Prompt.h" 

//��ʾ�ʹ��� 
// �Թ����������ļ�����ز�����  
class VideoPromptManage : public Manage<VideoPrompt>
{
	public:
		//δ��¼���û�ֻ��ʹ�ò�ѯ���ܣ���ʾ���� 
		void search(const string&);                   //��ѯ���� 
		void display();                               //��ʾ���� 
		//��¼���û��ſ���ʹ�����¹��� 
		void add(VideoPrompt&);                       //��ӹ���
        void change(const string&, const string&);    //�޸Ĺ���
        void del(const string&);                      //�����еĳ����࣬�û���¼����ɾ�������ļ���
        //�Ը����ļ����� 
        void personVideoAdd(VideoPrompt&);                                //���	
		void personVideoSearch(const string&);                            //��ѯ
		void personVideoDel(const string&);                               //ɾ�� 
		void personVideoChange(const string& , const string& );           //�޸�
		void personVideoDisplay();                                        //��ʾ 
};
#endif
