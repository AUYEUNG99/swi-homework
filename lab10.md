# 冒泡排序
```c
int main() {
	int temp = 0;
	int arr[5] = {5,9,8,4,1};
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
/*	for (int i = 0; i < 5; ++i)
		printf("%d",arr[i]);*/
}
```
# 希尔排序
```c
#include<stdio.h>
//    进行插入排序
//    初始时从dk开始增长，每次比较步长为dk
void Insrtsort(int *a, int n,int dk) {
    for (int i = dk; i < n; ++i) {
        int j = i - dk;
        if (a[i] < a[j]) {    //    比较前后数字大小
            int tmp = a[i];        //    作为临时存储    
            a[i] = a[j];
            while (a[j] > tmp) {    //    寻找tmp的插入位置
                a[j+dk] = a[j];
                j -= dk;
            }
            a[j+dk] = tmp;        //    插入tmp
        }
    }
}

void ShellSort(int *a, int n) {
    int dk = n / 2;        //    设置初始dk
    while (dk >= 1) {
        Insrtsort(a, n, dk);
        dk /= 2;
    }
}

int main() {
    int a[] = { 5,12,35,42,11,2,9,41,26,18,4 };
    int n = sizeof(a) / sizeof(int);
    ShellSort(a, n);
    printf("排序好的数组为：");
    for (int j = 0; j < n; j++) {
        printf("%d ", a [j]);
    }
    return 0;
}
```
# 直接选择排序
```c
#include<stdio.h>
void SelectSort(int *a, int n) {
    for (int i = 0; i < n; i++)
    {
        int key = i;    //    临时变量用于存放数组最小值的位置
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[key]) {    
                key = j;    //    记录数组最小值位置
            }
        }
            if (key != i)
            {
                int tmp = a[key]; a[key] = a[i]; a[i] = tmp;    //    交换最小值
            }
        
    }
}
int main() {
    int a[] = { 12,4,15,2,6,22,8,10,1,33,45,24,7 };
    int n = sizeof(a) / sizeof(int);
    SelectSort(a, n);
    printf("排序好的数组为： ");
    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);
    printf("\n");
    return 0;
}
```
