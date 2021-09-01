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
        scanf("%d", &readData);
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
    printf("%d\n");

    printf("print data!\n");

    if (head == NULL)
    {
        printf("No number\n");
    }
    else
    {
        cur = head;
        printf("%d ", cur->data);

        while (cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        Node *delNode = head;
        Node *delNextNode = head->next;
        printf("delete %d\n", head->data);
        free(delNode);

        while (delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("delete %d\n", delNode->data);
            free(delNode);
        }
    }
}