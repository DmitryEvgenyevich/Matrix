#include <iostream>
#include "ClassMatrix.h"

int main()
{
    srand(time(0));

    Matrix A{ 5 };
    Matrix B{ 10 };
    Matrix C{ Matrix{ 4 } };
    std::cout << A.getSize() << "\n\n";

    A.fill(5, 8);
    B = Matrix{ 8 };
    B.fill(5, 8);
    C.fill(5, 8);

    std::cout << "A:\n";
    A.printAllArr();
    std::cout << "B:\n";
    B.printAllArr();
    std::cout << "C:\n";
    C.printAllArr();

    std::cout << A.getValueByIndex(1, 1) << "\n\n";
    A.setValueByIndex(1, 1, 100);
    std::cout << "A:\n";
    A.printAllArr();
    std::cout << "A:\n";
    A++.printAllArr();
    std::cout << "A:\n";
    A.printAllArr();
    
    std::cout << "(A > B) = " << (A > B) << "\n";
    std::cout << "(A < B) = " << (A < B) << "\n";
    std::cout << "(A == C) = " << (A == C) << "\n";
    std::cout << "(A != C) = " << (A != C) << "\n";
    std::cout << "(A >= C) = " << (A >= C) << "\n";
    std::cout << "(A <= C) = " << (A <= C) << "\n";

    C = A;
    std::cout << "A:\n";
    A.printAllArr();
    std::cout << "C:\n";
    C.printAllArr();
    std::cout << "(A == C) = " << (A == C) << "\n";
    

    int*& temp = A[1];
    for (int i{}; i < 5; ++i)
        temp[i] = i;
    
    std::cout << "A:\n";
    A.printAllArr();
    std::cout << "A[0][2] = " << A(0,2);

}
