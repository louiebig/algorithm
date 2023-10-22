#include<iostream>

using namespace std;

// 快速排序
// 首先进行一次分，参数：数组参数、开始和结束标记；

int divide(int* arr, int p, int r){
    if (p==r) return p;
    // 哨兵元素
    int x = r;
    int i = p-1;
    int j = p;
    for (;j<r;j++){
        if (arr[j]<=arr[x]){
            swap(arr[j],arr[++i]);
        }
    }
    swap(arr[x],arr[++i]);
    return i;
}
int divide1(int* arr, int p, int r){
    if (p == r) return p;
    // 哨兵
    int x=p;
    int i=p+1;
    int j=r;
    while(i<=j){
        if (i<x){
            if(arr[i]>=arr[x]){
                swap(arr[i],arr[x]);
                x  = i;
            }
            i++;
        }
        if (j>x){
            if(arr[j]<=arr[x]){
                swap(arr[j],arr[x]);
                x=j;
            }
            j--;
        }
    }
    printf("i:%d,j:%d\n",i,j);
    return x;
}

void qiuck_sort(int *arr, int p, int r){
    if (p == r) return;
    int x = divide1(arr,p,r);
    // 打印划分结果；
    printf("一次划分结果\n");
    int i=0;
    while(i<10){
        printf("%d\t",arr[i]);
        i++;
    }
    printf("\n");
    printf("p:%d,r:%d,x:%d\n",p,r,x);
    if (p<x){
        qiuck_sort(arr,p,x-1);
    }
    if (x<r){
        qiuck_sort(arr,x+1,r);
    }
}


int main(){
    int arr[10];
    for(int i=0; i<10; i++){
        arr[i] = rand()%20;
    }
    int i=0;
    while(i<10){
        printf("%d\t",arr[i]);
        i++;
    }
    printf("\n");
    qiuck_sort(arr,0,9);
    i=0;
    while(i<10){
        printf("%d\t",arr[i]);
        i++;
    }
    return 0;
}
