#include <bits/stdc++.h>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 1005
#define MOD 1000000007
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, input, cnt = 0, x = 0;
    cin >> n;
    vi v(MAX, 0), save(MAX, 0);
    set<int> s;
    set<int>::iterator it;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        if(input < 0)
        {
            input = abs(input);
            v[input]--;
            if(v[input] < 0)
                save[cnt++] = input;
            if(v[input] != 0)
                v[input] = 0;
        }
        else{
            v[input]++;
            if(v[input] > 1)
            {
                save[cnt++] = input;
            }
        }
    }
    
    cout << cnt << endl;
    
    for(int i = 0; i < cnt; i++)
        cout << save[i] << endl;
}
