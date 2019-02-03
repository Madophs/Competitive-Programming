#include <bits/stdc++.h>
#include <unordered_map>

#define inf 1e9
using namespace std;
typedef pair<int, int>ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair< int, vector<int> > ivi;
typedef pair< int, vector<ii> > ivii;
typedef unsigned int ui;

int res[100][100];
class Grafo{
	typedef unordered_map<int, vector<int> > tabla;
public:
	tabla hash;
	Grafo(int tam):noVer(tam){
		for(int x=0; x<noVer; x++)inserta(x);
	}
	void inserta(int nom){
		vi nuevo;
		hash.insert(ivi(nom,nuevo));
	}
	void inAristas(int a, int b, int p){
		auto iter = hash.find(a);
		iter->second.push_back(b);
	}
	void aumento(int vertice,int inicio, int minimo){
		if(vertice==inicio){
			f=minimo;
			return;
		}else if(padre[vertice]!=-1){
			aumento(padre[vertice],inicio, min(minimo, res[padre[vertice]][vertice]));
			res[padre[vertice]][vertice]-=f;
			res[vertice][padre[vertice]]+=f;
		}
	}
	void edmonds_karp(int a, int b){
		int mf=0;
		while(true){
			f=0;
			padre.assign(noVer, -1);
			bitset<100> vis;
			vis[a]=true;
			queue<int> q;
			q.push(a);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(u==b)break;
				for(auto x=hash.find(u)->second.begin(); x!=hash.find(u)->second.end(); x++){
					if(res[u][*x]>0 && !vis[*x]){
						vis[*x]=true, q.push(*x),padre[*x]=u;
					}
				}
			}
			aumento(b,a,inf);
			if(f==0)break;
			mf+=f;
		}
		cout<<mf<<".\n\n";
	}
private:
	int noVer,f;
	vi padre;
};
int main(){
	int v=0,caso=0;
	while(cin>>v && v){
		int a,b,e;
		a=b=e=0;
		cin>>a>>b>>e;
		--a;--b;
		Grafo g(v);
		int i,d,p;
		i=d=p=0;
		memset(res,0,sizeof(res));
		while(e--){
			cin>>i>>d>>p;
			--i;--d;
			g.inAristas(i,d,p);
			g.inAristas(d,i,p);
			res[i][d]+=p;
			res[d][i]+=p;
		}
		cout<<"Network "<<++caso<<"\nThe bandwidth is ";
		g.edmonds_karp(a,b);
	}
	return 0;
}

