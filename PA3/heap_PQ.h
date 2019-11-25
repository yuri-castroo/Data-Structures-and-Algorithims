#ifndef HEAP_PQ
#define HEAP_PQ 

#include <exception>
#include <iostream> 
#include <vector> 

template <class Type>
class HeapPQ{
private:
public:
	void minHeapify(std::vector<Type>& array, int i){
		int min = i;
		int left = 2*i + 1;
		int right = 2*i + 2;
		if (left < array.size() && array[left] < array[max]){
			min = left;
		}
		if (right< array.size() && array[right] < array[max]){
			min = right; 
		}
		if (min != i){
			Type temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			minHeapify(array, max);
		}
	}
	void buildHeap(std::vector<Type>& v){
		for (int i = (v.size()/2)-1; i >= 0; i--){
			minHeapify(v,i);
		}
	}

	Type removeMin(std::vector<Type>& v) throw(exception){
		if (v.size() == 0){
			throw std::out_of_range("Empty heap");
		}
		else{
			Type min = v[0];
			v[0] = v[v.size()-1];
			v.erase(std::remove(v.begin(),v.end(),v[0],v.end()));
			v.shrink_to_fit();
			minHeapify(v, 0);
			return min; 
		}
	}

	void increaseHeap(std::vector<Type>& v, int i, Type data){
		if (data>v[i]){
			cout << "new value is larger than current value" << endl;
			return;
		}
		else{
			v[i] = data;
			while(i > 0 && v[(i/2)-1] > v[i]){
				Type temp = v[i];
				v[i] = v[(i/2)-1];
				v[(i/2)-1] = temp; 
			}
		}
	}
	void insertItem (std::vector<Type>& v, Type data){
   		v.resize(v.size()+1);
   		v[v.size()-1] = -1; 
   		v.push_back(data);
   }
};

#endif
