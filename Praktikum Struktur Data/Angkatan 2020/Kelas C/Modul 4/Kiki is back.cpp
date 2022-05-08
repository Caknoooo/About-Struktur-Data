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
#define MAX 1005

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
    char pulau1, pulau2;
    vector<int> v[MAX]; 
    vi visited(MAX, 0);
    int nodes, edge;
    cin >> nodes >> edge;
    while(edge--)
    {
        cin >> pulau1 >> pulau2;
        
        v[pulau1 - 'A' + 1].push_back(pulau2 - 'A' + 1);
        v[pulau2 - 'A' + 1].push_back(pulau1 - 'A' + 1);
    }
    
    int kunjungan = 0;
    
    for(int i = 1; i <= nodes; i++)
    {
        if(!visited[i])
        {
            kunjungan++;
            DFS(i, v, visited);
        }
    }
    
    cout << kunjungan - 1 << endl;
}
