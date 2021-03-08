#include "teaching_plan_class.h"


//�ļ���ʽ����γ���Ϣ����ͼ
void  Graph::Creat_graph1(Graph* p)
{
	ifstream in("course_information.txt");
	in >> p->course_number;
	for (int i = 1;i <= p->course_number;i++)
	{
		in >> p->course[i].id >> p->course[i].name >> p->course[i].credit;
		p->course[i].course_exist = true;
	}
	int i, j;
	for (int k = 0;k < 19;k++)                    //��������19�Թ�ϵ����Ӧͼ��19���ߣ�
	{
		in >> i >> j;
		p->adjmatrix[i][j] = 1;                   //��ʾ�γ�ci�ǿγ�cj�����޿γ�
	}
	in.close();
	cout << "�ļ�����Ŀγ���Ϣ�ѳɹ�¼�룡" << endl;
}

//������ʽ����γ���Ϣ����ͼ
void Graph::Creat_graph2(Graph* p)
{
	cout << "������γ�����" << endl;
	cin >> p->course_number;
	cout << "����������γ̱�š��γ����ƺ�ѧ��" << endl;
	for (int i = 1;i <= p->course_number;i++)
	{
		cin >> p->course[i].id >> p->course[i].name >> p->course[i].credit;
		p->course[i].course_exist = true;
	}
	memset(p->adjmatrix, 0, sizeof(p->adjmatrix));//��ʼ��adjmatrixȫ��Ԫ��Ϊ0 
	cout << "������γ�֮���ǰ���ϵ" << endl;
	int i, j, k;
	for (k = 1;k <= 19;k++)                       //��������19�Թ�ϵ����Ӧͼ��19���ߣ� 
	{
		cin >> i >> j;
		p->adjmatrix[i][j] = 1;                   //��ʾ�γ�ci�ǿγ�cj�����޿γ�
	}
	cout << "��������Ŀγ���Ϣ�ѳɹ�¼�룡" << endl;
}

//����γ���Ϣ 
void Graph::Display_information(Graph* p)
{
	cout<<"�γ���Ϣ��"<<endl;
	for (int i = 1;i <= p->course_number;i++)
	{
		cout << p->course[i].id << " ";
		cout << p->course[i].name << " ";
		cout << p->course[i].credit << " ";
		cout << endl;
	}
	cout<<endl<<"�γ̹�ϵ����"<<endl;
	for (int i = 1;i <= p->course_number;i++)
	{
		for (int j = 1;j <= p->course_number;j++)
			cout << p->adjmatrix[i][j] << " ";
		cout << endl;
	}
}

//�޸Ŀγ���Ϣ
void Graph::Modify_course(Graph* p)
{
	int number, choice;
	cout << "�����������޸ĵĿγ̱�ţ�" << endl;
	cin >> number;
	cout << "�����޸ĵ���ϢΪ(1.�γ����� 2.�γ�ѧ��)��" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "�������µĿγ�����" << endl;
		cin >> p->course[number].name;
	}
	if (choice == 2)
	{
		cout << "�������µĿγ�ѧ��" << endl;
		cin >> p->course[number].credit;
	}
	cout << "�޸ĳɹ�" << endl;
}

//������������
void Graph::ToplogicalSort(Graph* p, int toplogicalSort_reslut[])
{
	int indegree[p->course_number + 1];           //��Ÿ�������ȣ���indegree[1]��ʼ��ţ�
	memset(indegree, 0, sizeof(indegree));
	for (int i = 1;i <= p->course_number;i++)     //ͳ�Ƹ��������
		for (int j = 1;j <= p->course_number;j++)
			if (p->adjmatrix[i][j]) indegree[j]++;

	stack <int> s;
	for (int i = 1;i <= p->course_number;i++)     //���Ϊ0����ѹ��ջ
		if (!indegree[i]) s.push(i);

	int num = 0;                                  //��ʼ������������
	while (!s.empty())                            //ջ�ǿ�
	{
		int top;
		top = s.top();                            //ȡջ��Ԫ��
		s.pop();                                  //��ջ
		toplogicalSort_reslut[num++] = top;       //����ջ��Ԫ��
		for (int j = 1;j <= p->course_number;j++)
		{
			if (p->adjmatrix[top][j])
			{
				if (!--indegree[j]) s.push(j);    //ÿ��һ��Ԫ�أ�����ָ��Ľ����ȼ�1 
			}                                     //���ж��Ƿ�Ϊ0����Ϊ������ջ 
		}
	}
}
	
//����ѧ���е�ѧϰ�����������ȵ��ƶ���ѧ�ƻ�
void Graph::Output_teachingplan1(Graph* p, int toplogicalSort_reslut[])
{
	ofstream out("teaching_plan1.txt");
	int average_credit = 0;
	for (int i = 1;i <= p->course_number;i++)     //����γ���ѧ��
	{
		average_credit += p->course[i].credit;
	}

	int remaine_credit = average_credit;          //remaining_creditΪʣ����ѧ�� 
	average_credit /= 8;                          //���蹲8��ѧ��
	out << "ƽ��ѧ��Ϊ:" << average_credit << endl << endl;
	int term_number = 1, j = 0;                   //ѧ�ڱ�š��������е��±�

	while (remaine_credit > 0)                    //��ѧ�ֻ�ʣ��
	{
		int term_credit = 0;
		int term_remaine_credit = average_credit; //��ǰѧ�ڻ����޵�ѧ��
		out << "��" << term_number << "ѧ��:" << endl;
		if (remaine_credit > term_remaine_credit) //ʣ����ѧ�ֶ��ڵ�ǰѧ�ڻ����޵�ѧ��
		{
			while (term_remaine_credit > 0)       //��ǰѧ�ڻ����޵�ѧ�ֻ�ʣ��
			{
				out << p->course[toplogicalSort_reslut[j]].id << " ";
				out << p->course[toplogicalSort_reslut[j]].name << " ";
				out << p->course[toplogicalSort_reslut[j]].credit << " ";

				term_remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
				remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
				term_credit += p->course[toplogicalSort_reslut[j]].credit;
				j++;
				out << endl;
			}
			term_number++;                        //��ǰѧ��û�л����޵�ѧ�֣�����ѧ��
		}
		else                                      //ʣ����ѧ�����ڻ���ڵ�ǰѧ�ڻ����޵�ѧ��
		{
			out << p->course[toplogicalSort_reslut[j]].id << " ";
			out << p->course[toplogicalSort_reslut[j]].name << " ";
			out << p->course[toplogicalSort_reslut[j]].credit << " ";

			term_remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
			remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
			term_credit += p->course[toplogicalSort_reslut[j]].credit;
			j++;
			out << endl;
		}
		out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
	}
	out << "ѧ������Ϊ:" << term_number << endl;
	out.close();
	cout << "��ѧ�ƻ��ѱ��浽�ļ�teaching_plan1.txt��" << endl;
}

//�������̵ܶ�ʱ�����ѧϰ�ƶ���ѧ�ƻ�
void Graph::Output_teachingplan2(Graph* p, int toplogicalSort_reslut[])
{
	ofstream out("teaching_plan2.txt");
	int term_credit;                              //ѧ����ѧ��
	int term_number = 1;                          //ѧ�ڱ��
	int number = 0;                               //�����������±�
	int remain_credit = 0;                        //ʣ����ѧ��
	for (int i = 1;i <= p->course_number;i++)     //����γ���ѧ��
	{
		remain_credit += p->course[i].credit;
	}

	while (remain_credit > 15)                    //ÿѧ��ѧ������Ϊ15 
	{
		term_credit = 0;
		out << "��" << term_number << "ѧ��:" << endl;
		while (term_credit + p->course[toplogicalSort_reslut[number]].credit < 15)
		{                                         //��ǰ��ѧ����ѧ��+��һ��Ҫ���ſγ̵�ѧ��<ѧ������15
			out << p->course[toplogicalSort_reslut[number]].id << " ";
			out << p->course[toplogicalSort_reslut[number]].name << " ";
			out << p->course[toplogicalSort_reslut[number]].credit << " " << endl;
			term_credit += p->course[toplogicalSort_reslut[number]].credit;
			remain_credit -= p->course[toplogicalSort_reslut[number]].credit;
			number++;
		}
		term_number++;
		out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
    }

	term_credit = 0;
	out << "��" << term_number << "ѧ��:" << endl;//��ѧ��ʣ��С��15ʱ 
	while (remain_credit > 0)
	{
		out << p->course[toplogicalSort_reslut[number]].id << " ";
		out << p->course[toplogicalSort_reslut[number]].name << " ";
		out << p->course[toplogicalSort_reslut[number]].credit << " " << endl;
		term_credit += p->course[toplogicalSort_reslut[number]].credit;
		remain_credit -= p->course[toplogicalSort_reslut[number]].credit;
		number++;
	}
	out << "��ѧ����ѧ��Ϊ��" << term_credit << endl << endl;
	out << "ѧ������Ϊ:" << term_number << endl;
	out.close();
	cout << "��ѧ�ƻ��ѱ��浽�ļ�teaching_plan2.txt��" << endl;
}

//����˵�
int Graph::Menu()
{
	int i;
	do {
		system("cls");
		cout << "***************��ѧ�ƻ�����ϵͳ****************" << endl << endl;
		cout << "           1.�ļ���ʽ����γ���Ϣ" << endl;
		cout << "           2.������ʽ����γ���Ϣ" << endl;
		cout << "           3.�γ���Ϣ�޸�" << endl;
		cout << "           4.�γ���Ϣ���" << endl;
		cout << "           5.����ѧ���е�ѧϰ�����������ȵ��ƶ���ѧ�ƻ�" << endl;
		cout << "           6.�������̵ܶ�ʱ�����ѧϰ�ƶ���ѧ�ƻ�" << endl;
		cout << "           7.�˳�����" << endl << endl;
		cout << "����������ѡ��";
		cin >> i;
	} while (i < 1 || i>7);
	return i;
}
