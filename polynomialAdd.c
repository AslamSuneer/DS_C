#include<stdio.h>
struct add{
int deg,poly;
}
p1[50],p2[50],result[50],swap;
void main()
{
int n1,n2;
printf("Enter the no of terms of 1st polynomial:");
scanf("%d",&n1);
for(int i=0;i<n1;i++)
{
printf("Enter the degree of %d term ",i+1);
scanf("%d",&p1[i].deg);
printf("Enter the coefficient ");
scanf("%d",&p1[i].poly);
}for (int i=0;i<n1-1;i++){
for(int j=0;j<n1-1;j++){
if(p1[j].deg<p1[j+1].deg)
{
swap=p1[j];
p1[j]=p1[j+1];
p1[j+1]=swap;}
}
}
printf("Enter the no of of 2nd polynomial: ");
scanf("%d",&n2);
for(int i=0;i<n2;i++){
printf("Enter the degree of %d term ",i+1);
scanf("%d",&p2[i].deg);
printf("Enter the coefficient ");
scanf("%d",&p2[i].poly);
}
for (int i=0;i<n2-1;i++){
for(int j=0;j<n2-1;j++){
if(p2[j].deg<p2[j+1].deg)
{
swap=p2[j];
p2[j]=p2[j+1];
p2[j+1]=swap;}
}
}
int i=0,j=0,k=0;
while(i<n1&&j<n2){
if(p1[i].deg==p2[j].deg)
{
result[k].poly=p1[i].poly+p2[j].poly;
result[k].deg=p1[i].deg;
i++;
j++;
k++;
}
else if(p1[i].deg>p2[j].deg){
result[k].poly=p1[i].poly;
result[k].deg=p1[i].deg;
i++;
k++;
}
else{
result[k].poly=p2[j].poly;
result[k].deg=p2[j].deg;
j++;
k++;
}
}
while(i<n1){
result[k].poly=p1[i].poly;
result[k].deg=p1[i].deg;
i++;
k++;
}
while(j<n2)
{
result[k].poly=p2[j].poly;
result[k].deg=p2[j].deg;
j++;
k++;
}
printf("1st polynomial:\n");
int l=0;
while(l<i-1)
{
printf("%dx^%d\t+\t",p1[l].poly,p1[l].deg);
l++;
}
if(p1[l].deg==0)
printf("%d\n",p1[l].poly);
else
printf("%dx^%d\n",p1[l].poly,p1[l].deg);
printf("2nd polynomial:\n");
int m=0;
while(m<j-1){
printf("%dx^%d\t+\t",p2[m].poly,p2[m].deg);
m++;
}
if(p2[m].deg==0)
printf("%d\n",p2[m].poly);
else
printf("%dx^%d\n",p2[m].poly,p2[m].deg);
printf("sum\n");
int n=0;
while(n<k-1)
{
if(result[n].poly==0)
printf(" ");
else
{
printf("%dx^%d\t+\t",result[n].poly,result[n].deg);
n++;
}
}
if(result[n].deg==0)
printf("%d\n",result[n].poly);
else
printf("%dx^%d\n",result[n].poly,result[n].deg);
}
