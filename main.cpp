#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <deque>
using namespace std;


class MyClass {
private:
    string data;

public:
    MyClass() : data("") {}
    MyClass(const string& str) : data(str) {}

    bool operator<(const MyClass& other) const {
        return data < other.data;
    }
    bool operator==(const MyClass& other) const {
        return data == other.data;
    }

    bool operator!=(const MyClass& other) const {
        return !(*this == other);
    }

    string getData() const {
        return data;
    }
};

template<typename T, size_t SIZE1,size_t SIZE2>
auto mergeArrays(const array<T, SIZE1>& arr1, const array<T, SIZE2>& arr2) {
    array<T, SIZE1 + SIZE2> result;

    auto iter1 = arr1.begin();
    auto iter2 = arr2.begin();
    auto resultIter = result.begin();

    while (iter1 != arr1.end() && iter2 != arr2.end()) {
        if (*iter1 < *iter2) {
            *resultIter = *iter1;
            ++iter1;
        } else {
            *resultIter = *iter2;
            ++iter2;
        }
        ++resultIter;
    }

    while (iter1 != arr1.end()) {
        *resultIter = *iter1;
        ++iter1;
        ++resultIter;
    }

    while (iter2 != arr2.end()) {
        *resultIter = *iter2;
        ++iter2;
        ++resultIter;
    }

    return result;
}

template<typename T>
pair<vector<T>, vector<T>> splitVector(const vector<T>& input) {
    vector<T> evenNumbers;
    vector<T> oddNumbers;

    for (auto iter = input.begin(); iter != input.end(); ++iter) {
        if (*iter % 2 == 0) {
            evenNumbers.push_back(*iter);
        } else {
            oddNumbers.push_back(*iter);
        }
    }

    return make_pair(evenNumbers, oddNumbers);
}


template<typename T>
bool isPalindrome(const deque<T>& deque) {
    auto frontIter = deque.begin();
    auto backIter = deque.end();
    --backIter;
    while (frontIter < backIter) {
        if (*frontIter != *backIter) {
            return false;
        }
        ++frontIter;
        --backIter;
    }
    return true;
}

int main()
{
    array<int,4> arr1 = {-4,1,5,9};
    array<int,6> arr2 = {-76,-12,2,5,8,9};
    auto mergedIntArrays = mergeArrays(arr1, arr2);

    cout << "Merged integer array:" << endl;
    for (const auto& elem : mergedIntArrays) {
        cout << elem << " ";
    }
    cout << endl;
    cout <<"-------------------------------------------" << endl;
    array<MyClass, 3> arr3 = { MyClass("apple"), MyClass("banana"), MyClass("orange") };
    array<MyClass, 4> arr4 = { MyClass("grape"), MyClass("kiwi"), MyClass("lemon"), MyClass("melon") };

    auto classmerged = mergeArrays(arr3, arr4);

    cout << "Merged array:" << endl;
    for (const auto& item : classmerged) {
        cout << item.getData() << " ";
    }
    cout << endl;

    cout <<"-------------------------------------------" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto result = splitVector(numbers);

    cout << "Even numbers: ";
    for (const auto& num : result.first) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Odd numbers: ";
    for (const auto& num : result.second) {
        cout << num << " ";
    }
    cout << endl;

    cout <<"-------------------------------------------" << endl;

    deque<int> intDeque = {1, 2, 3, 2, 1};
    cout << "Is deque of integers a palindrome? " << boolalpha << isPalindrome(intDeque) << endl;

    deque<string> stringDeque = {"racecar"};
    cout << "Is deque of strings a palindrome? " << boolalpha << isPalindrome(stringDeque) << endl;

    deque<MyClass> items = {MyClass("racecar"), MyClass("caac"), MyClass("b"), MyClass("a") };

    bool palindrome = isPalindrome(items);

    if (palindrome) {
        cout << "The deque is a palindrome." << endl;
    } else {
        cout << "The deque is not a palindrome." << endl;
    }
    cout <<"-------------------------------------------" << endl;


    return 0;
}
