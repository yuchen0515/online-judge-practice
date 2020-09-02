#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct S_pair{
    int32_t from;
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

        vector<s_pair> num[105];
        int32_t short_path[105];
        int32_t cur[105];

        for (int32_t i = 0 ; i < 105; i++){
            short_path[i] = 1000000;
            cur[i] = -1;
        }
        

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        stl.push({0, 0, 0});
        short_path[0] = 0;
        
        char str[100], tp_str;
        int32_t tp_x = 0;
        cin.getline(str, 100, '\n');

        for (int32_t i = 0 ; i < n ; i ++){
            vector<int32_t> arr;
            while (1){
                scanf("%d%c", &tp_x, &tp_str);
                arr.push_back(tp_x);
                if (tp_str == '\n')
                    break;
            }

            for (int32_t j = 0 ; j < arr.size(); j++){
                for (int32_t k = 0 ; k < arr.size() ; k++){
                    if (j==k) continue;
                    num[arr[j]].push_back({arr[j], arr[k], i, abs(arr[j]-arr[k]) * time_arr[i]});
                }
            }
        }

        if (num[0].size() != 0)
            stl.push(num[0][0]);

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            for (auto c: num[temp.from]){
                int32_t cmpp = short_path[c.from] + c.w;
                
                if (cur[c.from] != -1 && cur[c.from] != c.t){
                    cmpp += 60;
                }

                if (cmpp < short_path[c.to]){
                    short_path[c.to] = cmpp;
                    stl.push({c.to, c.from, c.t, c.w});
                    cur[c.to] = c.t;
                }
            }
        }

        if (short_path[k] == 1000000)
            cout << "IMPOSSIBLE" << endl;
        else 
            cout << short_path[k] << endl;
    }


    return 0;
}
