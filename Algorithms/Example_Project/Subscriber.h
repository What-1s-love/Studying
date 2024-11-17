#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>

// Subscriber structure
struct Subscriber {
    std::string phoneNumber;  // Subscriber's phone number
    std::string operatorName; // Operator name
    int postalCode;           // Postal code
};

// Function to print subscriber data
void printSubscriber(const Subscriber& subscriber);

#endif // SUBSCRIBER_H
