#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

class DistanceToCity
{
    string name;
    int distance;
public:
    DistanceToCity(){}
    DistanceToCity(string n, int d) :name(n), distance(d){}
    bool operator <(const DistanceToCity right) const;
    string getName() const { return name;}
    int getDistance() const { return distance; }
};

bool DistanceToCity::operator <( const DistanceToCity right) const
{
    return right.distance < this->distance;
}

class DistanceFinder
{
    multimap<string, DistanceToCity> cities;
    typedef multimap<string, DistanceToCity> CityMap;
    multimap<string, DistanceToCity>::iterator Citr, p, stop;
public:
    void set_distance(string from, string to, int distance)
    { // 3 ways to insert into multimap
        cities.insert(pair<string, DistanceToCity>(from, DistanceToCity(to, distance))); //define <string...>
        cities.insert(make_pair(from, DistanceToCity(to, distance)));  // no define <string
        cities.insert(CityMap::value_type(from, DistanceToCity(to, distance))); //value_type
    }
    void find_distance(string start, map<string, int> &shortest)  //???? by reference
    {
        priority_queue<DistanceToCity> que;
        que.push(DistanceToCity(start, 0));
        while (!que.empty())
        {
            DistanceToCity new_city = que.top();
            que.pop();
                if (shortest.count(new_city.getName()) == 0)
                { //not in map begin take from map to queue
                    int d = new_city.getDistance();
                    shortest[new_city.getName()] = d;
                    p = cities.lower_bound(new_city.getName());
                    stop = cities.upper_bound(new_city.getName());
                    while (p != stop)
                    {
                        DistanceToCity next_destination = (*p).second;
                        int total_distance = d + next_destination.getDistance();
                        que.push(DistanceToCity(next_destination.getName(), total_distance));
                        ++p;
                    }
            }
        }
    }
};

int main()
{
    DistanceFinder d;
     d.set_distance("Pendleton", "Phoenix", 4);
     d.set_distance("Pendleton", "Pueblo", 8);
     d.set_distance("Pensacola", "Phoenix", 5);
     d.set_distance("Peoria", "Pittsburgh", 5);
     d.set_distance("Peoria", "Pueblo", 3);
     d.set_distance("Phoenix", "Peoria", 4);
     d.set_distance("Phoenix", "Pittsburgh", 10);
     d.set_distance("Phoenix", "Pueblo", 3);
     d.set_distance("Pierre", "Pendleton", 2);
     d.set_distance("Pittsburgh", "Pensacola", 4);
     d.set_distance("Princeton", "Pittsburgh", 2);
     d.set_distance("Pueblo", "Pierre", 3);

     map<string, int> shortest;
     d.find_distance("Pierre", shortest);
     map<string, int>::iterator current = shortest.begin();
     map<string, int>::iterator stop = shortest.end();
     while (current != stop) {
       pair<string, int> p = *current;
       cout << "distance to " << p.first << " is " << p.second << "\n";
       ++current;
     }
     return 0;
}
