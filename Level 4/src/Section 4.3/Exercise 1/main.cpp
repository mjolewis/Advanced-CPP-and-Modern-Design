//
// Explore random number generator techniques introduced in C++11.
// Note - The standard library improved on Boost Random syntax as the classes are now function objects.
//
// Created by Michael Lewis on 7/17/23.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <random>

// Part A - Copy and adapt this code by using the engine std::linear_congruential_engine
void test_linear_congruential_engine_uniform_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> engine(rd());

    // Generate uniform random variates in interval [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::uniform_real_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Engine - Uniform Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End Linear Congruential Engine - Uniform Distribution ***" << std::endl;
}

// Part A - Copy and adapt this code by using the engine std::mt19937
void test_mt19937_engine_uniform_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937 engine(rd());

    // Generate uniform random variates in interval [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::uniform_real_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Engine - Uniform Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937 Engine - Uniform Distribution ***" << std::endl;
}

// Part A - Copy and adapt this code by using the engine std::mt19937_64
void test_mt19937_64_engine_uniform_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937_64 engine(rd());

    // Generate the uniform random variates for interval [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::uniform_real_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Engine - Uniform Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937_64 Engine - Uniform Distribution ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::linear_congruential_engine with a normal distribution
void test_linear_congruential_engine_normal_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> engine(rd());

    // Generate normal random variates with mean and std_dev [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::normal_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Engine - Normal ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End Linear Congruential Engine - Normal ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937 with a normal distribution
void test_mt19937_engine_normal_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937 engine(rd());

    // Generate normal random variates with mean and std_dev [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::normal_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Engine - Normal ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937 Engine - Normal ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937_64 with a normal distribution
void test_mt19937_64_engine_normal_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937_64 engine(rd());

    // Generate normal random variates with mean and std_dev [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::normal_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Engine - Normal ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937_64 Engine - Normal ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::linear_congruential_engine with a chi-squared distribution
void test_linear_congruential_engine_chi_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> engine(rd());

    // Generate chi squared random variates using default degrees of freedom = 1
    int numTrials = 30;
    std::chi_squared_distribution<double> dist;

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Engine - Chi Squared ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End Linear Congruential Engine - Chi Squared ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937 with a chi-squared distribution
void test_mt19937_engine_chi_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937 engine(rd());

    // Generate chi squared random variates using default degrees of freedom = 1
    int numTrials = 30;
    std::chi_squared_distribution<double> dist;

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Engine - Chi Squared ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937 Engine - Chi Squared ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937_64 with a chi squared distribution
void test_mt19937_64_engine_chi_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937_64 engine(rd());

    // Generate chi squared random variates using default degrees of freedom = 1
    int numTrials = 30;
    std::chi_squared_distribution<double> dist;

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Engine - Chi Squared ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937_64 Engine - Chi Squared ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::linear_congruential_engine with a bernoulli distribution
void test_linear_congruential_engine_bernoulli_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> engine(rd());

    // Generate bernoulli distribution random variates using default distribution = 0.5
    int numTrials = 30;
    std::bernoulli_distribution dist;

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Engine - Bernoulli Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End Linear Congruential Engine - Bernoulli Distribution ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937 with a bernoulli distribution
void test_mt19937_engine_bernoulli_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937 engine(rd());

    // Generate bernoulli distribution random variates using default distribution = 0.5
    int numTrials = 30;
    std::bernoulli_distribution dist;

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Engine - Bernoulli Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937 Engine - Bernoulli Distribution ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937_64 with a bernoulli distribution
void test_mt19937_64_engine_bernoulli_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937_64 engine(rd());

    // Generate bernoulli distribution random variates using default distribution = 0.5
    int numTrials = 30;
    std::bernoulli_distribution dist;

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Engine - Bernoulli Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937_64 Engine - Bernoulli Distribution ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::linear_congruential_engine with a cauchy distribution
void test_linear_congruential_engine_cauchy_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647> engine(rd());

    // Generate cauchy distribution with distribution parameters [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::cauchy_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Engine - Cauchy Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End Linear Congruential Engine - Cauchy Distribution ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937 with a cauchy distribution
void test_mt19937_engine_cauchy_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937 engine(rd());

    // Generate cauchy distribution with distribution parameters [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::cauchy_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Engine - Cauchy Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937 Engine - Cauchy Distribution ***" << std::endl;
}

// Part B - Copy and adapt this code by using the engine std::mt19937_64 with a cauchy distribution
void test_mt19937_64_engine_cauchy_distribution()
{
    // Choose the seed
    std::random_device rd;

    // Choose the engine
    std::mt19937_64 engine(rd());

    // Generate cauchy distribution with distribution parameters [A, B]
    double A = 0.0;
    double B = 1.0;
    int numTrials = 30;
    std::cauchy_distribution<double> dist(A, B);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Engine - Cauchy Distribution ***" << std::endl;
    for (int i = 1; i <= numTrials; ++i)
    {
        std::cout << dist(engine) << ", ";
    }
    std::cout << "\n*** End mt19937_64 Engine - Cauchy Distribution ***" << std::endl;
}

// A generic function to generate a list of random numbers for a generic engine and a generic distribution
template<typename T, typename E, typename D>
std::vector<T> random_number_generator(D distribution, int size)
{
    // Choose the seed
    std::random_device rd;

    // Use the provided engine
    E engine(rd());

    std::vector<T> randomNumbers;
    for (int i = 0; i < size; ++i)
    {
        // Use the provided distribution
        randomNumbers.push_back(distribution(engine));
    }

    return randomNumbers;
}

// Part C - Copy and adapt this code by using the generic std::linear_congruential_engine with a uniform distribution
void test_linear_congruential_generic_engine_uniform_dist()
{
    // Initialize the distribution
    double A = 0.0;
    double B = 1.0;
    std::uniform_real_distribution<double> dist(A, B);

    // random numbers
    auto randomNums = random_number_generator<double,
            std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>,
            std::uniform_real_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Generic Engine - Uniform Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End Linear Congruential Generic Engine - Uniform Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937 engine with a uniform distribution
void test_mt19937_generic_engine_uniform_dist()
{
    // Generate uniform random variates in interval [A, B]
    double A = 0.0;
    double B = 1.0;
    std::uniform_real_distribution<double> dist(A, B);

    // random numbers
    auto randomNums = random_number_generator<double, std::mt19937, std::uniform_real_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Generic Engine - Uniform Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937 Generic Engine - Uniform Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937_64 engine with a uniform distribution
void test_mt19937_64_generic_engine_uniform_dist()
{
    // Generate the uniform random variates for interval [A, B]
    double A = 0.0;
    double B = 1.0;
    std::uniform_real_distribution<double> dist(A, B);

    // Random numbers
    auto randomNums = random_number_generator<double, std::mt19937_64, std::uniform_real_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Generic Engine - Uniform Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937_64 Generic Engine - Uniform Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::linear_congruential_engine with a normal distribution
void test_linear_congruential_generic_engine_normal_dist()
{
    // Generate normal random variates with mean and std_dev [A, B]
    double A = 0.0;
    double B = 1.0;
    std::normal_distribution<double> dist(A, B);

    auto randomNums = random_number_generator<double,
            std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>,
                    std::normal_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Generic Engine - Normal ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End Linear Congruential Generic Engine - Normal ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937 engine with a normal distribution
void test_mt19937_generic_engine_normal_dist()
{
    // Generate normal random variates with mean and std_dev [A, B]
    double A = 0.0;
    double B = 1.0;
    std::normal_distribution<double> dist(A, B);

    auto randomNums = random_number_generator<double, std::mt19937, std::normal_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Generic Engine - Normal ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937 Generic Engine - Normal ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937_64 engine with a normal distribution
void test_mt19937_64_generic_engine_normal_dist()
{
    // Generate normal random variates with mean and std_dev [A, B]
    double A = 0.0;
    double B = 1.0;
    std::normal_distribution<double> dist(A, B);

    auto randomNums = random_number_generator<double, std::mt19937_64, std::normal_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Generic Engine - Normal ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937_64 Generic Engine - Normal ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::linear_congruential_engine with a chi-squared distribution
void test_linear_congruential_generic_engine_chi_dist()
{
    // Generate chi squared random variates using default degrees of freedom = 1
    std::chi_squared_distribution<double> dist;

    // Random numbers
    auto randomNums = random_number_generator<double,
            std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>,
                    std::chi_squared_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Generic Engine - Chi Squared ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End Linear Congruential Generic Engine - Chi Squared ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937 engine with a chi-squared distribution
void test_mt19937_generic_engine_chi_distribution()
{
    // Generate chi squared random variates using default degrees of freedom = 1
    std::chi_squared_distribution<double> dist;

    // Random numbers
    auto randomNums = random_number_generator<double, std::mt19937, std::chi_squared_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Generic Engine - Chi Squared ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937 Generic Engine - Chi Squared ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937_64 engine with a chi squared distribution
void test_mt19937_64_generic_engine_chi_distribution()
{
    // Generate chi squared random variates using default degrees of freedom = 1
    std::chi_squared_distribution<double> dist;


    // Random numbers
    auto randomNums = random_number_generator<double, std::mt19937_64, std::chi_squared_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Generic Engine - Chi Squared ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937_64 Generic Engine - Chi Squared ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::linear_congruential_engine with a bernoulli distribution
void test_linear_congruential_generic_engine_bernoulli_distribution()
{
    // Generate bernoulli distribution random variates using default distribution = 0.5
    std::bernoulli_distribution dist;

    auto randomNums = random_number_generator<double,
            std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>,
                    std::bernoulli_distribution>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Generic Engine - Bernoulli Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End Linear Congruential Generic Engine - Bernoulli Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937 engine with a bernoulli distribution
void test_mt19937_generic_engine_bernoulli_distribution()
{
    // Generate bernoulli distribution random variates using default distribution = 0.5
    std::bernoulli_distribution dist;

    auto randomNums = random_number_generator<double, std::mt19937, std::bernoulli_distribution>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Generic Engine - Bernoulli Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937 Generic Engine - Bernoulli Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937_64 engine with a bernoulli distribution
void test_mt19937_64_generic_engine_bernoulli_distribution()
{
    // Generate bernoulli distribution random variates using default distribution = 0.5
    std::bernoulli_distribution dist;

    auto randomNums = random_number_generator<double, std::mt19937_64, std::bernoulli_distribution>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Generic Engine - Bernoulli Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937_64 Generic Engine - Bernoulli Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::linear_congruential_engine with a cauchy distribution
void test_linear_congruential_generic_engine_cauchy_distribution()
{
    // Generate cauchy distribution with distribution parameters [A, B]
    double A = 0.0;
    double B = 1.0;
    std::cauchy_distribution<double> dist(A, B);

    auto randomNums = random_number_generator<double,
            std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>,
                    std::cauchy_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start Linear Congruential Generic Engine - Cauchy Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End Linear Congruential Generic Engine - Cauchy Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937 engine with a cauchy distribution
void test_mt19937_generic_engine_cauchy_distribution()
{
    // Generate cauchy distribution with distribution parameters [A, B]
    double A = 0.0;
    double B = 1.0;
    std::cauchy_distribution<double> dist(A, B);

    auto randomNums = random_number_generator<double, std::mt19937, std::cauchy_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937 Generic Engine - Cauchy Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937 Generic Engine - Cauchy Distribution ***" << std::endl;
}

// Part C - Copy and adapt this code by using the generic std::mt19937_64 engine with a cauchy distribution
void test_mt19937_64_generic_engine_cauchy_distribution()
{
    // Generate cauchy distribution with distribution parameters [A, B]
    double A = 0.0;
    double B = 1.0;
    std::cauchy_distribution<double> dist(A, B);

    auto randomNums = random_number_generator<double, std::mt19937_64, std::cauchy_distribution<double>>(dist, 10);

    // Produce a number of random variates
    std::cout << "\n*** Start mt19937_64 Generic Engine - Cauchy Distribution ***" << std::endl;
    for (auto num : randomNums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n*** End mt19937_64 Generic Engine - Cauchy Distribution ***" << std::endl;
}

int main()
{
    test_linear_congruential_engine_uniform_distribution();
    test_mt19937_engine_uniform_distribution();
    test_mt19937_64_engine_uniform_distribution();
    test_linear_congruential_engine_normal_distribution();
    test_mt19937_engine_normal_distribution();
    test_mt19937_64_engine_normal_distribution();
    test_linear_congruential_engine_chi_distribution();
    test_mt19937_engine_chi_distribution();
    test_mt19937_64_engine_chi_distribution();
    test_linear_congruential_engine_bernoulli_distribution();
    test_mt19937_engine_bernoulli_distribution();
    test_mt19937_64_engine_bernoulli_distribution();
    test_linear_congruential_engine_cauchy_distribution();
    test_mt19937_engine_cauchy_distribution();
    test_mt19937_64_engine_cauchy_distribution();

    // Generic number generator
    test_linear_congruential_generic_engine_uniform_dist();
    test_mt19937_generic_engine_uniform_dist();
    test_mt19937_64_generic_engine_uniform_dist();
    test_linear_congruential_generic_engine_normal_dist();
    test_mt19937_generic_engine_normal_dist();
    test_mt19937_64_generic_engine_normal_dist();
    test_linear_congruential_generic_engine_chi_dist();
    test_mt19937_generic_engine_chi_distribution();
    test_mt19937_64_generic_engine_chi_distribution();
    test_linear_congruential_generic_engine_bernoulli_distribution();
    test_mt19937_generic_engine_bernoulli_distribution();
    test_mt19937_64_generic_engine_bernoulli_distribution();
    test_linear_congruential_generic_engine_cauchy_distribution();
    test_mt19937_generic_engine_cauchy_distribution();
    test_mt19937_64_generic_engine_cauchy_distribution();
    return 0;
}