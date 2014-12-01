#include <cstdlib>
#include <iostream>

using namespace std;

int dim=1000;
int swap_count;

void swap(int*,int,int);

int main(){
	
	int A[dim];

	srand(time(NULL));

	for(int i=0;i<dim;i++){
		A[i]=rand();
	}

	for(int i=0;i<dim-1;i++){
		for(int j=i+1;j<dim;j++){
			if(A[i]>A[j]){
				swap(A, i, j);		
			}
		}
	}

	for(int i=0;i<dim;i++){
		cout<<A[i]<<" ";
	}

	cout<<"\n\nNumero di confronti:"<<dim*(dim-1)/2<<endl;

	cout<<"\n\nNumero di scambi:"<<swap_count<<endl;

	system("PAUSE");
	return 0;
}

void swap(int* A, int b, int c){
    int temp;
    
    temp=A[b];
    A[b]=A[c];
    A[c]=temp;   
    swap_count++;
}
