#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() {
        max = MINSIZE;
        n = 0;
        arr = new T[max];
    }

    // Destructor
    ~ListArray() override {
        delete[] arr;
    }

    // --- Métodos heredados de la interfaz List<T> ---

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición no válida");
        }
        if (n == max) {
            resize(max * 2); // Duplicar tamaño si se llena
        }
        // Desplazar elementos a la derecha para hacer hueco
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e); // Insertar al final es simplemente insertar en la posición 'n'
    }

    void prepend(T e) override {
        insert(0, e); // Insertar al principio es insertar en la posición 0
    }

    T remove(int pos) override {
        if (pos < 0 || pos > n - 1) {
            throw std::out_of_range("Posición no válida");
        }
        T aux = arr[pos]; // Guardar el elemento antes de borrarlo
        // Desplazar elementos a la izquierda para tapar el hueco
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        // Reducir tamaño si está muy vacío (opcional pero recomendado en la práctica)
        if (n > 0 && n < max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        }
        return aux;
    }

    T get(int pos) override {
        if (pos < 0 || pos > n - 1) {
            throw std::out_of_range("Posición no válida");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; // No encontrado
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }

    // --- Métodos específicos de ListArray<T> ---

    T operator[](int pos) {
        return get(pos); // Reutilizamos el código de get()
    }

    friend std::ostream& operator<<(std::ostream& out, ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.size(); i++) {
            out << list.get(i);
            if (i < list.size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};
