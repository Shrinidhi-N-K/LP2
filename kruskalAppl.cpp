#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge between two cities
struct Road {
    int city1, city2, cost;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

class CityNetwork {
    int numCities; // Number of cities
    vector<Road> roads; // Vector to store roads

public:
    CityNetwork(int numCities) : numCities(numCities) {}

    // Function to add a road to the city network
    void addRoad(int city1, int city2, int cost) {
        Road road = {city1, city2, cost};
        roads.push_back(road);
    }

    // Function to find the parent of a city (with path compression)
    int find(vector<Subset>& subsets, int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    // Function to perform union of two subsets (by rank)
    void Union(vector<Subset>& subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    // Function to apply Kruskal's algorithm to find the minimum cost of building roads to connect all cities
    int findMinimumCostOfRoads() {
        vector<Road> result; // Stores the result roads
        int totalCost = 0; // Total cost of building roads
        int e = 0; // Index variable for sorted edges
        int i = 0; // Index variable for result vector

        // Step 1: Sort all the roads in non-decreasing order of their cost
        sort(roads.begin(), roads.end(), [](const Road& a, const Road& b) {
            return a.cost < b.cost;
        });

        // Allocate memory for creating numCities subsets
        vector<Subset> subsets(numCities);
        for (int v = 0; v < numCities; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        // Number of roads to be built is equal to numCities - 1
        while (e < numCities - 1 && i < roads.size()) {
            Road next_road = roads[i++];

            int x = find(subsets, next_road.city1);
            int y = find(subsets, next_road.city2);

            if (x != y) {
                result.push_back(next_road);
                Union(subsets, x, y);
                ++e;
                totalCost += next_road.cost;
            }
        }

        // Print the roads needed to connect all cities
        cout << "Minimum cost of building roads to connect all cities:\n";
        for (i = 0; i < result.size(); ++i)
            cout << "Road between city " << result[i].city1 << " and " << result[i].city2 << ", Cost: " << result[i].cost << endl;

        return totalCost;
    }
};

int main() {
    // Create a city network with 4 cities
    int numCities = 4;
    CityNetwork network(numCities);

    // Add roads along with their costs
    network.addRoad(0, 1, 10);
    network.addRoad(0, 2, 6);
    network.addRoad(0, 3, 5);
    network.addRoad(1, 3, 15);
    network.addRoad(2, 3, 4);

    // Find the minimum cost of building roads to connect all cities
    int minimumCost = network.findMinimumCostOfRoads();

    // Print the total minimum cost
    cout << "Total minimum cost of building roads to connect all cities: " << minimumCost << endl;

    return 0;
}
