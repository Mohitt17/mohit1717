#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partision(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;           //    partision is common part for both quicksort and quickselect 
    int end = ub;
    while(start < end){ 
        while(start <= ub && arr[start] <= pivot) {
            start++;
        }
        while(arr[end] > pivot) {
            end--;
        }
        if(start < end) swap(&arr[start], &arr[end]);
    }
    swap(&arr[lb], &arr[end]);
    return end;
}
int quickselect(int arr[], int lb, int ub, int given) {
    if(lb == ub){
        return arr[lb];
    }
    int p = partision(arr, lb, ub);
    if(given == p){
        return arr[p];
    }
    else if(given < p){
        return quickselect(arr, lb, p - 1, given);
    }
    else{
        return quickselect(arr, p + 1, ub, given);
    }
}
int main() {
    FILE *fh = fopen("input.txt","r");
    if(fh == NULL){
        printf("error");
        return 0;
    }
    int n;
    fscanf(fh,"%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        fscanf(fh,"%d",&arr[i]);
    }
    int m;
    fscanf(fh,"%d",&m);   
    FILE *fp = fopen("output.txt","w");
    if(fp == NULL){
        printf("error");
        return 0;
    }
    int ans = quickselect(arr, 0, n - 1, n-m);
    fprintf(fp, "%d", ans);
    return 0;
}