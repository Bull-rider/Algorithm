#include <iostream>
#include<stdio.h>
#include <iostream>

using std::endl;
using std::cout;

int  main()
{
	const int LEN=41;
	//scanf("LEN=%d M=%d", &LEN, &M);
	int a[LEN];
	for (int i = 0; i < LEN; i++) { a[i] = 1; }   // 数组初始化，1：表示为活着；0：表示自杀

	int leftCount = LEN;                // 计数器leftCount：计数剩下的人
	int index = 0, count = 0;            // 1.数组下标index；2.循环计数器count

	while (leftCount > 0) {                 // 当还剩下两个人结束

		if (a[index] == 1) {
			count++;
			if (3 == count) {             // 计数到3，1.自杀；2.循环计数器count重新开始计数；3.计数器leftCount减1
				a[index] = 0;
				count = 0;
				leftCount--;
				cout << index + 1 << endl;
			}
		}
		index++;

		if (index == LEN) { index = 0; }    // 当到数组尾，数组下标index置零，重新开始
	}

	//for (int j = 0; j < LEN; j++) {             // 输出结果
	//	if (1 == a[j]) { printf("剩下两个人为第%d个\n", j + 1); }
	//}
}
