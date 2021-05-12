#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "src/main.hxx"

using namespace std;




void runSum(int N) {
  int repeat = 5;
  float a1, a2;
  vector<float>    x(N);
  vector<Bfloat16> y(N);
  for (int i=0; i<N; i++) {
    float n = i + 1;
    x[i] = 1/(n*n);
    y[i] = 1/(n*n);
  }

  // Find sum of numbers, stored as float.
  double t1 = measureDuration([&]() { a1 = sum(x); }, repeat);
  printf("[%09.3f ms; %.0e elems.] [%f] sumFloat\n", t1, (double) N, a1);

  // Find sum of numbers, stored as Bfloat16.
  double t2 = measureDuration([&]() { a2 = sum(y, 0.0f); }, repeat);
  double e2 = abs(a2 - a1);
  printf("[%09.3f ms; %.0e elems.] [%f] sumBfloat16\n", t2, (double) N, a2);
}


int main(int argc, char **argv) {
  for (int n=10000; n<=1000000000; n*=10) {
    runSum(n);
    printf("\n");
  }
  return 0;
}
