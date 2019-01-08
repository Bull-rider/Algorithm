/****************************************
 File Name: Power.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Tue 08 Jan 2019 12:54:09 PM CST
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math>
using std::cout;
using std::endl;
//--------数值的整数次方---------------
bool g_InvalidInput=false;
bool equal(double num1,double num2);
double PowerWithUnsignedExponent(double base,unsigned int exponent);
double Power(double dase,int exponent)
{
	g_InvalidInput=false;
	if(equal(base,0.0)&&exponent<0)
	{
		g_InvalidInput=true;
		return 0.0;
	}
	unsigned int absExponent=(unsigned int)(exponent);
	if(exponent<0)
		absExponent=(unsigned int)(-exponent);
	double result =PowerWithUnsignedExponent(base,absExponent);
	if(exponent<0)
		return 1.0/result;
	return result;
}

double PowerWithUnsignedExponent(double dase,unsigned int exponent)
{
	if(exponent==0)
		return 1;
	if(exponent==1)
		return base;
	double result=PowerWithUnsignedExponent(base,exponent>>1);
	result*=result;
	if((exponent&0x1)==1)
		result*=base;
	return result;
}
bool equal(double num1,double num2)
{
	if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
		return true;
	else
		return false;
}
