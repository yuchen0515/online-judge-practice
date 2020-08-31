#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct S_pair{
    int32_t row;
    int32_t col;
    int32_t w;
}s_pair;

struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.w > b.w;
    }
};

int32_t rec[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(){

    int32_t t = 0;
    cin >> t;

    while (t--){
        int32_t row = 0 , col = 0;
        cin >> row >> col;

        int32_t table[row+2][col+2];
        int32_t short_path[row+2][col+2];
        int32_t vis[row+2][col+2];


        for (int32_t i = 0 ; i <= row+1 ; i++){
            for (int32_t j = 0 ; j <= col+1 ; j++){
                short_path[i][j] = 1000000;
                vis[i][j] = 0;
                table[i][j] = 0;
                if ((i >= 1 && i <= row) && (j >= 1 && j <= col))
                    cin >> table[i][j];
                else
                    vis[i][j] = 1;
            }
        }

        short_path[1][1] = table[1][1];
        vis[1][1] = 1;
        priority_queue<s_pair, vector<s_pair>, cmp> stl;
        stl.push({1, 1, short_path[1][1]});

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            for (int32_t i = 0 ; i < 4 ; i ++){
                int32_t tp_x = rec[i][0] + temp.row;
                int32_t tp_y = rec[i][1] + temp.col;
                if (short_path[temp.row][temp.col] + table[tp_x][tp_y] < short_path[tp_x][tp_y])
                    short_path[tp_x][tp_y] = short_path[temp.row][temp.col] + table[tp_x][tp_y];
                if (vis[tp_x][tp_y] == 0){
                    vis[tp_x][tp_y] = 1;
                    stl.push({tp_x, tp_y, short_path[tp_x][tp_y]});
                }
            }
        }
        cout << short_path[row][col] << endl;;

    }


    return 0;
}
