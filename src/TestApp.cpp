//
// Created by Chris Jurich  on 5/3/20.
//

#include "TestApp.h"

void
TestApp::input(const std::string& file_name) {
    // takes a file with a bunch of numbers on id
    auto infile = std::ifstream (file_name);
    auto raw_double_string = std::string();
    while(getline(infile,raw_double_string)) {
        // putting the values into the vector and map
        numbers.emplace_back(
                std::stod(raw_double_string)
                );
    }
    // closing the file
    infile.close();
}


void
TestApp::output(const std::string& file_name) {
    // outputs the test app's contents to the specified file path
    auto outfile = std::ofstream (file_name);
    // print the raw values
    outfile<<"value_list";
    for(const auto& value : numbers) {
        outfile<<'\n'<<value;
    }
    outfile.close();
}

std::string
TestApp::enviornment() {
    // testing the ability to get the TEST_PATH venv
    return std::getenv("TEST_PATH");
}
// some getter and setter action
void
TestApp::values(const std::vector<int>& input_vec) {
    numbers.insert(numbers.begin() + numbers.size(),input_vec.begin(), input_vec.end());
}

std::vector<int>
TestApp::values() {
    return numbers;
}
