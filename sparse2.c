#include<stdio.h>
int main()
{
int a[10][10];
int sa[10][3];
int ta[10][3];
int b[10][10];
int r,c,k,i,j;
printf("Enter the rows  :");
scanf("%d",&r);
printf("Enter the column  :");
scanf("%d",&c);

// matrix
for(i=0;i<r;i++)
  for(j=0;j<c;j++)
     scanf("%d",&a[i][j]);
     printf("MATRIX \n");
for(i=0;i<r;i++){
  for(j=0;j<c;j++){
     printf("%d\t",a[i][j]);}
     printf("\n");
     }
     
// sparse representation
 
k=1;
for(i=0;i<r;i++){
  for(j=0;j<c;j++){
  if(a[i][j]!=0)
  {
  sa[k][0]=i;
  sa[k][1]=j;
  sa[k][2]=a[i][j];
  k++;
  }
  }
  }

sa[0][0]=r;
sa[0][1]=c;
sa[0][2]=k-1;

printf("\nSPARSE MATRIX\n");
printf("\nrows\tcolumns\tnon zeros\n");
for(int i=0;i<=sa[0][2];i++){
for(int j=0;j<3;j++){
printf("%d\t",sa[i][j]);
}
printf("\n");}

//transpose

ta[0][0]=sa[0][1];
ta[0][1]=sa[0][0];
ta[0][2]=sa[0][2];
k=1;
for(i=0;i<sa[0][1];i++){
  for(j=0;j<=sa[0][2];j++){
  if(sa[j][1]==i){
  ta[k][0]=sa[j][1];
  ta[k][1]=sa[j][0];
  ta[k][2]=sa[j][2];
  k++;
  }
  }}
  printf("\nTRANSPOSED SPARSE MATRIX\n");
 printf("\ncolumns\trows\tnon zeros\n");
for(int i=0;i<=ta[0][2];i++){
for(int j=0;j<ta[0][1];j++){
printf("%d\t",ta[i][j]);
}
printf("\n");}

for(i=0;i<r;i++){
  for(j=0;j<c;j++){
     b[j][i]=a[i][j];}  }
     
     printf("\nTRANSPOSED MATRIX\n");
     
for(i=0;i<c;i++){
  for(j=0;j<r;j++){
     printf("%d\t",b[i][j]);}
      printf("\n");}
     
 
return 0;
}
