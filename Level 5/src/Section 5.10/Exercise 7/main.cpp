//
// Illustrative examples of vector and matrix expressions using Boost Ublas
//
// Created by Michael Lewis on 8/2/23.
//

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_expression.hpp>

using namespace boost::numeric::ublas;
using value_type = int;
using Matrix = matrix<value_type>;
using Vector = vector<value_type>;

// Inner product of two vectors.
void test_inner_product()
{
    Vector v1{3};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    Vector v2{3};
    v2(0) = 1;
    v2(1) = 2;
    v2(2) = 3;

    int result = boost::numeric::ublas::inner_prod(v1, v2);
    std::cout << "inner_prod(v1, v2) = " << result << std::endl;
}

// Outer product of two vectors.
void test_outer_product()
{
    Vector v1{3};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    Vector v2{3};
    v2(0) = 1;
    v2(1) = 2;
    v2(2) = 3;

    auto result = boost::numeric::ublas::outer_prod(v1, v2);
    std::cout << "outer_prod(v1, v2) = " << result << std::endl;
}

// Adding two vectors.
void test_add()
{
    Vector v1{3};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    Vector v2{3};
    v2(0) = 1;
    v2(1) = 2;
    v2(2) = 3;

    auto result = v1 + v2;
    std::cout << "(v1 + v2) = " << result << std::endl;
}

// Subtracting two vectors.
void test_subtract()
{
    Vector v1{3};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    Vector v2{3};
    v2(0) = 1;
    v2(1) = 2;
    v2(2) = 3;

    auto result = v1 - v2;
    std::cout << "(v1 - v2) = " << result << std::endl;
}

// The Euclidean, L1 and max norm of a vector.
void test_vector_norms()
{
    Vector v1{3};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    auto euclideanNorm = boost::numeric::ublas::norm_2(v1);
    auto l1Norm = boost::numeric::ublas::norm_1(v1);
    auto maxNorm = boost::numeric::ublas::norm_inf(v1);
    std::cout << "Euclidean Norm = " << euclideanNorm << std::endl;
    std::cout << "L1 Norm = " << l1Norm << std::endl;
    std::cout << "Max Norm = " << maxNorm << std::endl;
}

// L1 and max norms of a matrix.
void test_matrix_norms()
{
    Matrix m(10, 10);
    for (int i = 0; i < m.size1 (); ++ i)
    {
        for (int j = 0; j < m.size2 (); ++ j)
        {
            m(i, j) = (3 * i + j, i);
        }
    }

    auto l1Norm = boost::numeric::ublas::norm_1(m);
    auto maxNorm = boost::numeric::ublas::norm_inf(m);
    std::cout << "L1 Norm = " << l1Norm << std::endl;
    std::cout << "Max Norm = " << maxNorm << std::endl;
}

// The product of a matrix and a vector.
void test_matrix_and_vector_product()
{
    Vector v1{3};
    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;

    Matrix m(3, 3);
    for (int i = 0; i < m.size1 (); ++ i)
    {
        for (int j = 0; j < m.size2 (); ++ j)
        {
            m(i, j) = (i + j);
        }
    }

    std::cout << "Vector * Matrix = " << prod(v1, m) << std::endl;
    std::cout << "Matrix * Vector = " << prod(v1, m) << std::endl;
}

int main()
{
    test_inner_product();
    test_outer_product();
    test_add();
    test_subtract();
    test_vector_norms();
    test_matrix_norms();
    test_matrix_and_vector_product();
}