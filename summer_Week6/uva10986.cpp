#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct S_pair{
    int32_t sta;
    int32_t end;
    int32_t w;
}s_pair;

struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.w > b.w;
    }
};


int main(){

    int32_t t = 0;
    cin >> t;

    for (int32_t p = 1 ; p <= t; p++){

        cout << "Case " << "#" << p << ": ";
        int32_t point_num = 0, road = 0;
        int32_t start = 0 , end = 0;
        cin >> point_num >> road >> start >>  end;

        vector<s_pair> num[point_num];

        int32_t short_path[point_num];
        int32_t vis[point_num];

        for (int32_t i = 0 ; i < point_num ; i++){
            short_path[i] = 1000000;
            vis[i] = 0;
        }

        for (int32_t i = 0 ; i < road ; i++){
            int32_t tp_x = 0, tp_y = 0, tp_w = 0;
            cin >> tp_x >> tp_y >> tp_w;
            num[tp_x].push_back({tp_x, tp_y, tp_w});
            num[tp_y].push_back({tp_y, tp_x, tp_w});
        }

        priority_queue<s_pair, vector<s_pair>, cmp> stl;
        stl.push({start, 0, 0});
        short_path[start] = 0;
        vis[start] = 1;

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            for (auto c: num[temp.sta]){
                if (short_path[c.sta] + c.w < short_path[c.end]){
                    short_path[c.end] = c.w + short_path[c.sta];
                    stl.push({c.sta, c.end, c.w});
                }
            }
        }
        if (short_path[end] == 1000000)
            cout << "unreachable" << endl;
        else 
            cout << short_path[end] << endl;

    }


    return 0;
}
