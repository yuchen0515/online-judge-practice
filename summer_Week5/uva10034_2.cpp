#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Pair{
    int32_t v;
    int32_t u;
    double w;
}s_pair;


struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.w > b.w;
    }
};

double dist(pair<double, double> a, pair<double, double> b){
    double tp_a = a.first - b.first; 
    double tp_b = a.second - b.second;
    return sqrt((tp_a * tp_a) + (tp_b * tp_b));
}

int32_t dis_find(int32_t root[], int32_t a){
    if (a != root[a]){
        return root[a] = dis_find(root, root[a]);
    }else return a;
}

void dis_union(int32_t root[], int32_t a, int32_t b){
    int32_t x = dis_find(root, a);
    int32_t y = dis_find(root, b);

    if (x != y) root[y] = x;
}


int main(){
    
    int32_t t = 0;
    cin >> t;

    for (int32_t p = 0 ; p < t; p ++){
        if (p != 0) cout << endl;
        int32_t point_num = 0;
        double tp_x = 0, tp_y = 0;

        cin >> point_num;

        pair<double, double> num[point_num];

        int32_t root[point_num];
        
        for (int32_t i = 0; i < point_num ; i++){
            cin >> tp_x >> tp_y;
            num[i] = {tp_x, tp_y};
            root[i] = i;
        }

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        for (int32_t i = 0 ; i < point_num ; i++){
            for (int32_t j = i+1 ; j < point_num ; j++){
                stl.push({i, j, dist(num[i], num[j])});
                stl.push({j, i, dist(num[i], num[j])});
            }
        }

        double ans = 0;

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            if (dis_find(root, temp.u) != dis_find(root, temp.v)){
                ans += temp.w;
                dis_union(root, temp.u, temp.v);
            }
        }
        printf("%.2f\n", ans);
    }


    return 0;
}
