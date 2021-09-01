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

int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == NULL)
    {                 //더미노드가 NULL을 가리키면
        return FALSE; //변환할 데이터가 없다
    }

    plist->before = plist->head;    //before은 더미 노드를 가리키게 함
    plist->cur = plist->head->next; //cur은 첫번째 노드를 가리키게 함

    *pdata = plist->cur->data; //첫 번째 노드의 데이터를 전달
    return TRUE;
}

int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL)
    {
        return FALSE;
    }

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist)
{
    Node *rpos = plist->cur;  //소멸 대상의 주소 값을 rpos에 저장
    LData rdata = rpos->data; //소멸 대상의 데이터를 rdata에 저장

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
