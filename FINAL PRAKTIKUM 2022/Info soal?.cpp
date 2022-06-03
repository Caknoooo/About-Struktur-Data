#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef WIN32
inline int getchar_unlocked() 
    {return _getchar_nolock(); }
#endif

using namespace std;
using namespace __gnu_pbds;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define piii pair<int, pii>
#define psi pair<string, int>
#define pll pair<long long, long long>
#define all(x) x.begin(),x.end()
#define revAll(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define AVL tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define seev(v,n) for(int i = 0; i < n; i++){int x; cin >> x; v.push_back(x);}
#define sees(s,n) for(int i = 0; i < n; i++){int x; cin >> x; s.insert(x);}
#define MAX 105
#define MOD 1000000007
typedef long long ll;
vector<int> adj[MAX];
bool cek, vis[MAX], adjVis[MAX][MAX];
int n, e;

void DFS(int u, int ct)
{
    if(ct == n)
    {
        cek = true;
        return;
    }
    vis[u] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(cek)
            return;
        if(!vis[i] && adjVis[u][i])
            DFS(i, ct + 1);
    }
    vis[u] = false;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int u, v;
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> u >> v;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < adj[i].size(); j++)
        {
            int sz = adj[i][j];
            for(int k = 0; k < adj[sz].size(); k++)
            {
                int next = adj[sz][k];
                if(next != i)
                    adjVis[i][next] = true;
            }
        }
    }
    
    
    DFS(0, 1);
    if(cek)    
        return cout << "YES\n", 0;
    cout << "NO\n";
    return 0;
}
