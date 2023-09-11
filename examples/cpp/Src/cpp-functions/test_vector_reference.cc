
#include<iostream>
#include<vector>

void _test_vector_reference(const std::vector<std::string>& project_paths){

    for(auto& project_path : project_paths){
        std::cout << project_path << std::endl;
    }

}

void test_vector_reference(void){
    std::cout << "test_vector_reference" << std::endl;
    std::vector<std::string> project_paths = {"practice/Src/test/test_vector_reference.cc", \
                                            "practice/Src/test/test_vector_reference2.cc"};


    _test_vector_reference(project_paths);
}
