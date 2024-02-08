#include "string"
#include "iostream"

using namespace std;

#include "measurement.h"

void print_array(double array[2][2]) {
    cout << "{{" << array[0][0] << ", " << array[0][1] << "}, {" << array[1][0] << ", " << array[1][1] << "}}";
}

int main() {

    double x = 57.;
    double y = 69.;
    double error_matrix[2][2] = {{0.2,0},{0,0.3}};

    cout << "input values" << endl;
    cout << "x-coordinate: " << x << endl;
    cout << "y-coordinate: " << y << endl;
    cout << "error_matrix: ";
    print_array(error_matrix);
    cout << endl << endl;

    Measurement meas = Measurement(x, y, error_matrix);

    cout << "output values" << endl;

    cout << "x-coordinate: " << meas.get_x() << endl;
    cout << "y-coordinate: " << meas.get_y() << endl;

    double output_matrix[2][2];
    meas.get_error_matrix(output_matrix);

    cout << "error_matrix: ";
    print_array(output_matrix);
    cout << endl;

    cout << "radius: " << meas.get_r() << endl;
    cout << "error: " << meas.get_error() << endl;
    cout << "significance: " << meas.get_significance() << endl;


    return 0;
}