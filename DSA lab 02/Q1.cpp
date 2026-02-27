#include <iostream>
#include <string>
using namespace std;
template <typename T>
class ParkingLot {
private:
    int rows, cols;
    T** grid;
    bool** occupied;

    bool inBounds(int r, int c) const {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }

public:
    ParkingLot(int r, int c) : rows(r), cols(c) {
        if (rows <= 0) rows = 1;
        if (cols <= 0) cols = 1;

        grid = new T * [rows];
        occupied = new bool* [rows];

        for (int i = 0; i < rows; i++) {
            grid[i] = new T[cols];
            occupied[i] = new bool[cols];
            for (int j = 0; j < cols; j++) {
                occupied[i][j] = false;
            }
        }
    }

    ~ParkingLot() {
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
            delete[] occupied[i];
        }
        delete[] grid;
        delete[] occupied;
    }

    bool parkSlot(int r, int c, const T& value) {
        if (!inBounds(r, c)) return false;
        grid[r][c] = value;
        occupied[r][c] = true;
        return true;
    }

    bool removeVehicle(int r, int c) {
        if (!inBounds(r, c)) return false;
        occupied[r][c] = false;
        return true;
    }

    bool isAvailable(int r, int c) const {
        if (!inBounds(r, c)) return false;
        return !occupied[r][c];
    }

    bool getSlot(int r, int c, T& outValue) const {
        if (!inBounds(r, c)) return false;
        if (!occupied[r][c]) return false;
        outValue = grid[r][c];
        return true;
    }

    void printParkingLot() const {
        
        cout << "ParkingLot (" << rows << "x" << cols << ")\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (occupied[i][j]) cout << grid[i][j] << "\t";
                else cout << "-\t";
            }
            cout << "\n";
        }
    }
};

template <>
class ParkingLot<bool> {
private:
    int rows, cols;
    bool** grid;

    bool inBounds(int r, int c) const {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }

public:
    ParkingLot(int r, int c) : rows(r), cols(c) {
        if (rows <= 0) rows = 1;
        if (cols <= 0) cols = 1;

        grid = new bool* [rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = new bool[cols];
            for (int j = 0; j < cols; j++) {
                grid[i][j] = false;
            }
        }
    }

    ~ParkingLot() {
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    bool parkSlot(int r, int c, bool value) {
        if (!inBounds(r, c)) return false;
        grid[r][c] = value;
        return true;
    }

    bool removeVehicle(int r, int c) {
        if (!inBounds(r, c)) return false;
        grid[r][c] = false;
        return true;
    }

    bool isAvailable(int r, int c) const {
        if (!inBounds(r, c)) return false;
        return (grid[r][c] == false);
    }

    bool getSlot(int r, int c, bool& outValue) const {
        if (!inBounds(r, c)) return false;
        outValue = grid[r][c];
        return true;
    }

    void printParkingLot() const {
        cout << "ParkingLot<bool> (" << rows << "x" << cols << ")\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << (grid[i][j] ? 'P' : '-') << ' ';
            }
            cout << "\n";
        }
    }
};

