#include <bits/stdc++.h>

using namespace std;

void fillDeque(int n, deque<int> &d, int &h){
	int val;
	while(n--){
		cin>>val;
		h+=val;
		d.push_back(val);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n1, n2, n3,val;
	int *height = new int[3]();
	deque<int> s1, s2, s3;
	deque<int> *pilas = new deque<int>[3]();
	cin>>n1>>n2>>n3;
	fillDeque(n1,pilas[0],height[0]);
	fillDeque(n2,pilas[1],height[1]);
	fillDeque(n3,pilas[2],height[2]);
	int minValue=1e9, maxValue = -1, pos=0;
	while(1){
		minValue = 1e9, maxValue = -1;
		for(int x=0; x<3; x++){
			if(maxValue < height[x])pos = x, maxValue = height[x];
			minValue = min(minValue,height[x]);
		}
		if(minValue == maxValue){
			cout<<maxValue<<endl;
			break;
		}else{
			if(!pilas[pos].empty()){
				height[pos]-=pilas[pos].front();
				pilas[pos].pop_front();
			}
				
		}
	}
	return 0;
}