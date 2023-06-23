//
// Simple test class to illustrate the difference between raw pointer and smart pointers.
//
// Created by Michael Lewis on 6/22/23.
//

#include <iostream>
#include <exception>
#include <memory>
#include <utility>

/**
 * Simple point class to illustrate difference between raw pointers and smart pointers
 *
 * Note: The purpose of the destructor is to highlight when a memory leak does or does not occur.
 * In the case of raw pointers, the destructor will not be called when throwing the exception
 * immediately after creating the raw pointer, which indicate a memory leak. However, the destructor
 * is still called when an exception is throw immediately after a unique pointer is created, which
 * indicates that no memory leak as occurred.
 */
class Point
{
private:
    double xCoordinate;
    double yCoordinate;
public:
    Point() = default;
    Point(const Point& source) = default;
    Point(const double& xCoordinate, const double& yCoordinate) : xCoordinate{xCoordinate}, yCoordinate{yCoordinate} {}
    ~Point() { std::cout << "Point destroyed. No memory leak" << std::endl; }

    // Accessors
    double X() const noexcept {return xCoordinate;}
    double Y() const noexcept {return yCoordinate;}

    // Mutators
    void X(const double& x) {xCoordinate = x;}
    void Y(const double& y) {yCoordinate = y;}
};

// Part A - Test the fact that raw pointers can lead to memory leaks.
void test_rawPointer()
{
    {
        // Block with raw pointer lifecycle
        double* d = new double(1.0);
        Point* pt = new Point(1.0, 2.0);// Two-d Point class

        // Dereference and call member functions
        *d = 2.0;
        (*pt).X(3.0);// Modify x coordinate
        (*pt).Y(3.0);// Modify y coordinate

        // Can use operators for pointer operations
        pt->X(3.0);// Modify x coordinate
        pt->Y(3.0);// Modify y coordinate

        // Explicitly clean up memory (if you have not forgotten)
        delete d;
        delete pt;

        try
        {
            Point* pt1 = new Point;
            throw std::invalid_argument("Dummy exception - Raw Pointer");
//            delete pt1; unreachable code after exception is throw, so a memory leak occurs
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }

//        delete pt1; compiler error because pt1 is inaccessible and can't be deleted, causing a memory leak
    }
}

// Part B. Test the fact that unique pointers handle memory management and can prevent
// memory leaks.
void test_uniquePointer()
{
    {
        // Block with raw pointer lifecycle
        std::unique_ptr<double> d(new double(1.0));
        std::unique_ptr<Point> pt(new Point(1.0, 2.0));// Two-d Point class

        // Dereference and call member functions
        *d = 2.0;
        (*pt).X(3.0);// Modify x coordinate
        (*pt).Y(3.0);// Modify y coordinate

        // Can use operators for pointer operations
        pt->X(3.0);// Modify x coordinate
        pt->Y(3.0);// Modify y coordinate
    }

    try
    {
        std::unique_ptr<Point> pt1(new Point());
        throw std::invalid_argument("Dummy exception - Unique Pointer");
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

// Part C - Initialize two unique pointers to the same pointer.
// Assign a unique pointer to another unique pointers.
// Transfer ownership from one unique pointer to another unique pointer.
void test_pointerOwnership()
{
    // Initialize two unique pointers to the same pointer
    Point* point = new Point();
    std::unique_ptr<Point> p1(point);

    // On my compiler, assigned a pointer to multiple unique pointers causes a malloc error. As a result,
    // the code below has been commented.
//    std::unique_ptr<Point> P2(point);

    // Attempting to delete a pointer causes the program to crash. This implies that assigned two unique
    // pointers to the same pointer is not allowed.
//    delete point;
//    delete point;

    // Assign a unique pointer to another unique pointers.
    std::unique_ptr<Point> p3(new Point());

    // According to https://en.cppreference.com/w/cpp/memory/unique_ptr
    // std::unique_ptr is not CopyConstructible or CopyAssignable. These are in fact
    // implicitly deleted because std::unique_ptr satisfies MoveConstructible and MoveAssignable
//    std::unique_ptr<Point> p4(p3);
//    std::unique_ptr<Point> p5(p3);

    // Transfer ownership from one unique pointer to another
    std::unique_ptr<Point> p6(new Point());
    std::unique_ptr<Point> p7(std::move(p6));
}

template<typename T>
using UniquePointer = std::unique_ptr<T>;
using UniquePoint = UniquePointer<Point>;
// Part D - Use alias template (template typedef) to make the code more readable.
void test_aliasTemplate()
{
    UniquePoint p1(new Point());
    UniquePoint p2(new Point());
}

int main()
{
    test_rawPointer();
    test_uniquePointer();
    test_pointerOwnership();
    test_aliasTemplate();
    return 0;
}