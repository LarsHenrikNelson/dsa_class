#include <iostream>
#include <vector>

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fib_sum_fast(long long input)
{
    // write your code here
    int n = input % 60;
    if (n <= 1)
        return n;

    std::vector<long long> fib(60);
    fib[0] = 0;
    fib[1] = 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        result += fib[i];
    }
    return result % 10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << "\n";
    std::cout << fib_sum_fast(n) << "\n";
}
