// (c) Spyridon Zervos


#include<iostream>

#include "Core\CartesianCoordinates2D.h"

int main(int argc, char* argv[])
{
    /** INITIALIZATION TESTING */
    std::cout << "/** INITIALIZATION TESTING */" << '\n';
    
    const CartesianCoordinates2D PointA(-0.56, -10.09);
    std::cout << "PointA ";
    PointA.Print();
    std::cout << '\n';
    
    const CartesianCoordinates2D PointB(2.57, 100);
    std::cout << "PointB ";
    PointB.Print();
    std::cout << '\n';
    
    CartesianCoordinates2D PointC{};
    std::cout << "PointC ";
    PointC.Print();
    std::cout << '\n';

    /** OPERATOR TESTING */
    std::cout << "/** OPERATOR TESTING */" << '\n';

    PointC = PointB - PointA;
    std::cout << "PointC = PointB - PointA = ";
    PointC.Print();
    std::cout << '\n';
    
    const CartesianCoordinates2D PointD = PointA + PointC;
    std::cout << "PointD = PointA + PointC =";
    PointD.Print();
    std::cout << '\n';
    
    return 0;
}
