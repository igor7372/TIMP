#include <stdio.h>
#include <stdlib.h>

//куча
void sift(int *num,int root,int bot)
{	int maxI, done=0;
	while ((root*2<=bot)&&(!done))
	{	if (root*2==bot) maxI=root*2;
		else if (num[root*2]>num[root*2+1]) maxI=root*2;
			else maxI=root*2+1;
		if (num[root]<num[maxI])
		{	int q=num[root];
			num[root]=num[maxI];
			num[maxI]=q;
			root=maxI;}
		else done=1;}
}
//сортировка кучи
void sorting_function(int *arr,int arr_len)
{	int i;
	for (i=(arr_len/2)-1;i>=0;i--) sift(arr,i,arr_len-1);
	for (i=arr_len-1;i>=1;i--)
	{	int q=arr[0];
		arr[0]=arr[i];
		arr[i]=q;
		sift(arr,0,i-1);}
}
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
