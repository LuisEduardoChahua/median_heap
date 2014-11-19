#include "median_heap.h"

template <class T>
const T & median_heap<T>::get_median() {
  if (s > 0) return median;
  else std::cerr << "median heap is empty" << std::endl; 
  exit(-1);
}

template <class T>
void median_heap<T>::add(const T & item) {
  if (s == 0) median = item;
  else{
    if (item < median) {
      // Add it to the less heap
      less_max.push(item);
    }
    else {
      // Add it to the greater heap
      greater_min.push(item);
    }
  }
  ++s;
  balance();
}

template <class T>
void median_heap<T>::pop_median() {
  if (s > 0) {
    median = greater_min.top();
    greater_min.pop();
    --s;
    balance();
  }
}

template <class T>
int median_heap<T>::size() {
  return s;
}


template <class T>
void median_heap<T>::balance() {
  int ls = less_max.size();
  int gs = greater_min.size();
  if (ls - gs >= 1) {
    greater_min.push(median);   
    median = less_max.top();
    less_max.pop();
  }
  else {
    if (ls - gs < -1) {
      less_max.push(median);
      median = greater_min.top();
      greater_min.pop();
    }
  }
}
