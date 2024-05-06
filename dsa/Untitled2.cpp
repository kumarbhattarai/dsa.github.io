#include <stdio.h>

// Function to calculate the parity bit for a given data
int calculateParityBit(int data) {
    int parity = 0;
    
    // XOR all the bits in the data
    while (data != 0) {
        parity ^= (data & 1);
        data >>= 1;
    }
    
    return parity;
}

// Function to add a parity bit to the data
int addParityBit(int data) {
    int parity = calculateParityBit(data);
    
    // Add the parity bit to the data
    return (data << 1) | parity;
}

// Function to check if the received data has the correct parity
int checkParity(int data) {
    int receivedParity = data & 1;
    int dataWithoutParity = data >> 1;
    
    // Calculate the parity of the received data without the parity bit
    int calculatedParity = calculateParityBit(dataWithoutParity);
    
    // Compare the received parity with the calculated parity
    if (receivedParity == calculatedParity) {
        return 1; // Parity check passed
    } else {
        return 0; // Parity check failed
    }
}

int main() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
    // Generate parity bit and add it to the data
    int dataWithParity = addParityBit(data);
    printf("Data with parity bit: %d\n", dataWithParity);
    
    // Check if the received data has correct parity
    int result = checkParity(dataWithParity);
    if (result == 1) {
        printf("Parity check passed. Data is correct.\n");
    } else {
        printf("Parity check failed. Data may be corrupted.\n");
    }
    
    return 0;
}

