
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

void _test_vector_init() {
    std::vector<int16_t> samples(10, 0);
    int16_t buf[5] = {1, 2, 3, 4, 5};
    // int16_t buf[5] = {0};

    for (auto& sample : samples) {
        std::cout << sample << " ";
    }
    std::cout << std::endl;
    std::cout << "vector size: " << samples.size() << std::endl;

    samples = {buf, buf + 5};
    std::cout << "vector size: " << samples.size() << std::endl;

    samples.insert(samples.begin()+5, &buf[0], &buf[5]);
    for (auto& sample : samples) {
        std::cout << sample << " ";
    }
    std::cout << std::endl;
    std::cout << "vector size: " << samples.size() << std::endl;
}

void test_vector_function() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    std::cout << "vec max_size: " << vec.max_size() << std::endl;
    std::cout << "vec empty: " << vec.empty() << std::endl;
    std::cout << "vec front: " << vec.front() << std::endl;
    std::cout << "vec back: " << vec.back() << std::endl;
    std::cout << "vec data: " << vec.data() << std::endl;
    std::cout << "vec at: " << vec.at(2) << std::endl;
    std::cout << "vec operator[]: " << vec[2] << std::endl;
    std::cout << "vec begin: " << *vec.begin() << std::endl;
    std::cout << "vec end: " << *(vec.end()-1) << std::endl;
    std::cout << "vec rbegin: " << *vec.rbegin() << std::endl;
    std::cout << "vec rend: " << *(vec.rend()-1) << std::endl;

    for (auto it = vec.begin(); it != vec.end(); ) {
        std::cout << *it << " ";
        if (*it == 3) {
            it = vec.erase(it);
        } else {
            it++;
        }
    }
    for (auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void test_vector_typecast() {
    // float to uint8_t
    std::vector<float> float_vec = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<uint8_t> uint8_vec;
    uint8_vec.reserve(float_vec.size());
    uint8_t zero_point = 255;
    float scale = 0.333999;
    for (auto& f : float_vec) {
        std::cout << std::to_string(f) << " to "
                  << std::to_string(static_cast<uint8_t>(f/scale + zero_point))
                  << std::endl;
        uint8_vec.push_back(static_cast<uint8_t>(f/scale + zero_point));
    }

    for (auto& u : uint8_vec) {
        std::cout << std::to_string(u) << "\n";
    }
}

void test_vector() {
    // std::cout << "test_vector_reference" << std::endl;
    // std::vector<std::string> project_paths = {
    //                  "practice/Src/test/test_vector_reference.cc", \
    //                  "practice/Src/test/test_vector_reference2.cc"};
    // _test_vector_reference(project_paths);
    // _test_vector_assign();
    // _test_vector_init();
    // test_vector_function();
    test_vector_typecast();
}