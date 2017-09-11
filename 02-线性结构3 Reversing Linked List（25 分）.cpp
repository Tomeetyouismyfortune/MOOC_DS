#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

struct Node {
    int data;
    int next;
    Node() {
        data=0;
        next=-1;
    }
    Node(int a,int b) {
        data=a;
        next=b;
    }
}; 

int main() {
    int L,n,k;
    cin>>L>>n>>k;
    map<int,Node> List;
    int addr,data,next;
    for(int i=0;i<n;i++) {
        cin>>addr>>data>>next;
        List[addr]=Node(data,next);
    }
    vector<int> l;
    for(int k=L;k!=-1;k=List[k].next) l.push_back(k);
    n=l.size();
    int tmp;
    for(int j=0;j<n/k;j++) {
        for(int i=0;i<=(k-1)/2;i++) {
            tmp=l[i+j*k];
            l[i+j*k]=l[k-1-i+j*k];
            l[k-1-i+j*k]=tmp;
        }
    }
    for(int i=0;i<n;i++) {
        printf("%05d %d ",l[i],List[l[i]].data);
        if(i!=n-1) printf("%05d\n",l[i+1]);
        else printf("-1");
    }
    return 0;
}
