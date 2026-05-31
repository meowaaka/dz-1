#include <iostream>
using namespace std;

#define POWER(base, exp) (pow((base), (exp)))

#define SQRT(num) (sqrt((num)))

#define MULTIPLY3(a, b, c) ((a) * (b) * (c))

int main() {
    double x = 2.0;
    double y = 9.0;
    int a = 2, b = 3, c = 4;

    cout << "2^3 = " << POWER(x, 3) << endl;
    cout << "sqrt(9) = " << SQRT(y) << endl;
    cout << "2 * 3 * 4 = " << MULTIPLY3(a, b, c) << endl;

    return 0;
}
