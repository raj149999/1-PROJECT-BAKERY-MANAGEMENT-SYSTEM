#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    float price;
    int quantity;
};

// Function to show the bakery menu
void showMenu() {
    printf("\n--- Welcome to Sweet Treats Bakery ---\n");
    printf("Code\tItem\t\tPrice\n");
    printf("1\tCake Slice\tRs. 50\n");
    printf("2\tPastry\t\tRs. 30\n");
    printf("3\tBread\t\tRs. 25\n");
    printf("4\tCookies\t\tRs. 20\n");
    printf("5\tMuffin\t\tRs. 40\n");
    printf("6\tExit Order\n");
}

// Function to generate and print the final bill
void generateBill(struct Item orderList[], int count) {
    printf("\n======= Final Bill =======\n");
    printf("Item\t\tQty\tPrice\tTotal\n");

    float total = 0;
    int totalQuantity = 0;

    for (int i = 0; i < count; i++) {
        float itemTotal = orderList[i].price * orderList[i].quantity;
        total += itemTotal;
        totalQuantity += orderList[i].quantity;

        printf("%-12s\t%d\tRs. %.2f\tRs. %.2f\n",
               orderList[i].name, orderList[i].quantity, orderList[i].price, itemTotal);
    }

    float discount = 0;

    if (total >= 200) {
        discount = total * 0.1; // 10% discount
    }

    printf("\nTotal Unique Items: %d", count);
    printf("\nTotal Quantity Ordered: %d", totalQuantity);
    printf("\nSubtotal: Rs. %.2f", total);
    printf("\nDiscount: Rs. %.2f", discount);
    printf("\nGrand Total: Rs. %.2f", total - discount);
    printf("\n\nThank you for visiting Sweet Treats Bakery!\n");
}

int main() {
    int choice, quantity, count = 0;
    struct Item orderList[MAX_ITEMS];

    do {
        showMenu();
        printf("\nEnter item code (1-6): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            switch(choice) {
                case 1:
                    strcpy(orderList[count].name, "Cake Slice");
                    orderList[count].price = 50;
                    break;
                case 2:
                    strcpy(orderList[count].name, "Pastry");
                    orderList[count].price = 30;
                    break;
                case 3:
                    strcpy(orderList[count].name, "Bread");
                    orderList[count].price = 25;
                    break;
                case 4:
                    strcpy(orderList[count].name, "Cookies");
                    orderList[count].price = 20;
                    break;
                case 5:
                    strcpy(orderList[count].name, "Muffin");
                    orderList[count].price = 40;
                    break;
            }

            orderList[count].quantity = quantity;
            count++;

        } else if (choice != 6) {
            printf("Invalid item code! Please try again.\n");
        }

    } while (choice != 6);

    if (count > 0) {
        generateBill(orderList, count);
    } else {
        printf("\nNo items ordered. Thank you!\n");
    }

    return 0;
}

