#include<bits/stdc++.h>
using namespace std; 

template<typename T>
int BusquedaBinaria( T x, vector<T>& a, int ini, int fin){
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


template<typename T>
int BusquedaBinaria_INV(T x, vector<T>& a, int ini, int fin){
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

template<typename T>
int Partition(vector<T>& vec, int ini, int fin){
	T x = vec[fin];
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

template<typename T>
void QuickSort(vector<T>& vec, int ini, int fin){
	if(ini < fin){
		int pivot = Partition(vec, ini, fin);
		QuickSort(vec, ini, pivot - 1);
		QuickSort(vec, pivot + 1, fin);
	}
}



	
