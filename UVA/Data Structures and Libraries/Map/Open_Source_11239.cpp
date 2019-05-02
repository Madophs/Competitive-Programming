#include <bits/stdc++.h>

using namespace std;

struct Data{
	int students;
	string course;
	Data(int students, string course){
		this->students = students;
		this->course = course;
	}

	bool operator <(Data data) const{
		if(this->students > data.students) return true;
		return this->students == data.students && this->course < data.course;
	}

};

ostream & operator << (ostream &out,const Data &data){
	out<<data.course<<" "<<data.students;
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string title, userid;
	unordered_map<string,string> userIdRegistry;
	unordered_map<string,unordered_set<string>> titlesRegistry;
	unordered_set<string> excluded;
	while(getline(cin, title) && title[0]!='0'){
		userIdRegistry.clear(), titlesRegistry.clear(), excluded.clear();
		titlesRegistry.insert(make_pair(title,unordered_set<string>()));
		while(getline(cin, userid) && userid[0]!='1'){
			if(userid[0]>='A' && userid[0]<='Z'){
				title = userid;
				titlesRegistry.insert(make_pair(title, unordered_set<string>()));
				continue;
			}
			if(excluded.find(userid) != excluded.end()) continue;
			if(userIdRegistry.find(userid) != userIdRegistry.end()){
				string tempTitle = userIdRegistry.find(userid)->second;
				if(tempTitle != title){
					excluded.insert(userid);
					titlesRegistry.find(tempTitle)->second.erase(userid);
				}
			}else{
				userIdRegistry.insert(make_pair(userid,title));
				titlesRegistry.find(title)->second.insert(userid);
			}
		}
		vector<Data> results;
		for(auto iter: titlesRegistry){
			Data data((int) iter.second.size(), iter.first);
			results.emplace_back(data);
		}
		sort(results.begin(), results.end());
		for(Data data: results){
			cout<<data<<"\n";
		}
	}
	return 0;
}
