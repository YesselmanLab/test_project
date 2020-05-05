#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <fstream>
#include <vector>
#include "TestApp.h"

// unittests for the TestApp class used for Docker cross-compiling

TEST_CASE("Testing the TestApp class", "[TestApp]") {
    SECTION("testing that the .values() overloads work") {
        auto testapp = TestApp();
        const auto new_values = std::vector<int>{102,393,49,-1};
        testapp.values(new_values);

        const auto app_values = testapp.values();

        REQUIRE(app_values.size() == new_values.size());

        for(auto it = 0; it<new_values.size(); ++it) {
            REQUIRE(app_values[it] == new_values[it]);
        }
    }

    SECTION("testing that the .environment() method works") {
        REQUIRE("THIS IS A TEST" == TestApp().enviornment());
    }

    SECTION("testing file input with .input()") {
        auto testapp = TestApp();
        testapp.input("data/input.io");
        const auto target_values = std::vector<int>{
            1,2,3,4,5,6,7,8,9,10
        };

        const auto actual_values = testapp.values();

        REQUIRE(actual_values.size() == target_values.size());

        for(auto it = 0; it<actual_values.size(); ++it) {
            REQUIRE(actual_values[it] == target_values[it]);
        }
    }

    SECTION("testing file output with .output()") {
        auto testapp = TestApp();
        testapp.input("data/input.io");
        testapp.output("output.io");
        auto infile = std::ifstream ("output.io");
        auto raw_line = std::string{};
        auto file_contents = std::string{};
        while(getline(infile,raw_line)) {
            file_contents += raw_line + '\n';
        }
        file_contents.pop_back();
        const auto target_contents = "value_list\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10";
        REQUIRE(file_contents == target_contents);
    }
}