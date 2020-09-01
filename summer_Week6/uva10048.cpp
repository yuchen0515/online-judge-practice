#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int32_t c = 0, s = 0 , q = 0, cas = 1;
    while (1){
        cin >> c >> s >> q;
        if (c==0 && s==0 && q==0) break;

        if (cas != 1) cout << endl;

        cout << "Case #" << cas << endl;

        int32_t table[c+1][c+1];
        int32_t tp_x = 0, tp_y = 0 , tp_w = 0;

        memset(table, 0x3f, sizeof(table));

        for (int32_t i = 1 ; i <= c ; i++)
            table[i][i] = 0;

        for (int32_t i = 0 ; i < s ; i++){
            cin >> tp_x >> tp_y >> tp_w;
            table[tp_x][tp_y] = tp_w;
            table[tp_y][tp_x] = tp_w;
        }

        for (int32_t k = 1 ; k <= c; k++){
            for (int32_t i = 1 ; i <= c ; i++){
                for (int32_t j = 1 ; j <= c ; j ++){
                    table[i][j] = min(table[i][j], max(table[i][k], table[k][j]));
                }
            }
        }

        for (int32_t i = 0 ; i < q ; i++){
            cin >> tp_x >> tp_y;
            if (table[tp_x][tp_y] > 10000000)
                cout << "no path\n";
            else
                cout << table[tp_x][tp_y] << endl;
        }


        cas +=1;
    }


    return 0;
}
