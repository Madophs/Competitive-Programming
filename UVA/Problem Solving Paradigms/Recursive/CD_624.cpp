#include <bits/stdc++.h>

using namespace std;

vector<int> minutes;

int maxDuration(int limit, int index, int &ans){
    if(limit <= 0 || index >= minutes.size()) return 0;
    int ret = 0, bestAns = 0;
    for(int i = index; i < minutes.size(); i++){
        if(minutes[i] <= limit){
            int tempAns = ans|1<<i, temp = minutes[i] + maxDuration(limit-minutes[i], i+1,tempAns);
            if(ret < temp){
                ret = temp;
                bestAns = tempAns;
            }
        }
    }
    if(bestAns) ans = bestAns;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int minutesLong, tracks, duration;
    while(cin>>minutesLong>>tracks){
        minutes.clear();
        while(tracks-- && cin>>duration) minutes.emplace_back(duration);
        int solution = 0, ans = maxDuration(minutesLong,0,solution);
        for(int i = 0; solution; i++, solution>>=1){
            if(solution&1)cout<<minutes[i]<<" ";
        }
        cout<<"sum:"<<ans<<endl;
    }
    return 0;
}
