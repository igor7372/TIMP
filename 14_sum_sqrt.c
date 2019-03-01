#include <stdio.h>
int main()
{
int n,i,x,s=0;
scanf("%d", &n);
for (i=1;i<=n;i++)
{
scanf("%d", &x);
s=s+(i % 2)*x*x;
}
printf("%d\n", s);
return 0;
}
