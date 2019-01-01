/****************************************
  File Name: deleteBlank.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 31 Dec 2018 06:36:50 PM PST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//删除字符串开始和末尾的空格，并把中间的多个空格转化为一个
void fun(char *s)
{

	int i=0,j=0;
	while(s[j]==' ')
	{
		j++;
	}
	int len=strlen(s)-1;
	s[len+1]='\0';
	while(s[j]!='\0')
	{
		while(s[j]==' ')
		{

			j++;
		}
		if(s[j-1]==' '&&s[j-2]==' '&&i!=0)
		{
			s[i++]=' ';
		}
		s[i++]=s[j++];
	}
	s[i]='\0';
}

int main()
{
	char a[]="   he  ll o  ";
	fun(a);
	cout<<a<<endl;
	return 0;
}
