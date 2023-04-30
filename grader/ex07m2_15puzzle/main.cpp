#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

vector<pair<int,int>> correct = {{3,3},{0,0},{0,1},{0,2},
                                 {0,3},{1,0},{1,1},{1,2},
                                 {1,3},{2,0},{2,1},{2,2},
                                 {2,3},{3,0},{3,1},{3,2}};

struct state{
    vector<vector<int>> sol;
    int lb;
    int moved;

    int calCost(){
        int ans = 0;
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(sol[i][j] == 0) continue;
                ans += abs(correct[sol[i][j]].first - i) + abs(correct[sol[i][j]].second - j);
            }
        }
        return moved + ans;
    }

    bool finish(){
        return calCost() - moved == 0;
    }

    pair<int,int> findSpace(){
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(sol[i][j] == 0) return {i,j};
            }
        }
        return {10,10};
    }

    bool operator<(const state &rhs)const{
        return lb > rhs.lb;
    }
};

int main(){
    vector<vector<int>> initSol(4,vector<int>(4));
    for(int i = 0;i<4;i++) for(int j = 0;j<4;j++) cin >> initSol[i][j];
    state init;
    init.sol = initSol;
    init.moved = 0;
    init.lb = init.calCost();

    vector<pair<int,int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    priority_queue<state> pq;
    set<vector<vector<int>>> s;
    pq.push(init);
    s.insert(initSol);

    while(!pq.empty()){
        state t = pq.top();
        pq.pop();
        if(t.finish()){
            cout << t.moved;
            break; 
        } else{
            pair<int,int> space = t.findSpace();
            for(auto &d : direction){
                int r = space.first + d.first, c = space.second + d.second;
                if(r >= 0 && r < 4 && c >= 0 && c < 4){
                    state newT = t;
                    swap(newT.sol[space.first][space.second],newT.sol[r][c]);
                    if(s.count(newT.sol) == 0){
                        newT.moved++;
                        newT.lb = newT.calCost();
                        pq.push(newT);
                        s.insert(newT.sol);
                    }
                }
            }
        }
    }
}
