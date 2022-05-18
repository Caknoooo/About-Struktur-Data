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
#define MAX 10005
#define MOD 1000000007
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        priority_queue<pii> pq;
        queue<pii > q;
        int a, index, count = 1, x;
        cin >> a >> index;
        for(int i = 0; i < a; i++)
        {
            cin >> x;
            if(i == index)
            {
                pq.push(mp(x, 1));
                q.push(mp(x, 1));
            }
            else{
                pq.push(mp(x, 0));
                q.push(mp(x, 0));
            }
        }
        
        while(!q.empty())
        {
            if(q.front().second == 1 && q.front().first >= pq.top().first)
            {
                break;
            }
            if(q.front().first < pq.top().first)
            {
                q.push(mp(q.front().first, q.front().second));
                q.pop();
            }
            else{
                q.pop();
                pq.pop();
                count++;
            }
        }
        cout << count << endl;
    }
}
