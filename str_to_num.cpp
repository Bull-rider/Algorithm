/****************************************
 File Name: str_to_num.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 31 Dec 2018 01:15:06 AM PST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

enum Status{
	kValid=0,
	kInvalid
};
int g_nStatus=kValid;
int StrToInt(const char *str)
{
	g_nStatus=kInvalid;
	long long num=0;
	//判断str是否为空，不为空才进行以下操作
	if(str!=NULL)
	{
		const char *digit=str;
		bool minus=false;
		//判断正负
		if(*digit=='+')
		{
			digit++;
			minus=true;
		}else if(*digit=='-')
		{
			digit++;
		}
		//开始计算字符串转换为整型后的值
		while(*digit!='\0')
		{
			if(*digit>='0'&&*digit<='9')
			{
				num=num*10+(*digit-'0');
				if(num>0xFFFFFFFF)
				{
					num=0;
					break;
				}
				digit++;
			}else{
				num=0;
				break;
			}
		}
		//再根据minus的值修改最终的值
		if(*digit=='\0')
		{
			g_nStatus=kValid;
			if(minus)
				num=0-num;
		}
	}
	return num;
}
int main()
{
	const char a[6]="hello";
	long long num;
	num=StrToInt(a);
	cout<<num<<endl;
	return 0;
}
