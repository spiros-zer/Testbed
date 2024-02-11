// (c) Spyridon Zervos


#include<iostream>

#include "CartesianCoordinates/CartesianCoordinates2D.h"
#include "PolarCoordinates/PolarCoordinates.h"

void CheckCartesian();
void CheckPolar();

int main(int argc, char* argv[])
{
    std::cout << "/**** CHECKING CARTESIAN COORDINATES LIB" << '\n';
    CheckCartesian();

    std::cout << "/**** CHECKING POLAR COORDINATES LIB" << '\n';
    CheckPolar();
    
    return 0;
}

void CheckCartesian()
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
}

void CheckPolar()
{
    /**** INITIALIZATION TESTTING */
    std::cout << "/**** INITIALIZATION TESTING */" << '\n';
    
    const PolarCoordinates X(1, 90);
    std::cout << "X ";
    X.Print();
    std::cout << '\n';

    const PolarCoordinates Y(4, 180);
    std::cout << "Y ";
    Y.Print();
    std::cout << '\n';

    PolarCoordinates Z(1, 0);
    std::cout<< "Z ";
    Z.Print();
    std::cout << '\n';

    /**** OPERATOR TESTING */
    std::cout << "/**** OPERATOR TESTING */" << '\n';

    Z = X * Y;
    std::cout << "Z = Χ * Υ = ";
    Z.Print();
    std::cout << '\n';

    const PolarCoordinates K = Z / Z;
    std::cout << "K = Z / Z = ";
    K.Print();
    std::cout << "\n";
}
