#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int courses, categories, inCategory, requirements,val;
	bitset<10000> selectedCourses;
	while(cin>>courses && courses && cin>>categories){
		selectedCourses.reset();
		while(courses-- && cin>>val) selectedCourses.set(val);
		bool heCan = true;
		while(categories-- && cin>>inCategory>>requirements){
			int taken = 0;
			while(inCategory-- && cin>>val){
				if(selectedCourses.test(val)) ++taken;
			}
			if(taken<requirements) heCan = false;
		}
		cout<<(heCan?"yes\n":"no\n");
	}
	return 0;
}