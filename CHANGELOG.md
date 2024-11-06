# Changelog

## v2.1.2
- Fix decoding overflow bug

## v2.1.1
- Updated CMake minimum version to 3.14 to support FetchContent_MakeAvailable

## v2.1.0
- Removed the C++20 requirement
- Switched to header-only

## v2.0.1
- Conditionally include Arduino header

## v2.0.0
- Updated directory structure to support Arduino in addition to CMake builds
- Added an Arduino example
- Updated README

## v1.0.2
- Constify span in DecodeUleb128

## v1.0.1
- Removed iostream from uleb128.cc, which was only there for debugging.

## v1.0.0
- Initial version
