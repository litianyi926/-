#include <stdio.h>
#include <malloc.h>

typedef struct LNode *List;
struct LNode
{
    int number;
    int code;
    List Next;
    int tag;
};

List CreatList(int a)
{
    List Ptrl = (List)malloc(sizeof(struct LNode));
    if(Ptrl == NULL)
    {
        printf("内存不足，分配失败。\n");
        return NULL;
    }
    Ptrl->Next = NULL;
    Ptrl->number = 1;
    Ptrl->code = a;
    Ptrl->tag = 1;
    return Ptrl;
}

void Add(int Date,List Ptrl)
{
    List p = (List)malloc(sizeof(struct LNode));
    if(p == NULL)
    {
        printf("内存不足，分配失败。\n");
        return ;
    }
    p->code = Date;
    p->Next = NULL;
    while(Ptrl->Next!=NULL)
    {
        Ptrl = Ptrl->Next;
    }
    p->number = Ptrl->number+1;
    p->code = Date;
    p->Next = NULL;
    p->tag = 1;
    Ptrl->Next = p;
}
void Joseph(List Ptrl,int m,int n)
{
    if(m > 30||m < 1)
    {
        printf("ERROR.\n");
        return ;
    }
    int i = 1,j;
    List p = Ptrl;
    j = m;
    while(1)
    {
        while(i != j)
        {
            p = p->Next;
            if(p->tag == 1)
            {
                i++;
            }
        }
        printf("%d ",p->number);
        p->tag = 0;
        m = p->code;
        n--;
        if(n == 0)
        {
            break;
        }
        j = m;
        i = 0;
    }
}
int main()
{
    int i,n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    //构建数组方便对链表数值的添加
    int *a = (int *)malloc(n*sizeof(int));
    for(i = 0;i < n;++i)
    {
        scanf("%d",a+i);
    }
    List L = CreatList(a[0]);//创建链表
    //为链表添加需要的节点
    for(i = 1;i < n;++i)
        Add(a[i],L);
    //使链表循环
    List p = L;
    while(p->Next!=NULL)
    {
        p = p->Next;
    }
    p->Next = L;

    Joseph(L,m,n);
    return 0;
}


















