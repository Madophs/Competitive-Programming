#include <bits/stdc++.h>

using namespace std;

multiset<int, greater<int> > blues, greens;

void addSurvivors(multiset<int, greater<int>> &s, vector<int> &vec){
	while(!vec.empty()){
		s.insert(vec.back());
		vec.pop_back();
	}
}

void letsfight(vector<int> &greenSurvivers, vector<int> &blueSurvivers){
	int greenLemming = *greens.begin(), blueLemming = *blues.begin();
	greens.erase(greens.begin()), blues.erase(blues.begin());
	if(greenLemming > blueLemming){
		greenSurvivers.push_back(greenLemming-blueLemming);
	}else if(greenLemming < blueLemming){
		blueSurvivers.push_back(blueLemming-greenLemming);
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, numBlue, numGreen, battles, soldier;
	cin>>tests;
	for(int t = 0; t<tests; t++){
		if(t)cout<<'\n';
		cin>>battles>>numGreen>>numBlue;
		blues.clear(), greens.clear();
		while(numGreen-- && cin>>soldier) greens.insert(soldier);
		while(numBlue-- && cin>>soldier) blues.insert(soldier);
		vector<int> greenSurvivers, blueSurvivers;
		while(!greens.empty() && !blues.empty()){
			for(int fight = 0; fight<battles && !greens.empty() && !blues.empty(); fight++){
				letsfight(greenSurvivers,blueSurvivers);
				if(greens.empty() || blues.empty())break;
			}
			addSurvivors(greens, greenSurvivers);
			addSurvivors(blues, blueSurvivers);
		}
		if(greens.empty() && blues.empty()){
			cout<<"green and blue died\n";
		}else if(!greens.empty()){
			cout<<"green wins\n";
			for(auto it = greens.begin(); it!=greens.end(); it++){
				cout<<*it<<'\n';
			}
		}else{
			cout<<"blue wins\n";
			for(auto it = blues.begin(); it!=blues.end(); it++){
				cout<<*it<<'\n';
			}
		}
	}	
	return 0;
}