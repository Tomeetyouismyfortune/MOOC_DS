#include<iostream>
#include<map>
using namespace std;

struct TNode
{
  char data;
  int lchild,rchild;
  int parent;
};

int main()
{
  int k1,k2;
  char tmp;
  cin >> k1;
  TNode t1[k1+1];
  for (int i = 0; i < k1; i++)
  {
    cin >> t1[i].data;
    cin >> tmp;
    if (tmp!='-') { t1[i].rchild = tmp - '0'; t1[tmp - '0'].parent = i;}
    else t1[i].rchild = -1;
    cin >> tmp;
    if (tmp!='-') { t1[i].lchild = tmp - '0'; t1[tmp - '0'].parent = i;}
    else t1[i].lchild = -1;
  }
  cin >> k2;
  TNode t2[k2+1];
  for(int i = 0; i < k2; i++)
  {
    cin >> t2[i].data;
    cin >>tmp;
    if (tmp != '-') { t2[i].lchild = tmp - '0'; t2[tmp - '0'].parent = i;}
    else t2[i].lchild = -1;
    cin >> tmp;
    if (tmp != '-') { t2[i].rchild = tmp - '0'; t2[tmp - '0'].parent = i;}
    else t2[i].rchild = -1;
  }
  int k;
  if (k1 != k2)
  {
      cout << "No";
      return 0;
  }
  else k = k1;
  map<char, TNode> T2;
  for (int i = 0; i < k; i++) T2[t2[i].data] = t2[i];
  for (int i = 0; i < k; i++)
  {
      if(T2.count(t1[i].data) == 0)
      {
          cout << "No";
          return 0;
      }
      if (t1[i].parent != 0)
      {
          if (t1[t1[i].parent].data != t2[T2[t1[i].data].parent].data)
          {
			  cout << "No";
              return 0;
          }
      }
  }
  cout << "Yes";
  return 0;
}
