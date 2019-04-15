#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_INIT_SIZE 6   //再次调控问题规模。

typedef struct {
    int *base;
    int *top;
    int stacksize;
 }SqStack;

void InitStack(SqStack *S)
{
    S->base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!S->base) exit(-1);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return;
}

void Push(SqStack *S,int e)
{
    *S->top++ = e;
}

bool IsEmpty(SqStack *S)
{
    if(S->base == S->top)
        return true;
    else
        return false;
}
int Pop(SqStack *S)
{
    if(S->top == S->base) exit(-1);
    int e = *--S->top;
    return e;
}
void Scheduling(SqStack * S,int pos,int path[],int i)
{
    int temp;
    if(pos < STACK_INIT_SIZE)
    {
        Push(S,pos+1);
        Scheduling(S,pos+1,path,i);
        Pop(S);
    }
    if(IsEmpty(S) == false)
    {
        temp = Pop(S);
        path[i++] = temp;
        Scheduling(S,pos,path,i);
        Push(S,temp);
    }
    if(pos == STACK_INIT_SIZE&&IsEmpty(S)==true)
    {
        for(int j = 0;j < i;++j)
            printf("%d ",path[j]);
        printf("\n");
    }
}
int main()
{
    SqStack Sqeue;
    InitStack(&Sqeue);
    int a[STACK_INIT_SIZE];
    Scheduling(&Sqeue,0,a,0);
    return 0;
}




















