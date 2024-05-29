#ifndef VIDEOPROMPT_H
#define VIDEOPROMPT_H

#include "Prompt.h"
#include<string>

//视频提示此类，继承提示词类
class VideoPrompt : public Prompt
{
	private:
		string video_length;                    //时间长度  
	public:	 
		VideoPrompt();                          //构造函数，默认初始化十秒钟 
		void setVideoLen(const string& vl);     //设置视频时长
		string getVideoLen();                   //获得视频时长  
};
#endif 
