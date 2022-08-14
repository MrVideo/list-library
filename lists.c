#include "lists.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size(list l) {
    list curr = l;
    int i = 0;
    while(curr != NULL) {
        ++i;
        curr = curr -> next;
    }
    return i;
}

list add(list l, char *new_data) {
    list curr = l, prev = NULL;
    if(curr == NULL) {
        list tmp = malloc(sizeof(struct node));
        tmp -> data = strdup(new_data);
        tmp -> next = l;
        return tmp;
    } else {
        while(curr != NULL) {
            prev = curr;
            curr = curr -> next;
        }
        list tmp = malloc(sizeof(struct node));
        tmp -> data = strdup(new_data);
        tmp -> next = NULL;
        if(prev != NULL)
            prev -> next = tmp;
        return l;
    }
}

list delete(list l, char *to_delete) {
    list curr = l, prev = NULL;
    if(curr == NULL)
        return NULL;
    while(curr != NULL) {
        if(strcmp(curr -> data, to_delete) == 0) {
            list tmp = curr;
            curr = curr -> next;
            if(prev != NULL)
                prev -> next = curr;
            free(tmp);
            if(prev != NULL) return l;
            else return curr;
        }
        prev = curr;
        curr = curr -> next;
    }
    return l;
}

list search(list l, char *query) {
    list curr = l;
    while(curr != NULL) {
        if(strcmp(curr -> data, query) == 0)
            return curr;
        curr = curr -> next;
    }
    return NULL;
}

void print_inline(list l) {
    list curr = l;
    while(curr != NULL) {
        printf("%s -> ", curr -> data);
        curr = curr -> next;
    }
    printf("END\n");
}

void print_newline(list l) {
    list curr = l;
    while(curr != NULL) {
        printf("%s\n", curr -> data);
        printf("|\n");
        curr = curr -> next;
    }
    printf("END\n");
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

list duplicate(list l) {
    list curr = l, prev = NULL, head = NULL;
    while(curr != NULL) {
        list tmp = malloc(sizeof(struct node));
        tmp -> data = strdup(curr -> data);
        tmp -> next = NULL;
        if(head == NULL)
            head = tmp;
        else
            prev -> next = tmp;
        prev = tmp;
        curr = curr -> next;
    }
    return head;
}