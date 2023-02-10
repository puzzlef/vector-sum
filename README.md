Comparison of *vector element sum* using various data types.

For all experiments, each approach is attempted on a number of vector sizes,
running each approach 5 times per size to get a good time measure. The
experiments are done with guidance from [Prof. Dip Sankar Banerjee] and
[Prof. Kishore Kothapalli].

<br>


### Comparision with Float and BFloat16 storage types

In this experiment ([float-vs-bfloat16], [main]), we comparing the performance of
finding the sum of numbers between, the number stored as [float] or
[bfloat16]. While it seemed to me that **bfloat16** method would be a clear
winner because of reduced memory bandwidth requirement, for some reason it is
*only slightly faster*. This is possibly because memory loads are anyway
always 32-bit. The only reason using *bfloat16* is slightly faster could
possibly be because it allows data to be retained in cache for a longer period
of time (because of its small size). Note that neither approach makes use of
*SIMD instructions* which are available on all modern hardware.

[float-vs-bfloat16]: https://github.com/puzzlef/vector-sum/tree/float-vs-bfloat16
[main]: https://github.com/puzzlef/vector-sum

<br>
<br>


## References

- [A Study of BFLOAT16 for Deep Learning Training](https://www.slideshare.net/SubhajitSahu/a-study-of-bfloat16-for-deep-learning-training)
- [Convert FP32 to Bfloat16 in C++](https://stackoverflow.com/a/64493446/1413259)
- [Why is there no 2-byte float and does an implementation already exist?](https://stackoverflow.com/a/56017304/1413259)
- [Is it safe to reinterpret_cast an integer to float?](https://stackoverflow.com/a/13982359/1413259)

<br>
<br>


[![](https://i.imgur.com/oXo1Iwp.png)](https://www.youtube.com/watch?v=0XTLuFpuAtE)
[![ORG](https://img.shields.io/badge/org-puzzlef-green?logo=Org)](https://puzzlef.github.io)
[![DOI](https://zenodo.org/badge/366687370.svg)](https://zenodo.org/badge/latestdoi/366687370)


[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[float]: https://en.wikipedia.org/wiki/Single-precision_floating-point_format
[bfloat16]: https://en.wikipedia.org/wiki/Bfloat16_floating-point_format
