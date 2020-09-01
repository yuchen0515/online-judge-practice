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

    int32_t cas = 1, point_num = 0;
    while (1){
        cin >> point_num;
        if (point_num == 0) break;

        int32_t tp_x = 0 , tp_y = 0;
        
        vector<s_pair> num[point_num+1];
        int32_t table[point_num+1] = {0};

        int32_t start = 0;
        cin >> start;

        int32_t long_path = 0 , end = -1;

        while (1){
            cin >> tp_x >> tp_y;
            if (tp_x == 0 && tp_y == 0) break;

            num[tp_x].push_back({tp_y, 1});
        }
        
        for (int32_t i = 0 ; i < point_num-1; i++){
            queue<int32_t> stl;
            int32_t vis[point_num+1] = {0};
            stl.push(start);


            while (!stl.empty()){
                int32_t temp = stl.front();
                stl.pop();

                for (auto c:num[temp]){

                    if (table[temp] + c.w > table[c.to]){
                        table[c.to] = table[temp] + c.w;
                    }
                    if (vis[c.to] == 0){
                        vis[c.to] = 1;
                        stl.push(c.to);
                    }

                }

            }
        }



        for (int32_t i = 1 ; i <= point_num ; i++){
            if (table[i] > long_path){
                long_path = table[i];
                end = i;
            }
        }

        if (long_path == 0)
            end = start;

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cas, start, long_path, end);


        cas += 1;
    }



    return 0;
}
