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
        if (a.w == b.w){
            int32_t min_a = a.v < a.u ? a.v : a.u;
            int32_t min_b = b.v < b.u ? b.v : b.u;
            if (min_a != min_b)
                return min_a > min_b;
            else{
                min_a = a.v > a.u ? a.v : a.u;
                min_b = b.v > b.u ? b.v : b.u;
                return min_a > min_b;
            }
        }
        return a.w > b.w;
    }
};

//void replace_str(char str[]){
//    int32_t s = 0;
//    while (*(str+s) != '\0'){
//        if (*(str+s) == ',') *(str+s) = ' ';
//        s += 1;
//    }
//}

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

    for (int32_t p = 1 ; p <= t ; p++){
        cout << "Case " << p << ":\n";

        int32_t point_num = 0;
        cin >> point_num;

        getchar();

        int32_t root[point_num], tp_d = 0;
        char temp;
        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        for (int32_t i = 0 ; i < point_num ; i++){
            root[i] = i;

            for (int32_t j = 0 ; j < point_num ; j++){
                cin >> tp_d;
                if (j != point_num-1)
                    cin >> temp;
                if (tp_d != 0){
                    stl.push({i, j, tp_d});
                    stl.push({j, i, tp_d});
                }
            }
        }

        while (!stl.empty()){
            s_pair temp = stl.top();
            stl.pop();

            if (dis_find(root, temp.u) != dis_find(root, temp.v)){
                dis_union(root, temp.u, temp.v);
                int32_t min_out = temp.u < temp.v ? temp.u : temp.v;
                int32_t max_out = temp.u > temp.v ? temp.u : temp.v;
                printf("%c-%c %d\n", min_out+'A', max_out+'A', temp.w);
            }
        }
    }


    return 0;
}
