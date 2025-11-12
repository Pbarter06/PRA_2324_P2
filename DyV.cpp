#include <bits/stdc++.h>
#include "DyV.h"
using namespace std; 

template<typename T>
int main(){
	T valor; cin >> valor; 
	vector<T> v; 

	T x; 
	while(cin >> x){
		v.push_back(x); 
	}

	//sort(v.begin(), v.end()); 
	cout << "Vector ordenado: ";
	QuickSort(v, 0, v.size() -1);
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "posicion: " << BusquedaBinaria(valor, v, 0, v.size() -1)+ 1; 

	//reverse(v.begin(), v.end()); 

	cout << "posicion en inv: " << BusquedaBinaria_INV(valor, v, 0, v.size() - 1)+ 1; 

	return 0; 
}
