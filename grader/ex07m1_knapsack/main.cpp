#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>

using namespace std;

int n;
double maxW;
vector<double> v,w;

struct state{
    vector<int> sol;
    int len;
    double sumV;
    double sumW;
    double ub;

    double calUB(double maxW){
        double ub = 0;
        for(int i = 0;i<len;i++) ub += v[i]*sol[i];
        priority_queue<pair<double,int>> pq;
        for(int i = len;i<n;i++) pq.push({v[i]/w[i],i});
        while(!pq.empty() && maxW > 0){
            pair<double,int> t = pq.top();
            pq.pop();
            int idx = t.second;
            if(w[idx] > maxW){
                ub += (maxW/w[idx])*v[idx];
                maxW = 0;
            } else{
                ub += v[idx];
                maxW -= w[idx];
            }
        }
        return ub;
    }
    
    bool operator<(const state &rhs)const{
        return ub < rhs.ub;
    }
};

int main(){
    cin >> maxW >> n;
    v.resize(n);
    w.resize(n);
    for(int i = 0;i<n;i++) cin >> v[i];
    for(int i = 0;i<n;i++) cin >> w[i];
    state init;
    vector<int> initSol(n);
    init.sol = initSol;
    init.len = 0;
    init.sumV = 0;
    init.sumW = 0;
    init.ub = init.calUB(maxW);

    priority_queue<state> pq;
    pq.push(init);
    int maxUB = -1;
    vector<int> bestSol;
    while(!pq.empty()){
        state t = pq.top();
        pq.pop();
        if(t.ub < maxUB) break;
        if(t.len == n){
            if(t.ub > maxUB){
                maxUB = t.ub;
                bestSol = t.sol;
            }
        } else{
            state sol0 = t, sol1 = t;
            sol0.sol[sol0.len] = 0;
            sol0.len++;
            sol0.ub = sol0.calUB(maxW-sol0.sumW);
            pq.push(sol0);
            if(sol1.sumW + w[sol1.len] < maxW){
                sol1.sol[sol1.len] = 1;
                sol1.sumV += v[sol1.len];
                sol1.sumW += w[sol1.len];
                sol1.len++;
                sol1.ub = sol1.calUB(maxW-sol1.sumW);
                pq.push(sol1);
            }
        }    
    }
    double maxV = 0;
    for(int i = 0;i<n;i++) maxV += bestSol[i]*v[i];
    cout << setprecision(8) <<maxV;
}