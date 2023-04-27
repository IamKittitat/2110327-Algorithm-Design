#include<iostream>
#include<vector>

using namespace std;

int n,m,a,b;
vector<int> order,t,S;

// From < To
int straightDistance(int from,int to){
    if(from < to) return min(S[to]-S[from],S[from+m]-S[to]);
    else return min(S[from]-S[to],S[to+m]-S[from]);
}

int minDistance(int from,int to){
    int straight = straightDistance(from,to);
    int portal1 = straightDistance(from,a) + straightDistance(b,to);
    int portal2 = straightDistance(from,b) + straightDistance(a,to);
    return min(straight,min(portal1,portal2));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    order.resize(m+1);
    t.resize(m);
    for(int i =0;i<m;i++) cin >> order[i];
    order.back() = order[0];

    for(int i = 0;i<m;i++) cin >> t[i];
    S.resize(2*m+1);
    for(int i = 1;i<2*m;i++) S[i] = S[i-1] + t[(i-1)%m];

    for(int i = 0;i<n;i++){
        cin >> a >> b;
        int total = 0;
        for(int j = 1;j<order.size();j++){
            int from = order[j-1], to = order[j];
            total += minDistance(from,to);
        }
        cout << total << "\n";
    }
}