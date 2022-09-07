#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<limits.h>
#pragma warning(disable : 4996)
/* hm1
void binaryFormat(unsigned char num)
{
    unsigned char mask = 0b10000000;
    for (int i = 0; i < 8; i++)
    {
        (mask & num) != 0 ? printf("1") : printf("0");
        mask >>= 1;
    }
}
*/

/* hm2
void binaryFormat(unsigned char num) {
    unsigned char mask = 0b10000000;
    for (int i = 0; i < 8; i++) {
        (mask & num) != 0 ? printf("1") : printf("0");
        mask >>= 1;
    }
    printf("\n");

}


void setBit(unsigned char* p, int bitIndex) {

    for (int i = 0; i < bitIndex - 1; i++) {
        (*p) <<= 1;
    }
}
*/

    int main()
{
    /* hm1
    int bitIndex;
    unsigned char binNum;
    binNum = 0b00000001;
    printf("Insert bit index from right to left:");
    scanf("%d", &bitIndex);
    for (int i = 0; i < bitIndex - 1; i++) {
        binNum <<= 1;
    }
    binaryFormat(binNum);
    */

    /* hm2
    int bitIndex;
    unsigned char binNum,finalBin;
    binNum = 0b00000001;
    unsigned char* p=&binNum;
    char op=0;

    finalBin=(*p)^(*p);
    binaryFormat(finalBin);
    printf("Insert bit index from right to left:");
    scanf("%d",&bitIndex);
    while(bitIndex!=-1)
    {
    setBit(p,bitIndex);
    finalBin^=(*p);
    binaryFormat(finalBin);
    binNum = 0b00000001;
    printf("Insert bit index from right to left:");
    scanf("%d",&bitIndex);
    }
    */

	return 0;
}