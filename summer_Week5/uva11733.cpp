#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Pair{
    int32_t v;
    int32_t u;
    int32_t w;
}s_pair;


struct cmp{
    bool operator()(s_pair a, s_pair b){
        int32_t min_a = a.v < a.u ? a.v : a.u;
        int32_t min_b = b.v < b.u ? b.v : b.u;
        if (a.w == b.w)
            return min_a > min_b;
        return a.w > b.w;
    }
};

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

    for (int32_t p = 1 ; p <= t; p++){
        int32_t point_num = 0, road = 0, price = 0;
        int32_t tp_x = 0, tp_y = 0, tp_d = 0;

        cin >> point_num >> road >> price;

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        int32_t root[point_num+1];

        for (int32_t i = 0; i <= point_num ; i++){
            root[i] = i;
            if (i != 0){
                stl.push({0, i, price});
                stl.push({i, 0, price});
            }
        }

        for (int32_t i = 1; i <=  road; i++){
            cin >> tp_x >> tp_y >> tp_d;
            stl.push({tp_x, tp_y, tp_d});
            stl.push({tp_y, tp_x, tp_d});
        }

        int32_t ans = 0, cou = 0;

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            int32_t u_tp = dis_find(root, temp.u);
            int32_t v_tp = dis_find(root, temp.v);
            if (u_tp != v_tp){
                ans += temp.w;
                if (temp.u == 0 || temp.v== 0) cou += 1;
                dis_union(root, temp.u, temp.v);
            }
        }
        printf("Case #%d: %d %d\n", p, ans, cou);
    }


    return 0;
}
