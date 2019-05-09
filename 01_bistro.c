#include <stdio.h>

int sorting_function(int *arr, int lef, int right)
{	int s,p,i,j;
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
				arr[j]=s;}
			i++;
			if (j>0) j--;
		}
	}while (i<=j);
	if (i<right) sorting_function(arr,i,right);
	if (j>lef) sorting_function(arr,lef,j);
return 0;}

int main()
{	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);}
	int lef=0;
	int right=n-1;
	sorting_function(a,lef,right);
	for(i=0;i<n;i++)
	{	if(i!=n-1) printf("%d ",a[i]);
		else printf("%d",a[i]);}
printf("\n");
return 0;}

