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