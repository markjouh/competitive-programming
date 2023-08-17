# cp-library
Library code for programming contests. While the focus is brevity and ease of understanding, these implementations should be fairly fast as well.

## Notes

0-indexing and half intervals $[l, r)$ are used everywhere.

Implementations may use gcc-specific features such as `__lg`, as well as C++20 features such as `ssize(x)`.

The `ll` typedef and `all` macro defined in `template.cpp` are used throughout.
```cpp
using ll = long long;
#define all(x) begin(x), end(x)
```
