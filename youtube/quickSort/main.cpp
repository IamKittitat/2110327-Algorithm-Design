#include<iostream>
#include<vector>

using namespace std;

// Make left <= pivot and right > pivot
// 1 2 3 4 5 "5" 6 8 9
int partition(vector<int> &v,int l,int r){
    int pivot = v[l];
    int count = 0;
    // Count how many <= pivot (To get pivot real position)
    for(int i =l+1;i<=r;i++) if(v[i] <= pivot) count++;
    int pivotIdx = l + count;
    swap(v[l],v[pivotIdx]);
    int left = l,right = r;
    // Loop both side
    while(left < pivotIdx && right > pivotIdx){
        // v[left] <= pivot means v[left] is at the correct side
        while(v[left] <= pivot) left++;
        // v[right] > pivot means v[right] is at the correct side
        while(v[right] > pivot) right--;
        // left++ right-- so we dont need to do this again
        if(left < pivotIdx && right > pivotIdx) swap(v[left++],v[right--]);
    }
    return pivotIdx;
}

void quickSort(vector<int> &v,int l,int r){
    if(l < r){
        int p = partition(v,l,r);
        // No need to sort the pivot position
        quickSort(v,l,p-1);
        quickSort(v,p+1,r);
    }
}


int main()
{
    vector<int> v = {14,6392,124,19,-14,54,1,0,256,9,12,54,643,4,6,913,2,5,3123,54,331};
    quickSort(v,0,v.size()-1);
    for(auto &x : v) cout << x << " " ;
}