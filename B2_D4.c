#include <stdio.h>

int Cal (int l, int r)
{
	int XOR = l ^ r;
	int count = 0;
	for (int temp = XOR; temp > 0; temp >> 1)
	{
		printf("%d\n", temp);
		count ++;
	}
	return ( (1<<count) - 1);
}

int main()
{
	printf("KQ: %d", Cal(10,12));
}
