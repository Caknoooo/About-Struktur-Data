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

vector<vi> vec(10, vi(10)); // equal to vec[10][10]
vector<vb> visited(10, vb(10)); // 

int rowC[] = {-1, 0, 1, 0};
int columnC[] = {0, 1, 0, -1};

bool leave(int row, int column)
{
    return(row < 0 || row > 9 || column < 0 || column > 9);
}

void DFS(int row, int column)
{
    for(int i = 0; i < 4; i++)
    {
        int next_row = row + rowC[i];
        int next_column = column + columnC[i];
        
        if(leave(next_row, next_column))
            continue;
        
        if(!visited[next_row][next_column] && vec[next_row][next_column])
        {
            visited[next_row][next_column] = 1;
            DFS(next_row, next_column);    
        } 
    }
}

int main()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cin >> vec[i][j];
        
    int banyakPulau = 0;
    
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            if(!visited[i][j] && vec[i][j])
            {
                visited[i][j] = 1;
                DFS(i, j);
                banyakPulau++;
            }
        }
    
    return cout << banyakPulau, 0;
}
