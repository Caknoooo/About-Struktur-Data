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
    queue<int> q1, q2, q3, q4, tanda;
    map<int, string> mpp, st;
    map<string, int> mpp2;
    map<int, string>::iterator it;
    string str;
    for(int i = 1; i <= 4; i++)
    {
        cin >> str;
        mpp[i] = str;
        mpp2[str] = i;
    }
    
    int n, u, v, cek, input, size;
    string cmd;
    vector<string> vec;
    cin >> n >> cmd;
    int mark = mpp2[cmd];
    if(mark == 1)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> cek >> input;
            if(cek == 1)
                tanda.push(input);
            else if(cek == 2)
                q2.push(input);
            else if(cek == 3)
                q3.push(input);
            else
                q4.push(input);
        }
        
        while(!tanda.empty())
        {
            int a, b, c;
            int front = tanda.front();
            tanda.pop();
            if(!q2.empty())
            {
                a = q2.front();
                q2.pop();
                if(front == a)
                    st.insert(mp(mpp2[mpp[2]], mpp[2]));
            }
            if(!q3.empty())
            {
                b = q3.front();
                q3.pop();
                if(front == b)
                    st.insert(mp(mpp2[mpp[3]], mpp[3]));
            }
            if(!q4.empty())
            {
                c = q4.front();
                q4.pop();
                if(front == c)
                    st.insert(mp(mpp2[mpp[4]], mpp[4]));
            }
        }
    }
    
    else if(mark == 2)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> cek >> input;
            if(cek == 1)
                q1.push(input);
            else if(cek == 2)
                tanda.push(input);
            else if(cek == 3)
                q3.push(input);
            else
                q4.push(input);
        }
        
        while(!tanda.empty())
        {
            int a, b, c;
            int front = tanda.front();
            tanda.pop();
            if(!q1.empty())
            {
                a = q1.front();
                q1.pop();
                if(front == a)
                    st.insert(mp(mpp2[mpp[1]], mpp[1]));
            }
            if(!q3.empty())
            {
                b = q3.front();
                q3.pop();
                if(front == b)
                    st.insert(mp(mpp2[mpp[3]], mpp[3]));
            }
            if(!q4.empty())
            {
                c = q4.front();
                q4.pop();
                if(front == c)
                    st.insert(mp(mpp2[mpp[4]], mpp[4]));
            }
        }
    }
    
    else if(mark == 3)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> cek >> input;
            if(cek == 1)
                q1.push(input);
            else if(cek == 2)
                q2.push(input);
            else if(cek == 3)
                tanda.push(input);
            else
                q4.push(input);
        }
        
        while(!tanda.empty())
        {
            int a, b, c;
            int front = tanda.front();
            tanda.pop();
            if(!q1.empty())
            {
                a = q1.front();
                q1.pop();
                if(front == a)
                    st.insert(mp(mpp2[mpp[1]], mpp[1]));
            }
            if(!q2.empty())
            {
                b = q2.front();
                q2.pop();
                if(front == b)
                    st.insert(mp(mpp2[mpp[2]], mpp[2]));
            }
            if(!q4.empty())
            {
                c = q4.front();
                q4.pop();
                if(front == c)
                    st.insert(mp(mpp2[mpp[4]], mpp[4]));
            }
        }
    }
    
    else if(mark == 4)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> cek >> input;
            if(cek == 1)
                q1.push(input);
            else if(cek == 2)
                q2.push(input);
            else if(cek == 3)
                q3.push(input);
            else
                tanda.push(input);
        }
        
        while(!tanda.empty())
        {
            int a, b, c;
            int front = tanda.front();
            tanda.pop();
            if(!q1.empty())
            {
                a = q1.front();
                q1.pop();
                if(front == a)
                    st.insert(mp(mpp2[mpp[1]], mpp[1]));
            }
            if(!q2.empty())
            {
                b = q2.front();
                q2.pop();
                if(front == b)
                    st.insert(mp(mpp2[mpp[2]], mpp[2]));
            }
            if(!q3.empty())
            {
                c = q3.front();
                q3.pop();
                if(front == c)
                    st.insert(mp(mpp2[mpp[3]], mpp[3]));
            }
        }
    }
    
    if(!st.size())
        cout << cmd << " jaga lagi";
    else{
        int i = 0;
        for(it = st.begin(); it != st.end(); ++it, ++i)
        {
            if(i == st.size() - 1 && i != 0)
                cout << "dan ";
            cout << it->second;    
            if(i < st.size() - 1)
                cout << ",";
            cout << " ";
        }
        cout << "ditangkap oleh " << cmd;
    }
}
