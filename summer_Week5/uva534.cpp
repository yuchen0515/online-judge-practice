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

double dist(pair<int32_t, int32_t> a, pair<int32_t, int32_t> b){
    int32_t tp_a = a.first - b.first; 
    int32_t tp_b = a.second - b.second;
    return sqrt((double)(tp_a * tp_a) + (tp_b * tp_b));
}

int32_t dis_find(int32_t root[], int32_t a){
    if (a != root[a]){
        return root[a] = dis_find(root, root[a]);
    }else return a;
}

void dis_union(int32_t root[], int32_t a, int32_t b){
    int32_t x = dis_find(root, a);
    int32_t y = dis_find(root, b);

    int32_t min_t = x < y ? x : y;
    int32_t max_t = x > y ? x : y;

    if (x != y) root[max_t] = min_t;
}


int main(){
    
    int32_t t = 0, cas = 1;

    while (1){
        cin >> t;
        if (t == 0) break;
        int32_t tp_x = 0, tp_y = 0;

        cout << "Scenario #" << cas << endl;

        pair<int32_t, int32_t> num[t];

        int32_t root[t];
        
        for (int32_t i = 0; i < t; i++){
            cin >> tp_x >> tp_y;
            num[i] = {tp_x, tp_y};
            root[i] = i;
        }

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        for (int32_t i = 0 ; i < t; i++){
            for (int32_t j = i+1 ; j < t; j++){
                stl.push({i, j, dist(num[i], num[j])});
                stl.push({j, i, dist(num[i], num[j])});
            }
        }

        double ans = 0;

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            
            if (dis_find(root, 1) == 0) break;

            int32_t dis_u = dis_find(root, temp.u);
            int32_t dis_v = dis_find(root, temp.v);
            if (dis_u != dis_v){
                if (dis_u + dis_v == 1){
                    ans = temp.w;
                    break;
                }
                dis_union(root, temp.u, temp.v);
            }
        }
        printf("Frog Distance = %.3f\n\n", ans);
        cas += 1;
    }

    return 0;
}
