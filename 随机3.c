#include<stdio.h> 
#include<stdlib.h>
#include<windows.h>
#include<time.h>


int main()
{
	int container[100];//��¼������ݵ����� 
	int num=1;
	char be[3]={"re"};//�ж�ѭ�� 
	while(be!="re"||be!='r'||be!='R')
	{
		system("cls");
		int a,b,c,u;
		int i=1;
		printf("********************************************************************************\n"); 
		printf("\t\t������� ���繤����2017��ʵϰ���� ��д \t(V 2.3.3)\n");
		printf("********************************************************************************\n\n\n"); 
		printf("�����������Χ��\n");
		printf("********************************************************************************\n"); 
		printf("\t\t\t\t\t\b\b");
		scanf("%4d",&b);
		printf("********************************************************************************\n\n\n");
		printf("���������������\n");
		printf("********************************************************************************\n"); 
		printf("\t\t\t\t\t\b\b");
		scanf("\t\t\t\t\t%4d",&c);
		printf("********************************************************************************\n\n\n");
		printf("\t\t\t\t\t\b\b");

		while(c!=0)
		{
			srand(time(NULL));
			u=(rand()+i)%99;
			a=(rand()+u%12*i)%b+1;
		 
			int count;//�ж��ظ���� 
			for(count=1;num>=count;count++)
			{
				if(container[count]==a)
				{
					c++;
					break;
				}
			}
			container[count]=a;
			printf("%4d",a);
			printf("\b\b\b\b");
			Sleep(25);
			i++;
			c--;
		} 
	 
		system("cls"); //ͻ����ʾ 
		printf("\n\n\n\n\n\n\n\n\t\t\t \t*****************\n\n"); 
		printf("\t\t\t\t\t\b\b\b�����%d\n\n",a);
		printf("\n\n\t\t\t \t*****************\n\n");
		scanf("%s",&u);
		num++;
	}
	return 0;
}
