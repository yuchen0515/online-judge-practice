#include <iostream>
#include <cmath>

using namespace std;

typedef struct pair{
    double x;
    double y;
}s_pair;

double dist(s_pair a, s_pair b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


double ans = 0;
void dfs(s_pair num[], bool vis[], int32_t *tol_num, int32_t edge_num, int32_t cur){
    if (*tol_num == edge_num-1) return;
    vis[cur] = true;
    double dis_num = 1000000000;
    int32_t dis_po = 0;

    for (int32_t j = 0 ; j < edge_num ; j++){
        if (j == cur) continue;
        double temp = dist(num[cur], num[j]);
        if (vis[j] == 0 && dis_num > temp){
            dis_num = temp;
            dis_po = j;
        }
    }
    ans += dis_num;
    *tol_num +=1;
    dfs(num, vis, tol_num, edge_num, dis_po);
}

int main(){

    int32_t t = 0;
    cin >> t;

    for (int32_t p = 0 ; p < t ; p++){
        ans = 0;

        if (p != 0) cout << endl;

        int32_t edge_num = 0;
        double tp_x = 0 , tp_y = 0;
        cin >> edge_num;

        s_pair num[edge_num];
        bool vis[edge_num] = {0};
        int32_t tol_num = 0;

        for (int32_t i = 0 ; i < edge_num ; i++){
            cin >> tp_x >> tp_y;
            num[i] = {tp_x, tp_y};
        }


        dfs(num, vis, &tol_num, edge_num, 0);

        printf("%.2lf\n", ans);
    }

    return 0;
}
