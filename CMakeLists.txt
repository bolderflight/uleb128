cmake_minimum_required(VERSION 3.14)
# Project information
project(Uleb128
  VERSION 2.1.1
  DESCRIPTION "Unsigned little endian base 128 variable-length encoding."
  LANGUAGES CXX
)
# Add the library target
add_library(uleb128 INTERFACE)
# Setup include directories 
target_include_directories(uleb128 INTERFACE src/)

# Example and unit testing if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
	# Add the example target
	add_executable(uleb128_example examples/cmake/uleb128_example.cc)
	# Add the includes
	target_include_directories(uleb128_example PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the example target
	target_link_libraries(uleb128_example
		PRIVATE 
			uleb128
	)
	# Fetch google test
	include(FetchContent)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG release-1.10.0
	)
	FetchContent_MakeAvailable(googletest)
	enable_testing()
	include(GoogleTest)
	# Add the test target
	add_executable(uleb128_test tests/uleb128_test.cc)
	# Add the includes
	target_include_directories(uleb128_test PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	)
	# Link libraries to the test target
	target_link_libraries(uleb128_test
		PRIVATE 
			uleb128
			gtest_main 
			gtest
			gmock
	)
	# Discover unit tests
	gtest_discover_tests(uleb128_test)
endif()
