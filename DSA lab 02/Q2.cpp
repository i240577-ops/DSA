#include <iostream>
using namespace std;

template <typename T>
class InventoryWallet {
private:
    T currentQuantity;
    T* removals;
    T* additions;

    int numOfOperations;
    int counterRemovals;
    int counterAdditions;

public:
    // Constructor
    InventoryWallet(T initialQuantity, int allowedOps): currentQuantity(initialQuantity),numOfOperations(allowedOps),counterRemovals(0),counterAdditions(0){
        if (numOfOperations <= 0) numOfOperations = 1;

        removals = new T[numOfOperations];
        additions = new T[numOfOperations];

        for (int i = 0; i < numOfOperations; i++) {
            removals[i] = (T)0;
            additions[i] = (T)0;
        }
    }

    // Destructor
    ~InventoryWallet() {
        delete[] removals;
        delete[] additions;
    }

    bool isRemovalAllowed() const {
        return counterRemovals < numOfOperations;
    }

    bool isAdditionAllowed() const {
        return counterAdditions < numOfOperations;
    }

    bool removeItems(T value) {
        if (value < (T)0) return false;
        if (!isRemovalAllowed()) return false;
        if (value > currentQuantity) return false;

        currentQuantity = currentQuantity - value;
        removals[counterRemovals] = value;
        counterRemovals++;
        return true;
    }

    bool addItems(T value) {
        if (value < (T)0) return false;
        if (!isAdditionAllowed()) return false;

        currentQuantity = currentQuantity + value;
        additions[counterAdditions] = value;
        counterAdditions++;
        return true;
    }

    T getCurrentQuantity() const {
        return currentQuantity;
    }

    void print() const {
        cout << "Current Quantity: " << currentQuantity << "\n";
        cout << "Additions used: " << counterAdditions << "/" << numOfOperations
            << ", Removals used: " << counterRemovals << "/" << numOfOperations << "\n";
    }
};
