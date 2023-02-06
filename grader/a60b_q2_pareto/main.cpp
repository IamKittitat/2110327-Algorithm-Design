#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// DC approach with O(nlgn)  (NO NEED TO DO THIS JUST USE SORTING IS ENOUGH)
vector<int> pareto(int l,int r, vector<pair<int,int>> &v){ 
    vector<int> ans;
    if(r==l){
        ans.push_back(l);
        return ans;
    }
    if(r-l == 1){
        if(v[l].second <= v[r].second ) ans.push_back(r); // left not pareto
        else { ans.push_back(l); ans.push_back(r); } // left also pareto
        return ans;
    }

    int m = (l+r)/2;
    vector<int> left = pareto(l,m,v);
    vector<int> right = pareto(m+1,r,v);

    vector<int> totalAns;
    int yMax = -1;
    // Check from right to left, if the point has more y val than ever existed its pareto.
    for(int i = right.size()-1;i>=0;i--){
        if(v[right[i]].second > yMax){
            yMax = v[right[i]].second;
            totalAns.push_back(right[i]);
        } 
    }
    for(int i = left.size()-1;i>=0;i--){
        if(v[left[i]].second > yMax){
            yMax = v[left[i]].second;
            totalAns.push_back(left[i]);
        } 
    }

    for(int i = 0;i<totalAns.size()/2;i++){
        swap(totalAns[i],totalAns[totalAns.size()-1-i]);
    }
    return totalAns;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i= 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v[i] = {x,y};
    }
    sort(v.begin(),v.end());
    vector<int> ans = pareto(0,v.size()-1,v);
    cout << ans.size();
}


// Naive approach with O(n**2) PPPPPTTTTT
// int main(){
//     int n;
//     cin >> n;
//     vector<pair<int,int>> v(n);
//     for(int i= 0;i<n;i++){
//         int x,y;
//         cin >> x >> y;
//         v[i] = {x,y};
//     }
//     int ans = 0;
//     for(int i =0;i<n;i++){
//         bool isAns = true;
//         for(int j = 0;j<n;j++){
//             if(i == j) continue;
//             if(v[i].first < v[j].first && v[i].second < v[j].second) isAns = false;
//         }
//         if(isAns) ans++;
//     }
//     cout << ans;
// }