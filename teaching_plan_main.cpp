#include "teaching_plan_class.h"


//������
int main()
{
	int i;
	Graph graph, * p;
	p = (Graph*)malloc(sizeof(Graph));
	int toplogicalSort_reslut[20];
	memset(toplogicalSort_reslut, 0, sizeof(toplogicalSort_reslut));

    first:
	switch (graph.Menu())
	{
	    case 1:
	    {
		    system("cls");
		    graph.Creat_graph1(p);                               //�ļ���ʽ����γ���Ϣ����ͼ 
	    	system("pause");
	    	goto first;
	    }
	    case 2:
	    {
	    	system("cls");
	     	graph.Creat_graph2(p);                               //������ʽ����γ���Ϣ����ͼ
	    	system("pause");
	    	goto first;
    	}
        case 3:
	    {
		    system("cls");
		    graph.Modify_course(p);                              //�޸Ŀγ���Ϣ 
		    system("pause");
		    goto first;
	    }
	    case 4:
    	{
		    system("cls");
		    graph.Display_information(p);                        //����γ���Ϣ 
		    system("pause");
	    	goto first;
	    }
    	case 5:
    	{
		    system("cls");
		    graph.ToplogicalSort(p, toplogicalSort_reslut);      //�������� 
	    	graph.Output_teachingplan1(p, toplogicalSort_reslut);//����ѧ���е�ѧϰ�����������ȵ��ƶ���ѧ�ƻ�
		    system("pause");
	    	goto first;
	    }
    	case 6:
    	{
		    system("cls");
	    	graph.ToplogicalSort(p, toplogicalSort_reslut);       //�������� 
	    	graph.Output_teachingplan2(p, toplogicalSort_reslut); //�������̵ܶ�ʱ�����ѧϰ�ƶ���ѧ�ƻ�
	    	system("pause");
	    	goto first;
	    }
	}
	cout << "��лʹ�ã�"; 
	return 0;
}
