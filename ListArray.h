#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;

		void resize(int new_size){
			T* nuevo= new T[new_size];
			for(int i=0;i<n;i++){
				nuevo[i]=arr[i];
			}
			delete[] arr;
			arr=nuevo;
			max=new_size;
		}
	public:
		ListArray(){
			max=MINSIZE;
			n=0;
			arr = new T[MINSIZE];
		}

		~ListArray() override{
		delete[] arr;
		arr=nullptr;
		}

		T operator [](int pos){
                if(pos < 0 || pos > n-1){
                throw std::out_of_range("Posición imposible");
                }else{
                T valor=arr[pos];
                return valor;
                }
		}

	      friend std::ostream& operator<<(std::ostream &out,ListArray<T> &list){
        for(int i=0; i<=list.size()-1 ; i++){
                out << list[i] << std::endl ;
        }
        return out;

}

		
		
		void insert(int pos, T e) override {
  
                if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición no válida");
                 }

                if (n == max) {
                resize(max * 2); 
                }

   
                for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
                }

    
                arr[pos] = e;
                n++;
                }

		void append(T e) override{
			insert(n,e);
			}
		void prepend(T e) override{
			insert(0,e);
		}
		T remove(int pos) override{
			if(pos < 0 || pos >= size()){
				throw std::out_of_range("Posición fuera de rango");
			}
			T aux= arr[pos];
			for(int i=pos;i<n-1;i++){
				arr[i]=arr[i+1];
			}
			n--;
			return aux;
		}
		T get(int pos){
			if(pos < 0 || pos >= size()){
                                throw std::out_of_range("Posición fuera de rango");
                        }
			return arr[pos];
		}
		int search(T e){
			for(int i =0 ; i<n ; i++){
				if(arr[i]==e){
					return i;
				}
			}
			return -1;
		}
		
		bool empty () override{
			return n==0;
		}
		int size() override{
			return n;
		}

			
			


};







