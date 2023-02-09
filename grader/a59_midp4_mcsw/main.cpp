#include<iostream>
#include<vector>
#include<deque>

using namespace std;

deque<int> deq;

int mss(vector<int> &v,int w,vector<int> &S){
    int best = INT32_MIN;
    for(int i = 0;i<S.size();i++){
        if(!deq.empty() && i - deq.front() >= w) deq.pop_front();

        if(i !=  0 && S[i] - S[deq.front()] > best){
            best = S[i] - S[deq.front()];
        } 
        while(!deq.empty() && S[deq.back()] > S[i]) deq.pop_back();
        deq.push_back(i);
    }
    return best;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,w;
    cin >> n >> w;
    vector<int> v(n),S(n+1);
    for(int i =0;i<n;i++) cin >> v[i];
    S[0] = 0;
    for(int i = 0; i < n ; i++) S[i+1] = S[i] + v[i];
    cout << mss(v,w,S);
}

/*
5 3
-10 -2 -3 -4 -5

10 4
1 4 2 -3 5 -7 3 9 2 -7
*/