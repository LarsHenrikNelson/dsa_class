#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

std::string larger(const std::string a, const std::string b)
{
    int x = std::stoi(a);
    if (std::stoi(a) > std::stoi(b))
    {
        if (static_cast<int>(a.at(0) - 48) > static_cast<int>(b.at(0) - 48))
            return a;
        else if (static_cast<int>(a.at(0) - 48) == static_cast<int>(b.at(0) - 48) && (static_cast<int>(a.at(1) - 48) > static_cast<int>(b.at(0) - 48)))
            return a;
        else
            return b;
    }
    else
    {
        if (static_cast<int>(b.at(0) - 48) > static_cast<int>(a.at(0) - 48))
            return b;
        else if (static_cast<int>(b.at(0) - 48) == static_cast<int>(a.at(0) - 48) && (static_cast<int>(b.at(1) - 48) > static_cast<int>(a.at(0) - 48)))
            return b;
        else
            return a;
    }
}

int main()
{
    std::string n;
    std::string m;
    std::cin >> n >> m;
    std::cout << larger(n, m) << "\n";
    std::cout << (static_cast<int>(n.at(0) - 48) > static_cast<int>(m.at(0) - 48)) << "\n";
    return 0;
}