#include <iostream>
#include <fstream>
using namespace std;
#include "Video_Prompt.h"
#include <string>
#include <vector>

VideoPrompt::VideoPrompt()                       // 构造函数初始化，默认十秒钟 
{
	video_length = "十秒钟";
} 
void VideoPrompt::setVideoLen(const string& vl)  //设置视频时长 
{
	video_length = vl;
}

string VideoPrompt::getVideoLen()                //获得视频时长 
{      
	return video_length; 
}
