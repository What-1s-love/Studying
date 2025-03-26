#include <stdio.h>

int main() {
    int quantity;
    float price_per_item, total_cost;
    
    // Read the number of items and the price per item
    printf("Enter the quantity of items: ");
    scanf("%d", &quantity);
    printf("Enter the price per item: ");
    scanf("%f", &price_per_item);
    
    // Calculate the total cost
    total_cost = quantity * price_per_item;
    
    // Display the total cost
    printf("Total cost of the purchase: %.2f\n", total_cost);
    
    return 0;
}
