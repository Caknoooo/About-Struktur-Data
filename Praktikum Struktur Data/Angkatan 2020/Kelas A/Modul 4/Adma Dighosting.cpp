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

vector<vi> adjList;
vi memo;

int DFS(int currNode)
{
    if(memo[currNode] != -1)
        return memo[currNode];
        
    int maxDist = 0;
    
    rep(i, 0, adjList[currNode].size())
    {
        int nextNode = adjList[currNode][i];
        maxDist = max(maxDist, DFS(nextNode) + 1);
    }
    return memo[currNode] = maxDist;
}

int main()
{
    int n, a, b;
    cin >> n;
    
    adjList.assign(n + 1, vi());
    memo.assign(n + 1, -1);
    
    repp(i, 1, n - 1)
    {
        cin >> a >> b;
        adjList[a].push_back(b); // menyambungkan edge dari node A ke Node B
    }
    
    int ans = 0;
    
    repp(i, 1, n)
        ans = max(ans, DFS(i));
    
    return cout << ans << endl, 0;
}
