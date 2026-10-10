#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo de la lista
    int n;          // Número de elementos en la lista

public:
    // --- Constructor y Destructor ---

    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() override {
        // Implementación siguiendo exactamente tu guía (Actividad 7)
        while (first != nullptr) {
            Node<T>* aux = first->next; // 1. Situar puntero aux al siguiente nodo
            delete first;               // 2. Liberar memoria del nodo first
            first = aux;                // 3. Actualizar first a aux
        }
        // 4. Repetir hasta que no queden nodos
    }

    // --- Métodos heredados de la interfaz List<T> ---

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición no válida");
        }
        
        if (pos == 0) {
            // Insertar al principio
            first = new Node<T>(e, first);
        } else {
            // Avanzar hasta el nodo anterior a la posición de inserción
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            // Crear nuevo nodo apuntando al siguiente de prev, y prev apunta al nuevo
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e); // Reutilizamos insert para añadir al final
    }

    void prepend(T e) override {
        insert(0, e); // Reutilizamos insert para añadir al principio
    }

    T remove(int pos) override {
        if (pos < 0 || pos > n - 1) {
            throw std::out_of_range("Posición no válida");
        }

        Node<T>* aux = first;
        T data;

        if (pos == 0) {
            // Borrar el primer elemento
            first = first->next;
            data = aux->data;
            delete aux;
        } else {
            // Avanzar hasta el nodo anterior al que queremos borrar
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++) {
                prev = prev->next;
            }
            aux = prev->next;         // Nodo a borrar
            prev->next = aux->next;   // Desenlazarlo
            data = aux->data;
            delete aux;               // Liberar memoria
        }
        n--;
        return data;
    }

    T get(int pos) override {
        if (pos < 0 || pos > n - 1) {
            throw std::out_of_range("Posición no válida");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; i++) {
            aux = aux->next;
        }
        return aux->data;
    }

    int search(T e) override {
        Node<T>* aux = first;
        int pos = 0;
        while (aux != nullptr) {
            if (aux->data == e) {
                return pos; // Elemento encontrado
            }
            aux = aux->next;
            pos++;
        }
        return -1; // Elemento no encontrado
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    // --- Métodos específicos de ListLinked<T> ---

    T operator[](int pos) {
        return get(pos); // Reutilizamos get() que ya lanza la excepción y busca
    }

    friend std::ostream& operator<<(std::ostream& out, ListLinked<T>& list) {
        out << "[";
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << aux->data;
            if (aux->next != nullptr) {
                out << ", ";
            }
            aux = aux->next;
        }
        out << "]";
        return out;
    }
};

#endif
