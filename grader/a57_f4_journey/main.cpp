#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int n;
vector<vector<int>> g;

struct state{
    vector<int> sol;
    vector<bool> used;
    int len;
    int ub;

    // MAX IN
    int calUB(){
        set<int> passed;
        int ans = 0;
        for(int i = 0;i<len-1;i++){
            ans += g[sol[i]][sol[i+1]];
            passed.insert(sol[i]);
        }

        for(int i = 0;i<n;i++){
            int tmpMax = -20000;
            if(passed.count(i) == 0 && i != sol[len-1]){
                for(int j = 0; j < n;j++){
                    if(i!=j && passed.count(j) == 0){
                        tmpMax = max(tmpMax,g[j][i]);
                    }
                }
                ans += tmpMax;
            }
        }
        return ans;
    }

    bool operator<(const state &rhs)const{
        return ub < rhs.ub;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    g.resize(n,vector<int>(n));
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) cin >> g[i][j];
    state init;
    vector<int> initSol(n,0);
    vector<bool> initUsed(n,false);
    initSol[0] = 0; initUsed[0] = true;
    initSol[n-1] = n-1; initUsed[n-1] = true;
    init.sol = initSol;
    init.used = initUsed;
    init.len = 1;
    init.ub = init.calUB();

    int maxUB = -10005*21;
    vector<int> bestSol;
    priority_queue<state> pq;
    pq.push(init);
    while(!pq.empty()){
        state t = pq.top();
        pq.pop();
        if(t.ub < maxUB) break;
        if(t.len == n-1){
            if(t.ub > maxUB){
                maxUB = t.ub;
                bestSol = t.sol;
            }
        } else{
            for(int i = 1;i<n-1;i++){
                if(!t.used[i]){
                    t.used[i] = true;
                    t.sol[t.len] = i;
                    t.len++;
                    t.ub = t.calUB();
                    pq.push(t);
                    
                    t.len--;
                    t.used[i] = false;
                }
            }
        }
    }
    // for(auto &x : bestSol) cout << x << " ";
    int happiness = 0;
    for(int i = 0;i<n-1;i++) happiness += g[bestSol[i]][bestSol[i+1]];
    cout << happiness;

}