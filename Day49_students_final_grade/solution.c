#include <stdio.h>

int final_grade(int exam, int projects) {

    if (exam > 90 || projects > 10) {
        return 100;
    }
    if (exam > 75 && projects >= 5) {
        return 90;
    }
    if (exam > 50 && projects >= 2) {
        return 75;
    }
    return 0;
}


int main()
{
    final_grade(100, 12);
    return 0;
}