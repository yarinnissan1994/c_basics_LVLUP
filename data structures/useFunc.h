int Biggest(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

typedef struct s_item {
	int key;
	int val;
	struct s_item* next;
	struct s_item* prev;
} t_item;

typedef struct s_item2 {
	int key;
	int val;
	int id;
	struct s_item2* next;
	struct s_item2* prev;
} t_item2;

typedef struct {
	int version;
	int serialNum;
	int itemsCount;
	char reserve[100];
} t_headerFile;