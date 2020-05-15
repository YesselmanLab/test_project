import os
import glob
import Utils

def make_header(project_name):
    """Method that creates the header for a CMakeLists.txt file, taking the project name as the input parameter"""
    file_header = "#"*100 + '\n# Header information\n'
    file_header += "cmake_minimum_required(VERSION 3.0)\n"
    file_header += "project({NAME})\n".format(NAME=project_name)
    file_header += "set(CMAKE_CXX_STANDARD 14)\n"
    file_header += "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
    file_header += "set(CMAKE_SHARED_LINKER_FLAGS \"-Wl,--no-as-needed -ldl --enable-kernel=2.6\")\n"
    file_header +=  "set(CMAKE_CXX_FLAGS \"--enable-kernel=2.6\")\n"
    for directory in "src unittests".split():
        file_header += "include_directories({BASE}/{DIR}/)\n".format(
                BASE=os.getcwd(),DIR=directory
                )
    file_header += "#"*100 + '\n'
    return file_header

def make_file_variables(source_dir):
    """Method that creates the file variables"""
    file_contents = "#"*100 + "\n# File definitions\n"
    file_name = Utils.make_file_list(glob.glob( os.getcwd()+'/' + source_dir + "/*"))
    file_contents += "set(test_files\n" + "\n\t\t".join(file_name) + "\n)\n"
    file_contents += "add_library(test_lib ${test_files})\n"
    file_contents += "target_link_libraries(test_lib -static)\n"
    file_contents += "#"*100 + '\n'
    return file_contents

def write_cml_file(content_list):
    """Method that creates a CMakeLists.txt file and populates it with the string input list""" 
    with open("CMakeLists.txt","w") as outfile:
        for content in content_list:
            outfile.write(content)
 
def make_executables():
    """Method that creates the text for the executables"""
    executable_string = "#"*100 + '\n' + "# Executable declarations\n"
    for executable in "app.cpp unittests/TestApp_unittests.cpp".split():
        executable_string += "add_executable({NAME} {FILE})\n".format(NAME=executable.split('/')[-1].split('.')[0],FILE=executable)
        executable_string += "target_link_libraries({NAME} test_lib -static)\n".format(NAME=executable.split('/')[-1].split('.')[0])
    executable_string += "#"*100 + '\n'
    return executable_string

if __name__ == "__main__":
    write_cml_file(
    [
        make_header("crossbuild_test"), make_file_variables("src/"), make_executables()
        ]
            )
