#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

vector<vector<int>> cost;
int n;

bool check(int n, vector<vector<int>> &cost, vector<int> &work, int k){
    if(work.size() != n) return false;
    set<int> worker;
    int totalCost = 0;
    for(int i = 0;i<n;i++){
        // 1 Worker do more than 1 work
        if(worker.count(work[i]) != 0) return false;
        totalCost += cost[work[i]][i];
        worker.insert(work[i]);
    }
    return totalCost <= k;

}

struct state{
    // people i do work sol[i]
    vector<int> sol;
    // Work already handled
    vector<bool> used;
    int len;
    int lb;

    int calLB(){
        int ans = 0;
        for(int i = 0;i<len;i++) ans += cost[i][sol[i]];
        for(int i = len;i<n;i++){
            int tmpMin = INT32_MAX;
            for(int j = 0;j<n;j++) if(!used[j]) tmpMin = min(tmpMin,cost[i][j]);
            ans += tmpMin;
        }
        return ans;
    }
    
    bool operator<(const state &rhs)const{
        return lb > rhs.lb;
    }
};

int main(){
    cin >> n;
    cost.resize(n,vector<int>(n));
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) cin >> cost[i][j];
    vector<int> initSol(n,0);
    vector<bool> initUsed(n,false);
    state init;
    init.sol = initSol;
    init.used = initUsed;
    init.len = 0;
    init.lb = init.calLB();

    priority_queue<state> pq;
    pq.push(init);
    int minLB = INT32_MAX;
    vector<int> bestSol;
    while(!pq.empty()){
        state t = pq.top();
        pq.pop();
        if(t.lb > minLB) break;
        if(t.len == n){
            if(t.lb < minLB){
                minLB = t.lb;
                bestSol = t.sol;
            }
        } else{
            for(int i = 0;i<n;i++){
                if(!t.used[i]){
                    t.used[i] = true;
                    t.sol[t.len] = i;
                    t.len++;
                    t.lb = t.calLB();
                    pq.push(t);

                    t.used[i] = false;
                    t.len--;
                }
            }
        }
    }
    for(int i = 0;i<n;i++) cout << "People " << i << " do " << bestSol[i] << endl;
    int bestAns = 0;
    for(int i = 0;i<n;i++) bestAns += cost[i][bestSol[i]];
    cout << bestAns << endl;
    
    vector<int> work = {2,1,3,0};
    cout << check(n,cost,work,47);
}


/*
4
14 12 15 20
15 10 14 25
10 19 17 23
16 18 8 40
*/