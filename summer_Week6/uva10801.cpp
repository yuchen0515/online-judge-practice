#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct S_pair{
    int32_t to;
    int32_t t;
    int32_t w;
}s_pair;

struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.w > b.w;
    }
};


int main(){


    int32_t n = 0 , k = 0;
    while (cin >> n >> k){
        int32_t time_arr[n];
        for (int32_t i = 0 ; i < n ; i++)
            cin >> time_arr[i];

        vector<s_pair> num[k];
        int32_t short_path[k];
        int32_t vis[k];

        for (int32_t i = 0 ; i < k; i++){
            short_path[i] = 1000000;
            vis[i] = 0;
        }
        
        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        stl.push({0, 0, 0});
        short_path[0] = 0;

        //思考電梯存法，更新方法

        /*
        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            for (auto c: num[temp.sta]){
                if (short_path[c.sta] + c.w < short_path[c.end]){
                    short_path[c.end] = c.w + short_path[c.sta];
                    stl.push({c.end, c.sta, c.w});
                }
            }
        }
        */

        if (short_path[k-1] == 1000000)
            cout << "IMPOSSIBLE" << endl;
        else 
            cout << short_path[k-1] << endl;
    }








    return 0;
}
