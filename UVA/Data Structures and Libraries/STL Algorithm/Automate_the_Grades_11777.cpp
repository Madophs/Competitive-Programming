#include <bits/stdc++.h>

using namespace std;

int bestOfTwo(vector<int> &vec){
	sort(vec.begin(), vec.end());
	return (vec[1]+vec[2])/2;
}

char getLetter(int finalGrade){
	if(finalGrade >= 90){
		return 'A';
	}else if(finalGrade >= 80){
		return 'B';
	}else if(finalGrade >= 70){
		return 'C';
	}else if(finalGrade >= 60){
		return 'D';
	}
	return 'F';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tests, t1,t2,f,att;
	vector<int> c(3,0);
	cin>>tests;
	for(int t = 1; t<=tests; t++){
		cin>>t1>>t2>>f>>att>>c[0]>>c[1]>>c[2];
		int finalGrade = t1+t2+f+att+bestOfTwo(c);
		cout<<"Case "<<t<<": "<<getLetter(finalGrade)<<"\n";
	}
	return 0;
}