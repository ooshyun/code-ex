// C++ program to demonstrate
// Run Time Type Identification successfully
// With virtual function
// https://www.geeksforgeeks.org/rtti-run-time-type-information-in-cpp/

#include <iostream>

// Initialization of base class
class B {
    // dynamic_cast uses RTTI and the following program fails with the error
    // “cannot dynamic_cast `b’ (of type `class B*’) to type `class D*’
    // (source type is not polymorphic) ” because there is no virtual function
    //  in the base class B.
    virtual void fun() {}
};

// Initialization of Derived class
class D : public B {
};

// Driver Code
void test_rtti(void) {
    std::cout << "Allocate Base class object\n";
    B* b0 = new B;  // Base class pointer
    D* d0 = dynamic_cast<D*>(b0);  // Derived class pointer
    if (d0 != NULL)
        std::cout << "works\n";
    else
        std::cout << "cannot cast B* to D*\n";

    std::cout << "Allocate Derived class object\n";
    B* b = new D;  // Base class pointer
    D* d = dynamic_cast<D*>(b);  // Derived class pointer
    if (d != NULL)
        std::cout << "works\n";
    else
        std::cout << "cannot cast B* to D*\n";
}
