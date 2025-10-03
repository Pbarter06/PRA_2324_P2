#include<bits/stdc++.h>
using namespace std; 


int BusquedaBinaria( int x, vector<int>& a, int ini, int fin){
	if(ini > fin){
		cout << "No se encuentra el array";
	       return -1; 	
	}
	
	int medio = (ini + fin)/2; 
	if(a[medio] == x){
		return medio; 
	}	
	else if(a[medio] > x){
		return BusquedaBinaria(x, a, ini, medio -1);
	}
	else{
		return BusquedaBinaria(x, a, medio + 1, fin); 
	}
}



int BusquedaBinaria_INV(int x, vector<int>& a, int ini, int fin){
	if(ini > fin){
                cout << "No se encuentra el array";
               return -1;
        }

	int medio = (ini + fin)/2; 
	if(a[medio] == x){
		return medio; 
	} else if(a[medio] > x){
		return BusquedaBinaria_INV(x, a, medio + 1, fin); 
	} else{
		return BusquedaBinaria_INV(x, a, ini, medio -1); 
	}
}


int Partition(vector<int>& vec, int ini, int fin){
	int x = vec[fin];
	int i = ini;
	for(int j = ini; j < fin; j++){
		if(vec[j] <= x){
			int aux = vec[i];
			vec[i] = vec[j]; 
			vec[j] = aux;
			i = i + 1;
		}
	}  
	int aux = vec[i];
	vec[i] = vec[fin];
	vec[fin] = aux;
	return i;
}


void QuickSort(vector<int>& vec, int ini, int fin){
	if(ini < fin){
		int pivot = Partition(vec, ini, fin);
		QuickSort(vec, ini, pivot - 1);
		QuickSort(vec, pivot + 1, fin);
	}
}



	
