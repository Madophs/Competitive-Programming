#include <bits/stdc++.h>

using namespace std;

void printContainers(vector<stack<char>> vec){
    for(int i = 0; i < vec.size(); i++){
        while(!vec[i].empty()){
            cout<<vec[i].top()<<" ";
            vec[i].pop();
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string containers;
    int frec[27], test = 0;
    bool taken[27];
    while(cin>>containers && containers!="end"){
        memset(frec,0,sizeof frec);
        memset(taken,false, sizeof taken);
        for(int i = 0; i<containers.length(); i++) ++frec[containers[i]-'A'];
        vector< stack<char> > order;
        for(int i = 0; i<containers.length(); i++){
            if(order.empty()){
                order.emplace_back(stack<char>());
                order[0].emplace(containers[i]);
                --frec[containers[i]-'A'];
                taken[containers[i]-'A'] = true;
            }else{
                bool inserted = false;
                vector<char> lastBestChoice;
                for(int c = 0; c<order.size(); c++){
                    if(order[c].top()<containers[i]) continue;
                    if(order[c].top() == containers[i]){
                        order[c].emplace(containers[i]);
                        --frec[containers[i]-'A'];
                        inserted = true;
                        taken[containers[i]-'A'] = true;
                        break;
                    }else{
                        if(frec[order[c].top()-'A'] || taken[containers[i]-'A']) continue;
                        bool isTheBetterChoice = false;
                        for(int x = order[c].top()-'A'-1; x>=0; x--){
                            if(!frec[x]) continue;
                            if(x == (int)(containers[i]-'A'))isTheBetterChoice = true;
                            lastBestChoice.emplace_back(containers[i]);
                            break;
                        }
                        if(isTheBetterChoice){
                            order[c].emplace(containers[i]);
                            --frec[containers[i]-'A'];
                            taken[containers[i]-'A'] = true;
                            inserted = true;
                            break;
                        }else if(lastBestChoice.size()>1){
                            order[c].emplace(containers[i]);
                            --frec[containers[i]-'A'];
                            taken[containers[i]-'A'] = true;
                            inserted = true;
                            break;
                        }
                    }
                }
                if(!inserted){
                    order.emplace_back(stack<char>());
                    order.back().emplace(containers[i]);
                    --frec[containers[i]-'A'];
                    taken[containers[i]-'A'] = true;
                }
            }
        }
        //printContainers(order);
        cout<<"Case "<<++test<<": "<<order.size()<<"\n";
    }
	return 0;
}