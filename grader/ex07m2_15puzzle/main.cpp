#include<iostream>
#include<queue>
#include<map>

using namespace std;

vector<vector<int>> correctBoard = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};

typedef pair<int,vector<vector<int>>> bcsPair;

int cost(vector<vector<int>> &board){
    // int ans = 0;
    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<4;j++){
    //         if(board[i][j] == 0) continue;
    //         if(board[i][j] != correctBoard[i][j]) ans++;
    //     }
    // }
    // return ans;

    int ans = 0;

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(board[i][j] == 0) continue;
            int x = board[i][j];
            ans += abs(i-(x-1)/4) + abs(j-(x-1)%4);
        }

    return ans;
}

bool check(vector<vector<int>> &v){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(v[i][j] != correctBoard[i][j]) return false;
        }
    }
    return true;
}

pair<int,int> findSpace(vector<vector<int>> &v){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(v[i][j] == 0) return {i,j};
        }
    }
    return {5,5};
}

int main(){
    vector<vector<int>> ip(4,vector<int>(4));
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++) cin >> ip[i][j];
    }
    priority_queue<bcsPair,vector<bcsPair>,greater<bcsPair>> pq;
    pq.push({cost(ip),ip});
    map<vector<vector<int>>,int> m;
    m[ip] = 0;
    while(!pq.empty()){
        bcsPair t = pq.top();
        vector<vector<int>> board = t.second;
        int move = m[board];
        pq.pop();
        if(check(board)){
            cout << m[board];
            break;
        }

        vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int> space = findSpace(board);
        for(auto &d : direction){
            int r = space.first + d.first, c = space.second + d.second;
            if(r>=0 && r<4 && c >= 0 && c < 4){
                vector<vector<int>> tmp = board;
                swap(tmp[r][c],tmp[space.first][space.second]);
                if(m.count(tmp) == 0){
                    m[tmp] = move + 1;
                    pq.push({move+1+cost(tmp),tmp});
                }
            }
        }
    }
}





// Normal BFS (30/100) PPPTTTTTTT
/*
typedef pair<vector<vector<int>>,int> state;

vector<vector<int>> correctBoard = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};

pair<int,int> findSpace(vector<vector<int>> &v){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(v[i][j] == 0) return {i,j};
        }
    }
    return {5,5};
}

bool check(vector<vector<int>> &v){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(v[i][j] != correctBoard[i][j]) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> ip(4,vector<int>(4));
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++) cin >> ip[i][j];
    }

    set<vector<vector<int>>> s;
    s.insert(ip);
    queue<state> q;
    q.push({ip,0});

    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        state t = q.front();
        q.pop();
        vector<vector<int>> board = t.first;
        int move = t.second;
        if(check(board)){
            cout << move;
            break;
        }
        pair<int,int> space = findSpace(board);
        for(auto &d : direction){
            int r = space.first + d.first, c = space.second + d.second;
            if(r>=0 && r<4 && c >= 0 && c < 4){
                vector<vector<int>> tmp = board;
                swap(tmp[r][c],tmp[space.first][space.second]);
                if(s.count(tmp) == 0){
                    s.insert(tmp);
                    q.push({tmp,move+1});
                }
            }
        }
    }
}
*/