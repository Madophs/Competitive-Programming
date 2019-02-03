#include <bits/stdc++.h>

using namespace std;

struct ArrivalTime{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.first > b.first;
	}
};

struct PreparationTime{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.second > b.second;
	}
};

long long time_lapsed = 0, waiting = 0;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue< pair<int,int>, vector<pair<int,int>>, ArrivalTime> arrival;
	priority_queue< pair<int,int>, vector<pair<int,int>>, PreparationTime>order;
	int n,order_time,pizza_time,size;
	cin>>n;
	size = n; 
	while(n-- && cin>>order_time>>pizza_time)arrival.push(make_pair(order_time,pizza_time));

	while(!arrival.empty()){
		if(order.empty()){
			order.push(arrival.top());
			arrival.pop();
		}
		while(!order.empty()){
			pair<int,int> c = order.top();
			order.pop();
			int temp_time = 0;
			if(c.first >= time_lapsed){
				temp_time+=c.second+(c.first-time_lapsed);
				waiting+=c.second;
			}else{
				temp_time+=c.second;
				waiting+=c.second + (time_lapsed-c.first);
			}
			time_lapsed+=temp_time;
			while(!arrival.empty() && arrival.top().first<=time_lapsed){
				order.push(arrival.top());
				arrival.pop();
			}
		}
	}
	cout<<waiting/size<<endl;
	return 0;
}

/*

5
317664929 898415172
283280121 782916802
961148050 385599125
980913391 847912645
951133776 376367013

5
283280121 782916802
980913391 847912645
951133776 376367013
317664929 898415172
961148050 385599125

5
283280121 782916802
317664929 898415172
951133776 376367013
961148050 385599125
980913391 847912645

*/