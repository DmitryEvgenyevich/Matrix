#include <iostream>
#include "ClassMatrix.h"

int main()
{
    srand(time(0));

    Matrix A{5};
    std::cout << A.getSize() << "\n\n";
    A.fill(5, 8);
    A.printAllArr();
    std::cout << A.getValueByIndex(1, 1) << "\n\n";
    A.setValueByIndex(1, 1, 100);
    A.printAllArr();

    A++.printAllArr();
    A.printAllArr();
}