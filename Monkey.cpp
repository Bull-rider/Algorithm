/****************************************
 File Name: Monkey.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Thu 10 Jan 2019 03:14:35 PM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

bool func(int a,int k)
{
	int m=a;
	int n=k;

	if(m%3==1)
	{
		if(n<3)
		{
			m=m/3*2;
			n++;
			func(m,n);
		}else
		{
			if(n==3&&m/3==0&&a!=0)
				return true;
			else{
				return false;
		}
	}
}
void Print(int N)
{
	int i;
	for(i=4;i<N;++i)
	{
		int k=0;
		if(func(i,k))
			printf("%d",i);
		else
		{
			return;
		}
	}
}
int  main()
{
	int n;
	scanf("%d",&n);
	Print(n);
	return 0;
}
