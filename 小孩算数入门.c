#include<stdio.h>
int main()
{
	while(1)
	{
		int i=0,nums=0;
		char num[100];
		printf("*************************************\n");
		printf("���������֣�����������������:"); 
		scanf("%s",num);
		while(num[i]!=0)
		{
			if(num[i]>=48&&num[i]<=57)
			{
				nums+=(num[i]-'0');
			}else {
				printf("���ַǷ��ַ�--%c\n",num[i]);	
			}
			i++;
		}
		printf("*************************************\n");
		printf("\t���ֵĺ��ǣ�%d\n",nums);
	}
	return 0;
} 
