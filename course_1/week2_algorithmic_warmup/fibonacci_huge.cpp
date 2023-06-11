#include <iostream>
#include <vector>

long long pisano_period(long long m)
{
    long long previous = 0;
    long long current = 1;
    long long index{1};
    bool run{true};
    while (run)
    {
        ++index;
        long long tmp_previous = previous;
        previous = current % m;
        current = tmp_previous + current;
        if (current % m == 1 && previous % m == 0)
        {
            run = false;
        }
    }
    return index - 1;
}

long long get_fibonacci_huge_naive(long long n, long long m)
{
    auto p = pisano_period(m);
    n = n % p;
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current = 1;

    for (long long i = 2; i <= n; ++i)
    {
        long long tmp_previous = previous;
        previous = current % m;
        current = tmp_previous + current;
    }

    return current % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    // std::cout << pisano_period(m) << '\n';
}
