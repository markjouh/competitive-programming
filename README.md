# cp-library
This repository contains my library code for programming contests. The primary goals of these implementations are to maintain brevity, ensure ease of understanding, and also strive for reasonable execution speed.

## Notes

All indexing is 0-based, and half-open intervals of the form $[l, r)$ are employed.

Implementations may make use of GCC-specific features, such as `__lg`, as well as library functions defined in the C++17 standard.

I have chosen not to use C++20 features as of now due to inconsistent support among online judges, such as USACO.org (at the time of writing).

Although [`template.cpp`](utils/template.cpp) contains a handful of macros I consider useful, the rest of the library is completely macro-free.