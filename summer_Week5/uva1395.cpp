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
        double a_m = a.w < 0 ? -a.w : a.w;
        double b_m = b.w < 0 ? -b.w : b.w;
        return a_m > b_m;
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
    
    int32_t point_num = 0 , road = 0;

    while (1){
        
        int32_t tp_x = 0, tp_y = 0;
        double tp_d = 0;
        cin >> point_num >> road;

        if (point_num == 0 && road ==0) break;

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        s_pair num[point_num];

        double mean = 0;

        int32_t root[point_num+1];
        for (int32_t i = 0 ; i < point_num ; i++)
            root[i] = i;

        for (int32_t i = 0; i < road; i++){
            cin >> tp_x >> tp_y >> tp_d;
            num[i] = {tp_x-1, tp_y-1, (double)tp_d};
            mean += (tp_d / road);
            dis_union(root, tp_x-1, tp_y-1);
        }

        int32_t check = root[0];
        int32_t check_ans = 1;
        for (int32_t i = 1 ; i < point_num ; i++){
            if (root[i] != check){
                check_ans = 0;
                break;
            }
        }

        for (int32_t i = 0 ; i < road ; i++){
            num[i].w -=  mean;
            cout << "test: " << num[i].w << endl;
            stl.push(num[i]);
        }


        double ans_max = -100000, ans_min = 100000;

        for (int32_t i = 0 ; i < point_num ; i++)
            root[i] = i;

        while (check_ans == 1 && !stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            int32_t u_tp = dis_find(root, temp.u);
            int32_t v_tp = dis_find(root, temp.v);
            if (u_tp != v_tp){
                cout << "test1: " << temp.w << endl;
                if (ans_max < temp.w) ans_max= temp.w;
                if (ans_min > temp.w) ans_min= temp.w;

                dis_union(root, temp.u, temp.v);
            }
        }


        if (check_ans)
            cout << (int32_t)(ans_max - ans_min) << endl;
        else 
            cout << "-1" << endl;

    }


    return 0;
}
