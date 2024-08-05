#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phone_numbers;
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size(); i++) {
        if (phone_numbers.empty()) {
            phone_numbers.insert(phone_book[i]);
        }
        else {
            string substr = "";
            for (int j = 0; j < phone_book[i].length(); j++) {
                substr += phone_book[i][j];
                if (phone_numbers.find(substr) != phone_numbers.end())
                    return false;
            }
            phone_numbers.insert(phone_book[i]);
        }
    }
    
    return true;
}