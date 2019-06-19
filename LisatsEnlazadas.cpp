#include <iostream>
#include <stdlib.h>

using namespace std;


template <class T>

class Nodo
{
    public:
        Nodo();
        Nodo(T);
        ~Nodo();

        Nodo *siguiente;
        T datos;

        void eliminar();
        void imprimir();
};

// Constructor por defecto
template<typename T>

Nodo<T>::Nodo()
{
    datos = NULL;
    siguiente = NULL;
}

// Constructor por parámetro
template<typename T>
Nodo<T>::Nodo(T dato)
{
    datos = dato;
    siguiente = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void Nodo<T>::eliminar()
{
    if (siguiente)
        siguiente->eliminar();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void Nodo<T>::imprimir()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << datos << "-> ";
}

template<typename T>
Nodo<T>::~Nodo()
{}

template <class T>

class Lista
{
    public:
        class iterator;
        iterator begin();
        iterator end();
        iterator begin();
        iterator end();

        Lista();
        ~Lista();
        }
        void agregaInicio(T);
        void agregaFinal(T);
        void agregaEnOrden(T dato);
        void agregaElemento(T);
        void llenar_aleatorio(int);
        void concatenar(Lista);
        void eliminar();
        void eliminar_por_dato(T);
        void eliminar_por_posicion(int);
        void llenar_por_usuario(int);
        void invertir();
        void imprimir();
        void search(T);
        void MostarLista(Lista);
    private:
        Nodo<T> *m_inicial;
        int m_num_nodos;
};



// Constructor por defecto
template<typename T>
Lista<T>::Lista()
{
    m_num_nodos = 0;
    m_inicial = NULL;
}

template<typename T>
class Lista<T>::iterator
{

};

// Insertar al inicio
template<typename T>
void Lista<T>::agregaInicio(T dato)
{
    Nodo<T> *nuevo_nodo = new Nodo<T> (dato);
    Nodo<T> *temp = m_inicial;

    if (!m_inicial) {
        m_inicial = nuevo_nodo;
    } else {
        nuevo_nodo->siguiente = m_inicial;
        m_inicial = nuevo_nodo;

        while (temp) {
            temp = temp->siguiente;
        }
    }
    m_num_nodos++;
}

// Insertar al final
template<typename T>
void Lista<T>::agregaFinal(T dato)
{
    Nodo<T> *nuevo_nodo = new Nodo<T> (dato);
    Nodo<T> *temp = m_inicial;

    if (!m_inicial) {
        m_inicial = nuevo_nodo;
    } else {
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo_nodo;
    }
    m_num_nodos++;
}

// Insertar de manera ordenada
template<typename T>
void Lista<T>::agregaEnOrden(T dato)
{
    Nodo<T> *nuevo_nodo = new Nodo<T> (dato);
    Nodo<T> *temp = m_inicial;

    if (!m_inicial) {
        m_inicial = nuevo_nodo;
    } else {
        if (m_inicial->datos > dato) {
            nuevo_nodo->siguiente = m_inicial;
            m_inicial = nuevo_nodo;
        } else {
            while ((temp->siguiente != NULL) && (temp->siguiente->datos < dato)) {
                temp = temp->siguiente;
            }
            nuevo_nodo->siguiente = temp->siguiente;
            temp->siguiente = nuevo_nodo;
        }
    }
    m_num_nodos++;
}

// Concatenar a otra List
template<typename T>
void Lista<T>::concatenar(Lista Lista)
{
    Nodo<T> *temp2 = Lista.m_inicial;

    while (temp2) {
        agregaFinal(temp2->datos);
        temp2 = temp2->siguiente;
    }
}

// Eliminar todos los nodos
template<typename T>
void Lista<T>::eliminar()
{
    m_inicial->eliminar();
    m_inicial = 0;
}

// Eliminar por data del nodo
template<typename T>
void Lista<T>::eliminar_por_dato(T dato)
{
    Nodo<T> *temp = m_inicial;
    Nodo<T> *temp1 = m_inicial->siguiente;

    int cont = 0;

    if (m_inicial->datos == dato) {
        m_inicial = temp->siguiente;
    } else {
        while (temp1) {
            if (temp1->datos == dato) {
                Nodo<T> *aux_nodo = temp1;
                temp->siguiente = temp1->siguiente;
                delete aux_nodo;
                cont++;
                m_num_nodos--;
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
    Nodo<T> *temp = m_inicial;
    Nodo<T> *temp1 = temp->siguiente;

    if (pos < 1 || pos > m_num_nodos) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_inicial = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Nodo<T> *aux_nodo = temp1;
                temp->next = temp1->next;
                delete aux_nodo;
                m_num_nodos--;
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
/*
template<typename T>
void Lista<T>::llenar_aleatorio(int dim)
{
    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
        agregaFinal(rand() % 100);
    }
}

*/
// Invertir la lista
template<typename T>
void Lista<T>::invertir()
{
    Nodo<T> *prev = NULL;
    Nodo<T> *siguiente = NULL;
    Nodo<T> *temp = m_inicial;

    while (temp) {
        siguiente = temp->siguiente;
        temp->siguiente = prev;
        prev = temp;
        temp = siguiente;
    }
    m_inicial = prev;
}


// Imprimir la Lista
/*
template<typename T>
void Lista<T>::imprimir()
{
    Nodo<T> *temp = m_inicial;
    if (!m_inicial) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->imprimir();
            if (!temp->siguiente) cout << "NULL";
                temp = temp->siguiente;
        }
  }
  cout << endl << endl;
}
*/
template<typename T>
void Lista<T>::imprimir(Lista<int>& ls) {
    for (Lista<int>::iterator it = ls.begin(); it != ls.end(); ++it)
    {
    std::cout << *it << std::endl;
    }
}
// Buscar el dato de un nodo
/*
template<typename T>
void Lista<T>::search(T dato)
{
    Nodo<T> *temp = m_inicial;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->datos == dato) {
            cout << "El dato se encuentra en la posición: " << cont << endl;
            cont2++;
        }
        temp = temp->siguiente;
        cont++;
    }
        if (cont2 == 0) {
        cout << "No existe el dato " << endl;
    }
    cout << endl << endl;

*/

int search(LinkedList<int>& ls, int data)
{
    int i = 0;
    for (Lista<int>::iterator it = ls.begin(); it != ls.end(); ++it) {
    return i;
}

//-------------------------------Usando Pilas--------------------------------//
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

/* Look at the top */
template <typename T> T Stack<T>::peek() { return s.get(0)->getData(); }


template<typename T>
List<T>::~List() {}

int main()
{
    Lista<int> lista_1;
    Lista<int> lista_2;
    int elemento;

    int dim;
    int pos;


    cout << "Ingresa la dimensión de la lista: " << endl;
    cin >> dim;

    list_1.agregar_aleatorio(dim);

    cout << "Lista A al inicio " << endl;
    lista_1.imprimir();

    cout << "Agrega un elemento por la cabeza: " << endl;
    cin >> elemento;
    lista_1.agregaInicio(elemento);
    lista_1.imprimir();

    cout << "Lista invertida: " << endl;
    lista_1.invertir();
    lista_1.imprimir();

    cout << "Agrega un elemento. Será insertado ordenadamente: " << endl;
    cin >> elemento;
    lista_1.agregaEnOrden(elemento);
    lista_1.imprimir();

    cout << "Busca un elemento: " << endl;
    cin >> elemento;
    lista_1.search(elemento);

    cout << "Elimina un elemento por dato: " << endl;
    cin >> ele;
    lista_1.eliminar_por_dato(elemento);
    lista_1.imprimir();

    cout << "Elimina un elemento por posición: " << endl;
    cin >> pos;
    lista_1.eliminar_por_posicion(pos);
    lista_1.imprimir();

    cout << "Listas A y B concatenadas: " << endl;
    lista_1.concatenar(list_2);
    lista_1.imprimir();

    lista_1.eliminar();
    lista_1.imprimir();

    Lista<string> lista0;
    lista0.begin("Fred");
    lista0.begin("Jim");
    lista0.begin("Anne");
    lista0.begin("Susan");

    Lista<int>::interator pos;
    pos=Lista.agregaInicio();
    cout<<*pos<<endl;
    *pos="Barry"<<endl;

    return 0;
}
