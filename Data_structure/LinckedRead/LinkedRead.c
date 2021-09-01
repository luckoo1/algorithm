#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int data;
    struct __node *next;
} Node;

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    Node *newNode = NULL;

    int readData;

    while (1)
    {
        printf("Input number : ");
        scanf("%d\n", &readData);
        if (readData < 1)
        {
            break;
        }
        //node 추가
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }

        tail = newNode;
    }
}