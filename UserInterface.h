#ifndef USERINTERFACE_H
#define USERINTERFACE_H

//�û������࣬��Ҫ�Ǽ����˵� 
class UserInterface 
{
	public:
		void MainMenu();     //���˵� 
		void BrowserMenu();  //�ÿͲ˵� 
		void LoginMenu();    //��¼�˵� 
		void PersonalMenu(); //��¼��ĸ����ļ������˵� 
		void PublicMenu();   //�����ļ������˵�
		void PersonTextMenu();     //�����ı��ļ������˵�
		void PersonVideoMenu();    //������Ƶ��ʾ�ʲ����˵� 
		void PublicVideoMenu();    //������Ƶ��ʾ�ʲ����˵�
		void PublicTextMenu();     //�����ı���ʾ�ʲ����˵�
		void PublicModelMenu();    //����ģ�Ͳ����˵�
		void PublicFeedbackMenu(); //���������ļ������˵� 
		void Changepersonal();     //�޸ĸ�����Ϣ�˵� 
};
#endif
