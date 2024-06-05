/*
 *本程序要求实现一维数组的冒泡排序和选择排序
 *
 */




#include<stdio.h>

void bubbleSort(int A[],int n){
	int i;
	int j;
	int tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				tmp=A[j];
				A[j]=A[j+1];
				A[j+1]=tmp;	
			
			}
		}
	}
}

void print_Sort(int A[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%4d",A[i]);
	}
	printf("\n");
}

void selectionSort(int A[],int n){
	int i;
	int j=0;
	int min;
	int tmp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[min]){
				min=j;
			}
		}
		tmp=A[min];
		A[min]=A[i];
		A[i]=tmp;
	}
}

int main(){
	int bubble_arr[]={58,25,89,119,2,0,-23};
	int selection_arr[]={58,25,89,119,2,0,-23};
	bubbleSort(bubble_arr,7);
	selectionSort(selection_arr,7);
	printf("冒泡排序后的数组为：\n");
	print_Sort(bubble_arr,7);
	printf("选择排序后的数组为：\n");
	print_Sort(selection_arr,7);
	return 0;

}
