# LLVM BlockProfileCount Example
This is an example of how to use LLVM's BlockProfileCount. 

A few example programs are in the examples folder. 
The `examples/run.sh` runs all of the examples.

## Building
```sh
mkdir build
cd build/
cmake ..
make
```

## Running
```sh
clang example.cc -fprofile-generate -o example
./example
llvm-profdata merge default_*.profraw -output=example.prof
opt -load build/libPerformanceTest.so example.ll -pgo-test-profile-file=example.prof -pgo-instr-use -perf-test > /dev/null
```
For more examples have a look at the example directory.

