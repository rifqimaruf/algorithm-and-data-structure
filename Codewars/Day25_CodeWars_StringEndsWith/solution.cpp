#include <iostream>
#include <string>

using namespace std;

bool solution(string const &str, string const &ending)
{
    if (str.size() >= ending.size())
    {
        return str.compare(str.size() - ending.size(), ending.size(), ending) == 0;
    }
    else{
        return false;
    }
}


int main()
{
    string fullstring, ending;

    cout << "Enter the string: "; cin >> fullstring;
    cout << "Enter the ending: "; cin >> ending;

    cout << solution(fullstring, ending) << endl;
    return 0;
}