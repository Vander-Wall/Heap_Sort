#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define Status int

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void heapify(int tree[],int n,int i){ // n stands for the amount of nodes
	
	int c1 = 2 * i + 1;  // child 1
	int c2 = 2 * i + 2;  // child 2
	int max = i;
	if(c1 < n && tree[c1] > tree[max]){
		max = c1;
	}
	if(c2 < n && tree[c2]> tree[max]){
		max = c2;
	}
	if(max != i){ // 证明max改变了
		swap(tree,max,i);
		heapify(tree,n,max);// 你影响了哪个节点就要对哪个节点做heapify
	}
}

void build_heap(int tree[],int n){
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for(int i = parent; i >= 0; i--){
		heapify(tree,n,i);
	}
}

void heap_sort(int tree[],int n){
	build_heap(tree,n);
	for(int i = n-1;i >= 0;i--){
		swap(tree,i,0);
		heapify(tree,i,0);// i表示当前节点个数，每次循环需要将堆的尺寸缩小1
	}
}


int main(int argc, char const *argv[])
{
	int tree[] = {31234, 10, 3, 5, 1, 2,3,12,3,12,3,-99,12,3,321,-99999};
	int n = sizeof(tree)/sizeof(int);
	heap_sort(tree,n);
	for(int i = 0;i < n;i++){
		printf("%d\n", tree[i]);
	}
	return 0;

}

