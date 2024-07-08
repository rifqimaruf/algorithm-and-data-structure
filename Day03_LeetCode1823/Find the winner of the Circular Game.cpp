# include <iostream>
using namespace std;

int findTheWinner(int n, int k){
    //Base case
    if(n == 1){
        return 0;
    }
    //Recursive call
    return (findTheWinner(n-1, k) + k) % n;
}
int main(){
    int n, k;
    cin >> n >> k;

    cout << findTheWinner(n, k) + 1;
    return 0;
}