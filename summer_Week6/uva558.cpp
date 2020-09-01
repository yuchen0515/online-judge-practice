#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef struct S_pair{
    int32_t to;
    int32_t w;
}s_pair;

int main(){

    int32_t cas = 0, point_num = 0, road = 0;
    cin >> cas;
    while (cas--){

        cin >> point_num >> road;

        int32_t tp_x = 0 , tp_y = 0, tp_w = 0;
        
        vector<s_pair> num[point_num];
        int32_t table[point_num];
        memset(table, 0x3f, sizeof(table));

        while (road--){
            cin >> tp_x >> tp_y >> tp_w;
            num[tp_x].push_back({tp_y, tp_w});
        }
        
        int32_t copy[point_num];

        table[0] = 0;
        for (int32_t i = 1 ; i <= point_num; i++){
            queue<int32_t> stl;
            int32_t vis[point_num+1] = {0};
            stl.push(0);

            if (i == point_num){
                for (int32_t i = 0 ; i < point_num ; i++)
                    copy[i] = table[i];
            }

            while (!stl.empty()){
                int32_t temp = stl.front();
                stl.pop();

                for (auto c:num[temp]){

                    if (table[temp] + c.w < table[c.to]){
                        table[c.to] = table[temp] + c.w;
                    }
                    if (vis[c.to] == 0){
                        vis[c.to] = 1;
                        stl.push(c.to);
                    }
                }
            }

        }


        bool check = 0;

        for (int32_t i = 0 ; i < point_num ; i++){
            if (table[i] != copy[i]){
                check = 1;
                break;
            }
        }


        if (check) cout << "possible\n";
        else cout << "not possible\n";

    }



    return 0;
}
