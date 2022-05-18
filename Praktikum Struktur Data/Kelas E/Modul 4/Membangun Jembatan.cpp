#include <bits/stdc++.h>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 10005
#define MOD 1000000007
typedef long long ll;
vector<vi> v;
vector<int> visited;

void DFS(int mulai)
{
    visited[mulai] = 1;
    for(int i = 0; i < v[mulai].size(); i++)
    {
        int nextNode = v[mulai][i];
        if(!visited[nextNode])
        {
            DFS(nextNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node, edge, a, b;
    int jembatan = 0;
    cin >> node >> edge;
    v.assign(MAX, vi());
    visited.assign(MAX, 0);
    
    for(int i = 0; i < edge; i++)
    {
        cin >> a >> b;
        
        v[a].pb(b);
        v[b].pb(a);
    }
    
    for(int i = 1; i <= node; i++)
    {
        if(!visited[i])
        {
            jembatan++;
            DFS(i);
        }
    }
    cout << jembatan - 1 << endl;
}
