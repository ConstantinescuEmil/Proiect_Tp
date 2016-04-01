#include<stdlib.h>
#include<stdio.h>
#include"declarare_functii.h"
int* encrypt(unsigned char c,int k)//returneaza un vector cu codarea caracteruului c dupa exp k
{
	int *v=NULL;
	int p1=c>>k,p2=c&((1<<k)-1),u=p1+k+1,i=0;
	v=(int*)calloc((p1+2),sizeof(int));
	v[0]=p1+2;
	for(i=1;i<=p1+1;i++)
	{
		v[i]=1;
		if(i==(p1+1))v[i]=0;
	}
	v=(int*)realloc(v,(p1+2+k)*sizeof(int));
	v[0]+=k;
	for(i=p1+2;i<=p1+k+1;i++)
	{
		v[u]=p2&1;
		p2>>=1;
		u--;
	}
	return v;

}
void concat(int**rem,int**p)//concateneaza rem la p si sterge rem
{
	if((*rem)==NULL)return;
	if((*rem)[0]==1)return;
	int i,u=(*p)[0]+(*rem)[0]-2;
	(*p)=(int*)realloc((*p),((*p)[0]+(*rem)[0]-1)*sizeof(int));
	for(i=(*p)[0]-1;i>0;i--)
	{
		(*p)[u]=(*p)[i];
		u--;
	}
	for(i=1;i<(*rem)[0];i++)
	{
		(*p)[i]=(*rem)[i];
	}
	(*p)[0]=(*p)[0]+(*rem)[0]-1;
	free(*rem);
	return;
}
int* impartire(int *p,int**rem)//iparte returneaza descris multiplu de 8 si formeaza vectotul rem
{
	int *descris=NULL;
	int nr=(p[0]-1)/8,j=1,i=0;
	descris=(int*)malloc((1+nr*8)*sizeof(int));
	
	descris[0]=nr*8+1;
	for(i=1;i<descris[0];i++)
	{
		descris[i]=p[i];
	}
	
	
	(*rem)=(int*)malloc(((p[0]-1)%8+1)*sizeof(int));
	for(i=descris[0];i<p[0];i++)
	{
		(*rem)[j]=p[i];
		j++;
	}
	(*rem)[0]=j;
	free(p);
	return descris;
}
void restfin(int**rem)//realizeaza completarea restului final
{
	int i=0;
	(*rem)=(int*)realloc((*rem),9*sizeof(int));
	for(i=(*rem)[0];i<9;i++)
	{
		(*rem)[i]=0;
	}
	(*rem)[0]=9;
}
unsigned char char_codat(int **p)//transforma 0 secventa de biti si returneaza caracter
{
	int i=0,j=0,k=0;
	unsigned char u=char(0);
	if((*p)[0]>=9)
	{
		for(i=8;i>0;i--)
		{
			u=u+((*p)[i]<<(8-i));
		}
		for(i=9;i<(*p)[0];i++)
		{
			k++;
			(*p)[k]=(*p)[i];
		}
		(*p)[0]-=8;
	}
	return u;
}
int verif_ok(int *p,int k)//verifica daca in o secvevnta de biti poate fi un caracter codat corect
{
	if(p==NULL)return 0;
	if(p[0]==1)return 0;
	if(p[0]<9)return 0;
	int i,ok1=0,ok2=0;
	for(i=1;i<p[0];i++)
	{
		if(p[i]==0){ok1=1;break;}
	}
	if(i+k<=p[0]-1)ok2=1;
	return(ok1&&ok2);
}
int*  obt_vct_codat(unsigned char c)
{                                  
	
	int i=0,j;
	int *p=NULL;
	p=(int*)malloc(9*sizeof(int));
	if(int(c)==0){p[0]=1;return p;}
	p[0]=9;
	for(i=8;i>0;i--)
	{
		p[i]=c&1;
		c=c>>1;
	
		
	}
	
	return p;
}
unsigned char obt_char(int *p,int k)//danduise un vector returneaza caracterul daecodat
{
	unsigned char c=unsigned char(0);
	int i=1,u=0,j=0,rest=0;
	while(p[i]!=0){u++;i++;}
	c=u*(1<<k);
	for(j=i+1;j<=i+k;j++)
	{
		rest=(rest<<1)+p[j];
	}
	c=c+rest;
	return c;

}
//urmatoarea functie nu a fost testata in totlitate di cauza lipsei de date:
void scindare(int**p,int k)//danduise un vector cu un caracter valid si un rest izoleaza restul.
{
	int i=1,u=0,j=0,fin=0;;
	while((*p)[i]!=0){i++;}
	fin=i+k;
	u=1;
	for(j=fin+1;j<(*p)[0];j++)
	{
		(*p)[u]=(*p)[j];
		u++;
	}
	(*p)[0]=(*p)[0]-fin;
}
void bag_vect_la_sf(int **p,int *v)
{
	if((*p)==NULL)
	{
		(*p)=(int*)malloc(sizeof(int));
		(*p)[0]=1;
		bag_vect_la_sf(p,v);
		return;
	}
	int i=0,j=1;
	(*p)=(int*)realloc((*p),sizeof(int)*((*p)[0]+8));
	for(i=(*p)[0];i<=8+(*p)[0]-1;i++)
	{
		(*p)[i]=v[j];
		j++;
	}
	(*p)[0]+=8;
	free(v);
}
int rest0(int*p)
{
	int i=0;
	if(p[0]==1)return 0;
	for(i=1;i<p[0];i++)if(p[i]!=0)return 0;
	return 1;
}