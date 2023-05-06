#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

int n,m;
vector<int> coin;

struct state{
    int remain;
    int used;
    int lb;

    int calLB(){
        int ans = used;
        auto it = upper_bound(coin.begin(),coin.end(),remain);
        it--;
        ans += ceil((float)remain/(float)*it);
        return ans;
    }

    bool operator<(const state &rhs)const{
        return lb > rhs.lb;
    }
};  

int main(){
    cin >> n >> m;
    coin.resize(n);
    for(int i = 0;i<n;i++) cin >> coin[i];
    sort(coin.begin(),coin.end());
    state init;
    init.remain = m;
    init.used = 0;
    init.lb = init.calLB();
    priority_queue<state> pq;
    pq.push(init);
    int minLB = INT32_MAX;
    int minUsed = INT32_MAX;
    while(!pq.empty()){
        state t = pq.top();
        pq.pop();
        if(t.lb > minLB) break;
        if(t.remain == 0){
            if(t.lb < minLB){
                minLB = t.lb;
                minUsed = t.used;
            }
        } else{
            for(int i = 0;i<n;i++){
                if(coin[i] > t.remain) break;
                state newT = t;
                newT.remain -= coin[i];
                newT.used++;
                newT.lb = newT.calLB();
                pq.push(newT);
            }
        }
    }
    cout << minUsed;
}
