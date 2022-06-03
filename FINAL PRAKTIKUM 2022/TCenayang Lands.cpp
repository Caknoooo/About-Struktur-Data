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

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, cnt = 1;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    double luas = 9e10;
    
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
        
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                double luas2 = 0.5 * abs((a[j] - a[i]) * (b[k] - b[i]) - (a[k] - a[i]) * (b[j] - b[i]));
                if(luas2 == 0)
                    continue;
                if(luas2 < luas)
                {
                    luas = luas2;
                    cnt = 1;
                }
                else if(luas2 == luas)
                    cnt++;
                
            }
        }
    }
    if(luas == 9e10 || cnt > 1)
        cout << "-1.00";
    else
        cout << fixed << setprecision(2) << luas << "\n";
}
