# Uleb128
Unsigned little endian base 128 (ULEB128) implementation, which stores arbitrarily large unsigned integers in a variable length format.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

## Installation
CMake is used to build this library, which is exported as a library target called *uleb128*. The header is added as:

```
#include "uleb128/uleb128.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *uleb128_example*, and an executable for testing using the Google Test framework, called *uleb128_test*. The example executable source file is located at *examples/uleb128_example.cc*.

## Namespace
This library is within the namespace *bfs*.

## Functions

**std::size_t EncodeUleb128(uint64_t val, std::span<uint8_t> data)** Encodes a uint64_t *val* into a ULEB128 variable length format stored in the array viewed by the span *data*. Returns the number of bytes written if successful, otherwise, returns 0.

**std::size_t DecodeUleb128(std::span<const uint8_t> data, uint64_t &ast; const val)** Decodes a ULEB128 variable length value from the array viewed by the span *data* into a uint64_t variable *val*. Returns the number of bytes read if successful, otherwise, returns 0.

```C++
uint8_t buf[100];
uint64_t read_val = 0;
uint64_t orig_val = std::numeric_limits<uint64_t>::max();
std::size_t bytes_written = bfs::EncodeUleb128(orig_val, buf);
std::size_t bytes_read = bfs::DecodeUleb128(buf, &read_val);
```
