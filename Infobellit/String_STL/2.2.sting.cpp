#include <iostream>
#include <cstring> // For strlen, strcpy, etc. - allowed since it's part of C library
using namespace std;


class MyString {
private:
    char* data;    // Pointer to dynamically allocated array of characters
    size_t length; // Length of the string (excluding null terminator)

public:
    // Constructor (from C-string)
    MyString(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1]; // +1 for '\0'
        strcpy(data, str);
    }

    // Copy Constructor
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // Move Constructor
    MyString(MyString&& other) noexcept {
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Assignment Operator (Copy)
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;

            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // Assignment Operator (Move)
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }

    // Concatenation (operator+)
    MyString operator+(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // Accessor
    char& operator[](size_t index) {
        return data[index];
    }

    const char& operator[](size_t index) const {
        return data[index];
    }

    // Length Getter
    size_t size() const {
        return length;
    }

    // Print function
    void print() const {
        cout << data;
    }

    // === New Functions ===

    // stoi() - String to Integer
    int stoi() const {
        int value = 0;
        int sign = 1;
        size_t i = 0;

        while (data[i] == ' ' || data[i] == '\t') ++i;  // skip leading spaces

        if (data[i] == '-') { sign = -1; ++i; }
        else if (data[i] == '+') { ++i; }

        while (data[i] >= '0' && data[i] <= '9') {
            value = value * 10 + (data[i] - '0');
            ++i;
        }
        return value * sign;
    }

    // stof() - String to Float
    float stof() const {
        float value = 0.0f;
        float sign = 1.0f;
        size_t i = 0;

        while (data[i] == ' ' || data[i] == '\t') ++i;  // skip leading spaces

        if (data[i] == '-') { sign = -1.0f; ++i; }
        else if (data[i] == '+') { ++i; }

        // Integer part
        while (data[i] >= '0' && data[i] <= '9') {
            value = value * 10.0f + (data[i] - '0');
            ++i;
        }

        // Decimal part
        if (data[i] == '.') {
            ++i;
            float decimalPlace = 0.1f;
            while (data[i] >= '0' && data[i] <= '9') {
                value += (data[i] - '0') * decimalPlace;
                decimalPlace *= 0.1f;
                ++i;
            }
        }
        return value * sign;
    }

    
};

int main() {
    
    MyString s1("Hello");
    MyString s2(" World!");

    MyString s3 = s1 + s2; // Concatenation

    s3.print(); // Output: Hello World

    s3[6] = 'W';
    cout << "\nModified: ";
    s3.print(); // Output: Hello World (no change for now)

    MyString s4 = s3; // Copy constructor
    cout << "\nCopied: ";
    s4.print();
    cout << endl;


    MyString s5("Hello");
    const MyString s6("World");

    // Non-const string: Can modify characters
    s5[1] = 'a';  // Works because it calls: `char& operator[]`

    // Const string: Can only read characters
    char ch = s6[1];  // Works because it calls: `const char& operator[] const`
    cout << "ch : " << ch << endl;

    MyString s7("12345");
    MyString s8("-45.678");

    cout << "s7 as int: " << s7.stoi() << "\n";
    cout << "s8 as float: " << s8.stof() << "\n";

    return 0;
}
