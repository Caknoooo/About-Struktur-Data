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
#define MOD 1000000007

int banyak;

void DFS(int mulai, vi v[], vi &visited)
{
    visited[mulai] = 1;
    banyak++;
    
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
    
    map<string, int> mp;
    vi v[MAX];
    vi visited(MAX, 0);
    mp["A1"] = 1;
    mp["A2"] = 2;
    mp["A3"] = 3;
    mp["B1"] = 4;
    mp["B2"] = 5;
    mp["B3"] = 6;
    mp["C1"] = 7;
    mp["C2"] = 8;
    mp["C3"] = 9;
    
    int node, nodes[MAX], cnt = 0;
    string s1, junk, s2;
    
    loop(t)
    {
        cin >> s1 >> junk >> s2;
        
        v[mp[s1]].push_back(mp[s2]);
        v[mp[s2]].push_back(mp[s1]);
    }
    
    for(int i = 1; i <= 9; i++)
    {
        if(!visited[i])
        {
            banyak = 0;
            
            DFS(i, v, visited);
            
            nodes[cnt++] = banyak;
        }
    }
    int ans = 0;
    for(int i = 0; i < cnt - 1; i++)
    {
        for(int j = i + 1; j < cnt; j++)
        {
            ans += (nodes[i] * nodes[j]);
        }
    }
    cout << ans << endl;
    
}
