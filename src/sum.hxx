#pragma once
#include <vector>

using std::vector;




template <class T>
auto sum(const T *x, int N) {
  T a = T();
  for (int i=0; i<N; i++)
    a += x[i];
  return a;
}

template <class T>
auto sum(const vector<T>& x) {
  return sum(x.data(), x.size());
}


template <class T>
auto sumOmp(const T *x, int N) {
  T a = T();
  #pragma omp parallel for schedule(static,4096) reduction(+:a)
  for (int i=0; i<N; i++)
    a += x[i];
  return a;
}

template <class T>
auto sumOmp(const vector<T>& x) {
  return sumOmp(x.data(), x.size());
}
