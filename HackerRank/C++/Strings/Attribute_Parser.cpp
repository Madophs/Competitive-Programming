#include <bits/stdc++.h>

using namespace std;

class Tag{

public:
	Tag(string name):name(name){}

	void addAtribute(string name, string value){
		attributes[name] = value;
	}
	void addNestedTag(Tag *p){
		nested_tags[p->name] = p;
	}
	unordered_map<string, Tag*> getNestedTags(){
		return this->nested_tags;
	}
	string getAttributeValue(string attr){
		auto temp = attributes.find(attr);
		if(temp==attributes.end())
			return "Not Found!";
		return temp->second;
	}
	string getTagName(){
		return this->name;
	}
private:
	string name;
	unordered_map<string, Tag*> nested_tags;
	unordered_map<string,string> attributes;
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tags,q;
	stack<Tag*> stack_tags;
	unordered_map<string,Tag*> map_tags;
	string stag;
	cin>>tags>>q;
	cin.ignore();
	while(tags--){
		getline(cin,stag);
		if(stag[1]!='/'){
			stringstream ss(stag);
			string tagName,attrName,equals,value;
			getline(ss,tagName,' ');
			tagName.erase(remove_if(tagName.begin(), tagName.end(),[](char c){
				return c == '<' || c == '>';
			}),tagName.end());
			stack_tags.push(new Tag(tagName));
			while(getline(ss,attrName,' ')){
				getline(ss,equals,' ');
				getline(ss,value,' ');
				value.erase(remove_if(value.begin(), value.end(),[](char c){
					return c == '"' || c == '>';
				}),value.end());
				stack_tags.top()->addAtribute(attrName,value);
			}
		}else{
			Tag *temp = stack_tags.top();
			stack_tags.pop();
			if(stack_tags.empty()){
				map_tags[temp->getTagName()] = temp;
			}else{
				stack_tags.top()->addNestedTag(temp);
			}
		}
	}
	while(q--){
		getline(cin,stag);
		if(regex_match(stag,regex("[a-zA-Z0-9]+[\\~][a-zA-Z0-9]+"))){
			stringstream ss(stag);
			string tagName,attrName;
			getline(ss,tagName,'~');
			auto iter = map_tags.find(tagName);
			if(iter == map_tags.end()){
				cout<<"Not Found!"<<endl;
				continue;
			}
			getline(ss,attrName,'~');
			cout<<iter->second->getAttributeValue(attrName)<<endl;
		}else{
			vector<string> queries;
			stringstream ss(stag);
			string sentence,tagName,attrName;
			while(getline(ss,sentence,'.')){
				queries.push_back(sentence);
			}
			stringstream aux(queries.back());
			getline(aux,tagName,'~');
			getline(aux,attrName,'~');
			queries.pop_back();
			queries.push_back(tagName);
			Tag *p = nullptr;
			for(auto iter=queries.begin(); iter!=queries.end(); iter++){
				if(p==NULL){
					auto temp = map_tags.find(*iter);
					if(temp == map_tags.end()){
						tagName = "#";
						break;
					}
					p = map_tags.find(*iter)->second;
				}else{
					auto temp = p->getNestedTags().find(*iter);
					if(temp == p->getNestedTags().end()){
						tagName = "#";
						break;
					}
					p = p->getNestedTags().find(*iter)->second;
				}
			}
			if(tagName=="#"){
				cout<<"Not Found!"<<endl;
			}else{
				cout<<p->getAttributeValue(attrName)<<endl;
			}
		}
	}
	return 0;
}