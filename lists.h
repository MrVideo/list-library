#ifndef LISTS_H
#define LISTS_H

// Node structure
struct node {
    char *data;
    struct node *next;
};

// List type definition
typedef struct node *list;

// Function signatures
int size(list l);
list add(list l, char *new_data);
list delete(list l, char *to_delete);
list search(list l, char *query);
void print_inline(list l);
void print_newline(list l);
list add_sort(list l, char *new_data);
list duplicate(list l);

#endif //LISTS_H
