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

vector<vector<pii> > vec(MAX, vector<pii>());
vector<int> dist(MAX, -1);


void cinn(int &input)
{
    input = 0;
    char inp = getchar_unlocked(); 
    int k = 1;
    
    while(inp < '0' || inp > '9')
    {
        if(inp == '-')
            k = -1;
        inp = getchar_unlocked();
    }
    
    while(inp >= '0' && inp <= '9')
    {
        input = (input << 3) + (input << 1) + (int)(inp - '0');
        inp = getchar_unlocked();
        if(k < 1)
            input = -input;
    }
}

void BFS()
{
    queue <pii> q;
    dist[0] = 0;
    q.push(mp(0, 0));

    while(!q.empty())
    {
        int u = q.front().f;
        int d = q.front().s;
        q.pop();

        for(int i = 0; i < vec[u].size(); ++i)
        {
            int v = vec[u][i].f,
                w = vec[u][i].s;

            if(dist[v] == -1)
            {
                dist[v] = d + w;
                q.push(mp(v, d + w));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        vec[u].pb(mp(v, w));
        vec[v].pb(mp(u, w));
    }
    
    BFS();
    
    for(int i = 1; i < n; i++)
        cout << i << " " << dist[i] << "\n";
    return 0;
}
