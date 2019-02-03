#include <bits/stdc++.h>

using namespace std;

int mdsBinarySearch(vector<pair<long int, int>> &vec, long int val){
	int lower = 0, upper = vec.size()-1, middle;
	while(lower<=upper){
		middle = (lower+upper)/2;
		if(vec[middle].first < val){
			lower = middle+1;
		}else if(vec[middle].first > val){
			upper = middle-1;
		}else{
			return middle;
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int size;
	cin>>size;
	vector<long int> vec(size,0),vecClone;
	vector< pair<long int, int> > table,tableClone;
	for(int x=0; x<size && cin>>vec[x]; x++)table.push_back(make_pair(vec[x],x));
	sort(table.begin(), table.end());
	vecClone = vec;
	tableClone = table;
	int cont = 0 , cont2 = 0;
	for(int x=0,j=vec.size()-1; x<vec.size(); x++,j--){
		if(table[x].first != vec[x]){
			int newPosIndex = table[x].second, curPos = mdsBinarySearch(table,vec[x]);
			swap(vec[x],vec[table[x].second]);
			table[x].second = x;
			table[curPos].second = newPosIndex;
			++cont;
		}
		if(tableClone[j].first != vecClone[x]){
			int newPosIndex = tableClone[j].second, curPos = mdsBinarySearch(tableClone,vecClone[x]);
			swap(vecClone[x],vecClone[tableClone[j].second]);
			tableClone[j].second = x;
			tableClone[curPos].second = newPosIndex;
			++cont2;
		}
		
	}
	cout<<min(cont,cont2)<<'\n';
	return 0;
}
