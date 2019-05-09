#include <stdio.h>

int *sorting_function(int *arr, int arr_len)
{	if(arr && arr_len)
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
				}
			}
		}
	}
return 0;}

int main()
{	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);}
	sorting_function(a,n);
	for(i=0;i<n;i++)
	{	if(i!=n-1) printf("%d ",a[i]);
		else printf("%d",a[i]);}
printf("\n");
return 0;}
