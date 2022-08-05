#include "lists.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size(list l) {
    if(l == NULL)
        return 0;
    else
        return 1 + size(l -> next);
}

list add(list l, char *new_data) {
    if(l == NULL) {
        struct node *tmp = malloc(sizeof(struct node));
        tmp -> data = new_data;
        tmp -> next = l;
        return tmp;
    } else {
        l -> next = add(l -> next, new_data);
        return l;
    }
}

list delete(list l, char *to_delete) {
    if(l != NULL) {
        if(l -> data == to_delete) {
            list tmp = l;
            l = l -> next;
            free(tmp);
        } else l -> next = delete(l -> next, to_delete);
    }
    return l;
}

list search(list l, char *query) {
    if(l == NULL || !strcmp(l -> data, query))
        return l;
    else
        return search(l -> next, query);
}

void print(list l) {
    if (l == NULL)
        printf("END\n");
    else {
        printf("%s -> ", l -> data);
        print(l -> next);
    }
}