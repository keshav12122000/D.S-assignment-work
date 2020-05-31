#include<stdio.h>
#include<stdlib.h>

int main()
 {
   int n,*p;
   printf("enter no of elements you want to enter\n");
   scanf("%d",&n);
   p=(int *)malloc(n*sizeof(int));
   printf("enter elements\n");
   for(int i=0;i<n;i++)
   {
       scanf("%d",&p[i]);
   }
   for(int j=1;j<n;j++)
   {
    int x=p[j];
    for(int temp=j-1;temp>=0;temp--)
{
    if(x<p[temp])
    {
    p[temp+1]=p[temp];
    p[temp]=x;
    }
    else
    break;
}
return 0;
   }
for(int x=0;x<n;x++)
{
printf("%d",p[x]);
}
}
