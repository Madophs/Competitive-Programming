#include <bits/stdc++.h>

using namespace std;

class MaxHeap{

public:
	void insertValue(int val){
		heap_list.push_back(val);
		swapNodes(heap_list.size()-1);
	}
	void removeMaxValue(){
		if(heap_list.empty())return;
		if(heap_list.size()==1){
			heap_list.pop_back();
			return;
		}
		swap(heap_list[0],heap_list[heap_list.size()-1]);
		heap_list.pop_back();
		if(heap_list.size()>1)heapify(0);
	}
	int getMaxValue(){
		return heap_list.empty()? -1: heap_list.front();
	}
	void printMaxHeap(){
		for(auto iter = heap_list.begin(); iter!=heap_list.end(); iter++)cout<<*iter<<(iter+1==heap_list.end()?"\n":" ");
	}
private:
	vector<int> heap_list;

	void heapify(int index){
		int leftChild = left(index), rightChild = right(index), greatest = index;
		if(leftChild < heap_list.size() && heap_list[leftChild] > heap_list[greatest]){
			greatest = leftChild;
		}
		if(rightChild < heap_list.size() && heap_list[rightChild] > heap_list[greatest]){
			greatest = rightChild;
		}
		if(greatest != index){
			swap(heap_list[greatest], heap_list[index]);
			heapify(greatest);
		}

	}
	void swapNodes(int index){
		while(heap_list[parent(index)] < heap_list[index]){
			swap(heap_list[parent(index)],  heap_list[index]);
			index = parent(index);
		}
	}
	int parent(int index){
		return (index-1)/2;
	}
	int left(int index){
		return (index<<1)+1;
	}
	int right(int index){
		return (index<<1)+2;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int size,val;
	cin>>size;
	MaxHeap heap;
	while(size-- && cin>>val){
		heap.insertValue(val);
		heap.printMaxHeap();
	}
	heap.printMaxHeap();
	heap.removeMaxValue();
	heap.printMaxHeap();
	heap.removeMaxValue();
	heap.printMaxHeap();
	return 0;
}