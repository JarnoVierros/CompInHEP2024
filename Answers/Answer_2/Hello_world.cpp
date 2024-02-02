#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int input_number = strtol(argv[1], NULL, 0);
    cout << "Hello world " << input_number << endl;
    return 0;
}
