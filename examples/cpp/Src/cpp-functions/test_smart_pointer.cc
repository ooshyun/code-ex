#include <iostream>

class TestSmartPointer {
 public:
		TestSmartPointer() {
				std::cout << "TestSmartPointer constructor" << std::endl;
		}
		~TestSmartPointer() {
				std::cout << "TestSmartPointer destructor" << std::endl;
		}
    operator bool() const {
      return false;
    }
  private:
    int _test;
};

class TestPassSmartPointer {
  public:
    TestPassSmartPointer() = default;
    ~TestPassSmartPointer() {
      std::cout << "TestPassSmartPointer destructor" << std::endl;
      if (_test_smart_ptr) _test_smart_ptr.release();
    };
    void set_smart_ptr(std::unique_ptr<TestSmartPointer>&& test_smart_ptr) {
      _test_smart_ptr = std::move(test_smart_ptr);
    };
    TestSmartPointer& get_smart_ptr() const {
      if (_test_smart_ptr) return *_test_smart_ptr;
    };
  private:
    std::unique_ptr<TestSmartPointer> _test_smart_ptr;
};

void test_smart_pointer(void) {
    // smart ptr call = constructor
    // weak pointer, reference pointer 
    std::unique_ptr<int> usamrt_ptr(new int[10]);
    std::shared_ptr<int> ssmart_ptr(new int[10]);
    std::weak_ptr<int> wsmart_ptr = ssmart_ptr;
    std::shared_ptr<int> ssmart_ptr_1 = std::make_shared<int>(10); // new int[10];
    auto ssmart_ptr_2 = std::make_shared<int>(10);

    std::cout << "Before ssmart_ptr_1: " << ssmart_ptr_1.get() << std::endl;
    
    auto ssmart_ptr_3 = std::move(ssmart_ptr_1);

    std::cout << "After ssmart_ptr_1: " << ssmart_ptr_1.get() << std::endl;
    std::cout << "After ssmart_ptr_3: " << ssmart_ptr_3.get() << std::endl;


		std::unique_ptr<TestSmartPointer> test_smart_ptr;
		test_smart_ptr = std::make_unique<TestSmartPointer>();
		test_smart_ptr = std::make_unique<TestSmartPointer>();
		// while(true){};

    std::unique_ptr<TestPassSmartPointer> test_ptr;
    if (test_ptr){
      std::cout << "test_ptr is not nullptr" << std::endl;
    } else {
      std::cout << "test_ptr is nullptr" << std::endl;
    }

    if (!(test_ptr)){
      std::cout << "test_ptr is nullptr" << std::endl;
    } else {
      std::cout << "test_ptr is not nullptr" << std::endl;
    }

    // test_ptr = std::make_unique<TestPassSmartPointer>();    
    // if (test_ptr->get_smart_ptr()) {
    //   std::cout << "test_ptr->get_smart_ptr() is not nullptr" << std::endl;
    // } else {
    //   std::cout << "test_ptr->get_smart_ptr() is nullptr" << std::endl;
    // }
}
