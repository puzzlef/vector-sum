#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include "src/main.hxx"

using namespace std;




void runSum(int N) {
  int repeat = 5;
  double a1, a2;
  vector<double> x(N);
  for (int i=0; i<N; i++) {
    double n = i + 1;
    x[i] = 1/(n*n);
  }

  // Find x*y using a single thread.
  double t1 = measureDuration([&]() { a1 = sum(x); }, repeat);
  printf("[%09.3f ms; %.0e elems.] [%f] sum\n", t1, (double) N, a1);

  // Find x*y accelerated using OpenMP.
  double t2 = measureDuration([&]() { a2 = sumOmp(x); }, repeat);
  double e2 = abs(a2 - a1);
  printf("[%09.3f ms; %.0e elems.] [%f] sumOmp\n", t2, (double) N, a2);
}


int main(int argc, char **argv) {
  for (int n=10000; n<=1000000000; n*=10) {
    runSum(n);
    printf("\n");
  }
  return 0;
}
