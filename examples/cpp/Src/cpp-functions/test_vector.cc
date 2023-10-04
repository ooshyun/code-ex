
#include<iostream>
#include<vector>

void _test_vector_assign() {
    std::vector<unsigned char> key = {0x00, 0x01, 0x02, 0x03};
    std::string name_1 = "test_1";
    std::string name_2 = "test_123";
    std::string name_3 = "test_123456";

    for (auto& key_byte : key) {
        std::cout << key_byte << " ";
    }
    std::cout << std::endl;

    key.assign(name_2.begin(), name_2.end());
    for (auto& key_byte : key) {
        std::cout << key_byte << " ";
    }
    std::cout << std::endl;

    key.assign(name_3.begin(), name_3.end());
    for (auto& key_byte : key) {
        std::cout << key_byte << " ";
    }
    std::cout << std::endl;

    key.assign(name_1.begin(), name_1.end());
    for (auto& key_byte : key) {
        std::cout << key_byte << " ";
    }

    std::cout << std::endl;
}

void _test_vector_reference(const std::vector<std::string>& project_paths) {
    for (auto& project_path : project_paths) {
        std::cout << project_path << std::endl;
    }
}


void _test_vector_init(void) {
    std::vector<int16_t> audio_sample(22050);
    int16_t buf[11025];
    for (int i = 0; i < 11025; i++) {
        buf[i] = 2;
    }
    audio_sample = {buf, buf + 11025};

    for (auto& sample : audio_sample) {
        std::cout << sample << " ";
    }
}

void test_vector() {
    // std::cout << "test_vector_reference" << std::endl;
    // std::vector<std::string> project_paths = {
    //                  "practice/Src/test/test_vector_reference.cc", \
    //                  "practice/Src/test/test_vector_reference2.cc"};
    // _test_vector_reference(project_paths);
    // _test_vector_assign();
    _test_vector_init();
}