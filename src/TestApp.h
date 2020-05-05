//
// Created by Chris Jurich  on 5/3/20.
//

// test class for cross-compiling C++ using dockerfiles

#ifndef DOCKER_TEST_TESTAPP_H
#define DOCKER_TEST_TESTAPP_H

#include <cstdlib>
#include <fstream>
#include <vector>
#include <unordered_map>

class TestApp {
private:
    std::vector<int> numbers;
    // want to test file IO
public:
    void
    input(const std::string&);
public:
    void
    output(const std::string&);
    // want to test environment variables
public:
    std::string
    enviornment();
    // some simple file IO
public:
    void
    values(const std::vector<int>&);
public:
    std::vector<int>
    values();
};

#endif //DOCKER_TEST_TESTAPP_H