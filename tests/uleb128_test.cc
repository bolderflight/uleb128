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
#include "gtest/gtest.h"

/* Test minimum input */
TEST(Uleb128, MinInput) {
  uint8_t buf[10];
  uint64_t input = 0;
  uint64_t output = 0;
  std::size_t bytes_written = bfs::EncodeUleb128(input, buf);
  std::size_t bytes_read = bfs::DecodeUleb128(buf, &output);
  EXPECT_EQ(1, bytes_written);
  EXPECT_EQ(1, bytes_read);
  EXPECT_EQ(0, output);
}
/* Test maximum input */
TEST(Uleb128, MaxInput) {
  uint8_t buf[10];
  uint64_t input = std::numeric_limits<uint64_t>::max();
  uint64_t output = 0;
  std::size_t bytes_written = bfs::EncodeUleb128(input, buf);
  std::size_t bytes_read = bfs::DecodeUleb128(buf, &output);
  EXPECT_EQ(10, bytes_written);
  EXPECT_EQ(10, bytes_read);
  EXPECT_EQ(std::numeric_limits<uint64_t>::max(), output);
}
/* Test mid input */
TEST(Uleb128, MidInput) {
  uint8_t buf[10];
  uint64_t input = 12345;
  uint64_t output = 0;
  std::size_t bytes_written = bfs::EncodeUleb128(input, buf);
  std::size_t bytes_read = bfs::DecodeUleb128(buf, &output);
  EXPECT_EQ(2, bytes_written);
  EXPECT_EQ(2, bytes_read);
  EXPECT_EQ(12345, output);
}
/* Test small write buffer */
TEST(Uleb128, WriteBuffer) {
  uint8_t buf[1];
  uint64_t input = 12345;
  std::size_t bytes_written = bfs::EncodeUleb128(input, buf);
  EXPECT_EQ(0, bytes_written);
}
/* Test small read buffer */
TEST(Uleb128, ReadBuffer) {
  uint8_t buf[10];
  uint64_t input = 12345;
  uint64_t output = 0;
  std::size_t bytes_written = bfs::EncodeUleb128(input, buf);
  std::size_t bytes_read = bfs::DecodeUleb128({buf, 1}, &output);
  EXPECT_EQ(0, bytes_read);
}
/* Test null pointer */
TEST(Uleb128, NullPointer) {
  uint8_t buf[10];
  uint64_t input = 12345;
  uint64_t output = 0;
  std::size_t bytes_written = bfs::EncodeUleb128(input, buf);
  std::size_t bytes_read = bfs::DecodeUleb128({buf, 1}, NULL);
  EXPECT_EQ(0, bytes_read);
}
