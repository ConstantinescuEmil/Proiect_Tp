#include"declarare_functii.h"
#include<stdio.h>
#include<stdlib.h>
void print(int *p)
{
	if(p[0]==1)return;
	int i=0;
	for(i=1;i<p[0];i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}
void wrtcb(unsigned char u,FILE*A)
{
	fwrite(&u,sizeof(char),1,A);
}


int main()
{
	int* v=NULL;
	int* rem=NULL;
	int* descris=NULL;
	int* decode=NULL;
	int i,j=0;
	unsigned char c=char(1),b;
	FILE *A,*B;
	/*
	//v=obt_vct_codat(unsigned char());
	//print(v);
	
	v=encrypt(unsigned char(120),4);
	//printf("%d",obt_char(v,4));
	v=(int*)realloc(v,(v[0]+1)*sizeof(int));
	v[0]++;v[v[0]-1]=9;
	scindare(&v,4);
	//printf("%d",v[0]);
	print(v);
	return 0;
	concat(&rem,&v);
	descris=impartire(v,&rem);
	print(descris);
	printf("\n");
	return 0;
	while(descris[0]>1)
	{
		printf("%d\n",int(char_codat(&descris)));
	}
	
	free(descris);
	restfin(&rem);
	print(rem);
	printf("%d\n",int(char_codat(&rem)));
	
	free(rem);
	*/
	/*
	A=fopen("in.txt","rb");
	B=fopen("out.txt","wb");
	while(fread(&c,sizeof(unsigned char),1,A))
	{
		v=encrypt(c,3);
		concat(&rem,&v);
		descris=impartire(v,&rem);
		while(descris[0]>1)
		{
			
			b=char_codat(&descris);
			fwrite(&b,sizeof(unsigned char),1,B);
			
		}
		free(descris);
	}
	restfin(&rem);
	b=char_codat(&rem);
	fwrite(&b,sizeof(unsigned char),1,B);
	print(rem);
	fclose(B);
	fclose(A);
	free(rem);
	*/
	
	A=fopen("out.txt","rb");
	B=fopen("decode.txt","wb");
	v=NULL;
	while(c!=unsigned char(0))
	{
		decode=(int*)malloc(sizeof(int));
		decode[0]=1;
		concat(&rem,&decode);
	while(verif_ok(decode,3)==0)
	{
		
		
		if(fread(&c,sizeof(unsigned char),1,A))
		{
			if(verif_ok(decode,3)==0)
			{
			v=obt_vct_codat(c);
			bag_vect_la_sf(&decode,v);
			}

		}
		else {c=unsigned char(0);break;}
	}
	while(verif_ok(decode,3)==1&&(!rest0(decode)))
	{
		b=obt_char(decode,3);
		fwrite(&b,sizeof(unsigned char),1,B);
		scindare(&decode,3);
		if(rest0(decode))c=unsigned char(0);
	}
	rem=(int*)malloc(sizeof(int));
	rem[0]=1;
	concat(&decode,&rem);
	}
	fclose(A);
	fclose(B);
	
}