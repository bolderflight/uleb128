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

#include "uleb128.h"
#include <limits>
#include <iostream>

int main() {
  uint8_t buf[100];
  uint64_t read_val = 0;
  /* Try encoding and decoding the maximum uint64 value */
  uint64_t orig_val = std::numeric_limits<uint64_t>::max();
  std::cout << "Written value: " << orig_val << std::endl;
  std::cout << "Bytes written: " << bfs::EncodeUleb128(orig_val, buf, sizeof(buf)) << std::endl;
  std::cout << "Bytes read: " << bfs::DecodeUleb128(buf, sizeof(buf), &read_val) << std::endl;
  std::cout << "Read value: " << read_val << std::endl;
  /* Try encoding and decoding some random value */
  orig_val = 12345;
  std::cout << "Written value: " << orig_val << std::endl;
  std::cout << "Bytes written: " << bfs::EncodeUleb128(orig_val, buf, sizeof(buf)) << std::endl;
  std::cout << "Bytes read: " << bfs::DecodeUleb128(buf, sizeof(buf), &read_val) << std::endl;
  std::cout << "Read value: " << read_val << std::endl;
}
