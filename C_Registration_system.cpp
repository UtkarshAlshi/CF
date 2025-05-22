#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_set<string> registered;
    unordered_map<string, int> nextNum; // tracks next available number for each base name
    
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        if (registered.find(name) == registered.end()) {
            // Name doesn't exist, register it
            registered.insert(name);
            cout << "OK" << endl;
        } else {
            // Name exists, use the next available number
            int num = nextNum[name];
            if (num == 0) num = 1; // first time we need a number for this name
            
            string newName = name + to_string(num);
            registered.insert(newName);
            nextNum[name] = num + 1; // update next available number
            
            cout << newName << endl;
        }
    }
    
    return 0;
}