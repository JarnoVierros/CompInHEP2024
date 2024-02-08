#include <math.h>
using namespace std;

#include "measurement.h"

Measurement::Measurement(double x_in, double y_in, double error_matrix_in[2][2]) {
    x = x_in;
    y = y_in;
    error_matrix[0][0] = error_matrix_in[0][0];
    error_matrix[0][1] = error_matrix_in[0][1];
    error_matrix[1][0] = error_matrix_in[1][0];
    error_matrix[1][1] = error_matrix_in[1][1];
}

double Measurement::get_x() {
    return x;
}

double Measurement::get_y() {
    return y;
}

void Measurement::get_error_matrix(double output_matrix[2][2]) {
    output_matrix[0][0] = error_matrix[0][0];
    output_matrix[0][1] = error_matrix[0][1];
    output_matrix[1][0] = error_matrix[1][0];
    output_matrix[1][1] = error_matrix[1][1];
}

double Measurement::get_r() {
    return sqrt(x*x + y*y);
}

double Measurement::get_error() {
    return abs(get_r() - sqrt(pow(x + sqrt(error_matrix[0][0]), 2) + pow(y + sqrt(error_matrix[1][1]), 2)));
}

double Measurement::get_significance() {
    return get_r()/get_error();
}

/*
class Measurement {
    public:
        double x;
        double y;
        double error_matrix[2][2];
    
        Measurement(double x_in, double y_in, double error_matrix_in[2][2]) {
            x = x_in;
            y = y_in;
            error_matrix[0][0] = error_matrix_in[0][0];
            error_matrix[0][1] = error_matrix_in[0][1];
            error_matrix[1][0] = error_matrix_in[1][0];
            error_matrix[1][1] = error_matrix_in[1][1];
        }
        
        double get_x() {
            return x;
        }

        double get_y() {
            return y;
        }

        void get_error_matrix(double output_matrix[2][2]) {
            output_matrix[0][0] = error_matrix[0][0];
            output_matrix[0][1] = error_matrix[0][1];
            output_matrix[1][0] = error_matrix[1][0];
            output_matrix[1][1] = error_matrix[1][1];
        }

        double get_r() {
            return sqrt(x*x + y*y);
        }

        double get_error() {
            return abs(get_r() - sqrt(pow(x + sqrt(error_matrix[0][0]), 2) + pow(y + sqrt(error_matrix[1][1]), 2)));
        }

        double get_significance() {
            return get_r()/get_error();
        }
};
*/