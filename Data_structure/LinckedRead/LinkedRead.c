#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int data;
    struct __node *next;
} Node;

int main()
{
    Node *head = NULL; //리스트의 머리를 가리키는 포인터 변수
    Node *tail = NULL; //리스트의 꼬리를 가리키는 포인터 변수
    Node *cur = NULL;  //저장된 데이터의 조회에 사용되는 포인터 변수
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
        newNode = (Node *)malloc(sizeof(Node)); //노드의 생성

        newNode->data = readData; //노드의 데이터 저장
        newNode->next = NULL;     //노드의 next를 NULL로 저장

        if (head == NULL) //첫번째 노드라면
        {
            head = newNode; //첫번째 노드를 head를 가리키게 함
        }
        else //두번째 이후 노드라면
        {
            tail->next = newNode;
        }

        tail = newNode; //노드의 끝을 tail이 가리키게 함
    }
    printf("%d\n");

    printf("print data!\n");

    if (head == NULL)
    {
        printf("No number\n");
    }
    else
    {
        cur = head;               //cur이 리스트의 첫 번째 노드를 가리킨다.
        printf("%d ", cur->data); // 첫번째 데이터 출력

        while (cur->next != NULL) //연결된 노드가 존재하면
        {
            cur = cur->next;          //cur이 다음 노드를 가리키게 한다.
            printf("%d ", cur->data); //cur이 가리키는 노드 출력
        }
    }
    printf("\n\n");

    //데이터 삭제
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