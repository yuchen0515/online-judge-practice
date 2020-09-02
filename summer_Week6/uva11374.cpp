//題目需求尚找不好漂亮的結構去處理
//因此該程式檔可能會很醜
//
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

typedef struct S_pair{
    int32_t to; int32_t t;
}s_pair;

struct cmp{
    bool operator()(s_pair a, s_pair b){
        return a.t > b.t;
    }
};

int main(){
    int32_t n = 0, m = 0, s[2];
    bool check = 0;
    
    while (cin >> n >> s[0] >> s[1]){
        if (check) cout << endl;

        cin >> m; 

        vector<s_pair> num[n+1];
        s_pair short_path[n+1][2]; 

        int32_t k = 0, tp_x = 0; 
        int32_t tp_y = 0, tp_t = 0;

        priority_queue<s_pair, vector<s_pair>, cmp> stl;

        for (int32_t i = 0 ; i < m ; i++){
            cin >> tp_x >> tp_y >> tp_t;
            num[tp_x].push_back({tp_y, tp_t});
            num[tp_y].push_back({tp_x, tp_t});
        }

        for (int32_t j = 0 ; j <= n ; j ++){
            for (int32_t k = 0 ; k < 2; k++){
                short_path[j][k].t = 10000000;
                short_path[j][k].to = -1;
            }
        }

        for (int32_t i = 0 ; i < 2; i ++){
            short_path[s[i]][i].t = 0;
            stl.push({s[i], 0});

            while (!stl.empty()){
                s_pair temp = stl.top();
                stl.pop();

                //visit "cur"
                for (auto c: num[temp.to]){
                    if (c.t + short_path[temp.to][i].t < short_path[c.to][i].t){
                        short_path[c.to][i].t = c.t + short_path[temp.to][i].t;
                        short_path[c.to][i].to = temp.to;
                        stl.push({c.to, short_path[i][c.to].t});
                    }
                }
            }
        }

        cin >> k;
        int32_t ans = short_path[s[1]][0].t;
        int32_t res_s = -1 , res_e = -1;

        for (int32_t i = 0 ; i < k ; i++){
            cin >> tp_x >> tp_y >> tp_t;

            for (int32_t j = 0 ; j < 2; j ++){
                int32_t cmmp = tp_t;

                cmmp += (short_path[tp_x][0].t) * (tp_x != s[0]);
                cmmp += (short_path[tp_y][1].t) * (tp_y != s[1]);

                if ((cmmp != tp_t) && cmmp < ans){
                    ans = cmmp;
                    res_s = tp_x;
                    res_e = tp_y;
                }

                tp_x ^= tp_y;
                tp_y ^= tp_x;
                tp_x ^= tp_y;
            }
        }

        if (!(res_s == -1 && res_e == -1)){
            short_path[res_s][1].to = res_e;
            short_path[res_e][0].to = res_s;
        }

        int32_t cur = s[1], back_cur = s[0];
        stack<int32_t> ans_sta;
        queue<int32_t> ans_que;

        while (1){
            if (cur != -1) ans_sta.push(cur);
            if (back_cur != -1) ans_que.push(back_cur);
            
            if (cur == s[0] || back_cur == s[1]) break;

            if (cur != -1) cur = short_path[cur][0].to;
            if (back_cur != -1) back_cur = short_path[back_cur][1].to;
        }

        //尤其這段code要大改
        bool blank = 0;
        if (ans_sta.size() > ans_que.size()){
            while (!ans_sta.empty()){
                if (blank) cout << " ";
                cout << ans_sta.top();
                ans_sta.pop();
                blank = 1;
            }
        }else{
            while (!ans_que.empty()){
                if (blank) cout << " ";
                cout << ans_que.front();
                ans_que.pop();
                blank = 1;
            }
        }
        cout << endl;

        if (res_s == -1 && res_e == -1)
            cout << "Ticket Not Used" << endl;
        else 
            cout << res_s << endl;

        cout << ans << endl;

        check = 1;
    }

    return 0;
}
