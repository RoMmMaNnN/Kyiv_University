#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class planet {
private:
    int moons;
    long long dist_from_sun;
    double diameter;
    double mass_in_tons;

public:
    planet(long long distance, double diam, double mass_tons, int num_moons) {
        dist_from_sun = distance;
        diameter = diam;
        mass_in_tons = mass_tons;
        moons = num_moons;
    }

    long long get_miles() const { return dist_from_sun; }

    void display_info() const {
        cout << "Distance from Sun: " << dist_from_sun << " miles\n";
        cout << "Diameter: " << diameter << " miles\n";
        cout << "Mass: " << mass_in_tons << " tons\n";
        cout << "Moons: " << moons << endl;
    }
};

double light(const planet &p) {
    const long double speed_of_light = 186000.0L;
    return p.get_miles() / speed_of_light;
}

planet generate_planet() {
    long long distance = 50000000 + rand() % 850000000;
    double diameter = 3000 + rand() % 77000;
    double mass = 1e21 + rand() % static_cast<long long>(9.99e26);
    int moons = rand() % 101;

    return planet(distance, diameter, mass, moons);
}

int main() {
    srand(time(0));

    planet planet = generate_planet();

    cout << "Random planet characteristics:\n";
    planet.display_info();
    cout << "Time for light to " << light(planet) << " seconds" << endl;

    return 0;
}
