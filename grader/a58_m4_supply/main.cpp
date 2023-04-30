#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,pair<int,int>>> v(k);
    for(int i = 0;i<k;i++){
        int d,e,l;
        cin >> d >> e >> l;
        v[i] = {d,{e,l}};
    }
    sort(v.begin(),v.end());
    queue<int> request, produce;
    for(int i = 0;i<k;i++){
        int e,l;
        e = v[i].second.first; l = v[i].second.second;

        // e = 0 --> Produce | e = 1 --> Request
        if(e == 0){
            if(request.empty()){
                produce.push(l);
                cout << "0\n";
            } else{
                cout << request.front() << "\n";
                request.pop();
            }
        } else{
            if(produce.empty()){
                request.push(l);
                cout << "0\n";
            } else{
                cout << produce.front() << "\n";
                produce.pop();
            }
        }
    }
}