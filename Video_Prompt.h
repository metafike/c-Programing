#ifndef VIDEOPROMPT_H
#define VIDEOPROMPT_H

#include "Prompt.h"
#include<string>

//��Ƶ��ʾ���࣬�̳���ʾ����
class VideoPrompt : public Prompt
{
	private:
		string video_length;                    //ʱ�䳤��  
	public:	 
		VideoPrompt();                          //���캯����Ĭ�ϳ�ʼ��ʮ���� 
		void setVideoLen(const string& vl);     //������Ƶʱ��
		string getVideoLen();                   //�����Ƶʱ��  
};
#endif 
