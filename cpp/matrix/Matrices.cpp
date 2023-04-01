#include "Matrix.h" //iostream is there


int main()
{
    double** mtrx1 = new double* [2]{ new double[3]{2, 5, 8}, new double[3]{4, 7, 9} };
    double** mtrx2 = new double* [3]{ new double[2]{4, 4}, new double[2]{7, 9}, new double[2]{4, 4} };
    {
        Matrix lilOne(mtrx1, 2, 3), anotherLilOne(mtrx2, 3, 2);
        std::cout << lilOne * anotherLilOne;
    }
    std::cout << "This is the End. My only friend, the end...\n";
}