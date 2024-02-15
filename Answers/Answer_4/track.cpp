
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class Track {

    protected:

        double E;
        double p_x;
        double p_y;
        double p_z;

    public:

        Track(double in_E=0, double in_p_x=0, double in_p_y=0, double in_p_z=0) {
            E = in_E;
            p_x = in_p_x;
            p_y = in_p_y;
            p_z = in_p_z;
        }

        double get_E() {
            return E;
        }

        double get_p_x() {
            return p_x;
        }

        double get_p_y() {
            return p_y;
        }

        double get_p_z() {
            return p_z;
        }

        double get_pT() {
            return sqrt(p_x*p_x + p_y*p_y);
        }

        double get_p() {
            return sqrt(p_x*p_x + p_y*p_y + p_z*p_z);
        }

        double get_theta() {
            return acos(p_z/get_p());
        }

        double get_eta() {
            return -1*log(tan(get_theta()/2));
        }
    
};

class Particle: public Track {

    private:

        //It would probably be better to have these as integers, but for the exercise using strings is more convenient.
        string particle_id;
        string parent_particle_id;

    public:

        Particle(double in_E, double in_p_x, double in_p_y, double in_p_z, string in_particle_id, string in_parent_particle_id) : Track(in_E, in_p_x, in_p_y, in_p_z) {
            particle_id = in_particle_id;
            parent_particle_id = in_parent_particle_id;
        }

        string get_particle_id() {
            return particle_id;
        }

        string get_parent_particle_id() {
            return parent_particle_id;
        }

};

void test() {

    cout << "Creating a track with 4-momentum (16, 2, 9, 5)" << endl << endl;
    Track random_track = Track(16, 2, 9, 5);

    cout << "Getting the four momentum through getters:" << endl;
    cout << "(" << random_track.get_E() << ", " << random_track.get_p_x() << ", " << random_track.get_p_y() << ", " << random_track.get_p_z() << ")" << endl;

    cout << "Transverse momentum: " << random_track.get_pT() << endl;
    cout << "Pseudorapidity: " << random_track.get_eta() << endl << endl;

    cout << "Creating a pion originating from a rho meson with 4-momentum (23, 1, 3, 12)" << endl << endl;
    Particle random_particle = Particle(23, 1, 3, 12, "pion", "rho");

    cout << "Four momentum: (" << random_particle.get_E() << ", " << random_particle.get_p_x() << ", " << random_particle.get_p_y() << ", " << random_particle.get_p_z() << ")" << endl;
    cout << "Transverse momentum: " << random_particle.get_pT() << endl;
    cout << "Pseudorapidity: " << random_particle.get_eta() << endl;
    cout << "Particle id: " << random_particle.get_particle_id() << endl;
    cout << "Parent particle id: " << random_particle.get_parent_particle_id() << endl;

}

int main() {
    test();
}

