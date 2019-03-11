#include <bits/stdc++.h>

using namespace std;

struct Nodo{
	int disIzq, disDer, pesoIzq, pesoDer;
	bool balanceado;
	Nodo *izq, *der;
	Nodo(int d1, int d2, int p1, int p2){
		this->disIzq = d1;
		this->disDer = d2;
		this->pesoIzq = p1;
		this->pesoDer = p2;
		this->balanceado = true;
		this->izq = NULL, this->der = NULL;
	} 
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int pi,di,pd,dd, nom;
	bool primerDato = true;
	while(cin>>pi>>di>>pd>>dd && (pi || di || pd || dd)){
		Nodo *raiz = new Nodo(di,dd,pi,pd);
		stack<Nodo*> input;
		if(pi == 0 || pd == 0) input.push(raiz);
		while(!input.empty() && cin>>pi>>di>>pd>>dd){
			Nodo *temp = new Nodo(di,dd,pi,pd);
			if(input.top()->pesoIzq == 0){
				input.top()->izq = temp;
			}else if(input.top()->pesoDer == 0){
				input.top()->der = temp;
			}
			if(pi == 0 || pd == 0){
				input.push(temp);
			}else{
				temp->balanceado = temp->pesoIzq*temp->disIzq == temp->pesoDer * temp->disDer && temp->balanceado;
				input.top()->balanceado = temp->balanceado;
				if(input.top()->pesoIzq == 0){
					input.top()->pesoIzq = temp->pesoDer+temp->pesoIzq;
				}else if(input.top()->pesoDer == 0){
					input.top()->pesoDer = temp->pesoDer+temp->pesoIzq;
				}
				while(!input.empty() && input.top()->pesoIzq != 0 && input.top()->pesoDer != 0){
					Nodo *aux = input.top();
					input.pop();
					if(input.empty()) break;
					aux->balanceado = (aux->pesoIzq*aux->disIzq == aux->pesoDer * aux->disDer) && aux->balanceado;
					input.top()->balanceado = input.top()->balanceado && aux->balanceado;
					if(input.top()->pesoIzq == 0){
						input.top()->pesoIzq = aux->pesoDer+aux->pesoIzq;
					}else if(input.top()->pesoDer == 0){
						input.top()->pesoDer = aux->pesoDer+aux->pesoIzq;
					}
				}
			}
		}
		raiz->balanceado = (raiz->pesoIzq*raiz->disIzq == raiz->pesoDer * raiz->disDer) && raiz->balanceado;
		cout<<(raiz->balanceado?"SI\n":"NO\n");
	}
	return 0;
}