#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct
{
    element *data;
    int capacity;
    int top;
} StackType;

//stack 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입함수
//공간이 부족하면 메모리를 2배 더 확보한다.
void push(StackType *s, element item)
{
    if (is_full(s))
    {
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s))
    {
        printf("stack empty error\n");
        exit(1);
    }
    else
    {
        return s->data[(s->top)--];
    }
}

element peek(StackType *s)
{
    if (is_empty(s))
    {
        printf("stack empty error\n");
        exit(1);
    }
    else
    {
        return s->data[s->top];
    }
}

int main(void)
{
    StackType s;

    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    free(s.data);
    return 0;
}