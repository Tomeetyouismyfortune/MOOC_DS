#include<iostream>
#include<vector>
#include<deque>
using namespace std;

bool solution(int, int);

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    bool r[k];
    for (int i = 0; i < k; i++)
    {
        r[i] = solution(m, n);
    }
    for (int i = 0; i < k; i++)
    {
        if (r[i]) cout << "YES";
        else cout << "NO";
        if (i != k - 1) cout << endl;
    }
    return 0;
}

bool solution(int m, int n)
{
    deque<int> s;
    vector<int> popsq;
    popsq.resize(n);
    for (int i = 0; i < n; i++) cin >> popsq[i];
    int i = 0, j = 0;
    while(i < n)
    {
    	if(s.size() > m) return false;
        if (j < popsq[i])
        {
            j++;
            s.push_front(j);
            continue;
        }
        if (*s.begin() == popsq[i])
        {
            s.pop_front();
            i++;
            continue;
        }
        if (*s.begin() > popsq[i]) return false;
    }
    return true;
}
