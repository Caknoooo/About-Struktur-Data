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
#define MAX 505
#define MOD 1000000007

typedef struct cek{
    int x;
    int y;
    int distance;
} Node;

vector<vc> str(MAX, vc(MAX));
vector<vb> visited(MAX, vb(MAX, 0));
map<char, int> mpW;
int row[] = {-1, 0, 1, 0}, baris;
int column[] = {0, 1, 0, -1}, kolom, minimum = MOD;
int N, W, H, value, tandaX, tandaY;
Node node;
queue<Node> q;

int leave(int x, int y)
{
    return(!visited[x][y] && str[x][y] && x <= W && y <= H && x > 0 && y > 0);
}

int findCostMinimum(int x, int y)
{
    visited[x][y] = true;
    node.x = x;
    node.y = y;
    node.distance = 0;
    q.push(node);
    while(!q.empty())
    {
        int X = q.front().x;
        int Y = q.front().y;
        int dist = q.front().distance;
        q.pop();
        
        if(X == W || X == 1 || Y == H || Y == 1)
        {
            if(dist < minimum)
                minimum = dist;
            continue;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int next_row = row[i] + X;
            int next_column = column[i] + Y;
            if(leave(next_row, next_column))
            {
                visited[next_row][next_column] = true;
                node.x = next_row;
                node.y = next_column;
                node.distance = dist + mpW[str[next_row][next_column]];
                q.push(node);
            }
        }
    }
    return minimum;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    char input;
    cin >> N >> W >> H;
    
    for(int i = 0; i < N; i++)
    {
        cin >> input >> value;
        mpW[input] = value;
    }
    
    for(int i = 1; i <= W; i++)
    {
        for(int j = 1; j <= H; j++)
        {
            cin >> str[i][j];
            if(str[i][j] == 'Y')
            {
                tandaX = i;
                tandaY = j;
            }
        }
    }
    
    if(tandaX == W || tandaX == 1 || tandaY == H || tandaY == 1)
        return cout << 0 << endl, 0;
    
    return cout << findCostMinimum(tandaX, tandaY) << endl, 0;
}
