#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    int full_tank = tank;
    int refills{0};
    stops.resize(stops.size() + 1);
    stops.push_back(dist);

    for (size_t i = 0; i < stops.size() - 3; ++i)
    {
        // std::cout << "Stop: " << stops.at(i + 1) << "\n";
        tank -= (stops.at(i + 1) - stops.at(i));
        if ((stops.at(i + 1) - stops.at(i)) > full_tank)
        {
            return -1;
        }
        if (tank < ((stops.at(i + 2) - stops.at(i + 1))))
        {
            tank = full_tank;
            refills += 1;
            // std::cout << "Tank refilled to: " << tank << "\n";
        }
    }
    return refills;
}

int main()
{
    int dist = 0;
    cin >> dist;
    int tank = 0;
    cin >> tank;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 2);
    stops.at(0) = 0;
    stops.at(n + 1) = dist;
    for (size_t i = 1; i < n + 1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(dist, tank, stops) << "\n";

    return 0;
}
