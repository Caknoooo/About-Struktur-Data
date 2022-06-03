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
#define MAX 10005
#define MOD 1000000007
typedef long long ll;

void Gas(int l, int r, int h)
{        
    int n = r - l + 1;
    
    if(l > r)
        return;
    
    if(pow(2, h) / 2 >= n)
    {
        cout << l << " ";
        Gas(l + 1, r, h - 1);
    }
    else{
        int m = r - (pow(2, h) / 2) + 1;
        cout << m << " ";
        Gas(l, m - 1, h - 1);
        Gas(m + 1, r, h - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 1, n, h;
    while(true)
    {
        cin >> n >> h;
        if(!n && !h)
            break;
        cout << "Case " << cnt++ << ": ";
        if(n > pow(2, h) - 1)
        {
            cout << "Impossible.\n";
            continue;
        }
        
        Gas(1, n, h);
        cout << '\n';
    }
}
