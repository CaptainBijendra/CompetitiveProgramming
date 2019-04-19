/*
ID: sunheco1
LANG: C
TASK: vans
*/
#include<stdio.h>

char str1[1024],str2[1024],str3[1024],str4[1024],str5[1024],strtmp[1024];

int len1,len2,len3,len4,len5;

void Initialize()
{
	len1=0;
	len2=len3=1;
	len4=2;
	str1[1]=0;
	str2[1]=2;
	str3[1]=4;
	str4[1]=2;
	str4[2]=1;
	len5=0;
	str5[1]=0;
}

int add(char *b,int lenb,char *a,int lena)
{
	int i,c,len,res;
	len=lena>lenb?lena:lenb;
	for(i=1,c=0;i<=len;i++)
	{
		res=a[i]+b[i]+c;
		a[i]=res%10;
		c=res/10;
	}
	if(c!=0)
	{
		a[i]=c;
		return i;
	}
	return len;
}

int sub(char *b,int lenb,char *a,int lena)
{
	int i;
	for(i=1;i<=lena;i++)
	{
		if(a[i]<b[i])
		{
			b[i+1]++;
			a[i]+=10;
		}
		a[i]-=b[i];
	}
	while(a[lena]==0)
		lena--;
	return lena;
}

void push()
{
	int i;
	len5=add(str1,len1,str5,len5);
	len5=add(str4,len4,str5,len5);
	len5=add(str4,len4,str5,len5);
	len5=add(str3,len3,str5,len5);
	len5=add(str3,len3,str5,len5);
	for(i=1;i<=len2;i++)
		strtmp[i]=str2[i];
	for(;i<1024;i++)
		strtmp[i]=0;
	len5=sub(strtmp,len2,str5,len5);
	for(i=1;i<=len2;i++)
		strtmp[i]=str2[i];
	for(;i<1024;i++)
		strtmp[i]=0;
	len5=sub(strtmp,len2,str5,len5);
	for(i=1;i<=len2;i++)
	{
		str1[i]=str2[i];
	}
	for(;i<1024;i++)
		str1[i]=0;
	len1=len2;
	for(i=1;i<=len3;i++)
	{
		str2[i]=str3[i];
	}
	for(;i<1024;i++)
		str2[i]=0;
	len2=len3;
	for(i=1;i<=len4;i++)
	{
		str3[i]=str4[i];
	}
	for(;i<1024;i++)
		str3[i]=0;
	len3=len4;
	for(i=1;i<=len5;i++)
	{
		str4[i]=str5[i];
	}
	for(;i<1024;i++)
		str4[i]=0;
	len4=len5;
	len5=0;
	for(i=1;i<1024;i++)
		str5[i]=0; 
}

int main()
{
	int i,N;
	FILE *fin  = fopen ("vans.in", "r");
    FILE *fout = fopen ("vans.out", "w");
	fscanf(fin,"%d",&N);
	switch(N)
	{
	case 1:
		fprintf(fout,"0\n");
		return 0;
	case 2:
		fprintf(fout,"2\n");
		return 0;
	case 3:
		fprintf(fout,"4\n");
		return 0;
	case 4:
		fprintf(fout,"12\n");
		return 0;
	default:
		Initialize();
		break;
	}

	N-=4;
	while(N)
	{
		push();
		N--;
	}
	for(i=len4;i>=1;i--)
	{
		fprintf(fout,"%d",(int)str4[i]);
	}
	fprintf(fout,"\n");
	return 0;
}