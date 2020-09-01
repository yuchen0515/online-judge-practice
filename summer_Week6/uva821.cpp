#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int32_t from = 0 , to = 0, cas = 0;
    int32_t t = 1;
    while (1){
        cas = 0;

        int32_t table[105][105];
        int32_t vis[105];
        int32_t num = 0 ;
        memset(table, 0x3f, sizeof(table));

        for (int32_t i = 0 ; i < 105; i++){
            table[i][i] = 0;
            vis[i] = 1;
        }

        while (1){
            cin >> from >> to;
            if (from == 0 && to == 0) break;
            table[from][to] = 1;
            
            if (vis[from]){
                vis[from] = 0;
                num +=1;
            }
            if (vis[to]){
                vis[to] = 0;
                num +=1;
            }

            cas += 1;
        }
        if (cas == 0) break;


        for (int32_t k = 0 ; k < 105; k++){
            for (int32_t i = 0 ; i < 105; i++){
                for (int32_t j = 0 ; j < 105; j ++){
                    table[i][j] = min(table[i][j], table[i][k] + table[k][j]);

                }
            }

        }

        int32_t tol = 0;
        for (int32_t i = 0 ; i < 105 ; i++){
            for (int32_t j = 0 ; j < 105; j++){
                if (table[i][j] < 10000000){
                    tol += table[i][j];
                }
            }
        }

        cout << "Case " << t << ": ";
        cout << "average length between pages = ";
        printf("%.3f clicks\n", tol / (double)(num * (num-1)));

        t += 1;
    }


    return 0;
}
