#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {

    // arrayItem_t *array = malloc(sizeof(arrayItem_t) * M);
    // int *t1 = malloc(sizeof(int) * M);
    // int *t2 = malloc(sizeof(int) * M);

	node_t** t1 = init_hash();
	node_t** t2 = init_hash();
	node_t** aux = init_aux();

    int value;

	char c;
	scanf("%c", &c);
	while (!feof(stdin))
	{
		if (c == 'i')
		{
			scanf(" %d", &value);
			insert(t1, t2, value);
		}
		else if (c == 'r')
		{
			scanf(" %d", &value);
			remove_value(t1, t2, value);
		}
		scanf("%c", &c);
	}
	sort(t1,t2,aux);
	print(aux);
    delete_hash(t1);
	delete_hash(t2);
	delete_aux(aux);	
	return 0;
}