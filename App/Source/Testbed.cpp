// (c) Spyridon Zervos


#include<iostream>
#include <vector>

#include "Bitstreams/Bitstream.h"
#include "CartesianCoordinates/CartesianCoordinates2D.h"
#include "ComplexNumbers/ComplexNumbers.h"
//#include "Modulation/BPSK.h"
#include "Modulation/BPSK.h"
#include "PolarCoordinates/PolarCoordinates.h"

template<std::size_t N, class T>
constexpr std::size_t countof(T(&)[N]) { return N; }

void CheckCartesian();
void CheckPolar();
void CheckComplex();
void CheckBitstreams();
void CheckModulations();

int main(int argc, char* argv[])
{
    std::cout << "/******* CHECKING CARTESIAN COORDINATES LIB *******/" << '\n';
    CheckCartesian();
    std::cout << '\n';

    std::cout << "/******* CHECKING POLAR COORDINATES LIB *******/" << '\n';
    CheckPolar();
    std::cout << '\n';

    std::cout << "/******* CHECKING COMPLEX NUMBERS LIB *******/" << '\n';
    CheckComplex();
    std::cout << '\n';

    std::cout << "/******* CHECKING BITSTREAM LIB *******/" << '\n';
    CheckBitstreams();
    std::cout << '\n';

    std::cout << "/******* CHECKING MODULATIONS LIB *******/" << '\n';
    CheckModulations();
    std::cout << '\n';
    
    return 0;
}

void CheckCartesian()
{
    /** INITIALIZATION TESTING */
    std::cout << "/**** INITIALIZATION TESTING ****/" << '\n';
    
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
    std::cout << "/**** OPERATOR TESTING ****/" << '\n';

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
    std::cout << "/**** INITIALIZATION TESTING ****/" << '\n';
    
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
    std::cout << "/**** OPERATOR TESTING ****/" << '\n';

    Z = X * Y;
    std::cout << "Z = Χ * Υ = ";
    Z.Print();
    std::cout << '\n';

    const PolarCoordinates K = Z / Z;
    std::cout << "K = Z / Z = ";
    K.Print();
    std::cout << "\n";
}

void CheckComplex()
{
    std::cout << "/**** FUNCTIONALITY TESTING OF COMPLEX NUMBERS ****/\n";

    std::cout << "Test 1: Initialization of a Complex." << '\n';
    ComplexNumbers A = { 3, 1 };
    std::cout << "A = ";
    A.Print();
    std::cout << '\n';
    std::cout << "Polar form of A = ";
    A.PolarForm->Print();
    std::cout << '\n';

    ComplexNumbers B = { 4, -5 };
    std::cout << "B = ";
    B.Print();
    std::cout << '\n';
    std::cout << "Polar form of B = ";
    B.PolarForm->Print();
    std::cout << '\n';

    std::cout << '\n';
    std::cout << "Test 2: Operations between Complexes." << '\n';
    
    ComplexNumbers C = (A + B) * 2;
    std::cout << "C = (A + B) * 2 = ";
    C.Print();
    std::cout << '\n';
    std::cout << "Polar form of C = ";
    C.PolarForm->Print();
    std::cout << '\n';

    ComplexNumbers D = ComplexNumbers{ 1, 2 } / ComplexNumbers{ 0.5, -0.1 };
    std::cout << "D = (1+2i)/(0.5-i) = ";
    D.Print();
    std::cout << '\n';
    std::cout << "Polar form of D = ";
    D.PolarForm->Print();
    std::cout << '\n';

    ComplexNumbers E = C - D;
    std::cout << "E = C - D = ";
    E.Print();
    std::cout << '\n';
    std::cout << "Polar form of E = ";
    E.PolarForm->Print();
    std::cout << '\n';

    std::cout << "\nTest 3: Initialization of Polar Coordinates." << '\n';
    ComplexNumbers W = {1, 90, true};
    std::cout << "W = ";
    W.Print();
    std::cout << '\n';
    std::cout << "Polar form of W = ";
    W.PolarForm->Print();
    std::cout << '\n';
}

void CheckBitstreams()
{
    constexpr double DoubleArray[] = {-1, 0, 0.5, 1, 2, 3, 4, 5, 6, 7, 10, 1024};
    std::cout << "Initial data of array is:\n";
    for (const double& Num : DoubleArray)
    {
        std::cout << Num << " ";
    }
    std::cout << '\n';
    
    Bitstream Bits{DoubleArray};
    std::vector<double> Nums;

    std::cout << "Binary data contained in Bits:\n";
    Bits.PrintBinary();

    Bits.Data2Obj(Nums);
    std::cout << "Conversion of binary data to double yields the following:\n";
    for (const double& Num : Nums)
    {
        std::cout << Num << " ";
    }
    std::cout << '\n';
}

void CheckModulations()
{
    std::cout << "Modulation scheme: ";
    std::cout << BPSK::GetBPSKSystem().GetModulationName() << '\n';

    std::cout << "Spectral Efficiency =";
    std::cout << BPSK::GetBPSKSystem().GetSpectralEfficiency() << '\n';

    constexpr double Data[] = {-1, 0, 0.5, 1, 2, 3, 4, 5, 6, 7, 10, 1024};
    Bitstream Bytes{Data};
    
    std::vector<ComplexNumbers> Symbols;
    BPSK::GetBPSKSystem().ConvertToSymbols(&Bytes, Symbols);

    Bitstream Bytes2{};
    BPSK::GetBPSKSystem().ConvertToBinary(Symbols, Bytes2);
    
    std::vector<double> Nums;
    Bytes2.Data2Obj(Nums);

    std::cout << "Conversion double2binary then applying BPSK modulation (binary2symbol) and demodulation (symbol2binary) then binary2double yields the following:\n";
    for (const double& Num : Nums)
    {
        std::cout << Num << " ";
    }
    std::cout << '\n';

    std::cout << "And original data was:\n";
    for (const double& Num : Data)
    {
        std::cout << Num << " ";
    }
    std::cout << '\n';
}
