#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> //perhatikan header ini harus disertakan
#include <ext/pb_ds/tree_policy.hpp> //perhatikan header ini harus disertakan

using namespace std;
using namespace __gnu_pbds; //struktur data ini berada pada class __gnu_pbds

typedef tree<
int, //bisa diganti sesuai tipe data yang dibutuhkan
null_type,
less<int>, //jika ingin elemen tidak unik bisa menggunakan less_equal
rb_tree_tag,
tree_order_statistics_node_update> AVL; //karena namanya yang panjang, sebaiknya menggunakan typedef
                                        //menggunakan nama AVL karena memiliki fungsi-fungsi yang ada pada AVL Tree

int main()
{    
    int t, n, idx, input, junk, cnt;
    cin >> t;
    while(t--)
    {
        cnt = 0;
        AVL X;
        cin >> n >> idx;
        for(int i = 0; i < n; i++)
        {
            cin >> input;
            if(input == 0)
            {
                if(*X.find_by_order(idx - 1) == 0)
                    cout << "-1" << endl;
                else
                    cout << *X.find_by_order(idx - 1) << endl;
            }
            else
                X.insert(input);
        }
    }

//    cout << "elemen pada index ke 0 adalah : " << *X.find_by_order(0) << endl;
//    cout << "elemen pada index ke 5 adalah : " << *X.find_by_order(3) << endl;
//
//    cout << "jumlah elemen yang lebih kecil dari 6 sebanyak : " << X.order_of_key(6) << endl;
}
