#include <stdio.h>

int sorting_function(int *arr, int arr_len)
{	if(arr && arr_len)
	{	int jump,i,j;
		for(jump=arr_len/2;jump>0;jump/=2)
		{	for (i=jump; i<arr_len;i++)
			{	int q;
				q=arr[i];
				for(j=i; j>=jump;j-=jump)
				{	if (q<arr[j-jump]) arr[j]=arr[j-jump];
					else break;
				}
			arr[j]=q;
			}
		}
	}
return 0;}

int main()
{	int n,i,x;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);}
	sorting_function(a,n);
	for(i=0;i<n;i++)
	{ if(i!=i-1) printf("%d ",a[i]);
	else printf("%d",a[i]);}
printf("\n");
return 0;}
