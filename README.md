Performance of **vector element sum** using [float] vs [bfloat16] as the
*storage type*.

This experiment was for comparing the performance between:
1. Find sum of numbers, stored as **float**.
2. Find sum of numbers, stored as **bfloat16**.

Both approaches were attempted on a number of vector sizes, running each
approach 5 times per size to get a good time measure. While it seemed to me
that **bfloat16** method would be a clear winner because of reduced memory
bandwidth requirement, for some reason it is **only slightly faster**. This is
possibly because memory loads are anyway always 32-bit. The only reason using
*bfloat16* is slightly faster could possibly be because it allows data to be
retained in cache for a longer period of time (because of its small size).
Note that neither approach makes use of *SIMD instructions* which are
available on all modern hardware.

All outputs are saved in [out](out/) and a small part of the output is listed
here. Some [charts] are also included below, generated from [sheets]. This
experiment was done with guidance from [Prof. Dip Sankar Banerjee] and
[Prof. Kishore Kothapalli].

<br>

```bash
$ g++ -O3 main.cxx
$ ./a.out

# [00000.050 ms; 1e+04 elems.] [1.644725] sumFloat
# [00000.050 ms; 1e+04 elems.] [1.643810] sumBfloat16
#
# [00000.504 ms; 1e+05 elems.] [1.644725] sumFloat
# [00000.505 ms; 1e+05 elems.] [1.643810] sumBfloat16
#
# [00001.780 ms; 1e+06 elems.] [1.644725] sumFloat
# [00001.342 ms; 1e+06 elems.] [1.643810] sumBfloat16
#
# [00013.539 ms; 1e+07 elems.] [1.644725] sumFloat
# [00013.432 ms; 1e+07 elems.] [1.643810] sumBfloat16
#
# [00135.340 ms; 1e+08 elems.] [1.644725] sumFloat
# [00134.231 ms; 1e+08 elems.] [1.643810] sumBfloat16
#
# [01354.430 ms; 1e+09 elems.] [1.644725] sumFloat
# [01343.146 ms; 1e+09 elems.] [1.643810] sumBfloat16
```

[![](https://i.imgur.com/s6Nxyea.png)][sheets]

<br>
<br>


## References

- [A Study of BFLOAT16 for Deep Learning Training](https://www.slideshare.net/SubhajitSahu/a-study-of-bfloat16-for-deep-learning-training)
- [Convert FP32 to Bfloat16 in C++](https://stackoverflow.com/a/64493446/1413259)
- [Why is there no 2-byte float and does an implementation already exist?](https://stackoverflow.com/a/56017304/1413259)
- [Is it safe to reinterpret_cast an integer to float?](https://stackoverflow.com/a/13982359/1413259)

<br>
<br>

[![](https://i.imgur.com/KUYb9vo.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)
[![DOI](https://zenodo.org/badge/366687370.svg)](https://zenodo.org/badge/latestdoi/366687370)


[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[float]: https://en.wikipedia.org/wiki/Single-precision_floating-point_format
[bfloat16]: https://en.wikipedia.org/wiki/Bfloat16_floating-point_format
[charts]: https://photos.app.goo.gl/UfEY5BpeoDLfNKsi6
[sheets]: https://docs.google.com/spreadsheets/d/1HU_vOWPTmCLijEMAXW94IflGKrYrIWlyNDfEzyG49bs/edit?usp=sharing
