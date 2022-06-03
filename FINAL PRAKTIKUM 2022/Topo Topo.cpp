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
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
vector<int> vec[MAX];
vector<int> idx(MAX), ans;
priority_queue<int> pq;

void topo()
{    
    while(!pq.empty())
    {
        int top = pq.top();
        pq.pop();
        ans.pb(top);
        
        for(int i = 0; i < vec[top].size(); i++)
        {
            int nextNode = vec[top][i];
            
            if(!(--idx[nextNode]))
                pq.push(nextNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].pb(v);
        idx[v]++;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!idx[i])
            pq.push(i);
    }
    
    topo();
    
    for(int i = 1; i <= n; i++)
    {
        if(idx[i])
        {
            cout << "-1\n";
            return 0; 
        }
    }
    
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
