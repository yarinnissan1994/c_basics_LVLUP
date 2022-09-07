#include <stdio.h>
#pragma warning(disable : 4996)

int main1()
{
    int a = 65535;
	int b = sizeof(int)*8;
	a = a << 31;
	a = a << 1;
	printf("%d", a);
	/*while (a != 0)
	{
		a <<= 1;
	}
	printf("%d", a);*/

    return 0;
}
