#include<iostream>
using namespace std;

int partition(int a[], int left, int right){
    int x = a[left];
    while(left < right){
        while(left < right && a[right] < x) right--;
        if(left < right){
            a[left] = a[right];
            left++;
        }
        while(left < right && a[left] >= x) left++;
        if(left < right){
            a[right] = a[left];
            right--;
        }
    }
    a[left] = x;
    return left;
}

void qsort(int a[], int left, int right){
    if(left < right){
        int p = partition(a, left, right);
        qsort(a, left, p-1);
        qsort(a, p+1, right);
    }
}

int main(){
    int a[] = {9,8,7,6,5,3,2};
    int length = sizeof(a)/sizeof(a[0]);
    qsort(a,0,length - 1);
    for(int i = 0 ; i < length ; i++){
        cout<<a[i]<<endl;
    }
}
