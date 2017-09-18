#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct TNode
{
    int data;
    int rchild,lchild;
    int parent;
    TNode();
};
TNode::TNode()
{
    this->rchild = -1;
    this->lchild = -1;
    this->parent = -1;
}

int getroot(TNode t[]);

int main()
{
    int k;
    char tmp;
    cin >> k;
    TNode t[k];
    vector<int> show;
    deque<TNode> visit;
    for (int i = 0; i < k; i++)
    {
        t[i].data = i;
        cin >> tmp;
        if (tmp != '-')
        {
            t[i].lchild = tmp - '0';
            t[tmp - '0'].parent = i;
        }
        else t[i].lchild = -1;
        cin >> tmp;
        if (tmp != '-')
        {
            t[i].rchild = tmp - '0';
            t[tmp - '0'].parent = i;
        }
        else t[i].rchild = -1;
    }
    int root;
    root = getroot(t);
    visit.push_front(t[root]);
    deque<TNode>::iterator Tmp;
    while(!visit.empty())
    {
        Tmp = visit.end();
        Tmp--;
        //cout << "?";
        if ((Tmp->lchild == -1) && (Tmp->rchild == -1)) show.push_back(Tmp->data);
        visit.pop_back();
        if (Tmp->lchild != -1) visit.push_front(t[Tmp->lchild]);
        if (Tmp->rchild != -1) visit.push_front(t[Tmp->rchild]);
    }
    for (int i = 0; i < show.size(); i++)
    {
        cout << show[i];
        if (i != show.size() - 1) cout << " ";
    }
}

int getroot(TNode t[])
{
    int i;
    for (i = 0; t[i].parent != -1; i = t[i].parent) {}
    return i;
}
