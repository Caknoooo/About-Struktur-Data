#include <bits/stdc++.h>
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
typedef long long ll;

int main()
{
    stack<ll> s;
    queue<ll> q;
    int n, w, in, sum = 0;
    string cmd;
    loop(t)
    {
        cin >> in;
        q.push(in);
    }
    cin >> n >> w;
    while(n--)
    {
        cin >> cmd;
        if(cmd == "beri")
        {
            s.push(q.front());
            sum += q.front();
            q.pop();
        }
        else{
            sum -= s.top();
            s.pop();
        }
    }
    if(sum == w)
        cout << sum << " " << s.size();
    else
        cout << "YAH KOSONG DONG" << endl;
}
