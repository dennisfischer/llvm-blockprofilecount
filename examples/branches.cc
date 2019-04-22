#include <stdio.h>
int main( int argc, const char* argv[]) {
	for(int i = 0; i < 10; i++) {
		if(i % 2 == 0) {
			printf("foo\n");
		} else {
			printf("bar\n");
		}
	}
}
