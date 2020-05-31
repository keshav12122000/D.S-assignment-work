//QUICK SORT
#include<stdio.h>
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
int partition (int arr[], int x1, int x2)
{
int pivot = arr[x2];
int i = (x1 - 1);
for (int j = x1; j <= x2- 1; j++)
{
if (arr[j] <= pivot)
{
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[x2]);
return (i + 1);
}
void quickSort(int arr[], int x1, int x2)
{
if (x1 < x2)
{
int pi = partition(arr, x1, x2);
quickSort(arr, x1, pi - 1);
quickSort(arr, pi + 1, x2);
}
}
void printArray(int arr[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}
int main()
{
int arr[1000];
int n = sizeof(arr)/sizeof(arr[0]);
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
quickSort(arr, 0, n-1);
printf("The sorted array is:");
printArray(arr, n);
return 0;
}
