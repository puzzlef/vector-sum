#pragma once
#include <vector>

using std::vector;




template <class T, class U=T>
auto sum(const T *x, int N, U a=U()) {
  for (int i=0; i<N; i++)
    a += x[i];
  return a;
}

template <class T, class U=T>
auto sum(const vector<T>& x, U a=U()) {
  return sum(x.data(), x.size(), a);
}


template <class T, class U=T>
auto sumOmp(const T *x, int N, U a=U()) {
  #pragma omp parallel for schedule(static,4096) reduction(+:a)
  for (int i=0; i<N; i++)
    a += x[i];
  return a;
}

template <class T, class U=T>
auto sumOmp(const vector<T>& x, U a=U()) {
  return sumOmp(x.data(), x.size(), a);
}
