/* Do not modify */
#ifndef CQUEUE_H
#define CQUEUE_H

struct node_struct {
    char *data;
    struct node_struct *next;
};

typedef struct node_struct Node;

struct stack_struct {
    Node *head, *tail;
};

typedef struct stack_struct Stack;

/* Push a word to the top of this stack
 * You must keep a *COPY* of the word.
 * If q is NULL, allocate space for it here
 */
void push(Stack **q, char *word);

/* Returns the data at the top of the stack
 * and remove it from the stack as well.
 * If q is empty, return NULL
 */
char *pop(Stack *q);

/* Checks if the stack is empty */
int isEmpty(Stack *q);

/* Prints out the current stack, front to back.
 * If the stack is empty, prints out "No items"
 */
void print(Stack *q);

/* Deallocates all items in the stack */
void delete(Stack **q);

#endif
