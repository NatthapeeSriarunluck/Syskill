#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

void insertAt(int location, int num)
{
        Node *temp;
        int count = 0;
        if (first == NULL)
        {
                temp = malloc(sizeof(Node));
                temp->data = num;
                temp->next = NULL;
                temp->previous = NULL;
                first = temp;
                last = temp;
                return;
        }
        if (location == 0)
        {
                temp = malloc(sizeof(Node));
                temp->data = num;
                temp->next = first;
                temp->previous = NULL;
                first->previous = temp;
                first = temp;
                return;
        }
        for (temp = first; temp != NULL && count < location - 1; temp = temp->next, count++)
                ; // location -1 since we want to stop before the desired location
        {
                if (location > count)
                {
                        insert(num);
                }
                else
                {
                        Node *temp2;
                        temp2 = malloc(sizeof(Node));
                        temp2->data = num;
                        temp2->next = temp->next;
                        temp->next->previous = temp2;
                        temp2->previous = temp;
                        temp->next = temp2;
                }
        }
}

void insert(int num)
{
        Node *temp = first;
        if (first == NULL)
        {
                first = malloc(sizeof(Node));
                first->data = num;
                first->next = NULL;
                first->previous = NULL;
                last = first;
                return;
        }
        for (; temp->next != NULL; temp = temp->next)
                ;
        Node *newnode;
        newnode = malloc(sizeof(Node));
        newnode->data = num;
        newnode->next = NULL;
        temp->next = newnode;
        newnode->previous = temp;
        last = newnode;
}

int deleteNode(int num)
{
        Node *temp;
        if (first == NULL)
        {
                return 0;
        }
        if (first->data == num)
        {
                temp = first;
                first = temp->next;
                first->previous = NULL;
                if (first != NULL)
                {
                        first->previous = NULL;
                }
                else
                {
                        last = NULL;
                }
                free(temp);
                return 1;
        }
        for (temp = first; temp->next != NULL; temp = temp->next)
        {
                if (temp->next->data = num)
                {
                        Node *temp2;
                        temp2 = temp->next;
                        temp->next = temp->next->next;
                        if (temp->next != NULL)
                                temp->next->previous = temp;
                        else
                                last = temp;
                        free(temp2);
                        return 1;
                }
        }
        return 0;
}

void print()
{
        Node *temp = first;
        printf("Linked List Content: {");
        for (; temp != NULL; temp = temp->next)
        {
                printf("%d ,", temp->data);
        }
        printf("}\n");
}

int main()
{
        first = NULL;
        last = NULL;
        insert(4);
        insert(7);
        insertAt(1, 1);
        insertAt(20, 20);
        insertAt(1, 5);
        insertAt(0, 3);
        insert(8);
        print();
        deleteNode(4);
        deleteNode(8);
        deleteNode(2000);
        print();
        return 0;
}
