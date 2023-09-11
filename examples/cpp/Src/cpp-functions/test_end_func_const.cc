#include <iostream>

class MyClass
{
private:
    mutable int counter;
    // int counter;
public:

    MyClass() : counter(0) {}

    void Foo()
    {
        counter++;
        std::cout << "Foo" << std::endl;    
    }

    void Foo() const
    {
        // If int counter, it cannot compile 
        // This works because counter is `mutable`
        counter++;    
        std::cout << "Foo const" << std::endl;
    }

    int GetInvocations() const
    {
        return counter;
    }
};

void test_end_func_const(void)
{
    MyClass cc;
    const MyClass& ccc = cc;
    cc.Foo();
    ccc.Foo();
    std::cout << "Foo has been invoked " << ccc.GetInvocations() << " times" << std::endl;
}