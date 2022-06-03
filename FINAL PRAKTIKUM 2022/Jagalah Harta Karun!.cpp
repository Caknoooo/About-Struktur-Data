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
#define MAX 1000005
#define MOD 1000000007
typedef long long ll;

int n, m, hutan = 0;
vector<vc> adj;
vector<vi> vis;
bool flag = false;

int leave(int row, int col)
{
    return(row >= n || row < 0 || col >= m || col < 0 || adj[row][col] == '#' || vis[row][col]);
}

void DFS(int r, int c)
{
    if(leave(r, c)) return;
    if(r == n - 1 && c == m - 1)
    {
        flag = true;
        return;
    }
    vis[r][c] = 1;
    DFS(r, c + 1);
    if(!flag)
    {
        DFS(r + 1, c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    adj.assign(n + 1, vc(m + 1, ' '));
    vis.assign(n + 1, vi(m + 1, 0));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> adj[i][j];
    }
    
    if(m > 1)
    {
        DFS(0, 1);
        if(flag)
            hutan++;
    }
    flag = false;
    if(n > 1)
    {
        DFS(1, 0);
        if(flag)
            hutan++;
    }
    
    cout << hutan << '\n';
}
