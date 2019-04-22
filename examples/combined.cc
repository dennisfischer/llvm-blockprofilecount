#include <stdio.h>

void foo() {
	printf("foo\n");
}

void bar() {
	printf("bar\n");
}

int main( int argc, const char* argv[]){
	for(int i = 0; i < 1000; i++) {
		if(i % 2 == 0) {
			foo();
		} else {
			bar();
		}
	}
}
