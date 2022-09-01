#include <iostream>
#include "ClassMatrix.h"

int main()
{
    srand(time(0));

    Matrix<int> A{ 5 };
    Matrix<int> B{ 10 };
    Matrix<int> C{ Matrix<int>{ 4 } };
    std::cout << A.getSize() << "\n\n";

    //A.fill(5, 8);
    for (int i{}; i < A.getSize(); ++i)
        for (int j{}; j < A.getSize(); ++j)
            A.setValueByIndex(i, j, 0 + rand() % (10 - 0 + 1));

    B = Matrix<int>{ 8 };
    //B.fill(5, 8);
    for (int i{}; i < B.getSize(); ++i)
        for (int j{}; j < B.getSize(); ++j)
            B.setValueByIndex(i, j, 0 + rand() % (10 - 0 + 1));

    //C.fill(5, 8);
    for (int i{}; i < C.getSize(); ++i)
        for (int j{}; j < C.getSize(); ++j)
            C.setValueByIndex(i, j, 0 + rand() % (10 - 0 + 1));

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
