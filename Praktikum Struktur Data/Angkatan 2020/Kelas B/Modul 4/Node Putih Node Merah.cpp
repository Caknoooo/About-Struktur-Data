#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int node, a, b;
    vi vec(MAX);
    cin >> node;
    
    while(cin >> a >> b)
    {
        vec[a]++;
        vec[b]++;
    }
    string junk;
    cin >> junk;
    
    int max_node = 0, max = 0;
    int min_node = 1e9, min = 1e9;
    
    for(int i = 1; i <= node; i++)
    {
        if(vec[i] > max)
        {
            max = vec[i];
            max_node = i;
        }
        if(vec[i] <= min)
        {
            min = vec[i];
            min_node = i;
        }
    }
    cout << max_node << " itu si Node Putih" << endl;
    cout << min_node << " itu si Node Merah" << endl;
}
