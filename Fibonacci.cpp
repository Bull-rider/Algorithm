/****************************************
  File Name: Fibonacci.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Mon 07 Jan 2019 09:47:33 PM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//----------递归方法
long long Fibonacci1(unsigned int n)
{
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	return Fibonacci1(n-1)+Finonacci1(n-2);
}
//-------------循环方法
long long Fibonacci2(unsigned int n)
{
	int result[2]={0,1};
	if(n<2)
		return result[n];
	long long fibOne=1;
	long long fibTwo=0;
	long long fibN=0;
	for(unsigned int i=2;i<=n;i++)
	{
		fibN=fibOne+fibTwo;
		fibTwo=fibOne;
		fibOne=fibN;
	}
	return fibN;
}
//基于矩阵乘法
struct Matrix2By2
{
	Matrix2By2
		(
		 long long m00 = 0, 
		 long long m01 = 0, 
		 long long m10 = 0, 
		 long long m11 = 0
		)
		:m_00(m00), m_01(m01), m_10(m10), m_11(m11) 
		{
		}

	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;
};

	Matrix2By2 MatrixMultiply
(
 const Matrix2By2& matrix1, 
 const Matrix2By2& matrix2
 )
{
	return Matrix2By2(
			matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
			matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
			matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
			matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
	assert(n > 0);

	Matrix2By2 matrix;
	if(n == 1)
	{
		matrix = Matrix2By2(1, 1, 1, 0);
	}
	else if(n % 2 == 0)
	{
		matrix = MatrixPower(n / 2);
		matrix = MatrixMultiply(matrix, matrix);
	}
	else if(n % 2 == 1)
	{
		matrix = MatrixPower((n - 1) / 2);
		matrix = MatrixMultiply(matrix, matrix);
		matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
	}

	return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
	int result[2] = {0, 1};
	if(n < 2)
		return result[n];

	Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
	return PowerNMinus2.m_00;
}
