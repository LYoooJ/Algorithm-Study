#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    int size = 0;
    vector<int> answer;
    map<int, int> min_remove;
    map<int, int> max_remove;
    priority_queue<int, vector<int>, less<int>> max_heap; // max heap
    priority_queue<int, vector<int>, greater<int>> min_heap; // min heap
    int min, max;
    
    for (vector<string>::iterator iter = operations.begin(); iter != operations.end(); iter++) {
        char operation = (*iter)[0];
        (*iter).replace(0, 2, "");
        int num = stoi(*iter);
        
        if (operation == 'I') { // if operation I
            max_heap.push(num);
            min_heap.push(num);
            size++;
        } 
        else { // if operation 
            if (size == 0)
                continue;
            if (num == 1) { 
                while (min_remove[max_heap.top()] > 0) {
                    min_remove[max_heap.top()]--;
                    max_heap.pop();
                }
                max_remove[max_heap.top()]++;
                max_heap.pop();
            }
            else // Delete min value
            {
                while (max_remove[min_heap.top()] > 0) {
                    max_remove[min_heap.top()]--;
                    min_heap.pop();
                }
                min_remove[min_heap.top()]++;
                min_heap.pop();
            }
            size--;
        }
    }   
    
    if (size == 0) {
        min = 0; 
        max = 0;
    }
    else {
        while (min_remove[max_heap.top()] > 0) {
            min_remove[max_heap.top()]--;
            max_heap.pop();
        }
        while (max_remove[min_heap.top()] > 0) {
            max_remove[min_heap.top()]--;
            min_heap.pop();
        }
        min = min_heap.top();
        max = max_heap.top();
    }
    answer.push_back(max);
    answer.push_back(min);
    
    return answer;
}