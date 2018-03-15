#include<stdio.h>
int main()
{
	while(1)
	{
		int i=0,nums=0;
		char num[100];
		printf("*************************************\n");
		printf("请输入数字（不能输入其他！）:"); 
		scanf("%s",num);
		while(num[i]!=0)
		{
			if(num[i]>=48&&num[i]<=57)
			{
				nums+=(num[i]-'0');
			}else {
				printf("出现非法字符--%c\n",num[i]);	
			}
			i++;
		}
		printf("*************************************\n");
		printf("\t数字的和是：%d\n",nums);
	}
	return 0;
} 
