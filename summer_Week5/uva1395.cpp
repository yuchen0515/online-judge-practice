#include <bits/stdc++.h>

using namespace std;

typedef struct Pair{
    int32_t v;
    int32_t u;
    int32_t w;
}s_pair;

bool cmp(s_pair a, s_pair b){
    return a.w < b.w;
}

void dis_init(int32_t root[], int32_t point_num){
    for (int32_t i = 0 ; i < point_num ; i++)
        root[i] = i;
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

bool check_connect(int32_t root[], int32_t point_num){
    int32_t check = dis_find(root, 0);
    int32_t check_ans = 1;
    for (int32_t i = 1 ; i < point_num ; i++){
        if (dis_find(root, i) != check){
            check_ans = 0;
            break;
        }
    }
    return check_ans;
}

int32_t kruscal(vector<s_pair> num, int32_t root[], int32_t road, int32_t point_num, int32_t sta){
    int32_t ans_max = -1000000, ans_min = 1000000;
    
    dis_init(root, point_num);

    for (int32_t i = sta ; i < road ; i++){
        if (dis_find(root, num[i].u) != dis_find(root, num[i].v)){
            if (ans_max < num[i].w) ans_max= num[i].w;
            if (ans_min > num[i].w) ans_min= num[i].w;

            dis_union(root, num[i].u, num[i].v);
        }
    }
    return ans_max - ans_min;
}

int main(){

    int32_t point_num = 0 , road = 0;

    while (1){

        cin >> point_num >> road;

        if (point_num == 0 && road ==0) break;

        vector<s_pair> num;

        int32_t root[point_num];

        int32_t tp_x = 0, tp_y = 0, tp_d = 0;

        for (int32_t i = 0; i < road; i++){
            cin >> tp_x >> tp_y >> tp_d;
            num.push_back({tp_x-1, tp_y-1, tp_d});
            num.push_back({tp_y-1, tp_x-1, tp_d});
        }

        sort(num.begin(), num.end(), cmp);

        int32_t check = 0, ans = 1000000;
        for (int32_t i = 0 ; i < road*2 ; i++){
            int32_t temp = kruscal(num, root, road*2, point_num, i);
            if (check_connect(root, point_num) != 0){
                check = 1;
                if (temp < ans) ans = temp;
            }else break;
        }

        if (check) cout << ans << endl;
        else cout << "-1" << endl;

    }

    return 0;
}
