#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

string outed(const map<string, int> &meet, const string &boss) {
    double sum = 0.0;
    for (const auto& pair : meet) {
        if (pair.first == boss) {
            sum += 2 * pair.second;
        } else {
            sum += pair.second;
        }
    }

    double averageHappiness = sum / meet.size();

    if (averageHappiness > 5.0) {
        return "Nice Work Champ!";
    } else {
        return "Get Out Now!";
    }
}


int main()
{
    // input size of map
    int size, happiness;
    string name, boss;
    cout << "Ukuran map: "; cin >> size;

    map<string, int> happinessMap;
    
    // loop to append
    for (int i = 0; i < size; i++)
    {
        cout << "Nama ke " << i + 1 << ": "; cin >> name;
        cout << "Level kebahagiaan: "; cin >> happiness;

        happinessMap[name]= happiness;
    }

    // cetak nilai dari map
    vector<pair<string, int>> mapVector(happinessMap.begin(), happinessMap.end());
    cout << "NAMA KARYAWAN: LEVEL KEBAHAGIAAN";
    for (int i = 0; i < mapVector.size(); ++i) {
        cout << mapVector[i].first << ": " << mapVector[i].second << endl;
    }

    cout << "Nama boss: "; cin >> boss;
    cout << outed(happinessMap, boss) << endl;

    return 0;


}


