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
	  int n, cnt = 0;
    cin >> n;
    vector<string> vec;
    vec.push_back("home");
    vec.push_back("anton");
    while(n--)
    {
        string cmd, input;
        cin >> cmd;
        if(cmd == "goto")
        {
            cin >> input;
            vec.push_back(input);
        }
        else if(cmd == "whereami")
        {
            if(!vec.size())
                cout << "i am nowhere\n";
            else{
                for(int i = 0; i < vec.size(); i++)
                {
                    if(i)
                        cout << "/";
                    cout << vec[i];
                }
                cout << "\n";
            }
        }
        else if(cmd == "goback"){
            if(!vec.size())
            {
                cout << "cannot go back\n";
            }
            else{
                vec.pop_back();
            }
        }
        else{
            cout << "Query not found\n";
        }
    }
}
