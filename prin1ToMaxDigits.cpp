/****************************************
 File Name: prin1ToMaxDigits.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Tue 08 Jan 2019 03:47:27 PM CST
 ****************************************/
#include <stdio.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

void PrintNumber(char *number);
bool Increment(char *number);
void Print1ToMaxDigits(char *number,int length,int index);

void Print1ToMaxDigits(int n)
{
	if(n<=0)
		return;
	char *number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';
	while(!Increment(number))
	{
		PrintNumber(number);
	}
	delete [] number;
}
//字符串number表示一个数字，再number上增加1
//如果做加法溢出，则返回true，否则为false
bool Increment(char *number)
{
	bool isOverflow=false;
	int nTakeOver=0;
	int nLength=strlen(number);
	for(int i=nLength-1;i>=0;i--)
	{
		int nSum=number[i]-'0'+nTakeOver;
		if(i==nLength-1)
			nSum++;
		if(nSum>=10)
		{
			if(i==0)
				isOverflow=true;
			else{
				nSum-=10;
				nTakeOver=1;
				number[i]='0'+nSum;
			}
		}
		else{
			number[i]='0'+nSum;
			break;
		}
	}
	return isOverfloww;
}
//--------------方法二---------------
void Print1ToMaxDigits(int n)
{
	if(n<=0)
		return;
	char *number=new char[n+1];
	number[n]='\0';
	for(int i=0;i<10;++i)
	{
		number[0]=i+'0';
		Print1ToMaxOfN(number,n,0);
	}
	delete [] number;
}
void Print1ToMaxOfN(char *number,int length,int index)
{
	if(index==length-1)
	{
		printNumber(number);
		return;
	}
	for(int i=0;i<10;++i)
	{
		number[index+1]=i+'0';
		Print1ToMaxOfN(number,length,index+1);
	}
}
//---------公共函数-------------
void Print(char *number)//打印只有在碰到第一个非零的字符才开始打印
{
	bool isBeginning0=true;
	int length=strlen(number);
	for(int i=0;i<length;++i)
	{
		if(isBeginning0&&number[i]!='0')
			isBeginning0=false;
		if(!isBeginning0)
			printf("%c",number[i]); 
	}
}
