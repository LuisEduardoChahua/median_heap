#include <iostream>
#include <queue>
#include <functional>
#include <vector>

#ifndef __MEDIAN_HEAP_H__
#define __MEDIAN_HEAP_H__

template <class T>
class median_heap {
 public:
  median_heap(){s = 0;}
  void add(const T & item);
  const T & get_median();
  void pop_median();
  int size();
 private:
  //Attributes
  std::priority_queue<T> less_max;
  std::priority_queue<T, std::vector<T>, std::greater<T> > greater_min;
  T median;
  int s;
  //Methods
  void balance();
};

#endif
