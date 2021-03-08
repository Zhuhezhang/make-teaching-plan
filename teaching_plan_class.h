#ifndef TEACHING_PLAN_CLASS_H_
#define TEACHING_PLAN_CLASS_H_
#include <stack>
#include <cstring>
#include <fstream>
#include <iostream>
#define COURSE_MAX_NUMBER 20                                         //���γ̸���
using namespace std;

//�γ̽ṹ��
struct Course
{
	char id[10];                                                     //�γ̱��
	char name[20];                                                   //�γ���
	int credit;                                                      //�γ�ѧ��
	bool course_exist;                                               //�жϵ�ǰ�γ��Ƿ����
};

//ͼ��
class Graph
{
public:
	void Creat_graph1(Graph* p);                                     //�ļ���ʽ����γ���Ϣ����ͼ
	void Creat_graph2(Graph* p);                                     //������ʽ����γ���Ϣ����ͼ
	void Modify_course(Graph* p);                                    //�޸Ŀγ�
	void ToplogicalSort(Graph* p, int toplogicalSort_reslut[]);      //��������
	void Output_teachingplan1(Graph* p, int toplogicalSort_reslut[]);//����ѧ���е�ѧϰ�����������ȵ��ƶ���ѧ�ƻ�
	void Output_teachingplan2(Graph* p, int toplogicalSort_reslut[]);//�������̵ܶ�ʱ�����ѧϰ�ƶ���ѧ�ƻ�
	void Display_information(Graph* p);                              //����γ���Ϣ 
	int Menu();                                                      //����˵�
private:
	Course course[COURSE_MAX_NUMBER];                                //�γ���Ϣ 
	int course_number;                                               //�γ�����
	int adjmatrix[COURSE_MAX_NUMBER][COURSE_MAX_NUMBER];             //�ڽӾ����ſγ�֮��Ĺ�ϵ
};

#endif
