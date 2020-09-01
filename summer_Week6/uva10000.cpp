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
        int32_t vis[point_num+1] = {0};

        int32_t start = 0;
        cin >> start;

        while (1){
            cin >> tp_x >> tp_y;
            if (tp_x == 0 && tp_y == 0) break;

            num[tp_x].push_back({tp_y, 0});
        }

        queue<int32_t> order;
        order.push(start);
        vis[start] = 1;

        int32_t long_path = 0 , end = 10000;
        while (!order.empty()){
            int32_t temp = order.front();
            order.pop();

        //修
            for (auto c:num[temp]){
                if (vis[c.to] == 0){
                    order.push(c.to);
                    vis[c.to] = vis[temp] + 1;
                }
                if (vis[c.to] >= long_path){
                    if (vis[c.to] == long_path && c.to < end)
                        end = c.to;
                    if (vis[c.to] > long_path)
                        end = c.to;

                    long_path = vis[c.to];

                }
            }
        }




        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cas, start, long_path, end);


        cas += 1;
    }



    return 0;
}
