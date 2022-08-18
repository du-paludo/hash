#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {

    // arrayItem_t *array = malloc(sizeof(arrayItem_t) * M);
    int *t1 = malloc(sizeof(int) * M);
    int *t2 = malloc(sizeof(int) * M);

    int value;
    
    /* printf("o que voce que?\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d" , &value);
        insert(value, array);
    } */

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
			// remove(t1, t2, value);
		}
		scanf("%c", &c);
	}
	print_hash(t1, t2);
    delete_hash(t1, t2);
	return 0;
}