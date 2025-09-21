
# Mergesort with parallel excecution

Sorting algorithms are fundamental features of modern programming languages. This project provides an implementation of mergesort in C++. In the tests directory, I compare the execution speed of mergesort, the C standard library’s qsort, and C++’s std::sort (introsort) on arrays of various sizes. They have been tested with multithreading (except for qsort). The mergesort implementation is templated and provides an interface similar to std::sort.

### System specification

The benchmarks were run on a 12th Gen Intel(R) Core(TM) i7-12650H (2.30 GHz) processor,16.0 GB (15.7 GB usable) installed RAM, on WSL2 Ubuntu with windows 11 

### mergesort vs std::sort vs cstdlib qsort

<img width="640" height="480" alt="image" src="https://github.com/user-attachments/assets/0f868d8c-d794-416c-8d17-2dc58f8b5340" />

## License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0-or-later).  

