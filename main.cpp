#include <iostream>
#include "figure.h"

using namespace std;

int main()
{
    Figure f = Figure();
    float perimeter = f.calcPerimeter();

    cout << "Perimeter:\t" << perimeter << endl;
    return 0;
}
