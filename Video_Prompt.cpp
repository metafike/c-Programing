#include <iostream>
#include <fstream>
using namespace std;
#include "Video_Prompt.h"
#include <string>
#include <vector>

VideoPrompt::VideoPrompt()                       // ���캯����ʼ����Ĭ��ʮ���� 
{
	video_length = "ʮ����";
} 
void VideoPrompt::setVideoLen(const string& vl)  //������Ƶʱ�� 
{
	video_length = vl;
}

string VideoPrompt::getVideoLen()                //�����Ƶʱ�� 
{      
	return video_length; 
}
