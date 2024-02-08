class Measurement {
    double x;
    double y;
    double error_matrix[2][2];

public:

    Measurement(double x_in, double y_in, double error_matrix_in[2][2]);
    
    double get_x();

    double get_y();

    void get_error_matrix(double output_matrix[2][2]);

    double get_r();

    double get_error();

    double get_significance();
    
};