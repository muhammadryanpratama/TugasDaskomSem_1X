#include <stdio.h>
#include <string.h>

typedef struct {
    char NameVerif[50];
    char PassVerif[50];
    char type[50];
    int frequency;
} ClientUser;

ClientUser ClientUserAccess[100];
ClientUser BalanceSystem[100];
                        int topup;
                        int balance;

void balance_laundry() {
    int option1;
    char Username[50];
    FILE* file_client;
    FILE* file_client_baru;

    file_client = fopen("database_user.bat", "rb");
    file_client_baru = fopen("database_user_new.bat", "wb");

    printf("\n1) Check Balance\n2) Top Up Balance");
    printf("\nChoose Option: ");
    scanf("%d", &option1);

    switch (option1) {
        case 1:
            fread(&BalanceSystem, sizeof(BalanceSystem), 1, file_client);

            printf("Enter your username: ");
            scanf("%s", Username);

            if (strcmp(Username, "User.name") == 0) {
                int user_choice;
                printf("\n1) Do you want to top up your balance?\n2) Exit\n");
                printf("\nChoose Option: ");
                scanf("%d", &user_choice);

                switch (user_choice) {
                    
                        case 1:

                        fread(&BalanceSystem, sizeof(BalanceSystem), 1, file_client);
    
                        printf("Enter how much money you want to add: ");
                        scanf("%f", &topup);


                        if (topup > 0) {
        
                        balance += topup;

        
                        fwrite(&BalanceSystem, sizeof(BalanceSystem), 1, file_client_baru);
        
                        printf("Balance successfully updated!\n");
                 } else {
                    printf("Invalid amount entered. Please enter a positive value.\n");
                        }       
    

                        break;

                    case 2:
                        // Exit or return to menu
                        return;

                    default:
                        printf("\nInvalid option!\n");
                        printf("Please try again\n");
                        break;
                }
            }
            break;

        default:
            printf("\nInvalid option!\n");
            printf("Please try again\n");
            break;
    }

    fclose(file_client);
    fclose(file_client_baru);
}

void sending_laundry(){



}

void status_laundry (){



}

void Packages_prices (){


}


void Client_Homepage() {
    int option;
    FILE* file1;
    file1 = fopen("Data.bin", "rb");

    printf("1) Balance\n2) Sending Laundry\n3) Status Laundry\n4) View Packages and Prices\n5) Exit\n");
    printf("Choose Option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            balance_laundry();
            break;

        case 2:
            sending_laundry();
            break;

        case 3:
            status_laundry();
            break;

        case 4:
            Packages_prices();
            break;

        case 5:
            // Exit or return to menu
            break;

        default:
            printf("\nInvalid option!\n");
            printf("Please try again\n");
            break;
    }

    fclose(file1);
}
