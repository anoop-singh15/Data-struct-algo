#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function
bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second > b.second; // If first elements are equal, sort by second in descending order
    }
    return a.first > b.first; // Sort by first element in descending order
}

int main() {
    vector<pair<int, int>> vec = {{3, 4}, {5, 2}, {3, 8}, {5, 10}, {5, 7}, {2, 9}};

    // Sorting using custom comparator
    sort(vec.begin(), vec.end(), customComparator);

    // Displaying the sorted vector
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}



// 1 Sorting Pairs Based on First Element (Ascending Order)

// bool compFirstAsc(const pair<int, int>& a, const pair<int, int>& b) {
//     return a.first < b.first;
// }

// Usage: sort(vec.begin(), vec.end(), compFirstAsc);

// Example Output: (1,5) (2,3) (3,7) (4,6)


// ##########
// 2. Sorting Pairs Based on First Element (Descending Order)

// bool compFirstDesc(const pair<int, int>& a, const pair<int, int>& b) {
//     return a.first > b.first;
// }
// Usage: sort(vec.begin(), vec.end(), compFirstDesc);

// Example Output: (4,6) (3,7) (2,3) (1,5)

// ###########

// 3. Sorting Pairs Based on Second Element (Ascending Order)

// bool compSecondAsc(const pair<int, int>& a, const pair<int, int>& b) {
//     return a.second < b.second;
// }

// Usage: sort(vec.begin(), vec.end(), compSecondAsc);
// Example Output: (2,3) (1,5) (4,6) (3,7)


// ################

// 4. Sorting Pairs Based on Second Element (Descending Order)

// bool compSecondDesc(const pair<int, int>& a, const pair<int, int>& b) {
//     return a.second > b.second;
// }

// Usage: sort(vec.begin(), vec.end(), compSecondDesc);
// Example Output: (3,7) (4,6) (1,5) (2,3)

// ###################

// 5. Sorting Pairs Based on First, Then Second (Ascending)

// bool compFirstThenSecondAsc(const pair<int, int>& a, const pair<int, int>& b) {
//     if (a.first == b.first) {
//         return a.second < b.second;  // Sort by second if first elements are equal
//     }
//     return a.first < b.first;  // Sort by first element
// }

// Example Input: {(2, 3), (1, 5), (2, 2), (3, 4)}
// Example Output: (1,5) (2,2) (2,3) (3,4)

// #########################

// 6. Sorting Pairs Based on First, Then Second (Descending)

// bool compFirstThenSecondDesc(const pair<int, int>& a, const pair<int, int>& b) {
//     if (a.first == b.first) {
//         return a.second > b.second;  // Sort by second in descending if first elements are equal
//     }
//     return a.first > b.first;  // Sort by first element
// }
// Example Input: {(2, 3), (1, 5), (2, 2), (3, 4)}
// Example Output: (3,4) (2,3) (2,2) (1,5)

// ############################

// 7. Custom Sorting for Vectors of Integers (Descending Order)

// bool compIntDesc(int a, int b) {
//     return a > b;
// }
// Usage: sort(vec.begin(), vec.end(), compIntDesc);

// Example Output: {9, 7, 5, 3, 1}


// ###############################

// 8. Custom Sorting for Strings (Lexicographical Order)

// bool compStringLex(const string& a, const string& b) {
//     return a < b;  // Lexicographical order
// }
// Example Input: {"apple", "banana", "cherry", "date"}
// Example Output: {"apple", "banana", "cherry", "date"}

// #################################

// 9. Sorting Strings by Length (Ascending Order)

// bool compStringLengthAsc(const string& a, const string& b) {
//     return a.length() < b.length();
// }
// Example Input: {"apple", "kiwi", "banana", "date"}
// Example Output: {"kiwi", "date", "apple", "banana"}

// ####################################33
// 10. Sorting Strings by Length (Descending Order)

// bool compStringLengthDesc(const string& a, const string& b) {
//     return a.length() > b.length();
// }
// Example Output: {"banana", "apple", "date", "kiwi"}


// #######################################

// 11. Sorting a Set in Descending Order

// set<int, greater<int>> s = {5, 3, 8, 1, 9};
// Example Output: {9, 8, 5, 3, 1}


// ####################################

// 12. Sorting a Map by Value Instead of Key

// vector<pair<string, int>> vec = {{"apple", 3}, {"banana", 5}, {"cherry", 2}};

// bool compMapValue(const pair<string, int>& a, const pair<string, int>& b) {
//     return a.second > b.second;  // Sort by value in descending order
// }

// sort(vec.begin(), vec.end(), compMapValue);

// Example Output: {("banana", 5), ("apple", 3), ("cherry", 2)}

// #####################################

// 13. Using Lambda Functions for Quick Comparators
// Instead of writing separate functions, you can use lambda functions:


// sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//     return a.first > b.first;  // Sorting by first element in descending order
// });


// #####################################

// 14. Custom Comparator for Priority Queue (Max-Heap)
// By default, priority_queue in C++ is a max-heap. To make a min-heap, use this:

// priority_queue<int, vector<int>, greater<int>> pq;

// For a custom comparator for pairs:

// struct ComparePair {
//     bool operator()(pair<int, int> a, pair<int, int> b) {
//         return a.first > b.first;  // Min-heap based on first element
//     }
// };

// priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;

// ##########################################

// 15. Sorting a Struct with Custom Comparator
// If you have a struct and need to sort objects:

// struct Student {
//     string name;
//     int age;
// };

// // Comparator to sort by age
// bool compStudent(const Student& a, const Student& b) {
//     return a.age < b.age;
// }

// vector<Student> students = {{"Alice", 20}, {"Bob", 18}, {"Charlie", 22}};
// sort(students.begin(), students.end(), compStudent);
// Example Output: {"Bob", 18}, {"Alice", 20}, {"Charlie", 22}

