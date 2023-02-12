#include<iostream>
#include<vector>
#include<deque>

using namespace std;

deque<int> deq;

int solve(vector<int> &v,int w,vector<int> &S){
    int best = INT32_MIN;
    for(int i =0;i<S.size();i++){
        if(!deq.empty() && i - deq.front() >= w) deq.pop_front();

        if(i != 0 && !deq.empty())best = max(S[i]-S[deq.front()],best);

        while(!deq.empty() && S[deq.back()] >= S[i]) deq.pop_back();
        deq.push_back(i);
        cout << deq.size() << endl;
    }
    return best;
}

int main(){
    int n,w;
    cin >> n >> w;
    vector<int> v(n),S(n+1);
    for(int i =0;i<n;i++) cin >> v[i];
    S[0] = 0;
    for(int i =0;i<n;i++) S[i+1] = v[i] + S[i];
    cout << solve(v,w,S);
}