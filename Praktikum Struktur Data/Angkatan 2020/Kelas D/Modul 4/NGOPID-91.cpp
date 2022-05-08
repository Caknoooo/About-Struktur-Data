#include <bits/stdc++.h>
#include <vector>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 100005
typedef long long ll;

int main()
{
    int t, a, b, total = 0;
    cin >> t;
    vi vec[t + 1];
    vb visited(t);
    queue<int> q;
    while(--t)
    {
        cin >> a >> b;
        
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    int root = 1;
    q.push(root);
    visited[root] = 1;
    
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        int cnt = 0;
        
        for(unsigned i = 0; i < vec[currNode].size(); i++)
        {
            int nextNode = vec[currNode][i];
            if(!visited[nextNode])
            {
                visited[nextNode] = 1;
                q.push(nextNode);
                cnt++;
            }
        }
        
        int now = 1;
        while(now <= cnt)
        {
            total++;
            now *= 2;
        }
        total += cnt;;
    }
    cout << total << endl;
}
