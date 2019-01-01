/****************************************
 File Name: isUniqueCharString.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 31 Dec 2018 07:37:48 PM PST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
//判断一个字符串中是否所有的字符都不相等
bool char_set[256];
int isUniqueCharstring(const char *a)
{
	assert(a!=NULL);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		int value=a[i];
		if(char_set[value])
		{
			return 0;
		}
		char_set[value]=true;
	}
	return 1;
}

//如果假设字符串仅包含'a'~‘z'的字符，我们可以将空间降到一个int代码如下
int isUniqueCharString(const char *a)
{
	assert(str!=NULL);
	int checker=0;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		int val=str[i]-'a';
		if((checker&(1<<val))>0)
			return 0;
		checker|=(1<<val);
	}
	return 1;
}
