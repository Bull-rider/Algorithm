/*************************************************************************
	> File Name: m_n.cpp
	> Author: yxg
	> Mail: yxi7899@gmail.com 
	> Created Time: Thu 27 Dec 2018 06:45:29 PM CST
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

void m_n(int m,int n)
{
	int i,value;
	srand(time(NULL));
	for(i=1;i<n;i++)
	{
		if(rand()%(n-i)<m)
		{
			cout<<i<<" ";
			m--;
		}
	}
	cout<<endl;
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	m_n(m,n);
	return 0;
}
