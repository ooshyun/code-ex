#include <iostream>
#include <cstdlib>

void test_exec(void) {

    // Command to be executed with sudo
    std::string command = "sudo ls /bin";

    // Use system() function to execute the command
    int status = system(command.c_str());

    if (status != 0) {
        std::cerr << "Error executing command with sudo." << std::endl;
    }

}