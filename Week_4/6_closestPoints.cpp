#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using std::min;
using std::pair;
using std::sort;
using std::string;
using std::vector;

struct coord
{
    long long x, y;
};

double calcDist(coord c1, coord c2);
double calcResult(vector<coord> x, vector<coord> y);
double minimal_distance(vector<long long> x, vector<long long> y); 
bool sortX(coord c1, coord c2);
bool sortY(coord c1, coord c2);

int main()
{
    size_t n;
    std::cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x[i] >> y[i];
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}

double calcDist(coord c1, coord c2)
{
    return pow(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2), 0.5);
}

double minimal_distance(vector<long long> x, vector<long long> y)
{
    vector<coord> all_coords;
    for (size_t i = 0; i < x.size(); i++)
    {
        coord p;
        p.x = x[i];
        p.y = y[i];
        all_coords.push_back(p);
    }
    vector<coord> x_sorted_coords = all_coords;
    sort(x_sorted_coords.begin(), x_sorted_coords.end(), sortX);
    vector<coord> _x = x_sorted_coords;
    vector<coord> y_sorted_coords = all_coords;
    sort(y_sorted_coords.begin(), y_sorted_coords.end(), sortY);
    double result = calcResult(x_sorted_coords, y_sorted_coords);
    return result;
}

double calcResult(vector<coord> x, vector<coord> y)
{
    if (x.size() == 1)
        return 9999999999999.9;
    else if (x.size() == 2)
        return calcDist(x[0], x[1]);
    else if (x.size() == 3)
        return min(min(calcDist(x[0], x[2]), calcDist(x[0], x[1])), calcDist(x[1], x[2]));

    int mid = x.size() % 2 == 0 ? (x.size() - 1) / 2 : x.size() / 2;
    vector<coord> xl = x, xr = x, yl, yr;
    xl.erase(xl.begin() + mid + 1, xl.end());
    xr.erase(xr.begin(), xr.begin() + mid + 1);
    coord midC = x[mid];
    for (size_t i = 0; i < y.size(); i++)
    {
        if (y[i].x <= midC.x)
            yl.push_back(y[i]);
        else
            yr.push_back(y[i]);
    }

    double d1 = calcResult(xl, yl);
    double d2 = calcResult(xr, yr);
    double d = d1 > d2 ? d2 : d1;

    vector<coord> yFin;
    for (size_t i = 0; i < y.size(); i++)
    {
        if (y[i].x >= mid - d && y[i].x <= mid + d)
            yFin.push_back(y[i]);
    }
    for (size_t i = 0; i < yFin.size(); i++)
    {
        for (size_t j = i + 1; j < min(i + 9, yFin.size()); j++)
        {
            if (yFin[j].y - yFin[i].y > d)
                break;
            double distance = calcDist(yFin[i], yFin[j]);
            d = distance < d ? distance : d;
        }
    }
    return d;
}

bool sortX(coord c1, coord c2)
{
    return c1.x < c2.x;
}
bool sortY(coord c1, coord c2)
{
    return c1.y < c2.y;
}