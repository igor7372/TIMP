#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ras4eska(int *arr, int arr_len)
{	int k=0;
	if(arr && arr_len)
	{	int jump = arr_len,i,swap=1;
		while (jump>1 || swap)
		{	if (jump>1) jump/=1.24733;
			swap=0;
			for (i=0; i+jump<arr_len;i++)
			{	if (arr[i+jump]>arr[i])
				{	int q;
					q=arr[i];
					arr[i]=arr[i+jump];
					arr[i+jump]=q;
					swap=1;
					k++;
				}
			k++;
			}
		}
	}
return k;}

int shella(int *arr, int arr_len)
{	int k2=0;
	if(arr && arr_len)
	{	int jump,i,j;
		for(jump=arr_len/2;jump>0;jump/=2)
		{	for (i=jump; i<arr_len;i++)
			{	int q;
				q=arr[i];
				for(j=i; j>=jump;j-=jump)
				{	if (q<arr[j-jump]) {arr[j]=arr[j-jump]; k2++;}
					else break;
					k2++;
				}
			arr[j]=q;
			}
		}
	}
return k2;}

int bistro(int *arr, int lef, int right)
{	int s,p,i,j,k3=0;
	i=lef;
	j=right;
	p=arr[(lef+(right-lef)/2)];
	do
	{	while (arr[i]<p) i++;
		while (arr[j]>p) j--;
		if (i<=j)
		{	if (arr[i]>arr[j])
			{	s=arr[i];
				arr[i]=arr[j];
				arr[j]=s;
				k3++;}
			i++;
			if (j>0) j--;
		}
		k3++;
	}while (i<=j);
	if (i<right) bistro(arr,i,right);
	if (j>lef) bistro(arr,lef,j);
return k3;}

int sift(int *num,int root,int bot)
{	int maxI, done=0, k=0;
	while ((root*2<=bot)&&(!done))
	{	if (root*2==bot) maxI=root*2;
		else if (num[root*2]>num[root*2+1]) maxI=root*2;
			else maxI=root*2+1;
		if (num[root]<num[maxI])
		{	int q=num[root];
			num[root]=num[maxI];
			num[maxI]=q;
			root=maxI;
			k++;}
		else {done=1; k++;}}
return k;}
//сортировка кучи
int piramid(int *arr,int arr_len)
{	int i, k=0;
	for (i=(arr_len/2)-1;i>=0;i--) k+=sift(arr,i,arr_len-1);
	for (i=arr_len-1;i>=1;i--)
	{	int q=arr[0];
		arr[0]=arr[i];
		arr[i]=q;
		k++;
		k+=sift(arr,0,i-1);}
return k;}

int main ()
{	clock_t TIME, full_time;
	int i,j,q,p;
	int len[15]={1,2,3,4,5,10,15,20,25,30,50,75,100,250,500};
	for(p=0;p<4;p++)
{ if(p==0) printf("ИССЛЕДОВАНИЕ РАСЧЕСТКИ\n");
  else if (p==1) printf("ИССЛЕДОВАНИЕ ШЕЛЛА\n");
  else if (p==2) printf("ИССЛЕДРВАНИЕ БЫСТРОЙ СОРТИРОВКИ\n");
  else printf("ИССЛЕДОВАНИЕ ПИРАМИДАЛЬНОЙ СОРТИРОВКИ\n");
	for (i=0;i<15;i++)
	{	full_time=0;
		int k=0;
		int n=len[i];
		int *a=malloc(n*sizeof(int));
		srand(time(NULL));
		for (j=0;j<1000;j++)
		{	for (q=0;q<n;q++)
			{	a[q]=rand()%1000-500;}
			TIME=clock();
			if(p==0) k+=ras4eska(a,n);
			else if (p==1) k+=shella(a,n);
			else if (p==2) { int lef=0;
					int right=n-1;
					k+=bistro(a,lef,right);}
			else k+=piramid(a,n);
			TIME=clock()-TIME;
			full_time+=TIME; }
		printf("Количество элементов: %d\n",n);
		printf("Общее время: %f\n",(double)full_time/CLOCKS_PER_SEC);
		printf("Среднее время: %f\n",(double)full_time/CLOCKS_PER_SEC/1000);
		printf("Общее количество операций: %d\n",k);
		printf("Среднее количество операций: %d\n",k/1000);
		printf("------\n");
		free(a); }
}

for(p=0;p<4;p++)
{ if(p==0) printf("ИССЛЕДОВАНИЕ РАСЧЕСТКИ\n");
  else if (p==1) printf("ИССЛЕДОВАНИЕ ШЕЛЛА\n");
  else if (p==2) printf("ИССЛЕДРВАНИЕ БЫСТРОЙ СОРТИРОВКИ\n");
  else printf("ИССЛЕДОВАНИЕ ПИРАМИДАЛЬНОЙ СОРТИРОВКИ\n");
	int k=0;
	int n=100;
	int max=0,min=1000000;
	int *a=malloc(n*sizeof(int));		
	for (j=0;j<1000;j++)
			{	for (q=0;q<n;q++)
				{	a[q]=rand()%1000-200;}
				if(p==0) 
				{ k=ras4eska(a,n);
					if (k>max) max=k;
					if (k<min) min=k;}
				else if (p==1) 
				{ k=shella(a,n);
					if (k>max) max=k;
					if (k<min) min=k;}
				else if (p==2) 
					{ int lef=0;
					  int right=n-1;
					k=bistro(a,lef,right);
					if (k>max) max=k;
					if (k<min) min=k;}
				else {k=piramid(a,n);
					if (k>max) max=k;
					if (k<min) min=k;}
			}
		printf("Лучший результат: %d\n",min);
		printf("худший результат: %d\n",max);
free(a); 		
}
return 0;}
