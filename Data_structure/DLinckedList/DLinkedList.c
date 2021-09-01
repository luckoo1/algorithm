#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist) //더미 노드 생성
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
    {                         //정렬기준이 마련되지 않았다면
        Finsert(plist, data); //머리에 노드 추가
    }
    else //정렬기준이 마련되었다면
    {
        SInsert(plist, data); //정렬기준에 근거하여 노드에 추가
    }
}

void FInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); //새노드 생성
    newNode->data = data;                         //새노드에 데이터 저장

    newNode->next = plist->head->next; //새 노드가 다른 노드를 가리키게 함
    plist->head->next = newNode;       //더미 노드가 새 노드를 가리키게 함

    (plist->numOfData)++; //저장된 노드 수 증가
}