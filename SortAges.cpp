/****************************************
 File Name: SortAges.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 07 Jan 2019 10:09:27 PM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

void SortAges(int ages[],int length)
{
	if(ages==NULL||length<=0)
		return;
	const int oldestAge=99;
	int timesOfAge[oldestAge+1];
	for(int i=0;i<=oldestAge;++i)
	{
		timesOfAge[i]=0;
	}
	//统计每个年龄出现的次数
	for(int j=0;j<length;j++)
	{
		timesOfAge[ages[j]]++;
	}
	//某个年龄出现了多少次，就在数组ages里设置几次该年龄，这样就相	//当于给数组ages排序了.
	//这里按年龄从小到大排序，年龄
	int index=0;
	for(int i=0;i<oldestAge;++i)//年龄从0开始
	{
		for(int j=0;j<timesOfAge[i];++j)//出现几次就在数组中设置几次
		{
			ages[index]=i;
			++index;
		}
	}
}
