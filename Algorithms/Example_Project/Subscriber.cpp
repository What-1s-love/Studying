#include "Subscriber.h"
#include <iostream>

// Function to print subscriber data
void printSubscriber(const Subscriber& subscriber) {
    std::cout << "Phone Number: " << subscriber.phoneNumber
        << ", Operator: " << subscriber.operatorName
        << ", Postal Code: " << subscriber.postalCode << std::endl;
}
