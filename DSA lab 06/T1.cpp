#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& d, Node<T>* n = nullptr) : data(d), next(n) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    int counter;

    void clear() {
        Node<T>* curr = head;
        while (curr) {
            Node<T>* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
        head = nullptr;
        counter = 0;
    }

    void copyFrom(const List& other) {
        head = nullptr;
        counter = 0;

        Node<T>* tail = nullptr;
        Node<T>* curr = other.head;

        while (curr) {
            Node<T>* n = new Node<T>(curr->data);
            if (!head) {
                head = n;
                tail = n;
            }
            else {
                tail->next = n;
                tail = n;
            }
            ++counter;
            curr = curr->next;
        }
    }

public:
    List() : head(nullptr), counter(0) {}

    ~List() { clear(); }

    List(const List& other) : head(nullptr), counter(0) { copyFrom(other); }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    bool isEmpty() const { return head == nullptr; }

    Node<T>* gethead() { return head; }

    Node<T>* search(const T& studentID) {
        Node<T>* curr = head;
        while (curr) {
            if (curr->data == studentID) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    void print() const {
        Node<T>* curr = head;
        while (curr) {
            std::cout << curr->data;
            if (curr->next) std::cout << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    void insertAtHead(const T& studentID) {
        head = new Node<T>(studentID, head);
        ++counter;
    }

    void insertAtTail(const T& studentID) {
        Node<T>* n = new Node<T>(studentID);
        if (!head) {
            head = n;
            ++counter;
            return;
        }
        Node<T>* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = n;
        ++counter;
    }

    bool insertAfter(const T& newStudentID, const T& existingStudentID) {
        Node<T>* pos = search(existingStudentID);
        if (!pos) return false;
        pos->next = new Node<T>(newStudentID, pos->next);
        ++counter;
        return true;
    }

    bool insertBefore(const T& newStudentID, const T& existingStudentID) {
        if (!head) return false;

        if (head->data == existingStudentID) {
            insertAtHead(newStudentID);
            return true;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->next;
        while (curr) {
            if (curr->data == existingStudentID) {
                prev->next = new Node<T>(newStudentID, curr);
                ++counter;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    bool remove(const T& studentID) {
        if (!head) return false;

        if (head->data == studentID) {
            Node<T>* del = head;
            head = head->next;
            delete del;
            --counter;
            return true;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->next;
        while (curr) {
            if (curr->data == studentID) {
                prev->next = curr->next;
                delete curr;
                --counter;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    bool removeAfter(const T& studentID) {
        Node<T>* curr = search(studentID);
        if (!curr || !curr->next) return false;

        Node<T>* del = curr->next;
        curr->next = del->next;
        delete del;
        --counter;
        return true;
    }

    bool removeBefore(const T& studentID) {
        if (!head || !head->next) return false;
        if (head->data == studentID) return false;

        Node<T>* prevprev = nullptr;
        Node<T>* prev = head;
        Node<T>* curr = head->next;

        while (curr) {
            if (curr->data == studentID) {
                if (!prevprev) head = curr;
                else prevprev->next = curr;

                delete prev;
                --counter;
                return true;
            }
            prevprev = prev;
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        while (curr) {
            Node<T>* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }

    List sorted_merge(const List& list2) {
        Node<T>* a = head;
        Node<T>* b = list2.head;

        Node<T>* mergedHead = nullptr;
        Node<T>* mergedTail = nullptr;
        int mergedCount = 0;

        auto pushBack = [&](const T& val) {
            Node<T>* n = new Node<T>(val);
            if (!mergedHead) {
                mergedHead = n;
                mergedTail = n;
            }
            else {
                mergedTail->next = n;
                mergedTail = n;
            }
            ++mergedCount;
            };

        while (a && b) {
            if (a->data <= b->data) {
                pushBack(a->data);
                a = a->next;
            }
            else {
                pushBack(b->data);
                b = b->next;
            }
        }
        while (a) { pushBack(a->data); a = a->next; }
        while (b) { pushBack(b->data); b = b->next; }

        clear();
        head = mergedHead;
        counter = mergedCount;

        return *this;
    }


    Node<T>* headPublic() { return head; }
};