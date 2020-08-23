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

    while (t--){

        int32_t c = 0, r = 0;
        cin >> c >> r;


        int32_t root[c], tp_x = 0, tp_y = 0 , tp_d = 0;
        int32_t tol = 0;

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        for (int32_t i = 0 ; i < c ; i++)
            root[i] = i;
        
        for (int32_t i = 0; i < r; i++){
            cin >> tp_x >> tp_y >> tp_d;
            stl.push({tp_x, tp_y, tp_d});
            stl.push({tp_y, tp_x, tp_d});
            tol += tp_d;
        }

        int32_t ans = 0;

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            if (dis_find(root, temp.u) != dis_find(root, temp.v)){
                ans += temp.w;
                dis_union(root, temp.u, temp.v);
            }
        }
        cout << tol - ans << endl;
    }


    return 0;
}
