/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#include "uleb128/uleb128.h"
#include <span>
#include <cstdint>

namespace bfs {

std::size_t EncodeUleb128(uint64_t val, std::span<uint8_t> data) {
  std::size_t i = 0;
  do {
    /* Prevent buffer overflow */
    if (i < data.size()) {
      uint8_t b = val & 0x7F;
      val >>= 7;
      if (val != 0) {
        b |= 0x80;
      }
      data[i++] = b;
    } else {
      return 0;
    }
  } while (val != 0);
  return i;
}

std::size_t DecodeUleb128(std::span<const uint8_t> data, uint64_t * const val) {
  /* Null pointer check */
  if (!val) {return 0;}
  uint64_t res = 0, shift = 0;
  std::size_t i = 0;
  while (1) {
    /* Prevent buffer overflow */
    if (i < data.size()) {
      uint8_t b = data[i++];
      res |= (b & 0x7F) << shift;
      if (!(b & 0x80)) {break;}
      shift += 7;
    } else {
      return 0;
    }
  }
  *val = res;
  return i;
}

}  // namespace bfs
