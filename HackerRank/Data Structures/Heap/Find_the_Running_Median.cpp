#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
private:
	int parent(int index){
		return (index-1)/2;
	}
	int left(int index){
		return (index<<1)+1;
	}
	int right(int index){
		return (index<<1)+2;
	}
	vector<int> nodes;
public:
	void insert(int val){
		nodes.push_back(val);
		int index = nodes.size()-1;
		while(nodes[parent(index)] < nodes[index]){
			swap(nodes[parent(index)],nodes[index]);
			index = parent(index);
		}
	}
	void removeMax(){
		swap(nodes[nodes.size()-1], nodes[0]);
		nodes.pop_back();
		heapify(0);
	}
	void heapify(int index){
		int l = left(index), r = right(index), greatest = index;
		if(l < nodes.size() && nodes[l] > nodes[greatest]){
			greatest = l;
		}
		if(r < nodes.size() && nodes[r] > nodes[greatest]){
			greatest = r;
		}
		if(greatest != index){
			swap(nodes[greatest],nodes[index]);
			heapify(greatest);
		}
	}
	void print(){
		for(auto iter = nodes.begin(); iter!=nodes.end(); iter++)cout<<*iter<<" ";
		cout<<endl;
	}
	int size(){
		return nodes.size();
	}
	int getMax(){
		if(nodes.empty()) return -1;
		return nodes.front();
	}
};

class MinHeap{
private:
	int parent(int index){
		return (index-1)/2;
	}
	int left(int index){
		return (index<<1)+1;
	}
	int right(int index){
		return (index<<1)+2;
	}
	vector<int> nodes;
public:
	void insert(int val){
		nodes.push_back(val);
		int index = nodes.size()-1;
		while(nodes[parent(index)] > nodes[index]){
			swap(nodes[parent(index)],nodes[index]);
			index = parent(index);
		}
	}
	void removeMin(){
		swap(nodes[nodes.size()-1], nodes[0]);
		nodes.pop_back();
		heapify(0);
	}
	void heapify(int index){
		int l = left(index), r = right(index), greatest = index;
		if(l < nodes.size() && nodes[l] < nodes[greatest]){
			greatest = l;
		}
		if(r < nodes.size() && nodes[r] < nodes[greatest]){
			greatest = r;
		}
		if(greatest != index){
			swap(nodes[greatest],nodes[index]);
			heapify(greatest);
		}
	}
	void print(){
		for(auto iter = nodes.begin(); iter!=nodes.end(); iter++)cout<<*iter<<" ";
		cout<<endl;
	}
	int size(){
		return nodes.size();
	}
	int getMin(){
		if(nodes.empty()) return 1e9;
		return nodes.front();
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,val;
	cout<<setprecision(1)<<fixed;
	cin>>n;
	MaxHeap lowers;
	MinHeap uppers;
	while(n--){
		cin>>val;
		if(val < uppers.getMin()){
			lowers.insert(val);
		}else{
			uppers.insert(val);
		}
		if(lowers.size() < uppers.size()){
			lowers.insert(uppers.getMin());
			uppers.removeMin();
		}else if(abs(lowers.size() - uppers.size()) > 1){
			uppers.insert(lowers.getMax());
			lowers.removeMax();
		}
		if((lowers.size() + uppers.size()) & 1){
			cout<<(double)lowers.getMax()<<endl;
		}else{
			cout<<((double)(lowers.getMax()+uppers.getMin())/2.0)<<endl;			
		}
	}
	return 0;
}