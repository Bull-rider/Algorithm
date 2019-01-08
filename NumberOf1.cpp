/****************************************
 File Name: NumberOf1.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Tue 08 Jan 2019 10:57:10 AM CST
 ****************************************/
//通过移位实现
int NumberOf1(int n)
{
	int count=0;
	unsigned ing flag=1;
	while(flag)
	{
		if(n&flag)
			count++;
		flag=flag<<1;
	}
	return count;
}
//方法二就是从低位到高位
int NumberOf1(int n)
{
	int count=0;
	while(n)
	{
		++count;
		n=(n-1)&n;
	}
	return count;
}
