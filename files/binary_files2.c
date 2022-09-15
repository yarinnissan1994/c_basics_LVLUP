#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning (disable : 4996)

typedef struct OskarActor {
	int index;
	int year;
	int age;
	int popolarity;
	char name[1000];
	char movie[1000];
	struct OskarActor* next;
	struct OskarActor* prev;
}t_OskarActor;

typedef struct OskarActor_Header {
	int version;
	int actorCount;;
	char reserve[1000];
}t_OskarActor_Header;

t_OskarActor* head = NULL;
t_OskarActor* tail = NULL;

int itemCount = 0;

struct color
{
	char R;
	char G;
	char B;
};

int main() 
{
	FILE* f;
	t_OskarActor_Header h;
	h.version = 1;
	h.actorCount = 90;
	fwrite(&h, sizeof(t_OskarActor_Header), 1, f);
	for (int i = 0; i < 90; i++)
	{
		//fwrite(&h, sizeof(t_OskarActor), 1, f);
	}
	return 0;
}