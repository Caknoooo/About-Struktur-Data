#include <bits/stdc++.h>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define mp make_pair
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 10005
#define MOD 1000000007
int n, t, input, low, high, cnt = 1;
vector<int> v;

void find(int cari)
{
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(v[i] + v[j] == cari)
            {
                high = v[i];
                low = v[j];
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        cout << "Case " << cnt++ << ": " << low << " " << high << endl;
    else
        cout << "Case " << cnt++ << ": " << cari << " not found" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        cin >> input;
        find(input);
    }
}
