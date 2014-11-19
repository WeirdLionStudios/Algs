#include <cstdlib>
#include <iostream>

using namespace std;

const int SIZE=25;

int partition(int* A, int left, int right, int index) {
  int pivotValue = A[index];
  int storedIndex = left;
  int tmp;

  tmp = A[index];
  A[index] = A[right];
  A[right] = tmp;

  for (int i = left; i < right; i++) {
    if (A[i] <= pivotValue) {
      tmp = A[i];
      A[i] = A[storedIndex];
      A[storedIndex] = tmp;

      storedIndex++;
    }
  }
  tmp = A[storedIndex];
  A[storedIndex] = A[right];
  A[right] = tmp;

  return storedIndex;
}
int quicksort(int* A, int left, int right, int pivot) {
  //int pivot = 0;

  if (left < right) {
    pivot = partition(A, left, right, pivot);

    quicksort(A, left, pivot - 1, left);
    quicksort(A, pivot + 1, right, pivot + 1);

  }
  return 0;
}

void swap(int* A, int a, int b){
    int temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}

int main(int argc, char *argv[])
{
    int* A=new int[SIZE];

    srand(time(NULL));
    
    for(int i=0;i<SIZE;i++){
        A[i]=rand()%100;
        cout<<A[i]<<" ";    
    }
    
    cout<<endl;
    quicksort(A,0, SIZE-1, 0);
    
    for(int i=0;i<SIZE;i++){
        cout<<A[i]<<" ";
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

