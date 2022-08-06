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

list add_sort(list l, char *new_data) {
    list prev = NULL, curr = l;

    //If the list is empty, add the element on top.
    if(l == NULL) {
        list tmp = malloc(sizeof(struct node));
        tmp -> data = new_data;
        tmp -> next = l;
        return tmp;
    } else {
        //If the list is not empty
        while(curr != NULL) {
            //If new_data comes before the current node's data then add it before curr
            if(strcmp(new_data, curr -> data) < 0) {
                list tmp = malloc(sizeof(struct node));
                tmp -> data = new_data;
                tmp -> next = curr;
                //If the item goes in the first position, do not try to connect the previous node to it
                //Otherwise, do it
                if(prev != NULL) {
                    prev -> next = tmp;
                    return l;
                } else return tmp;
                //If the strings are the same, add it in the next node (it keeps the algorithm stable)
            } else if(strcmp(new_data, curr -> data) == 0) {
                prev = curr;
                curr = curr -> next;
                list tmp = malloc(sizeof(struct node));
                tmp -> data = new_data;
                tmp -> next = curr;
                prev -> next = tmp;
                return l;
                //Otherwise, just keep searching the list
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
        //If the list is over and nothing was added to it, the item goes in last
        if(curr == NULL && prev != NULL) {
            list tmp = malloc(sizeof(struct node));
            tmp -> data = new_data;
            tmp -> next = curr;
            prev -> next = tmp;
            return l;
        }
    }
    //This gets executed in case of an error
    return NULL;
}