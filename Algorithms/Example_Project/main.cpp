#include <iostream>
#include <fstream>
#include <string>
#include "Subscriber.h"
#include "RadixSort.h"

using namespace std;

// Operator codes
const string kyivstarCodes[] = { "067", "068", "096", "097", "098" };
const string vodafoneCodes[] = { "050", "066", "095", "099" };
const string lifecellCodes[] = { "063", "073", "093" };
const int operatorCount = 3;
const int maxNumbersPerOperator = 200;  // Maximum numbers per operator

// Function to check prefix match
string getOperatorByCode(const string& phoneNumber) {
    for (const string& code : kyivstarCodes) {
        if (phoneNumber.substr(0, code.length()) == code) {
            return "Kyivstar";
        }
    }
    for (const string& code : vodafoneCodes) {
        if (phoneNumber.substr(0, code.length()) == code) {
            return "Vodafone";
        }
    }
    for (const string& code : lifecellCodes) {
        if (phoneNumber.substr(0, code.length()) == code) {
            return "Lifecell";
        }
    }
    return "Unknown";  // If no code matched
}

void printBold(const string& text) {
    // For terminals supporting ANSI escape codes
    cout << "\033[1m" << text << "\033[0m";  // Bold text
}

int main() {
    // Reading phone numbers from file
    ifstream file("PhoneNumbers.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    // Dynamic array for storing subscribers
    const int maxSubscribers = 1000;  // Assume max 1000 subscribers
    Subscriber* subscribers = new Subscriber[maxSubscribers];  // Allocate memory
    int subscriberCount = 0;

    // Reading data from file
    string phoneNumber;
    int postalCode;
    while (file >> phoneNumber >> postalCode) {
        if (subscriberCount < maxSubscribers) {
            string operatorName = getOperatorByCode(phoneNumber);
            subscribers[subscriberCount++] = { phoneNumber, operatorName, postalCode };
        }
    }

    file.close();

    // Sort subscribers by postal code and operator
    sortByPostalCodeAndOperator(subscribers, subscriberCount);

    // Sorting the phone numbers within each operator using radix sort
    radixSortSubscribers(subscribers, subscriberCount);

    // Postal codes for output
    int postalCodes[] = { 40000, 40100, 40200, 40300, 40400, 40500, 40600 };
    const int numPostalCodes = sizeof(postalCodes) / sizeof(postalCodes[0]);

    // Output information
    ofstream outputFile("SortedPhoneNumbers.txt", ios::trunc); // Open file for writing, truncating
    if (!outputFile.is_open()) {
        cerr << "Failed to open file for writing!" << endl;
        delete[] subscribers; // Free memory before exit
        return 1;
    }

    for (int i = 0; i < numPostalCodes; ++i) {
        int postalCode = postalCodes[i];
        cout << "Postal Code: " << postalCode << endl;  // Console output
        outputFile << "Postal Code: " << postalCode << endl;  // Write to file (in English)

        bool foundOperator = false;

        // For each operator
        for (int j = 0; j < operatorCount; ++j) {
            string operatorName;
            string operatorNumbers[maxNumbersPerOperator];
            int operatorNumberCount = 0;

            if (j == 0) operatorName = "Kyivstar";
            else if (j == 1) operatorName = "Vodafone";
            else operatorName = "Lifecell";

            // Find numbers for each operator
            for (int k = 0; k < subscriberCount; ++k) {
                if (subscribers[k].postalCode == postalCode && subscribers[k].operatorName == operatorName) {
                    if (operatorNumberCount < maxNumbersPerOperator) {
                        operatorNumbers[operatorNumberCount++] = subscribers[k].phoneNumber;
                    }
                }
            }

            if (operatorNumberCount > 0) {
                foundOperator = true;
                printBold(operatorName);  // Bold text for operator
                cout << " (" << operatorNumberCount << " numbers)" << endl;  // Console output
                outputFile << operatorName << " (" << operatorNumberCount << " numbers)" << endl;  // Write to file (in English)

                // Write sorted numbers to file
                for (int m = 0; m < operatorNumberCount; ++m) {
                    outputFile << operatorNumbers[m] << endl;  // Write number to file
                }
            }
        }

        if (!foundOperator) {
            cout << "No subscribers" << endl;  // Console output
            outputFile << "No subscribers" << endl;  // Write to file (in English)
        }
    }

    // Close file
    outputFile.close();

    // Inform user that the data was saved to file
    cout << "More detailed information has been saved to the file." << endl;

    // Free dynamically allocated memory
    delete[] subscribers;

    return 0;
}
