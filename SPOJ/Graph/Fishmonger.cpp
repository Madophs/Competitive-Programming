#include <bits/stdc++.h>

using namespace std;

struct Data{
	int leftTime, tolls;
	Data(int leftTime, int tolls){
		this->leftTime = leftTime;
		this->tolls = tolls;
	}
	bool operator == (Data data) const{
		return this->leftTime == data.leftTime && this->tolls == data.tolls;
	}
	bool operator != (Data data) const{
		return this->leftTime != data.leftTime || this->tolls != data.tolls;
	}
};

const int MAX_STATES = 55, INF = 1e9, MAX_TIME = 1010;
int matrixTime[MAX_STATES][MAX_STATES], matrixTolls[MAX_STATES][MAX_STATES];
int state, availableTime;
vector<vector<Data>> memo(MAX_STATES, vector<Data>(MAX_TIME, Data(-1,-1)));

Data fishmonger(int u, int leftTime){
	if(leftTime < 0) return Data(INF, INF);
	if(u == state-1) return Data(0,0);
	if(memo[u][leftTime] != Data(-1,-1)) return memo[u][leftTime];
	Data ans(INF,INF);
	for(int v = 0; v<state; v++){
		if(v!=u){
			Data result = fishmonger(v, leftTime - matrixTime[u][v]);
			if(result.tolls + matrixTolls[u][v] < ans.tolls){
				ans.tolls = result.tolls + matrixTolls[u][v];
				ans.leftTime = result.leftTime + matrixTime[u][v];
			}
		}
	}
	return memo[u][leftTime] = ans;
}

void resetMemo(){
	for(int i = 0; i<MAX_STATES; i++){
		for(int j = 0; j<MAX_TIME; j++){
			memo[i][j].leftTime = -1;
			memo[i][j].tolls = -1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>state>>availableTime && (state || availableTime)){
		for(int i = 0; i<state; i++){
			for(int j = 0; j<state; j++){
				cin>>matrixTime[i][j];
			}
		}
		for(int i = 0; i<state; i++){
			for(int j = 0; j<state; j++){
				cin>>matrixTolls[i][j];
			}
		}
		Data ans = fishmonger(0, availableTime);
		cout<<ans.tolls<<" "<<ans.leftTime<<"\n";
		resetMemo();
	}
	return 0;
}