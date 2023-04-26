#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>> day(k+1);
    queue<int> sent,request;
    for(int i = 0;i<k;i++){
        int d,e,l;
        cin >> d >> e >> l;
        day[d] = {e,l};
    }
    for(int i = 1;i<=k;i++){
        if(day[i].first == 0){
            if(request.empty()){
                sent.push(day[i].second);
                cout << 0 << "\n";
            } else{
                cout << request.front() << "\n";
                request.pop();
            }
        } else{
            if(sent.empty()){
                request.push(day[i].second);
                cout << 0 << "\n";
            } else{
                cout << sent.front() << "\n";
                sent.pop();
            }
        }
    }
}
