#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

int n;
vector<vector<int>> v;

struct state{
    vector<int> sol;
    vector<bool> used;
    int len;
    int ub;

    int calUb(){
        // set to store city that already out
        set<int> passed;
        int ans = 0;
        // Passed happiness
        for(int i = 0;i<len-1;i++){
            ans += v[sol[i]][sol[i+1]];
            passed.insert(sol[i]);
        }
        // Upper Bound for happiness
        for(int j = 0;j<n;j++){
            int tmpMax = -11111;
            // Not yet out the city
            if(passed.count(j) == 0 && j != sol[len-1]){
                for(int i = 0;i<n;i++){
                    // CANT BE i == j (self loop)
                    if(passed.count(i) == 0 && i != j) tmpMax = max(tmpMax,v[i][j]);
                }  
                ans += tmpMax;     
            }
        }
        return ans;
    }

    bool operator<(const state &rhs)const{
        return this->ub < rhs.ub;
    }
};

int main(){
    cin >> n;
    state start;
    v.resize(n,vector<int>(n));
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) cin >> v[i][j];
    
    // Initialize parameter
    vector<int> init(n,0);
    vector<bool> initUsed(n,false);
    init[0] = 0; initUsed[0] = true;
    init[init.size()-1] = n-1; initUsed[n-1] = true;
    start.sol = init;
    start.len = 1;
    start.used = initUsed;
    start.ub = start.calUb();

    // Priority Queue that Max UB comes first
    priority_queue<state> pq;
    pq.push(start);

    // Parameter for max happiness solution
    int ubMax = -10005*25;
    vector<int> bestSol;

    while(!pq.empty()){
        state t = pq.top();
        pq.pop();
        // Bound
        if(t.ub < ubMax) break;
        // n-1 + (last city) = n ==> travel complete
        if(t.len == n-1){
            if(t.ub > ubMax){
                ubMax = t.ub;
                bestSol = t.sol;
            }
        } else{
            // Permutation
            for(int i = 1;i<n-1;i++){
                if(!t.used[i]){
                    t.sol[t.len] = i;
                    t.used[i] = true;
                    t.len++;
                    t.ub = t.calUb();
                    pq.push(t);
                    
                    // Set back for next loop
                    t.used[i] = false;
                    t.len--;
                }
            }
        }
    }

    int maxHappines = 0;
    for(int i = 0;i<n-1;i++) maxHappines += v[bestSol[i]][bestSol[i+1]];
    cout << maxHappines;
}