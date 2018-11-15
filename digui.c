#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
date:2018/11/15
author:BetterMe1
compiler：Microsoft Visual Studio 2013
program:递归练习
*/

/*
1.一个人赶着鸭子去每个村庄卖，每经过一个村子卖去所赶鸭子的一半又一只。
这样他经过了七个村子后还剩两只鸭子，问他出发时共赶多少只鸭子？
经过每个村子卖出多少只鸭子？
*/

/*
分析、算法：
before：进入村庄时的鸭子数；
sell：卖出的鸭子数
after:剩余鸭子数
sell：before/2+1;
after:before-sell=before/2-1;
*/

//int i=7;
//int n=2;//最终剩余鸭子数
//int count=2;//统计鸭子总数
//int sell;
//
///*卖出鸭子函数*/
//void SellDuck(int after){
//	if(i>=1){
//		int before=(after+1)*2;
//		sell=before/2+1;
//		printf("经过第%d个村庄时卖出的鸭子数为：%d\n",i,sell);
//		count=count+sell;
//		i--;
//		SellDuck(before);
//	}
//	else{
//		printf("出发时共赶了%d个鸭子!\n",count);
//	}
//}
//int main(){
//	SellDuck(n);
//	system("pause");
//	return 0;
//}

/*
2.角谷定理。输入一个自然数，若为偶数，则把它除以2，若为奇数，则把它乘以3加1。
经过如此有限次运算后，总可以得到自然数值1。求经过多少次可得到自然数1。
如：输入22，
输出 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
STEP=16
*/
/*分析、算法：
n:输入的数；count：统计次数；
函数：
输出这个数；
count++;
判断是否为1,打印次数，
        不为1判断奇数还是偶数，
        偶数：n=n/2;
        奇数：n=n*3+1;
        再次调用直到为1
*/


//int n=0;
//int count =0;
//
///*角谷定理函数*/
//void ValleyAngle(int n){
//	printf("%d ",n);
//	count++;
//	if(n==1){
//		printf("\n");
//		printf("STEP=%d\n",count);
//	}
//	else{
//		if(n%2==0){
//			n=n/2;
//			ValleyAngle(n);
//		}
//		else{
//			n=n*3+1;
//			ValleyAngle(n);
//		}
//	}
//}
//int main(){
//	printf("请输入一个自然数：");
//	scanf("%d",&n);
//	ValleyAngle(n);
//	system("pause");
//	return 0;
//}
//


/*
3.日本著名数学游戏专家中村义作教授提出这样一个问题：父亲将2520个桔子分给六个儿子。
分完 后父亲说：“老大将分给你的桔子的1/8给老二；老二拿到后连同原先的桔子分1/7给老三；
老三拿到后连同原先的桔子分1/6给老四；老四拿到后连同原先的桔子分1/5给老五；老五拿到后
连同原先的桔子分1/4给老六；老六拿到后连同原先的桔子分1/3给老大”。结果大家手中的桔子
正好一样多。问六兄弟原来手中各有多少桔子？
*/

/*
分析、算法：
N:桔子总数;n1、n2、n3、n4、n5、n6:六个儿子手中原来的桔子;n:最终每人手中的桔子数；
n1+n2+n3+n4+n5+n6=N;
n=N/6;
n=(n1/8+n2)*6/7    //老二最终拿到的桔子
则未分给老三前手中的桔子：before2：(n1/8+n2)=n*7/6;
n=(before2/7+n3)*5/6   //老三最终拿到的桔子
则未分给老四前手中的桔子：before3：(before2/7+n3)=（n/6+n3)=n*6/5;则n3=n*(6/5-1/6);
n=(before3/6+n4)*4/5    //老四最终拿到的桔子
则未分给老五前手中的桔子：before4：(before3/6+n4)=n*5/4;则n4=n*(5/4-1/5);
...
利用最后一个孩子的桔子数再计算一、二个孩子的桔子数
*/

/*分桔子函数*/
/*将N个桔子分给j个孩子，老大将分的桔子的1/i给老二，老二拿到后连同原先的桔子分1/(i-1)给老三,以此类推...*/
int N = 2520;
int i= 8;
int m = 8;//用来记录i的初始值
int j = 6;
int k = 3;//第k个孩子
int before = 0;//拿到上一个人给的桔子但是还没有分出去；
int begin = 0;//最开始手中的桔子
void DivideOrange(int N, int i,int j){
	int n = N/j;//平均数
	if (k <=j){
		before = n*(i - 2) / (i - 3);//初始从老三开始；
		//printf("%d\n", before);
		begin = before - n/ (i - 2);
		printf("第%d个孩子手中原来手中有%d个桔子！\n",k,begin);
		i--;
		k++;
		DivideOrange(N, i, j);
	}
	if(k==j+1){
		int n1 =( n -before / (i - 1))*m/(m-1);
		int n2 = n * 7 / 6 - n1 / 8;
		printf("第1个孩子手中原来手中有%d个桔子！\n", n1);
		printf("第2个孩子手中原来手中有%d个桔子！\n", n2);
		k++;//防止再次进入递归
	}
}
void main(){
	DivideOrange(N,i,j);
	system("pause");
}