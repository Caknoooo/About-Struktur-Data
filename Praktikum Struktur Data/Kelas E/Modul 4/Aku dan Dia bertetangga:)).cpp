#include <bits/stdc++.h>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define psi pair<string, int>
#define pb push_back
#define mp make_pair
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 10005
#define MOD 1000000007
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    string str[MAX], str2, search;
    map<string, vector<psi> > mpp;
    int t, cost, n;
    cin >> t;
    for(int i = 0; i < t; i++)
        cin >> str[i];
    
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        while(n--)
        {
            cin >> str2 >> cost;
            mpp[str[i]].pb(mp(str2, cost)); 
        }
    }
    
    cin >> search;
    if(mpp[search].size() == 0)
        return cout << "TIDAK TERSEDIA" << endl, 0;
    
//    for(int i = 0; i < t - 1; i++)
//    {
//        cout << "("<<  mpp[search][i].first << ", " << mpp[search][i].second << ") ";
//    }
    
    for(auto it = mpp[search].begin(); it != mpp[search].end(); it++)
    {
        cout <<  "("<<  it->first << ", " << it->second << ") ";
    }
}
