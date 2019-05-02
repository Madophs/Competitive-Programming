#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;
const int MAX_CITIES = 12, MAX_DAYS = 1010;
int days, cities, period, flightPrice;
int memo[MAX_CITIES][MAX_DAYS];

struct Flight{
	int city;
	vector<int> prices;
	Flight(int city){
		this->city = city;
	}
};

class Graph{
	public:
		vector<vector<Flight>> cityGraph;
		Graph(int numCities){
			cityGraph.assign(numCities, vector<Flight>());
		}
		void addSchedule(int current, int from, vector<int> prices){
			Flight flight(from);
			flight.prices = prices;
			cityGraph[current].emplace_back(flight);
		}
		int minimumPrice(int u, int leftDays){
			if(leftDays == 1 && u!= cities-1){
				int day = (days-leftDays) % cityGraph[u].back().prices.size();
				if(cityGraph[u].back().prices[day] == 0) return INF;
				return cityGraph[u].back().prices[day];
			}else if(leftDays == 0){
				if(u == cities-1) return 0;
				else return INF;
			}
			if(memo[u][leftDays] != -1) return memo[u][leftDays];
			int ans = INF;
			for(int v = 0; v<cityGraph[u].size(); v++){
				int day = (days - leftDays) % cityGraph[u][v].prices.size();
				if(cityGraph[u][v].prices[day] == 0) continue;
				int result = minimumPrice(cityGraph[u][v].city, leftDays-1) + cityGraph[u][v].prices[day];
				ans = min(ans, result);
			}
			return memo[u][leftDays] = ans;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int scenario = 0;
	while(cin>>cities>>days && (cities || days)){
		Graph g(cities);
		for(int u = 0; u<cities; u++){
			for(int v = 0; v<cities; v++){
				if(u == v) continue;
				cin>>period;
				vector<int> tempPrices;
				while(period-- && cin>>flightPrice) tempPrices.emplace_back(flightPrice);
				g.addSchedule(u,v,tempPrices);
			}
		}
		memset(memo, -1, sizeof memo);
		int ans = g.minimumPrice(0,days);
		cout<<"Scenario #"<<++scenario<<"\n";
		if(ans == INF){
			cout<<"No flight possible.\n";
		}else{
			cout<<"The best flight costs "<<ans<<".\n";
		}
		cout<<"\n";
	}
	return 0;
}