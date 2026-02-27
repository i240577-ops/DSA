#include <iostream>
using namespace std;

// Custom Pair (replacement for std::pair)


template <typename T>
class WeatherMatrix
{
private:
    int rows;
    int cols;
    T** data;
   

public:
    struct Pair
    {
        T first;
        int second;
    };
    // Constructor
    WeatherMatrix(int r, int c)
    {
        rows = r;
        cols = c;

        data = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = T{};
        }
    }

    // Destructor
    ~WeatherMatrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    // Set value
    void setValue(int i, int j, T value)
    {
        data[i][j] = value;
    }

    // Get value
    T getValue(int i, int j) const
    {
        return data[i][j];
    }

    // Rotate matrix 90 degrees clockwise
    void rotate90()
    {
        T** rotated = new T * [cols];
        for (int i = 0; i < cols; i++)
            rotated[i] = new T[rows];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                rotated[j][rows - 1 - i] = data[i][j];

        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        data = rotated;
        int temp = rows;
        rows = cols;
        cols = temp;
    }

    // Add constant to all elements
    void addConstant(T k)
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] += k;
    }

    // Scale all elements
    void scale(int factor)
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] *= factor;
    }

    // Maximum temperature for a day
    Pair dayMax(int dayIndex) const
    {
        Pair result;
        result.first = data[0][dayIndex];
        result.second = 0;

        for (int i = 1; i < rows; i++)
        {
            if (data[i][dayIndex] > result.first)
            {
                result.first = data[i][dayIndex];
                result.second = i;
            }
        }

        return result;
    }
};
