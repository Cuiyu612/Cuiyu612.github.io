#include<stdio.h>
int main()
{
	double n,t,sum=0;
	double a[110],b[110],c[110],d,m,k;
	int i,j;
	scanf("%lf %lf",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a[i],&b[i]);//数组a代表重量，数组b代表价值； 
		c[i]=b[i]/a[i];
	}
	for(i=1;i<=n-1;i++)//冒泡排序；双层嵌套； 
	{
		for(j=1;j<=n-i;j++)
		{
			if(c[j]<c[j+1])
			{
				d=c[j];c[j]=c[j+1];c[j+1]=d;
				m=a[j];a[j]=a[j+1];a[j+1]=m;
				k=b[j];b[j]=b[j+1];b[j+1]=k;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(t-a[i]>-0.001)
		{
			t-=a[i];
			sum+=b[i];
		}
		else 
		{
			sum+=t*c[i];
			break;
		}
	}
	printf("%.2lf",sum);
	return 0;
 } 
