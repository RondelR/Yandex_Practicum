#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string FindWidespreadBird(const vector<string>& types) {
    // напишите здесь ваше решение
    string max_birds;
    map <string, int> MyMap;
    for (string bird : types)
    {
        if (MyMap.count(bird) == 0)
        {
            MyMap[bird] = 1;
        }
        else 
        {
            ++MyMap[bird];
        }
    }
    int tmp = 0;
    for (const auto& [key, value] : MyMap)
    {
        if (value > tmp)
        {
            max_birds = key;
            tmp = value;
        }
        else if (value == tmp && max_birds > key)
        {
            max_birds = key;
        }
    }
    return max_birds;
}

int main() {
    vector<string> bird_types1 = { "zyablik"s, "sinica"s, "vorobey"s, "zyablik"s, "sinica"s };
    if (FindWidespreadBird(bird_types1) == "sinica"s) {
        cout << "Correct"s << endl;
    }
    else {
        cout << "Not correct"s << endl;
    }

    vector<string> bird_types2 = { "ruh"s, "sirin"s, "blue bird of fortune"s, "finist"s, "fenix"s };
    if (FindWidespreadBird(bird_types2) == "blue bird of fortune"s) {
        cout << "Correct"s << endl;
    }
    else {
        cout << "Not correct"s << endl;
    }
}