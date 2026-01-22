#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partision(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
    while(arr[start]<=pivot){
        start++;
    }
    while(arr[end]>pivot){
        end--;
    }
    if(start<end){
        swap(&arr[start],&arr[end]);
    }
}
    swap(&arr[lb],&arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int point=partision(arr,lb,ub);
        quicksort(arr,lb,point-1);
        quicksort(arr,point+1,ub);
    }
}
int main(){
    FILE *fp=NULL;
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("error");
        return 0;
    }
    int n;
    fscanf(fp,"%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    int m;
    fscanf(fp,"%d",&m);
     FILE *fos=NULL;
    fos=fopen("output.txt","w");
    if(fos==NULL){
        printf("error");
        return 0;
    }
    fprintf(fos,"%d",arr[m-1]);
}