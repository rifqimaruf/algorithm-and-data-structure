# include <iostream>
using namespace std;

int findPillow(int n, int time){
    int cyclyLength = 2 * n - 2;
    int t = time % cyclyLength;

    if (t< n){
        return 1 + t;
    }
    else {
        return n - (t - n + 1);
    }
}

int main(){
    int n, m;
    cin >> n;    
    cin >> m;

    cout << findPillow(n, m);
    return 0;
}