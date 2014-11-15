package wls.algs.mergesort;

import java.util.Random;

public class MergeSort {
	static final int SIZE=100;
	static final int MAX=100;
	
	static int[] A=new int[SIZE];
	
	public static void main(String[] args){
		//Generazione di un array di numeri casuali
		for(int i=0;i<SIZE;i++)
			A[i]=new Random().nextInt()%MAX;
		
		for(int i=0;i<SIZE;i++)
			System.out.print(A[i]+" ");
		System.out.println("\n");
		
		//Execute mergesort
		A=mergeSort(A, 0, SIZE-1);
		
		for(int i=0;i<SIZE;i++)
			System.out.print(A[i]+" ");
		System.out.println("\n");
	}
	
	static int[] mergeSort(int[] A, int p, int r){
		if(p<r){
			int q=(p+r)/2;
			A=mergeSort(A, p, q);
			A=mergeSort(A, q+1, r);
			A=merge(A, p, q, r);
		}
		return A;
	}
	
	static int[] merge(int[] A, int p, int q, int r){
		int n1=q-p+1;
		int n2=r-q;
		int[] l1=new int[n1+1];
		int[] l2=new int[n2+1];
		
		for(int i=0;i<n1;i++)
			l1[i]=A[p+i];
		for(int i=0;i<n2;i++)
			l2[i]=A[q+i+1];
		
		l1[n1]=Integer.MAX_VALUE;
		l2[n2]=Integer.MAX_VALUE;
		
		int k1=0, k2=0;
		for(int i=p;i<=r;i++){
			if(l1[k1]<=l2[k2])
				A[i]=l1[k1++];
			else
				A[i]=l2[k2++];
		}
		return A;
	}
}