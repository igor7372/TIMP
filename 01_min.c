#include <stdio.h>
int main()
{
int i,n,x,min=999999;
scanf("%d", &n);
for (i=0;i<n;i++)
{
scanf("%d", &x);
if (x<min) min=x;
}
printf("%d\n", min);
return 0;
}
