#include <bits/stdc++.h>

using namespace std;

typedef struct S_pair{
    int32_t u;
    int32_t v;
    double w;
}s_pair;

double dist(pair<double, double> num[], int32_t u, int32_t v){
    double tp_u = num[u].first - num[v].first;
    double tp_v = num[u].second - num[v].second;
    return sqrt(tp_u * tp_u + tp_v * tp_v);
}

struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.w > b.w;
    }
};

int main(){

    int32_t t = 0;
    cin >> t;

    for (int32_t p = 0; p < t ; p++){
        if (p != 0) cout << endl;

        int32_t point_num = 0;
        double tp_x = 0, tp_y = 0;
        cin >> point_num;

        pair<double, double> num[point_num];
        for (int32_t i = 0 ; i < point_num ; i++){
            cin >> tp_x >> tp_y;
            num[i] = {tp_x, tp_y};
        }

        vector<s_pair> edge[point_num];
        for (int32_t i = 0 ; i < point_num ; i++){
            for (int32_t j = i+1 ; j < point_num ; j++){
                edge[i].push_back({i, j, dist(num, i, j)});
                edge[j].push_back({j, i, dist(num, i, j)});
            }
        }

        bool vis[point_num] = {0};
        priority_queue<s_pair, vector<s_pair>, cmp> stl;
        queue<int32_t> order;
        order.push(0);
        vis[0] = 1;

        double ans = 0;

        while (!order.empty()){
            int32_t cur = order.front();
            order.pop();

            for (auto c:edge[cur]){
                stl.push(c);
            }

            while (!stl.empty()){
                s_pair temp = stl.top();
                stl.pop();

                if (vis[temp.v] == 0){
                    order.push(temp.v);
                    vis[temp.v] = 1;
                    ans += temp.w;
                    break;
                }
            }
        }

        printf("%.2f\n", ans);

    }


    return 0;
}
