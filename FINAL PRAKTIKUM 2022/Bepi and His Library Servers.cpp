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
#define pis pair<int, string>
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

string input_buku, input_server;
int n, m, x, total = 0, sz, level;
vector<vector<string> > vec;
vector<int>::iterator it_level;

map<string, string> nama_server; // 
map<string, vector<string> > list_server; // connect server
map<string, vi > list_level; // menaruh buku di level keberapa

map<string, vector<string> >::iterator it_buku;
map<string, vi>::iterator it_server;

void input()
{
    loop(t)
    {
        cin >> input_server >> x >> level;
        while(x--)
        {
            cin >> input_buku;
            list_level[input_buku].pb(level); // buku itu ada lantai berapa
            list_server[input_buku].pb(input_server); // buku itu ada di server apa
        }
    }
}

void process()
{
    for(it_buku = list_server.begin(); it_buku != list_server.end(); ++it_buku)
    {
        sort(it_buku->s.begin(), it_buku->s.end());
        
        int sz2 = it_buku->s.size();
        
        for(int i = 0; i < sz2; i++)
        {
            if(i != 0)
                nama_server[it_buku->f] += '|';
            nama_server[it_buku->f] += it_buku->s[i];
        }
    }
    
    for(it_server = list_level.begin(); it_server != list_level.end(); ++it_server)
        sort(it_server->s.begin(), it_server->s.end());
}

void testCase()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        priority_queue<pis, vector<pis>, greater<pis> > pq;
        set<int> vis;
        bool flag = false;
        cin >> x >> level;
        while(x--)
        {
            cin >> input_buku;
            if(!list_server.count(input_buku))
                flag = true;
            else{
                int minLevel;
                it_level = lower_bound(list_level[input_buku].begin(), list_level[input_buku].end(), level);
                if(it_level == list_level[input_buku].begin())
                    minLevel = abs(*it_level - level);
                else if(it_level == list_level[input_buku].end())
                    minLevel = abs(*(it_level - 1) - level); // jika data diluar level, maka ambil level paling akhir
                else
                    minLevel = min(abs(*it_level - level), abs(*(it_level - 1) - level));
                
                sz = list_server[input_buku].size();
                for(int i = 0; i < sz; i++)
                    vis.insert(list_level[input_buku][i]);
                pq.push(mp(minLevel, input_buku));
            }
        }
        
        if(flag)
        {
            cout << "As Client " << i;
            cout << " is unable to find the needed data, they went to the competitor instead :(\n";
        }
        else{
            cout << "Client " << i;
            cout << " got what they need\n";
            while(!pq.empty())
            {
                cout << pq.top().s << ' ';
                cout << nama_server[pq.top().s];
                cout << '\n';
                pq.pop();
            }
        }
        
        total += vis.size();
    }
    cout << "Number of connections: " << total;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    process();
    testCase();
    return 0;
}
