#include <stdio.h>
int generateParity(int num) {
    int parity = 0;
    while (num) {
        parity = !parity;
        num = num & (num - 1);
    }
    return parity;
}
void checkParity(int num) {
    int parity = generateParity(num);
    if (parity == 0)
        printf("The number %d has even parity.\n", num);
    else
        printf("The number %d has odd parity.\n", num);
}

int main() {
    int num = 7;  // Example number
    checkParity(num);

    return 0;
}

