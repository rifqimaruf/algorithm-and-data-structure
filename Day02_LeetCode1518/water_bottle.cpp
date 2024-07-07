# include <iostream>
using namespace std;

int maxBottles(int numBottles, int numExchange){
    int total = numBottles;
    int empty = numBottles;
    
    if(numExchange <= 0){
        return total;
    }

    while (empty >= numExchange){
        int addnew = empty / numExchange;
        total += addnew;
        empty = addnew + (empty % numExchange);
    }
    return total;
}

int main(){
    int numBottles, numExchange;
    cin >> numBottles;
    cin >> numExchange;

    cout << maxBottles(numBottles, numExchange);
    return 0;
}