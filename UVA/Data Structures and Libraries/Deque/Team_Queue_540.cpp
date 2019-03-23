#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int teams, t = 0, members, val;
	string command;
	while(cin>>teams && teams){
		unordered_map<int,int> hashTeam;
		while(teams-- && cin>>members){
			while(members-- && cin>>val){
				hashTeam[val] = teams+1; 
			}
		}
		deque< deque<int> > alpha;
		cout<<"Scenario #"<<++t<<"\n";
		while(cin>>command && command!="STOP"){
			if(command == "ENQUEUE" && cin>>val){
				if(alpha.empty()){
					alpha.emplace_back(deque<int>());
					alpha[0].emplace_back(val);
				}else{
					int teamId = hashTeam.find(val)->second;
					bool inserted = false;
					for(int i = 0; i<alpha.size() && !inserted; i++){
						if(teamId == hashTeam.find(alpha[i].front())->second){
							alpha[i].emplace_back(val);
							inserted = true;
						}
					}
					if(!inserted){
						alpha.emplace_back(deque<int>());
						alpha.back().emplace_back(val);
					}
				}
			}else{
				if(alpha.empty()) continue;
				cout<<alpha[0].front()<<"\n";
				alpha[0].pop_front();
				if(alpha[0].empty()) alpha.pop_front();
			}
		}
		cout<<"\n";
	}
	return 0;
}