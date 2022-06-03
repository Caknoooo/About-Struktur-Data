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
    
    stack<pii> st;
    int cnt = 0, n;
    cin >> n;
    while(n--)
    {
        int in;
        cin >> in;
        if(!st.empty())
        {
            if(st.top().f == in)
            {
                int sum = st.top().s + 1;
                st.pop();
                if(sum < in)
                {
                    st.push(mp(in, sum));
                    cnt++;
                }
                else{
                    cnt -= (sum - 1);
                }
            }
            else{
                int sum = 1;
                st.push(mp(in, sum));
                cnt++;
            }
        }
        else{
            int sum = 1;
            st.push(mp(in, sum));
            cnt++;
        }
        cout << cnt << "\n";
    }
}
