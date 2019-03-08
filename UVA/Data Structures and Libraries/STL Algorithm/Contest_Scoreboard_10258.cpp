#include <bits/stdc++.h>

using namespace std;

struct Contestant{
	int number,solved,accumulatedTime;
	vector< pair<int,int> > score;
	bitset<10> listSolved;
	Contestant(int num=0){
		number = num;
		solved = 0;
		score.assign(10, make_pair(0,0));
		listSolved.reset();
		accumulatedTime = 0;
	}
	void verifySubmission(int problem, int submissionTime, char veredict){
		if(veredict == 'E' || veredict == 'U' || veredict == 'R')return;
		if(veredict == 'C' && !listSolved.test(problem)){
			listSolved.set(problem);
			++solved;
			score[problem].first = submissionTime;
			accumulatedTime += score[problem].first+score[problem].second*20;
		}else{
			score[problem].first = submissionTime;
			++score[problem].second;
		}
	}
	bool operator<(Contestant &cons) const{
		if(solved > cons.solved)return true;
		if(solved == cons.solved && accumulatedTime < cons.accumulatedTime)return true;
		return solved == cons.solved && accumulatedTime == cons.accumulatedTime && number < cons.number;
	}
	friend ostream& operator<<(ostream &out,Contestant &cons){
		out<<cons.number<<" "<<cons.solved<<" "<<cons.accumulatedTime;
		return out;
	}	
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_map<int,Contestant> scoreboard;
	int t;
	int c,problem, submissionTime;
	char veredict;
	bool jump = false;
	string submission;
	cin>>t;
	cin.ignore();
	while(t--){
		if(jump){
			cout<<'\n';
		}else{
			jump = true;
			cin.ignore();
		}
		scoreboard.clear();
		while(getline(cin,submission) && !submission.empty()){
			stringstream ss(submission);
			ss>>c>>problem>>submissionTime>>veredict;
			if(scoreboard.find(c) == scoreboard.end()){
				Contestant cons(c);
				scoreboard[c] = cons;
				scoreboard.find(c)->second.verifySubmission(problem, submissionTime, veredict);
			}else{
				scoreboard.find(c)->second.verifySubmission(problem, submissionTime, veredict);
			}
		}
		vector< Contestant > finalResults;
		for(auto it = scoreboard.begin(); it!=scoreboard.end(); it++){
			auto ref = *it;
			finalResults.push_back(ref.second);
		}
		sort(finalResults.begin(),finalResults.end());
		for(auto it = finalResults.begin(); it!=finalResults.end(); it++)cout<<*it<<"\n";
	}
	return 0;
}
