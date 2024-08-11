#include<stdio.h>
#define MAX 100

int s[MAX],x[MAX],d;

void sumofsub(int p , int k , int r){
    int i;
    x[k]=1;
    if((p+s[k])==d){
        for(i=1;i<=k;i++)
        if(x[i]==1)
        printf("%d",s[i]);
        printf("/n");
    }

    else
    if((p+s[k]+s[k+1])<=d)
    sumofsub(p+s[k],k+1,r-s[k]);
    if((p+r-s[k]>=d)&&(p+s[k+1]<=d)){
        x[k]=0;
        sumofsub(p,k+1,r-s[k]);
    }

}

int main(){
    int sum=0,n,i,j;
     printf("\n enter the total number of elements");
     scanf("%d",&n);
     printf("\n enter the elements in increasing order");
     for(i=1;i<=n;i++)
     scanf("%d",&s[i]);
     printf("\n enter the sum needed");
     scanf("%d",&d);
     for(i=1;i<=n;i++)
     sum=sum+s[i];
     if(sum<d || s[1]>d)
     printf("\n no sub sets");
     else
      sumofsub(1,0,sum);
     return 0;
     
     }