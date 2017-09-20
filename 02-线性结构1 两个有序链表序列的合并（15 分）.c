#include<stdio.h>
typedef struct Node *PtrToNode;
struct Node {
    int Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Merge(List L1, List L2)
{
    List pre, next, Ls, tmp;
    pre = NULL;
    while((L1 != NULL) || (L2 != NULL))
    {
        if((L1 != NULL) && (L2 != NULL))
        {
            if(L1->Data >= L2->Data)
            {
                next = L2;
                L2 = L2->Next;
                if(pre != NULL) pre->Next = next;
                else Ls = next;
                pre = next;
            }
            else
            {
                next = L1;
                L1 = L1->Next;
                if(pre != NULL) pre->Next = next;
                else Ls = next;
                pre = next;
            }
        }
        if((L1 == NULL) && (L2 != NULL))
        {
            next = L2;
            L2 = L2->Next;
            if(pre != NULL) pre->Next = next;
            else Ls = next;
            pre = next;
        }
        if((L2 == NULL) && (L1 != NULL))
        {
            next = L1;
            L1 = L1->Next;
            if(pre != NULL) pre->Next = next;
            else Ls = next;
            pre = next;
        }
    }
    return Ls;
}
int main()
{
	return 0;
}
