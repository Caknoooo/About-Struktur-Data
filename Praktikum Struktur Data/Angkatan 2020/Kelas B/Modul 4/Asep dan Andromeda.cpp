#include <bits/stdc++.h>
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
#define MAX 10005

void DFS(int mulai, vi v[], vi &visited)
{
    visited[mulai] = 1;
    
    for(int i = 0; i < v[mulai].size(); i++)
    {
        int nextNode = v[mulai][i];
        if(!visited[nextNode])
        {
            DFS(nextNode, v, visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    vector<int> visited(MAX, 0);
    vector<int> vec[MAX];
    int node, edge, a, b;
    cin >> node >> edge;
    for(int i = 0; i < edge; i++)
    {
        cin >> a >> b;
        
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int banyak = 0;
    
    for(int i = 1; i <= node; i++)
    {
        if(!visited[i])
        {
            banyak++;
            DFS(i, vec, visited);
        }
    }
    if(banyak - 1 != 0)
        cout << banyak - 1 << endl;
    else
        cout << "HAIL ASEP!" << endl;
}
