#include<stdio.h>

/*����һ�������׶���ʽ,�������->      f(x)=1+(1��n�ۼ�)x^i/i           */

void f1(int n,double x)
{
	double num = 0.0;
	int i;
	for(i=n;i>=1;i--)			/*ѭ�����(Ԥ�Ȳ��ɶ��ṹ)*/
	{
		num = x*(1.0/i + num);  
	} 
	num += 1;
	printf("%lf",num);	
}

int main()
{
	int n;
	double x;
	scanf("%d%lf",&n,&x);
	f1(n,x);
	return 0; 
}
