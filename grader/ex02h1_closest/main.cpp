#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int dist(pair<int,int> a,pair<int,int> b){
    return pow((a.first-b.first),2) + pow((a.second-b.second),2);
}

bool isSame(pair<int,int> a,pair<int,int> b){
    return a.first == b.first && a.second == b.second;
}

int solve(vector<pair<int,int>> &x_sort,vector<pair<int,int>> &y_sort,int l,int r){
    if(r==l) return 30000*30000*2+1;
    if(r-l==1) return dist(x_sort[l],x_sort[r]);

    int m = (l+r)/2, mx = x_sort[m].first;
    vector<pair<int,int>> y_sort_left,y_sort_right;
    // Separate y sort to left and right
    for(int i =0;i<y_sort.size();i++){
        if(y_sort[i].first < mx) y_sort_left.push_back(y_sort[i]);
        else y_sort_right.push_back(y_sort[i]);
    }

    int leftAns = solve(x_sort,y_sort_left,l,m);
    int rightAns = solve(x_sort,y_sort_right,m+1,r);
    
    int b = min(leftAns,rightAns);
    int lb = mx-b, rb = mx+b; //left border and right border
    int midAns = 30000*30000*2+1;
    vector<pair<int,int>> y_in;
    for(int i = 0;i<y_sort.size();i++){
        if(y_sort[i].first >= lb && y_sort[i].first <= rb) y_in.push_back(y_sort[i]);
    }

    for(int i =0;i<y_in.size();i++){
        for(int j =i+1;j<y_in.size();j++){
            if(y_in[i].second +b > y_in[j].second) break;
            int dist_i_j = dist(x_sort[i],y_in[j]);
            midAns = min(dist_i_j,midAns);
        }
    }
    // for(int i =l;i<=r;i++){
    //     if(x_sort[i].first >= rb || x_sort[i].first <= lb) continue;
    //     for(int j = 0;j<y_in.size();j++){
    //         if(y_in[j].second <= x_sort[i].second) continue;
    //         if(y_in[j].second >= x_sort[i].second + b) break;
    //         if(isSame(x_sort[i],y_in[j])) continue;
    //         int dist_i_j = dist(x_sort[i],y_in[j]);
    //         midAns = min(dist_i_j,midAns);
    //     }
    // }
    return min(b,midAns);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> x_sort(n);
    for(int i =0;i<n;i++) cin >> x_sort[i].first >> x_sort[i].second;
    vector<pair<int,int>> y_sort = x_sort;
    sort(x_sort.begin(),x_sort.end());
    sort(y_sort.begin(), y_sort.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;});
    cout << solve(x_sort,y_sort,0,n-1);

}

/*
3
1 1
2 2
5 1

6
10 2
10 4
10 6
12 3
12 5
12 7

*/