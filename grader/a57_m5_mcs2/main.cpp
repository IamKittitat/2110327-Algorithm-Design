#include<iostream>
#include<vector>
#include<deque>

using namespace std;

deque<int> deq;

int mss(int n,vector<int> &S){
    int best = INT32_MIN;
    for(int i =0;i<S.size();i++){
        if(!deq.empty() && i - deq.front() > n) deq.pop_front();
        if(i != 0 && S[i] - S[deq.front()] > best){
            best = S[i] - S[deq.front()];
        }
        while(!deq.empty() && S[deq.front()] > S[i]) deq.pop_back();
        deq.push_back(i);
    }
    return best;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(2*n),S(2*n+1);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i = 0;i<n;i++) v[n+i] = v[i];
    S[0] = 0;
    for(int i = 0; i < 2*n ; i++) S[i+1] = S[i] + v[i];
    // for(auto &x : S) cout << x << " ";
    // cout << endl;
    cout << mss(n,S);
}

/*
4
1 -2 -3 1

15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4

8
-1 -2 -2 -2 -2 -2 -2 -1

4
3 2 1 2
*/
