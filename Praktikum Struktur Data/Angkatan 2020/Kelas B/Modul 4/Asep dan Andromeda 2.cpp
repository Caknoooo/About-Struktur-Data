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
vector<vi> v(11, vi(11));
vector<vi> visited(11, vi(11));

int r[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int c[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int leave(int row, int column)
{
    return(row < 0 || row > 4 || column < 0 || column > 4);
}

void DFS(int row, int column)
{
    for(int i = 0; i < 8; i++)
    {
        int next_row = row + r[i], 
            next_column = column + c[i];
            
        if(leave(next_row, next_column))
            continue;
            
        if(!visited[next_row][next_column] && v[next_row][next_column])
        {
            visited[next_row][next_column] = 1;
            DFS(next_row, next_column);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cin >> v[i][j];
    }
    
    int pulau = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(!visited[i][j] && v[i][j])
            {
                visited[i][j];
                pulau++;
                DFS(i, j);
            }
        }
    }
    cout << "Jumlah pulau Andromeda: " <<  pulau << endl;
}
