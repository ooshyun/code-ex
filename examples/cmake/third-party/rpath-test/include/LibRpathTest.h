#ifndef LIB_RPATH_TEST_H
#define LIB_RPATH_TEST_H

/**
 * \ingroup RPathTest_namespace
 *
 * RPathTest namespace.
 */
namespace RPathTest {

/**
 * @class RPathTest::printClass
 * @headerfile RPathTest.h <RPathTest/RPathTest.h>
 *
 * @brief A class from RPathTest namespace.
 *
 * This class does a summation.
 */
class printClass
{
public:
    /**
     * Constructor
     */
    printClass();

    /**
     * Destructor
     */
    virtual ~printClass();

    /**
     * A method that does a summation
     */
    virtual double doSomething();
};


/**
 * @class RPathTest::doubleprintClass
 * @headerfile RPathTest.h <RPathTest/RPathTest.h>
 *
 * @brief A derived class from RPathTest namespace.
 *
 * This class performs a difference.
 */
class doubleprintClass : public printClass
{
public:
    /**
     * Constructor
     */
    doubleprintClass();

    /**
     * Destructor
     */
    virtual ~doubleprintClass();

    /**
     * A method that does something
     */
    virtual double doSomething();
};


} // namespace RPathTest

#endif /* LIB_RPATH_TEST_H */