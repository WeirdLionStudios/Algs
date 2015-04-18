/**
*
*Author: Trek3
*/

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100
#define DIM 8

void carica(int a[], int dim){
    for(int i=0;i<dim;i++){
            a[i]=rand()%MAX;
    }    
}

void print(int a[], int dim){
    for(int i=0;i<dim;i++){
            cout<<a[i]<<"\t";
    }    
    cout<<endl;
}

void merge(int a[], int left, int center, int right){
    int n1=center-left+1, n2=right-center;
    int l1[n1], l2[n2];
    
    for(int i=0;i<n1;i++)
        l1[i]=a[left+i];
    for(int i=0;i<n2;i++)
        l2[i]=a[i+center+1];
        
    l1[n1]=1<<31-1;
    l2[n2]=1<<31-1;
    
    int k1=0, k2=0;
    
    for(int i=left;i<=right;i++)
        if(l1[k1]<=l2[k2])
            a[i]=l1[k1++];
        else
            a[i]=l2[k2++];
        
    
}

void mergesort(int a[], int left, int right){
    
    int center;
    if(left<right){
        center=(left+right)/2;
        mergesort(a, left, center);
        mergesort(a, center+1, right);
        merge(a, left, center, right);    
    }    
}

 main(){
    int A[DIM];
    
    srand(time(NULL));
    
    carica(A, DIM);
    print(A, DIM);
    mergesort(A, 0, DIM-1);
    print(A, DIM);

    system("pause");

}

