#include<iostream>
#include <iomanip>
#include<vector>
#include<queue>

using namespace std;

typedef pair<float,pair<vector<float>,int>> bbpair;

int n;
float maxW;
vector<float> v,w;

// Compute upper bound from items idx to n (maxV not exceeding maxW)
float ub(int idx,float maxW){
    float ans = 0;
    // cout << "!" << idx ;
    priority_queue<pair<float,int>> pq;
    for(int i = idx;i < n;i++) pq.push({v[i]/w[i],i});
    while(maxW > 0 && !pq.empty()){
        pair<float,int> t = pq.top();
        pq.pop();
        int i = t.second;
        if(w[i] > maxW){
            ans += (maxW*v[i])/w[i];
            maxW = 0;
        } else{
            ans += v[i];
            maxW -= w[i];
        }
    }
    // cout << "out" << endl;
    return ans;
}

float calSum(vector<float> &v,vector<float> &sol){
    float ans = 0;
    for(int i = 0;i<n;i++) ans += v[i]*sol[i];
    return ans;
}

int main(){
    cin >> maxW >> n;
    v.resize(n);
    w.resize(n);

    for(int i = 0;i<n;i++) cin >> v[i];
    for(int i = 0;i<n;i++) cin >> w[i];
    priority_queue<bbpair> pq;
    vector<float> ans;
    float maxV = 0;
    pq.push({ub(0,maxW),{vector<float>(n,0),0}});

    while(!pq.empty()){
        bbpair t = pq.top();
        pq.pop();
        if(t.first < maxV) break;
        vector<float> tmpAns = t.second.first;
        int len = t.second.second;
        if(len == n){
            if(t.first > maxV){
                maxV = t.first;
                ans = tmpAns;
            }
        } else{
            float sumV = calSum(v,tmpAns),sumW = calSum(w,tmpAns);
            tmpAns[len] = 0;
            pq.push({sumV + ub(len+1,maxW-sumW),{tmpAns,len+1}});
            if(sumW + w[len] <= maxW){
                tmpAns[len] = 1;
                pq.push({sumV + ub(len+1,maxW-sumW-w[len])+v[len],{tmpAns,len+1}});
            }
        }
    }
    double maxVAns = 0;
    for(int i = 0; i<n;i++) maxVAns += v[i]*ans[i];
    cout << std::setprecision(10) << maxVAns;
}