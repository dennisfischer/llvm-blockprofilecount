#!/bin/bash
for file in *.prof; do
	name=${file##*/}
	base=${name%.prof}
	echo "##############$base###############"
	opt -load ../build/libPerformanceTest.so $base.ll -pgo-test-profile-file=$base.prof -pgo-instr-use -perf-test > /dev/null
done
