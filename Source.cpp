#include <iostream>
using namespace std;

struct Fraction
{
    int numerator;
    int denominator;
};

void writeFractions(const char* filename, Fraction* arr, int size)
{
    FILE* file;
    if (fopen_s(&file, filename, "wb") == 0)
    {
        fwrite(reinterpret_cast<void*>(arr), sizeof(Fraction), size, file);
        fclose(file);
    }
    else
    {
        cout << "Unable to open the file for reading!" << endl;
    }
}

void readFractions(const char* filename, Fraction* arr, int size)
{
    FILE* file;
    if (fopen_s(&file, filename, "rb") == 0)
    {
        fread(reinterpret_cast<void*>(arr), sizeof(Fraction), size, file);
        fclose(file);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i].numerator << "/" << arr[i].denominator << endl;
        }
    }
    else
    {
        cout << "Unable to open the file for reading!" << endl;
    }
}

int main()
{
    const unsigned int N = 5;
    Fraction fractions[N] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}
    };

    writeFractions("fractions.bin", fractions, N);

    Fraction loaded[N];

    readFractions("fractions.bin", loaded, N);

    return 0;
}
