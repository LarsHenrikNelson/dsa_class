#include <iostream>
#include <vector>

long long fib_sum_fast(long long start, long long stop)
{
    std::vector<long long> fib(stop + 1);
    long long result = 0;
    for (long long i = 0; i <= stop; ++i)
    {
        if (i == 0)
            fib[0] = 0;
        else if (i == 1)
            fib[1] = 1;
        else
            fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
        if (i >= start)
            result += fib[i] % 10;
    }
    return result;
}

long long get_fib_last_fast(long long input)
{
    // write your code here
    long long n = input % 60;
    if (n <= 1)
        return n;

    std::vector<long long> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (long long i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    long long result = fib[n];
    return result % 10;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    long long start = from % 60;
    long long end = to % 60;
    if (start == end)
    {
        auto f = get_fib_last_fast(start);
        std::cout << f << '\n';
        return 0;
    }
    else if (start > end)
    {
        auto f = fib_sum_fast(start, end + 60);
        std::cout << f % 10 << '\n';
        return 0;
    }
    else
    {
        auto f = fib_sum_fast(start, end);
        std::cout << f % 10 << "\n";
        return 0;
    }
}
