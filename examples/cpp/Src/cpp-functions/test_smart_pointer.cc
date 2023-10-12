#include <iostream>

class TestSmartPointer {
 public:
		TestSmartPointer(int test = 0) : _test(test) {
				std::cout << "TestSmartPointer constructor" << std::endl;
		}
		~TestSmartPointer() {
				std::cout << "TestSmartPointer destructor" << std::endl;
		}
    void get_value() {
      std::cout << "TestSmartPointer get_value: " << _test << std::endl;
    }
    void set_value(int test) {
      _test = test;
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
      if (_test_smart_ptr) _test_smart_ptr.reset();
      if (_test_smart_ptr_shared) _test_smart_ptr_shared.reset();
    };
    void set_smart_ptr(std::unique_ptr<TestSmartPointer>&& test_smart_ptr) {
      std::cout << "set smart pointer in TestPassSmartPointer\n";
      _test_smart_ptr = std::move(test_smart_ptr);
      std::cout << "finish set smart pointer in TestPassSmartPointer\n";
    };
    TestSmartPointer& get_smart_ptr() const {
      if (_test_smart_ptr) return *_test_smart_ptr;
    };
    std::shared_ptr<TestSmartPointer>& get_smart_ptr_shared() {
      if (_test_smart_ptr_shared) {
        std::cout << "get smart pointer shared in TestPassSmartPointer\n";
        return _test_smart_ptr_shared;
      }
    }
    void set_smart_ptr_shared(const std::shared_ptr<TestSmartPointer>& test_smart_ptr_shared) {
      // std::cout << "set smart pointer shared in TestPassSmartPointer\n";
      _test_smart_ptr_shared = test_smart_ptr_shared;
      // std::cout << "finish set smart pointer shared in TestPassSmartPointer\n";
    };
  private:
    std::unique_ptr<TestSmartPointer> _test_smart_ptr;
    std::shared_ptr<TestSmartPointer> _test_smart_ptr_shared;
    // TestSmartPointer* _test_smart_ptr_shared;
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
    auto ssmart_ptr_4 = ssmart_ptr_3;

    std::cout << "After ssmart_ptr_1: " << ssmart_ptr_1.get() << std::endl;
    std::cout << "After ssmart_ptr_3: " << ssmart_ptr_3.get() << std::endl;
    std::cout << "After ssmart_ptr_4: " << ssmart_ptr_3.get() << std::endl;

		std::unique_ptr<TestSmartPointer> test_smart_ptr;
		test_smart_ptr = std::make_unique<TestSmartPointer>();
		test_smart_ptr = std::make_unique<TestSmartPointer>();
    test_smart_ptr.reset();
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
    if (test_ptr) test_ptr.reset();


    /* Get Smart pointer in other class 

    Class A: 
      ...

      std::unique_ptr x;


    Class B:

      ...
      std::unique_ptr y;

    Can y refer to x? Yes! const <type T> & value
    */

    std::cout << "Testing move smart pointer in the class\n";
    std::unique_ptr<TestPassSmartPointer> test_ptr_other = std::make_unique<TestPassSmartPointer>();
    test_ptr = std::make_unique<TestPassSmartPointer>();

    test_ptr->set_smart_ptr_shared(std::make_shared<TestSmartPointer>(5));

    std::cout << "Set smart pointer in the class\n"; // error
    test_ptr_other->set_smart_ptr_shared(test_ptr->get_smart_ptr_shared());
    
    std::cout << " Before:  \n";
    // (before) print test_ptr_other's val
    test_ptr->get_smart_ptr_shared()->get_value();
    test_ptr_other->get_smart_ptr_shared()->get_value();

    std::cout << " After:  \n";
    // (after) print test_ptr_other's val
    test_ptr->get_smart_ptr_shared()->set_value(10);
    test_ptr->get_smart_ptr_shared()->get_value();
    test_ptr_other->get_smart_ptr_shared()->get_value();

}
