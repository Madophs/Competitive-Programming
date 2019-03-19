#include <bits/stdc++.h>

using namespace std;

struct Node{
	int id, period, initValue;
	Node(int id, int period):id(id),period(period),initValue(period){}
};

class Heap{
public:
	void insertNode(int id, int period){
		tree.emplace_back(Node(id,period));
		bubbleUp(tree.size()-1);
	}
	Node getHeap(){
		Node node = tree[0];
		increaseKey(0);
		return node;
	}
	void printHeap(){
		for(int i = 0; i<tree.size(); i++){
			cout<<tree[i].id<<" "<<tree[i].period<<endl;
		}
		cout<<endl;
	}
private:
	vector<Node> tree;
	int parent(int index){
		return (index-1)/2;
	}
	int left(int index){
		return (index<<1)+1;
	}
	int right(int index){
		return (index<<1)+2;
	}
	void bubbleUp(int current){
		while(tree[parent(current)].period > tree[current].period){
			if(tree[parent(current)].period > tree[current].period){
				swap(tree[parent(current)],tree[current]);
				current = parent(current);
			}
		}
		while(tree[parent(current)].period == tree[current].period && tree[parent(current)].id > tree[current].id){
			swap(tree[parent(current)],tree[current]);
			current = parent(current);
		}
	}
	void increaseKey(int key){
		tree[key].period+=tree[key].initValue;
		heapify(0);
	}
	void heapify(int index){
		int leftChild = left(index), rightChild = right(index), lowest = index;
		if(leftChild < tree.size() && tree[leftChild].period<=tree[lowest].period){
			if(tree[leftChild].period < tree[lowest].period){
				lowest = leftChild;
			}else if(tree[leftChild].id < tree[lowest].id){
				lowest = leftChild;
			}
		}
		if(rightChild < tree.size() && tree[rightChild].period<=tree[lowest].period){
			if(tree[rightChild].period < tree[lowest].period){
				lowest = rightChild;
			}else if(tree[rightChild].id < tree[lowest].id){
				lowest = rightChild;
			}
		}
		if(lowest != index){
			swap(tree[lowest], tree[index]);
			heapify(lowest);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string command;
	int id, period,queries;
	Heap h;
	while(cin>>command && command!="#"){
		cin>>id>>period;
		h.insertNode(id,period);
	}
	cin>>queries;
	//h.printHeap();
	while(queries--){
		Node ans = h.getHeap();
		cout<<ans.id<<"\n";
	}
	return 0;
}