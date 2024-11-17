#include "RadixSort.h"
#include <iostream>
#include <cstring>
#include <algorithm>

// Function to sort subscribers
void radixSortSubscribers(Subscriber* subscribers, int num_subscribers) {
    const int max_digit = 10;  // Maximum number of digits in a phone number
    for (int exp = 1; exp < max_digit; exp *= 10) {
        int* output = new int[num_subscribers];  // Dynamically allocate memory
        int count[10] = { 0 };

        // Count the occurrence of each digit
        for (int i = 0; i < num_subscribers; i++) {
            count[(subscribers[i].phoneNumber[9 - exp] - '0')]++; // Determine the digit
        }

        // Transform counts to cumulative counts
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Place subscribers in correct order based on the current digit
        for (int i = num_subscribers - 1; i >= 0; i--) {
            output[count[subscribers[i].phoneNumber[9 - exp] - '0'] - 1] = i;
            count[subscribers[i].phoneNumber[9 - exp] - '0']--;
        }

        // Rebuild the subscriber array with sorted elements
        for (int i = 0; i < num_subscribers; i++) {
            int idx = output[i];
            std::swap(subscribers[i], subscribers[idx]);
        }

        delete[] output; // Free memory
    }
}

// Function to sort by postal code and operator
void sortByPostalCodeAndOperator(Subscriber* subscribers, int subscriberCount) {
    std::sort(subscribers, subscribers + subscriberCount, [](const Subscriber& a, const Subscriber& b) {
        if (a.postalCode == b.postalCode) {
            return a.operatorName < b.operatorName;  // Sort by operator name if postal codes match
        }
        return a.postalCode < b.postalCode;  // Otherwise, sort by postal code
        });
}
