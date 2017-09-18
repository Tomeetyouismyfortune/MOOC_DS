#include<iostream>
#include<deque>
#include<string>
#include<vector>
using namespace std;

void solution(vector<int> &pre, vector<int> &in, vector<int> &post, int preL, int inL, int postL, int n)
{
    if (n == 0) return;
    if (n == 1)
    {
        post[postL] = pre[preL];
        return;
    }
    post[postL + n - 1] = pre[preL];
    int L;
    for (int i = 0; i < n; i++)
    {
        if (in[inL + i] == pre[preL])
        {
            L = i;
            break;
        }
    }
    int R = n - L -1;
    solution(pre, in, post, preL + 1, inL, postL, L);
    solution(pre, in, post, preL + L + 1, inL + L + 1, postL + L, R);
    return;
}

int main()
{
    int k;
    cin >> k;
    deque<int> visit;
    string s;
    int tmp;
    vector<int> pre,in,post;
    post.resize(k);
    for (int i = 0; i < 2 * k; i++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> tmp;
            visit.push_front(tmp);
            pre.push_back(tmp);
        }
        else {
            deque<int>::iterator Tmp = visit.begin();
            visit.pop_front();
            in.push_back(*Tmp);
        }
    }
    solution(pre, in, post, 0, 0, 0, k);
    for (int i = 0; i < k; i++)
    {
        cout << post[i];
        if (i != k - 1) cout << " ";
    }
}
