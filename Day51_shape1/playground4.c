#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=n; i>0; i--)
	{
		int point=i-1;
		for(int j=0; j<n; j++)
		{
			if(point){
				printf(" ");
				point--;
				continue;
			}
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}
