#include <iostream>
#include "src/TestApp.h"

int
main(int argc, char** argv){
    // instantiating with C++11 syntax
    auto TEST = TestApp();
    // file io
    TEST.input("data/input.io");
    TEST.output("data/output.io");
    // environment variables
    TEST.enviornment();
    // getters and setters with C++11 style
    TEST.values({-1, -2, -3, -4});
    auto vals = TEST.values();
	for(int i = 0; i<argc; ++i) {
		std::cout<<argv[i]<<'\t';
	}
	std::cout<<'\n';
}
