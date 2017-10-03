#include <stdio.h>
int main()
{
	int num, i;
    float a, b;
	i=0;
	while (i<5)
	{  printf("input num :\n");
     scanf("%d",&num);
    a=num%4;
    b=num%100;
	if(a==0&&b!=0)
		printf("yes\n");
	else
		printf("no\n");
	i++;}
return 0;
}