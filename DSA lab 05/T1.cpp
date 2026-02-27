#include <iostream>
#include <string>

using namespace std;
template <typename T>
class List {
private:
    T* arr;
    int capacity;
    int counter;

    void shiftRightFrom(int index) {
        for (int i = counter; i > index; i--) {
            arr[i] = arr[i - 1];
        }
    }

    void shiftLeftFrom(int index) {
        for (int i = index; i < counter - 1; i++) {
            arr[i] = arr[i + 1];
        }
    }

public:
    List(int cap) : arr(nullptr), capacity(cap), counter(0) {
        if (capacity < 0) {
            capacity = 0;
        }
        arr = (capacity > 0) ? new T[capacity] : nullptr;
    }

    ~List() {
        delete[] arr;
    }

    List(const List& other) : arr(nullptr), capacity(other.capacity), counter(other.counter) {
        arr = (capacity > 0) ? new T[capacity] : nullptr;
        for (int i = 0; i < counter; ++i) {
            arr[i] = other.arr[i];
        }
    }

    bool isEmpty() const {
        return counter == 0;
    }
    bool isFull() const {
        return counter == capacity;
    }

    int search(T studentID) const {
        for (int i = 0; i < counter; ++i) {
            if (arr[i] == studentID) {
                return i;
            }
        }
        return -1;
    }

    void insert(T studentID) {
        if (isFull()) {
            return;
        }
        arr[counter++] = studentID;
    }

    void insertAt(T studentID, int index) {
        if (isFull()) {
            return;
        }
        if (index < 0 || index > counter) return;
        shiftRightFrom(index);
        arr[index] = studentID;
        counter++;
    }

    void insertAfter(T newStudentID, T existingStudentID) {
        if (isFull()) return;
        int idx = search(existingStudentID);
        if (idx == -1) return;
        insertAt(newStudentID, idx + 1);
    }

    void insertBefore(T newStudentID, T existingStudentID) {
        if (isFull()) return;
        int idx = search(existingStudentID);
        if (idx == -1) return;
        insertAt(newStudentID, idx);
    }

    void remove(T studentID) {
        int idx = search(studentID);
        if (idx == -1) return;
        shiftLeftFrom(idx);
        counter--;
    }

    void removeBefore(T studentID) {
        int idx = search(studentID);
        if (idx <= 0) return;
        shiftLeftFrom(idx - 1);
        --counter;
    }

    void removeAfter(T studentID) {
        int idx = search(studentID);
        if (idx == -1) return;
        if (idx >= counter - 1) return;
        shiftLeftFrom(idx + 1);
        --counter;
    }

    void reverse() {
        int i = 0, j = counter - 1;
        while (i < j) {
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    void print() const {
        for (int i = 0; i < counter; ++i) {
            cout << arr[i];
            if (i + 1 < counter) std::cout << " ";
        }
        cout << endl;
    }

    ////////////////////////

    void rotateLeft(int k) {
        if (counter <= 1) return;
        if (k < 0) return;
        k %= counter;
        if (k == 0) return;

        T* temp = new T[k];
        for (int i = 0; i < k; ++i) temp[i] = arr[i];
        for (int i = k; i < counter; ++i) arr[i - k] = arr[i];
        for (int i = 0; i < k; ++i) arr[counter - k + i] = temp[i];
        delete[] temp;
    }

    void sort(bool ascending = true) {
        for (int i = 0; i < counter - 1; ++i) {
            int best = i;
            for (int j = i + 1; j < counter; ++j) {
                if (ascending) {
                    if (arr[j] < arr[best]) best = j;
                }
                else {
                    if (arr[j] > arr[best]) best = j;
                }
            }
            if (best != i) {
                T tmp = arr[i];
                arr[i] = arr[best];
                arr[best] = tmp;
            }
        }
    }

    void removeDuplicates() {
        for (int i = 0; i < counter; ++i) {
            for (int j = i + 1; j < counter; ) {
                if (arr[j] == arr[i]) {
                    shiftLeftFrom(j);
                    --counter;
                }
                else {
                    ++j;
                }
            }
        }
    }

    List subList(int start, int end) const {
        List result(0);
        if (start < 0 || end < 0 || start > end) return result;
        if (start >= counter) return result;
        if (end >= counter) end = counter - 1;

        int newCap = end - start + 1;
        result = List(newCap);
        for (int i = start; i <= end; ++i) result.insert(arr[i]);
        return result;
    }

    T findMax() const {
        if (counter == 0) return T();
        T mx = arr[0];
        for (int i = 1; i < counter; ++i) {
            if (arr[i] > mx) mx = arr[i];
        }
        return mx;
    }

    T findMin() const {
        if (counter == 0) return T();
        T mn = arr[0];
        for (int i = 1; i < counter; ++i) {
            if (arr[i] < mn) mn = arr[i];
        }
        return mn;
    }

    void replace(T oldValue, T newValue) {
        for (int i = 0; i < counter; ++i) {
            if (arr[i] == oldValue) arr[i] = newValue;
        }
    }
    
};

/////////////////////////////////////////////////////





    // ---------------- Task 2 Added Operations ----------------