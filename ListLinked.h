#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h" 
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    // Constructor
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    // Destructor
    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    // Operador []
    T operator[](int pos) { //va hasta size()-1 porque en la posicion size() no hay nada. Si size= 4, las posiciones son 0 1 2 3, en la 4 hay basura 
    	    if (pos < 0 || pos >= size()) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    // Operador << (Amigo)
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* aux = list.first;
        int i = 0;
        while (aux != nullptr) {
            out << "Nodo " << i << " :" << aux->data << std::endl;
            aux = aux->next;
            i++;
        }
        return out;
    }

    // Método insert
    void insert(int pos, T e) override {
        if (pos < 0 || pos > size()) { //va hasta size() porque puedes insertar en la última posición
            throw std::out_of_range("Posicion fuera de rango");
        }
        Node<T>* aux = first;
        if (pos == 0) {
            first = new Node<T>(e, aux);
            n++;
            return;
        }
        Node<T>* prev = nullptr;
        for (int i = 0; i < pos; i++) {
            prev = aux;
            aux = aux->next;
        }
        prev->next = new Node<T>(e, aux);
        n++;
    }

    // Método remove
    T remove(int pos) override {
        if (pos < 0 || pos > size() - 1) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        Node<T>* aux = first;
        T valor;
        if (pos == 0) {
            first = aux->next;
        } else {
            Node<T>* prev = nullptr;
            for (int i = 0; i < pos; i++) {
                prev = aux;
                aux = aux->next;
            }
            prev->next = aux->next;
        }
        valor = aux->data;
        delete aux;
        n--;
        return valor;
    }

    // Método get
    T get(int pos) override {
        if (pos < 0 || pos > size() - 1) {
            throw std::out_of_range("Posicion fuera de rango");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    // Método search
    int search(T e) override {
        Node<T>* aux = first;
        int i = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return i;
            }
            aux = aux->next;
            i++;
        }
        return -1;
    }

    // Método size
    int size() const override {
        return n;
    }

    // Método empty
    bool empty() const override {
        return n == 0;
    }
};

#endif
