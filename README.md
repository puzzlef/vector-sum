Performance of sequential execution based vs OpenMP based vector element sum.

This experiment was for comparing the performance between:
1. Find `Σx` using a single thread (**sequential**).
2. Find `Σx` accelerated using **OpenMP**.

Here `x` is a floating-point vector. Both approaches were attempted on a
number of vector sizes, running each approach 5 times per size to get a
good time measure. While it might seem that **OpenMP** method would be a clear
winner, the results indicate it is dependent upon the workload. If the vector
size is small, using a small number of threads has a lower overhead. When the
vector size is large, using a larger number of thread helps. This is possibly
because with a large vector, the overhead associated with managing threads is
smaller than the work to be done.

```bash
$ g++ -O3 -fopenmp main.cxx
$ OMP_NUM_THREADS=4 ./a.out

# [00000.050 ms; 1e+04 elems.] [1.644834] sum
# [00000.084 ms; 1e+04 elems.] [1.644834] sumOmp
#
# [00000.464 ms; 1e+05 elems.] [1.644924] sum
# [00000.130 ms; 1e+05 elems.] [1.644924] sumOmp
#
# [00001.715 ms; 1e+06 elems.] [1.644933] sum
# [00000.508 ms; 1e+06 elems.] [1.644933] sumOmp
#
# [00014.652 ms; 1e+07 elems.] [1.644934] sum
# [00005.921 ms; 1e+07 elems.] [1.644934] sumOmp
#
# [00144.494 ms; 1e+08 elems.] [1.644934] sum
# [00040.842 ms; 1e+08 elems.] [1.644934] sumOmp
#
# [01444.743 ms; 1e+09 elems.] [1.644934] sum
# [00408.852 ms; 1e+09 elems.] [1.644934] sumOmp
```

```bash
$ g++ -O3 -fopenmp main.cxx
$ OMP_NUM_THREADS=48 ./a.out

# [00000.039 ms; 1e+04 elems.] [1.644834] sum
# [00025.367 ms; 1e+04 elems.] [1.644834] sumOmp
#
# [00000.169 ms; 1e+05 elems.] [1.644924] sum
# [00023.483 ms; 1e+05 elems.] [1.644924] sumOmp
#
# [00001.685 ms; 1e+06 elems.] [1.644933] sum
# [00020.744 ms; 1e+06 elems.] [1.644933] sumOmp
#
# [00015.561 ms; 1e+07 elems.] [1.644934] sum
# [00022.450 ms; 1e+07 elems.] [1.644934] sumOmp
#
# [00145.128 ms; 1e+08 elems.] [1.644934] sum
# [00026.619 ms; 1e+08 elems.] [1.644934] sumOmp
#
# [01443.808 ms; 1e+09 elems.] [1.644934] sum
# [00171.276 ms; 1e+09 elems.] [1.644934] sumOmp
```

<br>
<br>


## References

- [Parallel for loop in openmp](https://stackoverflow.com/a/11773714/1413259)
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)

<br>
<br>

[![](https://i.imgur.com/KoxZ0HW.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)
