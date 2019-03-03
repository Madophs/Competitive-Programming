#include <bits/stdc++.h>

using namespace std;

class Heap{
public:
	bool insertNode(int val){
		nodes.push_back(val);
		int currentIndex = nodes.size()-1;
		while(nodes[parent(currentIndex)] > nodes[currentIndex]){
			swap(nodes[parent(currentIndex)], nodes[currentIndex]);
			currentIndex = parent(currentIndex);
		}
		return true;
	}
	void removeHeap(){
		if(nodes.empty())return;
		swap(nodes[0],nodes[nodes.size()-1]);
		nodes.pop_back();
		heapify(0);
	}
	void heapify(int index){
		int leftChild = left(index), rightChild = right(index), current = index;
		if(leftChild < nodes.size() && nodes[leftChild] < nodes[current]){
			current = leftChild;
		}
		if(rightChild < nodes.size() && nodes[rightChild] < nodes[current]){
			current = rightChild;
		}
		if(current != index){
			swap(nodes[current], nodes[index]);
			heapify(current);
		}
	}
	int getHeap(){
		if(nodes.empty()) return 0;
		return nodes[0];
	}
	int popHeap(){
		int heap = getHeap();
		removeHeap();
		return heap;
	}
	bool isEmpty(){
		return nodes.empty();
	}
	void printHeap(){
		for(auto it = nodes.begin(); it!=nodes.end(); it++){
			cout<<*it<<(it+1 == nodes.end()?"\n":" ");
		}
	}
private:
	vector<int> nodes;
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
	cout.tie(NULL);
	int length, values;
	while(cin>>length && length){
		Heap h;
		while(length-- && cin>>values && h.insertNode(values));
		long long sum=0, ans=0;
		while(!h.isEmpty()){
			ans += sum = h.popHeap() + h.popHeap();
			if(!h.isEmpty())h.insertNode(sum);
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}