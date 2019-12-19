#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void read(int *ptr, int  maxlines);
void swap(int *ptr, int ptr1, int ptr2);
int *bubblesort(int *ptr, int first, int last);
int *selectsort(int *ptr, int left, int right);
int *insertsort(int *ptr, int left, int right);
int *qqsort(int *ptr, int left, int right);
int *shelltsort(int *ptr, int left, int right);
void writelines(int *ptr, int nlines);
int main()
{
	int ptr[10000];
	read(ptr, 100000);
	return 0;
}

void read(int *ptr, int  maxlines)
{
	FILE *fp;
	int i;
	char store1[1000];
	int nlines = 0;
	char file_path[] = "E:\\x.txt";
	fp = fopen(file_path, "r");
	if ((fp) == NULL)
	{
		printf("Cannot open file!\n");
	}
	else
	{
		while (!feof(fp) && nlines <= 99)
		{
			i = 0;
			fgets(store1, 1000, fp);
			if (feof(fp))
			{
				break;
			}
			ptr[(nlines * 100) + i] = atoi(strtok(store1, "   "));//atoi可转换为int型
			for (i = 1; i < 99; i++)
			{
				ptr[(nlines * 100) + i] = atoi(strtok(NULL, "   "));
			}
			ptr[(nlines * 100) + i] = atoi(strtok(NULL, "\n"));//分行
			nlines++;
		}
		fclose(fp);
		writelines(ptr, nlines);
	}
}
void swap(int *ptr, int i, int j)
{
	int temp;
	temp = ptr[i];
	ptr[i] = ptr[j];
	ptr[j] = temp;
}
int *bubblesort(int *ptr, int first, int last)
{
	int i,j, time;
	clock_t start, finish;
	start = clock();
	for(i = first;i<last -first +1;i++)
	{
		for (j = first; j < last-i; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				swap(ptr, j, j + 1);
			}
		}
	}
	finish = clock();
	time = finish - start;
	printf("冒泡排序耗时：%dmilliceconds\n", time);
	return ptr;
}
int *selectsort(int *ptr, int left, int right)
{
	int i, j, min;
	int time;
	clock_t start, finish;
	start = clock();
	for (i = left; i < right; i++)
	{
		min = i;
		for (j = i + 1; j <= right; j++)
		{
			if (ptr[min] > ptr[j])
				min = j;
		}
		if (min != i)
			swap(ptr, min, i);
	}
	finish = clock();
	time = finish - start;
	printf("选择排序耗时：%dmilliceconds\n", time);
	return ptr;
}
int *insertsort(int *ptr, int left, int right)
{
	int i, j, temp, time;
	clock_t start, finish;
	start = clock();
    for (i = 1; i<right + 1; i++)
	{
		temp = ptr[i];
		j = i - 1;
		while ((j >= 0) && (temp < ptr[j])) 
		{
			ptr[j + 1] = ptr[j];
			j--;
		}
		ptr[j + 1] = temp;
	}
	finish = clock();
	time = (int)(finish - start);
	printf("直接插入排序耗时：%dmilliceconds\n", time);
	return ptr;
}
int *qqsort(int *ptr, int left, int right)
{
	clock_t start, finish;
	if (left >= right)
	{
		return 0;
	}
	int i = left;
	int j = right;
	int key = ptr[i];
	while (i < j)
	{
		while (i < j && key <= ptr[j])
		{
			j--;
		}
		ptr[i] = ptr[j];

		while (i < j && key >= ptr[i])
		{
			i++;
		}

		ptr[j] = ptr[i];
	}

	ptr[i] = key;
	qqsort(ptr, left, i - 1);
	qqsort(ptr, i + 1, right);
	return ptr;
}
int *shelltsort(int *ptr, int left, int right)
{
	int i, j, k, time,gap, temp;
	k = right + 1 - left;
	clock_t start, finish;
	start = clock();
	/*int gap = right / 2;
	while (gap > 0)
	{
		for (k = 0; k < gap; k++)
		{
			for (i = k + gap; i < right + 1; i += gap)
			{
				if (ptr[i] < ptr[i - gap])
				{
					temp = ptr[i];
					for (j = i - gap; j >= k && ptr[j] > temp; j -= gap)
					{
						ptr[j + gap] = ptr[j];
					}
					ptr[j + gap] = temp;
				}
			}
		}
		gap /= 2;
	}*/
	for (gap = k / 2; gap > 0; gap /= 2)
		for (i = gap; i < k; ++i)
			for (j = i - gap; j >= 0 && ptr[j] > ptr[j + gap]; j -= gap)
				swap(ptr, j, j + gap);
	finish = clock();
	time = (int)(finish - start);
	printf("希尔插入排序耗时：%dmilliceconds\n", time);
	return ptr;
}
void writelines(int *ptr, int nlines)
{
	FILE *STORE;
	char file_path1[] = "E:\\sorteddata.txt";
	int i, j ,v ;
	int store1[10000], store2[10000], store4[10000], store3[10000], store5[10000],time;
	/*scanf("%d", &v);*/
	for (i = 0; i < 10000; i++)
	{
		store1[i] = ptr[i];
		store2[i] = ptr[i];
		store3[i] = ptr[i];
		store4[i] = ptr[i];
		store5[i] = ptr[i];
	}
	clock_t start, finish;
	
	bubblesort(store1, 0, 9999);
	selectsort(store2, 0, 9999);
	insertsort(store3, 0, 9999);
	start = clock();
	qqsort(store4, 0, 9999);
	finish = clock();
	time = (int)(finish - start);
	printf("qsort算法排序耗时：%dmilliceconds\n", time);
	shelltsort(store5, 0, 9999);
	STORE = fopen(file_path1, "w+");
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j<100; j++)
			fprintf(STORE, "%7d", store5[i * 100 + j]); //store后的数字可以更改来对应不同的sort
		fprintf(STORE, "\n");//换行
	}
	fclose(STORE);
	printf("处理后的数据储存在:%s\n", file_path1);
}

