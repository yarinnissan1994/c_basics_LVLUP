#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)

void testCopy(char* src, char* dst)
{
	int sum = 0;
	int read = 1;
	int write;
	char dummy;
	FILE* f = fopen(src, "r");
	if (!f)
	{
		//ERROR
		return;
	}
	else
	{
		while (read > 0)
		{
		read = fread(&dummy, sizeof(char), 1, f);
		sum = sum + read;
		}
		fclose(f);
	}
	char* memory = (char*) malloc(sizeof(char) * sum);
	f = fopen(src, "r");
	if (!f)
	{
		//ERROR
		return;
	}
	else
	{
			read = fread(memory, sizeof(char), sum, f);
	}
	fclose(f);
	f = fopen(dst, "w");
	if (!f)
	{
		//ERROR
		return;
	}
	else
	{
		write = fwrite(memory, sizeof(char), sum, f);
	}
	fclose(f);
	free(memory);
}

int main(int argc, char* argv[])
{
	testCopy(argv[1], argv[2]);
	return 0;
}