#include <bits/stdc++.h>

using namespace std;

class MinHeap{

public:
	void insertValue(int val){
		heap_list.push_back(val);
		swapNodes(heap_list.size()-1);
	}
	void removeMinValue(){
		if(heap_list.empty())return;
		if(heap_list.size()==1){
			heap_list.pop_back();
			return;
		}
		swap(heap_list[0],heap_list[heap_list.size()-1]);
		heap_list.pop_back();
		if(heap_list.size()>1)heapify(0);
	}
	void printMinHeap(){
		for(auto iter = heap_list.begin(); iter!=heap_list.end(); iter++)cout<<*iter<<(iter+1==heap_list.end()?"\n":" ");
	}
	int getMinValue(){
		return heap_list.empty()? -1: heap_list.front();
	}
	bool isEmpty(){
		return heap_list.empty();
	}
	int size(){
		return heap_list.size();
	}
private:
	vector<int> heap_list;

	void heapify(int index){
		int leftChild = left(index), rightChild = right(index), smallest = index;
		if(leftChild < heap_list.size() && heap_list[leftChild] < heap_list[smallest]){
			smallest = leftChild;
		}
		if(rightChild < heap_list.size() && heap_list[rightChild] < heap_list[smallest]){
			smallest = rightChild;
		}
		if(smallest != index){
			swap(heap_list[smallest], heap_list[index]);
			heapify(smallest);
		}

	}
	void swapNodes(int index){
		while(heap_list[parent(index)] > heap_list[index]){
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
	int n,k,cookie,ans=0;
	MinHeap heap;
	cin>>n>>k;
	while(n-- && cin>>cookie)heap.insertValue(cookie);
	while(true){
		if(heap.isEmpty()){
			cout<<-1<<endl;
			break;
		}else{
			if(heap.getMinValue()>=k){
				cout<<ans<<endl;
				break;
			}else{
				if(heap.size()==1){
					cout<<-1<<endl;
					break;
				}else{
					int a = heap.getMinValue();
					heap.removeMinValue();
					int b = heap.getMinValue();
					heap.removeMinValue();
					heap.insertValue(a+2*b);
					++ans;
					//heap.printMinHeap();
				}
			}
		}
	}
	return 0;
}