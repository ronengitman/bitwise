#include<stdio.h>
void bin32(unsigned n)
{
	unsigned i;
	for (i = 1 << 31; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}
void bin16(unsigned n)
{
	unsigned i;
	for (i = 1 << 15; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}
void bin8(unsigned n)
{
	unsigned i;
	for (i = 1 << 7; i > 0; i = i / 2)
		(n & i) ? printf("1") : printf("0");
	printf("\n");
}

int pack4Chars2Int(char c1, char c2, char c3, char c4) {
	unsigned i = 0 << 8;
	i = c1 | i;
	i = i << 8;
	i = c2 | i;
	i = i << 8;
	i = c3 | i;
	i = i << 8;
	i = c4 | i;
	return i;
}

int checkEvenParity(short input) {
	unsigned i;
	int count = 0;
	for (i = 1 << 15; i > 0; i = i / 2) {
		if(input & i) count++;
	}
	if (count % 2 == 1) return 1;
	return 0;
}

void main(void)
{	
	printf("j: ");
	bin8('j');
	printf("r: ");
	bin8('r');
	printf("b: ");
	bin8('b');
	printf("x: ");
	bin8('x');
	int a = pack4Chars2Int('j', 'r', 'b', 'x');
	printf("combined: ");
	bin32(a);
	printf("short num: ");
	bin16(1239);
	printf("checkEvenParity: %d", checkEvenParity(24));

}
