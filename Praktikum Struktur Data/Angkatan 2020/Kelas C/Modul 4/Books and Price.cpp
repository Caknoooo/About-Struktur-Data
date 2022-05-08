#include <bits/stdc++.h>
#include <string>
#include <vector>
#define SUKSES using
#define BUTUH namespace
#define PROSES std

SUKSES BUTUH PROSES;

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<int, int>
#define loop(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define MAX 100005

int main()
{
    map<string, int> mp;
    string str;
    char tmp[MAX], harga[MAX];
    int cnt = 0, cnt1 = 0;
    
    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ';' || i == str.length() - 1)
        {
            int num = atoi(harga);
            if(tmp)
                mp[tmp] = num;
            memset(tmp, 0, sizeof(tmp));
            memset(harga, 0, sizeof(harga));
            cnt = 0, cnt1 = 0;
            continue;
        }
        if(str[i] == '_')
            continue;
        else if(str[i] >= '0' && str[i] <= '9')
        {
            harga[cnt1] = str[i];
            cnt1++;
        }
        else{
            tmp[cnt] = str[i];
            cnt++;
        }
    }
    
    int sum = 0;
    loop(t)
    {
        cin >> str;
        sum += mp[str];
    }
    cout << sum << endl;
}
