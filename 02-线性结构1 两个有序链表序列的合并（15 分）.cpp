List Merge(List L1, List L2)
{
    List tmp;
    if ((L1 == NULL) && (L2 == NULL)) return NULL;
    if (L1 == NULL)
    {
        tmp = L2;
        L2 = tmp->Next;
        tmp->Next = Merge(L1, L2);
        return tmp;
    }
    if (L2 == NULL)
    {
        tmp = L1;
        L1 = tmp->Next;
        tmp->Next = Merge(L1, L2);
        return tmp;
    }
    if (L1->Data >= L2->Data)
    {
        tmp = L2;
        L2 = tmp->Next;
        tmp->Next = Merge(L1, L2);
        return tmp;
    }
    if (L1->Data < L2->Data)
    {
        tmp = L1;
        L1 = tmp->Next;
        tmp->Next = Merge(L1, L2);
        return tmp;
    }
}