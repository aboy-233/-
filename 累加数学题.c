#include<stdio.h>

/*给定一个不定阶多项式,计算求和->      f(x)=1+(1到n累加)x^i/i           */

void f1(int n,double x)
{
	double num = 0.0;
	int i;
	for(i=n;i>=1;i--)			/*循环求和(预先拆解成多层结构)*/
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
