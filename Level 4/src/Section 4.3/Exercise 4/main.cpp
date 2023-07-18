//
// Approximate the value of pi using the unit circle and random number generators.
//
// Created by Michael Lewis on 7/18/23.
//

#include <cmath>
#include <iostream>
#include <random>

// Approximate the value of pi using N trials and the std::mt19937_64 random engine
void test_calculate_pi(int trials)
{
    // Part A - Create a random number engine and set its seed (for example, using std::random_device).
    std::random_device rd;
    std::mt19937_64 engine(rd());

    // Part B - Create two instances of std::uniform_real_distribution<double> on the unit interval.
    double A = 0.0;
    double B = 1.0;
    std::uniform_real_distribution<double> dist1(A, B);
    std::uniform_real_distribution<double> dist2(A, B);

    // Part C - Create a loop, generate uniform random values x and y.
    // Determine the Pythagorean distance to the origin is greater than 1 and if so, increment the counter.
    // Note, you can increment counter if distance is less than or equal to 1, so I take this approach.
    int counter = 0;
    for (int i = 0; i < trials; ++i)
    {
        double x = dist1(engine);
        double y = dist2(engine);
        double distance = sqrt(pow(x, 2) + pow(y, 2));
        if (distance <= 1.0) ++counter;
    }

    // Part D - Compute the value of pi. How many trials to compute ~3.14159
    // Note - pi = 4B/trials
    std::cout << "Approximation of PI: " << 4.0 * (counter / (double) trials)  << std::endl;
}

int main()
{
    test_calculate_pi(100'000'000);  // Result during trial runs: Approximation of PI: 3.14159
    test_calculate_pi(75'000'000);  // Result during trial runs: Approximation of PI: 3.14144
    test_calculate_pi(50'000'000);  // Result during trial runs: Approximation of PI: 3.14146
    test_calculate_pi(25'000'000);  // Result during trial runs: Approximation of PI: 3.14149
    test_calculate_pi(10'000'000);  // Result during trial runs: Approximation of PI: 3.14198
    return 0;
}
