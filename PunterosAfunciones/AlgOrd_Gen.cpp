#include <iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

template <class T>
int asc(T a, T b){
	return a > b;
}

template <class T>
int desc(T a, int b){
	return a < b;
}

template <class T>
void ordenar(T *arreglo_generico, int n, int (*criterio)(T,T) ){
	int i, j, aux;
	
	for (i = 0 ; i < n-1 ; i++)
		for (j = i+1 ; j < n ; j++)
			if (criterio(arreglo_generico[i], arreglo_generico[j])){
				aux = arreglo_generico[i];
				arreglo_generico[i] = arreglo_generico[j];
				arreglo_generico[j] = aux;
			}
}

template <class T>
void imprimir(T *arreglo_generico, int n){
	int i;
	for (i = 0 ; i < n ; i++)
		cout<<arreglo_generico[i];
}

  /*Quicksort generico*/
template <class T>
void intercambiar(T *v[], int i, int j) {
    void *aux;

    aux= v[i];
    v[i]= v[j];
    v[j]= aux;
  }

template <class T>
void qsort(T *arrglo[], int izq, int der,int (*compare)(T *, T *)) 
{
    int i, last;

    if (izq>=der)
      return;

    intercambiar(arrglo, izq, (izq+der)/2);
    last= izq;

    for (i= izq+1; i<=der; ++i)
      if ((*compare)(arrglo[i], arrglo[izq])<0)
        intercambiar(arrglo, ++last, i);
    intercambiar(arrglo, izq, last);

    qsort(arrglo, izq, last-1, compare);
    qsort(arrglo, last+1, der, compare);
  }

int main()
{
    
    int Arreglo_gen[] = {6,2,1,7,-9,0,4};
	imprimir(Arreglo_gen, 7);
	ordenar(Arreglo_gen, 7, asc);
	cout<<"\n Ordenado \n";
	imprimir(Arreglo_gen, 7);

    cout<<"\n <======Quicksort=======>\n";
    
    char s[50];
    char *linea[50];
    int i, j;
    

    int (*compare)(void *, void *)= (int (*)(void *, void*)) strcmp; /* Ver nota */

    for (i= 0; fgets(s, 50, stdin)!=NULL; ++i)
      linea[i]= strdup(s);

    qsort((void **)linea, 0, i-1, compare);

    for (j= 0; j<i; ++j)
      fputs(linea[j], stdout);
  
    return 0;
}