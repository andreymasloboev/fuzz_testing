![Build](https://github.com/andreymasloboev/fuzz_testing/actions/workflows/build.yml/badge.svg)
![Tests](https://github.com/andreymasloboev/fuzz_testing/actions/workflows/tests.yml/badge.svg)
# Sample how-to use Google FuzzTest in CMake projects

[FuzzTest Framework](https://github.com/google/fuzztest)

[LLVM Reference](https://llvm.org/docs/Reference.html#libfuzzer)

# Dependencies

Packages clang compiler, cmake

NOTE: it is not work with GCC.

## How to use:

1. git clone https://github.com/andreymasloboev/fuzz_testing.git
2. cd fuzz_testing
3. CC=clang CXX=clang++ cmake . -Bbuild
4. cmake --build build --parallel 16
5. ctest --test-dir build --output-on-failure -R ResourceTS

Run tests:
```
andrey@fedora ~/p/f/fuzz_test (develop)> ctest --test-dir build --output-on-failure -R ResourceTS
Internal ctest changing into directory: /home/andrey/projects/fuzz/fuzz_test/build
Test project /home/andrey/projects/fuzz/fuzz_test/build
    Start 1: ResourceTS.SetStatus
1/3 Test #1: ResourceTS.SetStatus ................................   Passed    0.00 sec
    Start 2: ResourceTS.SetStatusAlwaysSucceedPositiveIntegers
2/3 Test #2: ResourceTS.SetStatusAlwaysSucceedPositiveIntegers ...   Passed    0.03 sec
    Start 3: ResourceTS.SetStatusAlwaysFailNegativeIntegers
3/3 Test #3: ResourceTS.SetStatusAlwaysFailNegativeIntegers ......   Passed    0.03 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   0.06 sec
```