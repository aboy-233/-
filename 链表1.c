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




DATA *add(DATA *head)                              //添加信息 
{
	int AGE;										//设置中间变量 
	long PHONE_NUMBER;
	char NAME[10]; 

	DATA *p = NULL;    
	DATA *pr = head;                                //定义指针pr的初始位置
	p = (DATA *)malloc(sizeof(DATA)); 				//指针p指向新节点 
	if(p==NULL)
	{
		exit(0);
	}
	if(head==NULL)
	{
		head = p;								   //新节点为头节点 
	}
	else
	{
		while(pr->next!=NULL)					   //寻找链表结尾 
		{
			pr = pr->next;
		}
		pr->next = p;						       //pr指向新节点 
	} 
	printf("姓名：");
	scanf("%s",NAME);
	printf("\n年龄：");
	scanf("%d",&AGE);
	printf("\n电话号码：");
	scanf("%ld",&PHONE_NUMBER);
	p->age=AGE;								       //给新节点赋值 
	p->phone_number=PHONE_NUMBER;
	strcpy(p->name,NAME);
	p->next =NULL; 
	return head;								  //返回添加新节点后链表的首地址 	  
}



void display(DATA *head)						 //输出链表内容 
{
	DATA *p=head;
	int i = 1;
	while(p!=NULL)
	{
		printf("---------------------------------------------\n");
		printf("\t姓名\t\t年龄\t电话号码\n",i);
		printf("%d.\t%-16s%-5d\t%-ld\n",i,p->name,p->age,p->phone_number);
		printf("---------------------------------------------\n");
		p=p->next;
		i++; 
	} 
//	printf("2333");
	deteplay(head);
}



void detele(DATA *head)							//释放内存 
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
	printf("输入选项：\n1.录入信息\n2.查看信息\n3.退出\n");
	scanf("%d",&num);
	*a=num;
}


DATA *cut_out(DATA *head,char NAME[])				//删除指定节点 
{
	DATA *p=head;
	DATA *pr=NULL;
	if (head==NULL)								//链表为空 
	{
		printf("内容为空！\n");
		sleep(2);
		system("cls"); 
		return(head); 
	} 
	while((strcmp(NAME,p->name)!=0)&&(p->next)!=NULL)			//未找到且未到表尾 
	{
		pr=p;
		p=p->next; 
	}
	if(strcmp(NAME,p->name)==0)
	{
		if(strcmp(NAME,head->name)==0)
		{
			head=p->next;						//改变头指针的指向 
		}
		else
		{
			pr->next=p->next;					//断开被删除节点的连接 
		} 
		free(p);
		
	}
	else
	{
		printf("未搜索到与%s有关数据\n",NAME); 
	}
	return head;		
} 


DATA *revise(DATA *head,char NAME[])
{
	int AGE;										//设置中间变量 
	long PHONE_NUMBER;
	
	printf("姓名：");
	scanf("%s",NAME);
	printf("\n年龄：");
	scanf("%d",&AGE);
	printf("\n电话号码：");
	scanf("%ld",&PHONE_NUMBER);
		
	DATA *p=head;
	DATA *pr=NULL;
		if (head==NULL)								//链表为空 
		{
			printf("内容为空！\n");
			sleep(2);
			system("cls"); 
			return(head); 
		} 
		while((strcmp(NAME,p->name)!=0)&&(p->next)!=NULL)			//未找到且未到表尾 
		{
			pr=p;
			p=p->next; 
		}
		if((strcmp(NAME,p->name)==0)&&(p->next==NULL))
		{
			printf("查无此人\n"); 
		}
		
		if(strcmp(NAME,p->name)==0)
		{
			if(strcmp(NAME,head->name)==0)
			{
				head->age=AGE;								       //给头节点赋值 
				head->phone_number=PHONE_NUMBER;
				strcpy(head->name,NAME);
				head->next =NULL; 
										
			}
			else
			{
				p->age=AGE;								       //给节点赋值 
				p->phone_number=PHONE_NUMBER;
				strcpy(p->name,NAME); 					 
			} 
		}
		return head;
		system("cls"); 
}

DATA *deteplay(DATA *head)				//展示后的二级菜单 
{
	int i;
	char NAME[10];
	printf("选择你的操作：\n1.返回\n2.删除\n3.修改\n");
	scanf("%d",&i);
	if(i==1)
	{
		system("cls");
		return head;
		
	}
	if(i==2)
	{
		printf("输入你要删除的名字信息\n");
		scanf("%s",&NAME);
		cut_out(head,NAME);
	}
	if(i==3)
	{
		printf("输入你要修改的名字信息\n");
		scanf("%s",NAME);
		revise(head,NAME); 
	}
	else
	{
		printf("输入有误!\n"); 
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




