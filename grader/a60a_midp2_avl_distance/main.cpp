#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ans = 0;

vector<int> solve(int node,int k,int depth,vector<vector<int>> &edge){
    vector<int> nodeInDepth (30,0);

    if(edge[node].empty()){
        nodeInDepth[depth] = 1;
        return nodeInDepth;
    }

    nodeInDepth = solve(edge[node][0],k,depth+1,edge);
    nodeInDepth[depth] = 1;

    if(edge[node].size() == 1){
        if(depth + k < nodeInDepth.size()) ans += nodeInDepth[depth + k];
        return nodeInDepth;
    }

    vector<int> nodeInDepth2 = solve(edge[node][1],k,depth+1,edge);
    nodeInDepth2[depth] = 1;

    int idx;

    for( int i = depth ; i < 30 ; i++ ){
        //Since i - height is distance from this node to the one children side (Assume it is left)
        //then it needs the right one to be far from this node = k - ( i - height )
        idx = ( k - ( i - depth ));

        //but k might be less than i - height
        //and we complete the find only in this height ( not less this than height )
        //idx must be >= 0 and idx + height not more than max height 
        if( 0 <= idx && depth + idx < 30 )
            ans += nodeInDepth[i] * nodeInDepth2[ depth + idx ];
    }
    for( int i = depth + 1 ; i < 30 ; i++ )
        nodeInDepth[i] += nodeInDepth2[i];

    return nodeInDepth;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> edge(n+1);
    for(int i =0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    solve(1,k,0,edge);
    cout << ans;
}

/*
6 4
1 2
1 5
5 6
2 4
2 3
*/