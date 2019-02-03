#include <bits/stdc++.h>

using namespace std;
typedef pair<int,string> is;

int moveRobot(string instruction){
	if (instruction == "LEFT")return -1;
	return 1;
}
string getInstruction(string instruction, vector<string> &ins){
	stringstream ss(instruction);
	string trash, result;
	int noInstruction;
	ss>>trash;
	ss>>trash;
	ss>>noInstruction;
	if(ins[noInstruction]=="LEFT" || ins[noInstruction]=="RIGHT"){
		return ins[noInstruction];
	}else{
		result=getInstruction(ins[noInstruction],ins);
	}
	return result;
}
int main() {
	int t,instructions;
	cin>>t;
	while(t--){
		cin>>instructions;
		cin.ignore();
		vector<string> ins(1,"inicio");
		int pos=0;
		string instruction;
		while(instructions--){
			getline(cin,instruction);
			if(instruction=="LEFT" || instruction=="RIGHT"){
				ins.push_back(instruction);
				pos+=moveRobot(instruction);
			}else{
				ins.push_back(instruction);
				pos+=moveRobot(getInstruction(instruction,ins));
			}
		}
		cout<<pos<<"\n";
	}
    return 0;
}