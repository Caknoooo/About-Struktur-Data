#include <bits/stdc++.h>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define mp make_pair
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 10005
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    vector<pii > v;
    priority_queue<pii > pq;
    pii temp;
    map<int, int> data;
    map<int, int>::iterator it;
    
    int N, A, cnt = 0;
    cin >> N;
    
    while(N--)
    {
        cin >> A;
        if(!data.count(A))
        {
            data.insert(mp(A, cnt++));
            v.push_back(mp(1, A));
        }
        else
            v[data[A]].first++;
    }
    
    for(it = data.begin(); it != data.end(); ++it)
        pq.push(mp(v[it->second].first, (cnt - it->second - 1)));
    
    while(!pq.empty())
    {
        temp = pq.top();
        pq.pop();
        while(v[cnt - temp.second - 1].first--)
            cout << v[cnt - temp.second - 1].second << " ";
    }
}
