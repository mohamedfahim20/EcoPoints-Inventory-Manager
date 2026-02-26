#include <stdio.h>
struct User {
    int points;
    char name[50];
};
void earnPoints(struct User *u, int pts) {
    u->points += pts;
    printf("Earned %d points! Total: %d\n", pts, u->points);
}
int redeemPoints(struct User *u, int pts) {
    if (u->points >= pts) {
        u->points -= pts;
        printf("Redeemed %d points! Remaining: %d\n", pts, u->points);
        return 1;
    } else {
        printf("Insufficient points!\n");
        return 0;
    }
}

int main() {
    struct User user = {0, "Mohamed"};  // Start with 0 points
    printf("Welcome to Walkaroo Loyalty, %s!\n", user.name);
    
    int choice;
    do {
        printf("\n1. Scan QR (earn 10 pts)\n2. View points\n3. Redeem 20 pts\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: earnPoints(&user, 10); break;
            case 2: printf("Points: %d\n", user.points); break;
            case 3: redeemPoints(&user, 20); break;
            case 4: printf("Bye!\n"); break;
            default: printf("Invalid!\n");
        }
    } while (choice != 4);
    
    return 0;
}
