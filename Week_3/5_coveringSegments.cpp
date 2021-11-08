#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments, int n);
bool sortSegment(Segment i, Segment j);

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments, n);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}

vector<int> optimal_points(vector<Segment> &segments, int n)
{
    vector<int> points;
    std::sort(segments.begin(), segments.end(), sortSegment);
    int point = segments[0].end;
    points.push_back(point);
    for (int i = 1; i < n; i++)
    {
        if (point < segments[i].start || point > segments[i].end)
        {
            point = segments[i].end;
            points.push_back(point);
        }
    }
    return points;
}

bool sortSegment(Segment i, Segment j)
{
    return (i.end < j.end);
}