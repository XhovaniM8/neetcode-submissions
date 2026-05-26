#include <string>
using namespace std;

class Singleton {
private:   
    static Singleton* instance;
    string value;
    
    // Private constructor ensures no outside instantiation
    Singleton() : value("") {}

public:
    // Static method to access the single instance
    static Singleton *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    string getValue() {
        return value;
    }

    // Fixed the assignment logic here
    void setValue(string val) {
        value = val;
    }
};

// Initialize the static pointer to nullptr
Singleton* Singleton::instance = nullptr;