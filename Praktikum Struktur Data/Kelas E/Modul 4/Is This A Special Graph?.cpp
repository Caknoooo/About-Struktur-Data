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
bool flag = false;
int cnt = 0;
typedef long long ll;
vi::iterator it;

void DFS(int node, int prev, vector<vi > v, vi &visited, bool &flag)
{
    if(visited[node])
    {
        flag = true;
        return;
    }
    
    visited[node] = 1;
    
    for(int i = 0; i < v[node].size(); i++)
    {
        if(v[node][i] == prev)
            continue;
        DFS(v[node][i], node, v, visited, flag);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int node, edge, a, b, t;
    cin >> t;
    while(t--)
    {
        vector<int> visited(MAX, 0);
        vector<vi > v(MAX, vi());
        int cek[MAX];
        bool list = false;
        memset(cek, 0, sizeof(cek));
        
        cin >> node >> edge;
        for(int i = 0; i < edge; i++)
        {
            cin >> a >> b;
            cek[a]++;
            cek[b]++;
            if(cek[a] > 2 || cek[b] > 2)
                list = true;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        bool flag = false;
        for(int i = 1; i <= node; i++)
        {
            if(!visited[i])
                DFS(i, i, v, visited, flag);
        }
        if(!list)
            cout << "Graf ini adalah linked list" << endl;
        else if(flag)    
            cout << "Graf ini adalah graf biasa" << endl;
        else
            cout << "Graf ini adalah tree" << endl;
        fill(visited.begin(), visited.end(), 0);
    }
}
