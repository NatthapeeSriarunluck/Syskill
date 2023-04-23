/* Name: Natthapee Sriarunluck
 * ID: 6480266
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
/* Push a word to the top of this stack
 * You must keep a *COPY* of the word.
 * If q is NULL, allocate space for it here
 */

void push(Stack **q, char *word)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(word) + 1);
    strcpy(newNode->data, word);
    newNode->next = NULL;
    if (*q == NULL || (*q)->head == NULL)
    {
        *q = malloc(sizeof(Stack));
        (*q)->head = newNode;
        (*q)->tail = newNode;
    }
    else
    {
        newNode->next = (*q)->head;
        (*q)->head = newNode;
        
    }
}
/* Returns the data at the top of the stack
 * and remove it from the stack as well.
 * If q is empty, return NULL
 */

char *pop(Stack *q)
{
    if (q == NULL || q->head == NULL)
    {
        return NULL;
    }
    else
    {
        char *popData = q->head->data;
        Node *temp = q->head;
        q->head = q->head->next;
        free(temp);
        if (q->head == NULL)
        {
            q->tail = NULL;
        }
        return popData;
    }
}
/* Prints out the current stack, front to back.
 * If the stack is empty, prints out "No items"
 */
void print(Stack *q)
{
    if (isEmpty(q))
    {
        printf("No items\n");
    }
    else
    {
        Node *current = q->head;
        while (current != NULL)
        {
            printf("%s\n", current->data);
            current = current->next;
        }
    }
}
/* Checks if the stack is empty */
int isEmpty(Stack *q)
{
    if (q == NULL || q->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Deallocates all items in the stack */
void delete(Stack **q)
{
    if (isEmpty(*q))
    {
        return;
    }
    Node *current = (*q)->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    (*q)->head = NULL;
    (*q)->tail = NULL;
    free(*q);
    *q = NULL;
}

/***** Expected output: *****
No items
a
b
c
a
b
c
d
e
f
No items
s = World
t = Hello
*****************************/
int main(int argc, char **argv)
{
    Stack *q = NULL;

    // print the stack
    print(q);

    // push items
    push(&q, "a");
    push(&q, "b");
    push(&q, "c");
    print(q);

    // pop items
    while (!isEmpty(q)) {
        char *item = pop(q);
        printf("%s\n", item);
        free(item);
    }
    
    free(q);

    char *item = pop(q);
    assert(item == NULL);

    // push again
    push(&q, "d");
    push(&q, "e");
    push(&q, "f");
    print(q);

    // destroy the stack
    delete(&q);

    // print again
    print(q);

    // check copy
    char *s = (char *)malloc(10);
    strcpy(s, "Hello");
    push(&q, s);
    strcpy(s, "World");
    char *t = pop(q);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);
    free(s);

    // free the stack
    free(q);
}
