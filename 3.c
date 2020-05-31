//SORT THE STRINGS USING MERGE SORT IN INCREASING ORDER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
void mergesorting(char* arr[],int low,int high) //Merge Sort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesorting(arr,low,mid);//function call
        mergesorting(arr,mid+1,high);
        mergefunction(arr,low,mid,high);
    }
}
void mergefunction(char* arr[],int low,int mid,int high) //Merging function
{
    int i;
    int x= mid-low+1;
    int y= high-mid;

    char** t1=malloc(sizeof(char *)*x);
    char** t2=malloc(sizeof(char *)*y);
    for(i=0;i<x;i++)
    {
        t1[i]=malloc(sizeof(arr[low+i]));
        strcpy(t1[i],arr[low+i]);
    }
    for(i=0;i<y;i++)
    {
        t2[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(t2[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;//defining  or say initializing to be 0
    k=low;
    while((i<x)&&(j<y))
    {
        if(strcmp(t1[i],t2[j])<0)strcpy(arr[k++],t1[i++]);
        else strcpy(arr[k++],t2[j++]);
    }
    while(i<x)strcpy(arr[k++],t1[i++]);
    while(j<y)strcpy(arr[k++],t2[j++]);

}
int main()
{
    printf("\nEnter the no of alphabets contained in the string: \n");
    int size;  //array size of string
    scanf("%d",&size);

    char** arr= malloc(sizeof(char*)* size); //Creating required string array
    printf("\nInputting the alphabets of strings of the array: ");

    int i;
    for(i=0;i<size;i++)
    {
        arr[i]=malloc(sizeof(char)*MAX);
        printf("\n Enter the string of alphabets\n");
        scanf("%s",arr[i]);
    }
    mergesorting(arr,0,size-1);
    printf("\nThe resulted Sorted string in alphabetical order is:\n ");
    for(i=0;i<size;i++)\
    {
        printf("%s,",arr[i]);
    }
    return 0;

}
