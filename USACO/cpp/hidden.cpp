/*
ID:wx539181
PROG:hidden
LANG:C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char mu[222222],m2[222222];
int L,l,com=0;
int wx(int I,int J)
{
    for(com=0;com<L;com++)
    if(mu[I+com]>mu[J+com])
                        return 1;
    else if(mu[I+com]<mu[J+com])
                             return -1;
    printf("0\n");
    exit(0);
}
int main()
{
     freopen("hidden.in","r",stdin);
    freopen("hidden.out","w",stdout);
    int i,j,k=0;
    scanf("%d%c",&L,&mu[0]);
    while(scanf("%c",&mu[k++])==1)
     if(mu[k-1]=='\n')k--;
    mu[k-1]=0;
    strcpy(m2,mu);
    l=strlen(mu);
    strcpy(mu+l,m2);
    l=strlen(mu);
    mu[l]='z'+1;
    i=0;j=1;
    while(j<=l/2)
    {
     if(wx(i,j)>0){
                   i=j;
                   j++;
                   }
 
     else {
           if(com==0)com++;j+=com;
           }
    }
    printf("%d\n",i);
    return 0;
}