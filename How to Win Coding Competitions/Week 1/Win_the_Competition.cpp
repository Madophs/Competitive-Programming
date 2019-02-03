#include "edx-io.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	const int limit = 300*60;
	int n;
	io>>n;
	vector<int> vec(n);
	for(int x = 0; x<n; x++)io>>vec[x];
	sort(vec.begin(),vec.end());
	int sum = 0, ans = 0;
	for(int x=0; x<vec.size(); x++){
		if(sum+vec[x]<=limit) sum+=vec[x],++ans;
	}
	io<<ans<<"\n";
	return 0;
}