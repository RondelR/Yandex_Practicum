#include <iostream>
#include <string>
#include <map>

using namespace std;

bool CheckAnagram(const string& s1, const string& s2)
{
    bool res = true;
    map <char, int > Map1;
    map <char, int > Map2;
    for (int i = 0; i < s1.size(); i++)
    {
        if (Map1.count(s1[i]) == 0)
        {
            Map1[s1[i]] = 1;
        }
        else 
        {
            ++Map1[s1[i]];
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (Map2.count(s2[i]) == 0)
        {
            Map2[s2[i]] = 1;
        }
        else
        {
            ++Map2[s2[i]];
        }
    }
    for (const auto& [key, value] : Map1) {
        if (Map2.count(key) == 1)
        {
            if (Map2[key] != value)
            {
                res = false;
            }
        }
        else
        {
            res = false;
        }
    }
    return res;
}



// напишем небольшую функцию для проверки
void CheckIsTrue(bool value)
{
    if (value)
    {
        cout << "Test passed :)"s << endl;
    }
    else
    {
        cout << "Test failed :("s << endl;
    }
}

int main() {
    CheckIsTrue(CheckAnagram("tea"s, "eat"s));
    CheckIsTrue(CheckAnagram("battle"s, "beatle"s));
    CheckIsTrue(CheckAnagram("lift"s, "elevator"s));
    CheckIsTrue(CheckAnagram("ocean"s, "canoe"s));
}