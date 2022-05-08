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
#define MAX 205
#define MOD 1000000007

int t, xA, xB, yA, yB, n, x, y;
int arr[MAX][MAX];

int maxHist(int baris)
{
    stack<int> idx; // untuk menyimpan index
    
    int atas; // untuk mengecek top stack -> top stack isi panjang vertical
    
    int max_luas = 0; // untuk menyimpan luas maksimal
    
    int luas = 0, i = 0;
    
    while(i <= y)
    {
        if(idx.empty() || arr[baris][idx.top()] <= arr[baris][i])
            idx.push(i++);
            
        else{
            atas = arr[baris][idx.top()];
            idx.pop();
            luas = atas * i;
            
            if(!idx.empty())
                luas = atas * (i - idx.top() - 1);
            //cout << luas << endl;
            
            max_luas = max(luas, max_luas);
        }
    }
    
    while(!idx.empty())
    {
        atas = arr[baris][idx.top()];
        idx.pop();
        luas = atas * i;
            
        if(!idx.empty())
            luas = atas * (i - idx.top() - 1);
        
        //cout << "idx : " << luas << endl;
        max_luas = max(luas, max_luas);
    }
    return max_luas;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cin >> t;
    while(t--)
    {
        memset(arr, 0, sizeof(arr));
        cin >> x >> y >> n;
        
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                arr[i][j] = 1;
            }
        }
        
        while(n--)
        {
            cin >> xA >> yA >> xB >> yB;
            for(int i = xA; i <= xB; i++)
            {
                for(int j = yA; j <= yB; j++)
                {
                    arr[i][j] = 0;
                }
            }
        }
        
//        for(int i = 1; i <= x; i++)
//        {
//            for(int j = 1; j <= y; j++)
//            {
//                cout << arr[i][j] << " ";
//            }
//            cout << endl;
//        }

        int luas = maxHist(1); // cari luas pertama
        
        for(int i = 2; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                if(arr[i][j])
                    arr[i][j] += arr[i - 1][j];
            }
            
            luas = max(luas, maxHist(i));
        }
        
        cout << luas << endl;
    }
}
