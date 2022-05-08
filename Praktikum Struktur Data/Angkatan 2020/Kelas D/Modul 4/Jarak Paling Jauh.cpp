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
vector<vi> adjList(MAX, vi(MAX, 0));
vi visited(MAX, 0);
list<int> q;
int ans = 0, tempCount; 

void BFS(int mulai)
{
    visited[mulai] = 1;
    q.push_back(mulai);
    
    while(!q.empty())
    {
        int x = q.back();
        q.pop_front();
        tempCount++;
        for(auto i = adjList[x].begin(); i != adjList[x].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = 1;
                q.push_back(*i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node, a, b, cnt = 0;
    cin >> node;
    
    for(int q = 1; q <= node; q++)
        adjList[q].push_back(q);
    for(int i = 1; i <= node - 1; i++)
    {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
    for(int i = 1; i <= node; i++)
    {
        tempCount = 0;
        if(!visited[i])
        {
            BFS(i);
            fill(visited.begin(), visited.end(), 0);
        }
        tempCount -= 2;
        if(cnt < tempCount)
            cnt = tempCount;
    }
    cout << cnt << endl;
}
