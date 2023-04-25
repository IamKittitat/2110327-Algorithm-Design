#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

vector<pair<int,int>> correct = {{3,3},{0,0},{0,1},{0,2},
                                 {0,3},{1,0},{1,1},{1,2},
                                 {1,3},{2,0},{2,1},{2,2},
                                 {2,3},{3,0},{3,1},{3,2}};

struct board{
    int used;
    vector<vector<int>> table;

    int cost()const{
        int ans = 0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                if(this->table[i][j] == 0) continue;
                int x = this->table[i][j];
                ans += abs(i-(x-1)/4) + abs(j-(x-1)%4);
            }
        return ans;
    }

    pair<int,int> findSpace(){
        for(int i = 0;i<4;i++){
            for(int j = 0;j<4;j++){
                if(this->table[i][j] == 0) return {i,j};
            }
        }
        return {4,4};
    }

    bool finish(){
        return cost() == 0;
    }

    bool operator<(const board &state)const{
        int lcost = cost();
        int rcost = state.cost();
        return lcost + this->used > rcost + state.used;
    }
};

int main(){
    vector<vector<int>> start(4,vector<int>(4));
    board state;
    for(int i= 0 ;i<4;i++) for(int j = 0;j<4;j++) cin >> start[i][j];
    state.table = start;
    state.used = 0;
    priority_queue<board> pq;
    set<vector<vector<int>>> s;
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};

    s.insert(start);
    pq.push(state);

    while(!pq.empty()){
        board state = pq.top();
        pq.pop();
        if(state.finish()){
            cout << state.used;
            break;
        }
        pair<int,int> space = state.findSpace();
        for(auto &d : direction){
            int r = space.first + d.first, c = space.second + d.second;
            if(r < 4 && r >= 0 && c < 4 && c >= 0){
                board newState;
                newState.table = state.table;
                swap(newState.table[space.first][space.second],newState.table[r][c]);
                if(s.count(newState.table) == 0){
                    s.insert(newState.table);
                    newState.used = state.used + 1;
                    pq.push(newState);
                }
            }   
        }
    }
}