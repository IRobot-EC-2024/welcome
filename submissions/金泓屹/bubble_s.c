#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int n=0,m=0,t=0;
	printf("输入需要排序的数字个数：");
	scanf("%d",&n);
	t = n-1;
	int sz[10] = { 0 };
	int h,j, k;
	int i;
	//输入
	while (t >= 0) {
		printf("输入需要排序的数字%d（空格隔开）：",t+1);
		scanf("%d",&m);
		sz[t] = m;
		t -= 1;
	}
	//冒泡
	for (h = 0; h < n - 1;h++) {
		for (j = 0; j < n-h-1; j++) {
			if (sz[j + 1] < sz[j]) {
				k = sz[j + 1];
				sz[j + 1] = sz[j];
				sz[j] = k;
			}
		}
	}
	//输出
	for (i = 0; i < n; i++) {
		printf("%d", sz[i]);
			}	
	}