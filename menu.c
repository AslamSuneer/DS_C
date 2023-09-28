#include<stdio.h>
void linearS(int n,int a[]);
void binaryS(int n,int a[]);
void main()
{
int a[10],n,i,cho;
printf("Enter the size of array");
scanf("%d",&n);
printf("Enter the element of array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
do{
printf("\n Select the Menu\n");
printf("1.Linear Search\n");
printf("2.Binary Search\n");
printf("3.Exit\n");
printf("Enter the choice: ");
scanf("%d",&cho);
switch(cho)
{
case 1:linearS(n,a);
break;
case 2:binaryS(n,a);
break;
default:break;
}
}while(choice<3);
}

void linearS(int n,int a[]){
int key,i,flag=1;
printf("Enter the element to be search: ");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(a[i]==key)
{
flag=i+1;
break;
}
}
if(flag!=1)
{
printf("Searched element is at position%d",flag);
}
else{
printf("Element is not found\n");
}

void binaryS(int n,int a[])
{
int i,j,key,temp=0,low,high,flag=0,mid;
for(i=0;i<n-1;i++)
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1]
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
printf("array is sorted as")
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
printf("\n Enter the element to search:\n");
scanf("%d",&key);
high=n-1,low=0;
while(low<=high)
{
mid=low+high/2;
if(a[mid]==key)
{
flag=1;
break;
}
else if(a[mid]>key){
high=mid-1;
}
else{
low=mid+1;
}
if(flag==0)
printf("Element not found");
else
print("Element is in position%d",flag+1);
}