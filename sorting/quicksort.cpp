/**
 * Author: Trek3
 * /

#include <cstdlib>
#include <iostream>

using namespace std;

#define DIM 8
#define MAX 100

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

void swap(int A[], int a, int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}

int partition(int A[], int left, int right, int pivot) {
    int pivotValue = A[pivot];
    int storedIndex = left;
    int tmp;

    swap(A, pivot, right);

    for (int i = left; i < right; i++) {
        if (A[i] <= pivotValue) {
            swap(A, i, storedIndex);
            storedIndex++;
        }
    }
    swap(A, storedIndex, right);
    return storedIndex;
}
int quicksort(int A[], int left, int right, int pivot) {

    if (left < right) {
        pivot = partition(A, left, right, pivot);
        quicksort(A, left, pivot - 1, left);
        quicksort(A, pivot + 1, right, pivot + 1);

    }
    return 0;
}

int main(){
    
    int A[DIM];

    srand(time(NULL));
    
    carica(A, DIM);
    print(A, DIM);
    quicksort(A, 0, DIM-1, DIM/2);
    print(A, DIM);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

