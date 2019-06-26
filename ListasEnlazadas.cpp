#include <iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

template <typename T>
class Lista;

template <typename T>
class Nodo
{
    private:
        friend class Lista<T>;
        Nodo<T> *siguiente;
        T datos;
    public:
        T getDato(){return datos;}
};


template <class T>
class Lista
{
    private:
        Nodo<T> *n_inicial;
        Nodo<T> *n_cola;
        int n_num_nodos;

    public:
        class iterator;
        iterator begin();
        iterator end();
        Lista();
        ~Lista();
        Nodo<T> *get(int i);
        void agregaInicio(T const &dato);
        void agregaFinal(T const &dato);
        void agregaEnOrden(int i, T const &dato);
        void agregaElemento(T);
        void llenar_aleatorio(int);
        void eliminar();
        void eliminar_por_dato(T);
        void eliminar_por_posicion(int);
        void llenar_por_usuario(int);
        void imprimir();
        void search(T);
        int nodos()
        {
            return n_num_nodos;
        }

};

template<typename T>
class Lista<T>::iterator
{
    private:
        Nodo<T> *actual;

    public:
        iterator(Nodo<T> *ptr):actual(ptr){}
        iterator &operator++()
        {
            actual = actual->siguiente;
            return *this;
        }
        T &operator*()
        {
            return actual->datos;
        }
        bool operator==(iterator const &x) const {return actual == x.actual;}
        bool operator!=(iterator const &x) const {return actual != x.actual;}
};

template<typename T>
typename Lista<T>::iterator Lista<T>::begin()
{
    iterator it(n_inicial);
    return it;
}

template<typename T>
typename Lista<T>::iterator Lista<T>::end()
{
    iterator it(n_cola);
    return it;
}

template<typename T>
Nodo<T> *Lista<T>::get(int i)
{
    Nodo<T> *ptr = n_inicial;
    for(int a = 0; a<i; ++a)
        ptr = ptr->siguiente;
    return ptr;
}

// Constructor por defecto
template<typename T>
Lista<T>::Lista()
{
    n_num_nodos = 0;
    n_inicial = nullptr;
    n_cola    = nullptr;
}

template<typename T>
Lista<T>::~Lista()
{
    while(n_inicial != nullptr)
    {
        Nodo<T> *ptr = n_inicial->siguiente;
        delete n_inicial;
        n_inicial = ptr;
    }
}

// Insertar al inicio
template<typename T>
void Lista<T>::agregaInicio(T const &dato)
{
    Nodo<T> *nuevo_nodo = new Nodo<T>();
    nuevo_nodo->datos = dato;
    nuevo_nodo->siguiente = n_inicial;
    n_inicial = nuevo_nodo;
    if(n_inicial->siguiente == nullptr)
        n_cola = n_inicial;
    n_num_nodos++;
}

// Insertar al final
template<typename T>
void Lista<T>::agregaFinal(T const &dato)
{
    if(n_cola == nullptr)
    {
        agregaInicio(dato);
    return;
    }
    Nodo<T> *nuevo_nodo = new Nodo<T>();
    nuevo_nodo->datos = dato;
    n_cola->siguiente = nuevo_nodo;
    n_cola = nuevo_nodo;
    n_num_nodos++;
}

// Insertar de manera ordenada
template<typename T>
void Lista<T>::agregaEnOrden(int i, T const &dato)
{
    if(i<0 || i>nodos())
    {
        return;
    }
    if(i==0)
    {
        agregaInicio(dato);
        return;
    }
    if(i=nodos())
    {
        agregaFinal(dato);
        return;
    }
    Nodo<T> *a = get(i-1);
    Nodo<T> *b = a->siguiente;
    Nodo<T> *nuevo_nodo = new Nodo<T>();
    nuevo_nodo->datos = dato;
    nuevo_nodo->siguiente = b;
    a->siguiente = nuevo_nodo;
    n_num_nodos++;
}

// Eliminar todos los nodos
template<typename T>
void Lista<T>::eliminar()
{
    n_inicial->eliminar();
    n_inicial = 0;
}

// Eliminar por data del nodo
template<typename T>
void Lista<T>::eliminar_por_dato(T dato)
{
    Nodo<T> *temp = n_inicial;
    Nodo<T> *temp1 = n_inicial->siguiente;

    int cont = 0;

    if (n_inicial->datos == dato) {
        n_inicial = temp->siguiente;
    } else {
        while (temp1) {
            if (temp1->datos == dato) {
                Nodo<T> *aux_nodo = temp1;
                temp->siguiente = temp1->siguiente;
                delete aux_nodo;
                cont++;
                n_num_nodos--;
            }
            temp = temp->siguiente;
            temp1 = temp1->siguiente;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

// Eliminar por posición del nodo
template<typename T>
void Lista<T>::eliminar_por_posicion(int pos)
{
    Nodo<T> *temp = n_inicial;
    Nodo<T> *temp1 = temp->siguiente;

    if (pos < 1 || pos > n_num_nodos) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        n_inicial = temp->siguiente;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Nodo<T> *aux_nodo = temp1;
                temp->siguiente = temp1->siguiente;
                delete aux_nodo;
                n_num_nodos--;
            }
            temp = temp->siguiente;
            temp1 = temp1->siguiente;
        }
    }
}

// Llenar la Lista por teclado
template<typename T>
void Lista<T>::llenar_por_usuario(int dim)
{
    T elemento;
    for (int i = 0; i < dim; i++) {
        cout << "Ingresa el elemento " << i + 1 << endl;
        cin >> elemento;
        agregaFinal(elemento);
    }
}

 // Llenar la Lista aleatoriamente para enteros
template<typename T>
void Lista<T>::llenar_aleatorio(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        agregaFinal(rand() % 100);
    }
}


void imprimir(Lista<int> &ls)
{

    for (Lista<int>::iterator it = ls.begin(); it != ls.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}


int search(Lista<int>& ls, int data)
{
    int i = 0;
    for (Lista<int>::iterator it = ls.begin(); it != ls.end(); ++it) {
    return i;
    }
}

//-------------------------------Usando Pilas--------------------------------//
/*
template <typename T>
class Pila {
 private:
  Lista<T> p;

 public:
  void push(T const& dato);
  T pop();


  int size() { return p.size(); }
};

template <typename T>
void Pila<T>::push(T const& dato) { p.insert(data); }


template <typename T>
T Pila<T>::pop() {
  T dato = p.get(0)->getData();
  s.erase();
  return data;
}

template <typename T>
T Stack<T>::peek() { return s.get(0)->getData(); }

*/


int main()
{
    Lista<int> lista1;
    Lista<int> lista2;


    lista1.agregaInicio(5);
    lista1.agregaFinal(2);
    imprimir(lista1);
    return 0;
}
