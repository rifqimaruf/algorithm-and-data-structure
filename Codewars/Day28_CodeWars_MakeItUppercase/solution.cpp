
#include <iostream>
#include <string>

using namespace std;
string makeUpperCase(const string& input_str)
{
    string result = input_str;
    for (int i = 0; i < result.length(); i++)
    {
        result[i] = toupper(result[i]);
    }
    return result;
}

int main()
{
    string s;
    cout << "what's on your mind: ";
    cin >> s;
    cout << "here is the uppercase style, no offense* : " << makeUpperCase(s);

}