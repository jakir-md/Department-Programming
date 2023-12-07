
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    int cnt = 0; //counting total inversion in each halves
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else {
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1); //Modification 2
        }
    }

    while (left <= mid) temp.push_back(arr[left++]); // if any left in the left half array
    while (right <= high) temp.push_back(arr[right++]); //if any left in the right half array

    // transfering all elements from temporary to arr //
    int j=0;
    while(low<=high) arr[low++]=temp[j++];
    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = mergeSort(a, 0, n-1);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}