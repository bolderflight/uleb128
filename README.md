[![Pipeline](https://gitlab.com/bolderflight/software/uleb128/badges/main/pipeline.svg)](https://gitlab.com/bolderflight/software/uleb128/) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

![Bolder Flight Systems Logo](img/logo-words_75.png) &nbsp; &nbsp; ![Arduino Logo](img/arduino_logo_75.png)

# Uleb128
Unsigned little endian base 128 (ULEB128) implementation, which stores arbitrarily large unsigned integers in a variable length format. This library is compatible with Arduino ARM and with CMake build systems.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Installation

## Arduino
Use the Arduino Library Manager to install this library or clone to your Arduino/libraries folder. This library is added as:

```C++
#include "uleb128.h"
```

An example Arduino executable is located at *examples/arduino/uleb128_example/uleb128_example.ino*. Teensy 3.x, 4.x, and LC devices are used for testing under Arduino and this library should be compatible with other ARM devices. This library is *not* expected to work on AVR devices.

## CMake
CMake is used to build this library, which is exported as a library target called *uleb128*. The header is added as:

```C++
#include "uleb128.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library, an example executable called *uleb128_example*, and an executable for testing using the Google Test framework, called *uleb128_test*. The example executable source file is located at *examples/cmake/uleb128_example.cc*.

# Namespace
This library is within the namespace *bfs*.

# Functions

**std::size_t EncodeUleb128(int64_t val, uint8_t &ast; const data, const std::size_t len)** Encodes a uint64_t *val* into a ULEB128 variable length format stored in the array *data* of length *len*. Returns the number of bytes written if successful, otherwise, returns 0.

**std::size_t DecodeUleb128(uint8_t const &ast; const data, const std::size_t len, int64_t &ast; const val)** Decodes a ULEB128 variable length value from the array *data* of length *len* into a uint64_t variable *val*. Returns the number of bytes read if successful, otherwise, returns 0.

```C++
uint8_t buf[100];
uint64_t read_val = 0;
uint64_t orig_val = std::numeric_limits<uint64_t>::max();
std::size_t bytes_written = bfs::EncodeUleb128(orig_val, buf, sizeof(buf));
std::size_t bytes_read = bfs::DecodeUleb128(buf, sizeof(buf), &read_val);
```
