#include <bits/stdc++.h>

#define ll long long
#define N (ll)(2*1e5)
#define EPS (double)(1e-12)
#define M (ll)(1e9+7)

using namespace std;

void merge(vector<int>& arr, int l, int middle, int r) {
    int n1 = middle-l+1;
    int n2 = r-middle;
    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0; i < n1; i++) L[i] = arr[i+l];
    for(int i = 0; i < n2; i++) R[i] = arr[i+middle+1];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] < R[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = R[j++];
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];

}


void mergeSort(vector<int>& arr, int l, int r) {
    int middle;
    if(l < r) {
        middle = (l+r)/2;
        mergeSort(arr, l, middle);
        mergeSort(arr, middle+1, r);
        merge(arr, l, middle, r);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    
    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++)      
        cout << arr[i] << " ";


    return 0;
}