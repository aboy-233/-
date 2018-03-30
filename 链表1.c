#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data 
{
	char name[10];
	int age;
	long phone_number;
	struct data *next;
	
} DATA;

DATA *deteplay(DATA *head);
DATA *add(DATA *head); 
void display(DATA *head);
DATA *cut_out(DATA *head,char NAME[]);
void  printfln(int *a);
void detele(DATA *head);




DATA *add(DATA *head)                              //�����Ϣ 
{
	int AGE;										//�����м���� 
	long PHONE_NUMBER;
	char NAME[10]; 

	DATA *p = NULL;    
	DATA *pr = head;                                //����ָ��pr�ĳ�ʼλ��
	p = (DATA *)malloc(sizeof(DATA)); 				//ָ��pָ���½ڵ� 
	if(p==NULL)
	{
		exit(0);
	}
	if(head==NULL)
	{
		head = p;								   //�½ڵ�Ϊͷ�ڵ� 
	}
	else
	{
		while(pr->next!=NULL)					   //Ѱ�������β 
		{
			pr = pr->next;
		}
		pr->next = p;						       //prָ���½ڵ� 
	} 
	printf("������");
	scanf("%s",NAME);
	printf("\n���䣺");
	scanf("%d",&AGE);
	printf("\n�绰���룺");
	scanf("%ld",&PHONE_NUMBER);
	p->age=AGE;								       //���½ڵ㸳ֵ 
	p->phone_number=PHONE_NUMBER;
	strcpy(p->name,NAME);
	p->next =NULL; 
	return head;								  //��������½ڵ��������׵�ַ 	  
}



void display(DATA *head)						 //����������� 
{
	DATA *p=head;
	int i = 1;
	while(p!=NULL)
	{
		printf("---------------------------------------------\n");
		printf("\t����\t\t����\t�绰����\n",i);
		printf("%d.\t%-16s%-5d\t%-ld\n",i,p->name,p->age,p->phone_number);
		printf("---------------------------------------------\n");
		p=p->next;
		i++; 
	} 
//	printf("2333");
	deteplay(head);
}



void detele(DATA *head)							//�ͷ��ڴ� 
{
	DATA *p = head;
	DATA *pr = NULL;
	while(p!=NULL)
	{
		pr = p;
		p = p->next;
		free(pr); 
	}
}



void  printfln(int *a)								     
{
	int num;
	printf("����ѡ�\n1.¼����Ϣ\n2.�鿴��Ϣ\n3.�˳�\n");
	scanf("%d",&num);
	*a=num;
}


DATA *cut_out(DATA *head,char NAME[])				//ɾ��ָ���ڵ� 
{
	DATA *p=head;
	DATA *pr=NULL;
	if (head==NULL)								//����Ϊ�� 
	{
		printf("����Ϊ�գ�\n");
		sleep(2);
		system("cls"); 
		return(head); 
	} 
	while((strcmp(NAME,p->name)!=0)&&(p->next)!=NULL)			//δ�ҵ���δ����β 
	{
		pr=p;
		p=p->next; 
	}
	if(strcmp(NAME,p->name)==0)
	{
		if(strcmp(NAME,head->name)==0)
		{
			head=p->next;						//�ı�ͷָ���ָ�� 
		}
		else
		{
			pr->next=p->next;					//�Ͽ���ɾ���ڵ������ 
		} 
		free(p);
		
	}
	else
	{
		printf("δ��������%s�й�����\n",NAME); 
	}
	return head;		
} 


DATA *revise(DATA *head,char NAME[])
{
	int AGE;										//�����м���� 
	long PHONE_NUMBER;
	
	printf("������");
	scanf("%s",NAME);
	printf("\n���䣺");
	scanf("%d",&AGE);
	printf("\n�绰���룺");
	scanf("%ld",&PHONE_NUMBER);
		
	DATA *p=head;
	DATA *pr=NULL;
		if (head==NULL)								//����Ϊ�� 
		{
			printf("����Ϊ�գ�\n");
			sleep(2);
			system("cls"); 
			return(head); 
		} 
		while((strcmp(NAME,p->name)!=0)&&(p->next)!=NULL)			//δ�ҵ���δ����β 
		{
			pr=p;
			p=p->next; 
		}
		if((strcmp(NAME,p->name)==0)&&(p->next==NULL))
		{
			printf("���޴���\n"); 
		}
		
		if(strcmp(NAME,p->name)==0)
		{
			if(strcmp(NAME,head->name)==0)
			{
				head->age=AGE;								       //��ͷ�ڵ㸳ֵ 
				head->phone_number=PHONE_NUMBER;
				strcpy(head->name,NAME);
				head->next =NULL; 
										
			}
			else
			{
				p->age=AGE;								       //���ڵ㸳ֵ 
				p->phone_number=PHONE_NUMBER;
				strcpy(p->name,NAME); 					 
			} 
		}
		return head;
		system("cls"); 
}

DATA *deteplay(DATA *head)				//չʾ��Ķ����˵� 
{
	int i;
	char NAME[10];
	printf("ѡ����Ĳ�����\n1.����\n2.ɾ��\n3.�޸�\n");
	scanf("%d",&i);
	if(i==1)
	{
		system("cls");
		return head;
		
	}
	if(i==2)
	{
		printf("������Ҫɾ����������Ϣ\n");
		scanf("%s",&NAME);
		cut_out(head,NAME);
	}
	if(i==3)
	{
		printf("������Ҫ�޸ĵ�������Ϣ\n");
		scanf("%s",NAME);
		revise(head,NAME); 
	}
	else
	{
		printf("��������!\n"); 
	}
	return head;
}
 


int main()
{
	DATA *head = NULL; 
	int a;
	printfln(&a);
	while(a!=3)
	{
		
		if(a==1)
		{
			head =add(head);
			system("cls");
		}
	    if(a==2)
	    {
	    	display(head);
	    }
		printfln(&a);
	} 
		detele(head);
		//exit(0);
		return 0;
} 




