#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int arr[MAX];
int tmp_arr[MAX];
int N;

void insertion_sort(){
    for(int i = 1; i < N; i++){
        int tmp = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > tmp){
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = tmp;
    }
}

void bubble_sort(){
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N - i; j++){
            if(arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
        }
    }
}

void quick_sort(int start, int end){
    if(start >= end) return;

    int pivot = arr[(start + end) / 2];
    int l = start, r = end;
    while(l <= r){
        while(pivot > arr[l]) l++;
        while(pivot < arr[r]) r--;
        if(l >= r) break;
        swap(arr[l], arr[r]);
    }

    quick_sort(start, l - 1);
    quick_sort(l + 1, end);
}

void merge(int start, int mid, int end){
    
    int i = start, j = mid + 1, k = start;

    while(i <= mid && j <= end){
        if(arr[i] < arr[j]) tmp_arr[k] = arr[i++];
        else tmp_arr[k] = arr[j++];
        k++;
    }

    if(i > mid){
        while(j <= end) tmp_arr[k++] = arr[j++];
    }
    else{
        while(i <= mid) tmp_arr[k++] = arr[i++];
    }

    for(int t = start; t <= end; t++){
        arr[t] = tmp_arr[t];
    }
}

void merge_sort(int start, int end){
    if(start >= end) return;

    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
}

int main(){
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    // quick_sort(0, N - 1);
     merge_sort(0, N - 1);
    // bubble_sort();
    // insertion_sort();
    for(int i = 0; i < N; i++) cout << arr[i] << '\n';
}