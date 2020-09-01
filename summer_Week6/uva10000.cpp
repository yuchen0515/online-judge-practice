#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int32_t cas = 1, point_num = 0;
    while (1){
        cin >> point_num;
        if (point_num == 0) break;

        int32_t tp_x = 0 , tp_y = 0;
        int32_t table[point_num+1][point_num+1];
        int32_t short_path[point_num+1][point_num+1];

        memset(table, 0 , sizeof(table));
        memset(short_path, 0 , sizeof(short_path));

        int32_t start = 0;
        cin >> start;

        while (1){
            cin >> tp_x >> tp_y;
            if (tp_x == 0 && tp_y == 0) break;

            table[tp_x][tp_y] = 1;
        }

        for (int32_t k = 1 ; k <= point_num ; k++){
            for (int32_t i = 1 ; i <= point_num ; i++){
                for (int32_t j = 1 ; j <= point_num ; j++){
                    if (table[i][j] > 0)
                        table[i][j] = max(table[i][j], table[i][k]+table[k][j]);
                }
            }
        }

        tp_x = 0;
        int32_t res = 0;
        for (int32_t i = 1 ; i <= point_num ; i++){
            if (table[start][i] > tp_x){
                tp_x = table[start][i];
                res = i;
            }
        }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cas, start, tp_x, res);


        cas += 1;
    }



    return 0;
}
