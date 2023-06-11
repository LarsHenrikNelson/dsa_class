#include <iostream>
#include <vector>

long long get_fibonacci_last_digit_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n + 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    // std::cout << current << "\n";

    return current % 10;
}

long long get_fib_last_fast(long long input)
{
    // write your code here
    int n = input % 60;
    if (n <= 1)
        return n;

    std::vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    long long result = fib[n];
    return result % 10;
}

int main()
{
    long long n;
    std::cin >> n;
    // long long c = get_fibonacci_last_digit_naive(n);
    // std::cout << c << '\n';
    long long d = get_fib_last_fast(n);
    std::cout << d << '\n';
}
