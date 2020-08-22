#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

typedef struct ppair{
    pair<int32_t, int32_t> x;
    pair<int32_t, int32_t> y;
    double w;
}s_pair;

double dist(s_pair a, s_pair b){
    return sqrt((a.x.first-b.x.first)*(a.x.first-b.x.first) + (a.y.second-b.y.second)*(a.y.second-b.y.second));
}


struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.w > b.w;
    }
};

double ans = 0;

int main(){

    int32_t t = 0;
    cin >> t;

    for (int32_t p = 0 ; p < t ; p++){
        ans = 0;

        if (p != 0) cout << endl;

        int32_t edge_num = 0;
        double tp_x = 0 , tp_y = 0;
        cin >> edge_num;

        pair<int32_t, int32_t> num[edge_num];
        int32_t root[edge_num];
        int32_t tol_num = 0;

        for (int32_t i = 0 ; i < edge_num ; i++){
            cin >> tp_x >> tp_y;
            num[i] = {tp_x, tp_y};
            root[i] = i;
        }

        priority_queue<s_pair, vector<s_pair>, cmp> stl;


        for (int32_t i = 0 ; i < edge_num ; i++){
            for (int32_t j = i + 1 ; j < edge_num ; j++){
                stl.push({num[i], num[j], dist(num[i], num[j])});
                stl.push({num[j], num[i], dist(num[i], num[j])});
            }
        }
        
        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();
            //尚未完成

        }







        printf("%.2lf\n", ans);
    }

    return 0;
}
