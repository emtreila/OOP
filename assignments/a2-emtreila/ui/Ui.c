#include "Ui.h"


//function to create a new UI
EstateUi createUi(EstateService estate_service) {
    EstateUi ui = {
        .service = estate_service
    };
    return ui;
}

void show_menu() {
    //function to display the menu
    printf("\n");
    printf("MENU\n");
    printf("0. Exit.\n");
    printf("1. Add estate.\n");
    printf("2. Delete estate.\n");
    printf("3. Update estate.\n");
    printf("4. Display all estates whose address contains a given string, sorted ascending by their price.\n");
    printf("5. Display all estates of a given type, having the surface greater than a user provided value.\n");
    printf("6. Undo.\n");
    printf("7. Redo.\n");
    printf("\n");
}

void addEstateUi(EstateUi *ui, char type[MAX_TYPE_LENGTH], char address[ADDRESS_LENGTH], double surface, double price) {
    EstateType estateType;

    if (strcmp(type, "house") == 0) {
        //check if the type is valid
        estateType = HOUSE;
    } else if (strcmp(type, "apartment") == 0) {
        estateType = APARTMENT;
    } else if (strcmp(type, "penthouse") == 0) {
        estateType = PENTHOUSE;
    } else {
        printf("Invalid type!");
        return;
    }

    if (address == NULL) {
        //check if the address is valid
        printf("Invalid address!");
        return;
    }

    if (surface < 0) {
        //check if the surface is valid
        printf("Invalid surface!");
        return;
    }

    if (price < 0) {
        //check if the price is valid
        printf("Invalid price!");
        return;
    }

    if (!addEstateService(&ui->service, estateType, address, surface, price)) {
        //check if the estate already exists
        printf("Estate already exists!");
    } else {
        //add the estate
        printf("Estate added successfully!");
    }
}

//function for having at least 10 entries available at application startup
void addInitialEstates(EstateUi *ui, char type[MAX_TYPE_LENGTH], char address[ADDRESS_LENGTH], double surface,
                       double price) {
    EstateType estateType;

    if (strcmp(type, "house") == 0) {
        //check if the type is valid
        estateType = HOUSE;
    } else if (strcmp(type, "apartment") == 0) {
        estateType = APARTMENT;
    } else if (strcmp(type, "penthouse") == 0) {
        estateType = PENTHOUSE;
    } else {
        printf("Invalid type!");
        return;
    }

    if (address == NULL) {
        //check if the address is valid
        printf("Invalid address!");
        return;
    }

    if (surface < 0) {
        //check if the surface is valid
        printf("Invalid surface!");
        return;
    }

    if (price < 0) {
        //check if the price is valid
        printf("Invalid price!");
        return;
    }
    //add the estate
    addEstateService(&ui->service, estateType, address, surface, price);
}

//function to delete an estate
void deleteEstateUi(EstateUi *ui, char toDelete[ADDRESS_LENGTH]) {
    if (toDelete == NULL) {
        //check if the address is valid
        printf("Invalid address!");
        return;
    }
    if (!deleteEstateService(&ui->service, toDelete)) {
        //check if the estate exists
        printf("Estate not found!");
    } else {
        //delete the estate
        printf("Estate deleted successfully!");
    }
}

//function to update an estate
void updateEstateUi(EstateUi *ui, char newType[MAX_TYPE_LENGTH], char address[ADDRESS_LENGTH], double newSurface,
                    double newPrice) {
    EstateType estateType;

    if (strcmp(newType, "house") == 0) {
        //check if the type is valid
        estateType = HOUSE;
    } else if (strcmp(newType, "apartment") == 0) {
        estateType = APARTMENT;
    } else if (strcmp(newType, "penthouse") == 0) {
        estateType = PENTHOUSE;
    } else {
        printf("Invalid new type!");
        return;
    }

    if (address == NULL) {
        //check if the address is valid
        printf("Invalid address!");
        return;
    }

    if (newSurface < 0) {
        //check if the surface is valid
        printf("Invalid new surface!");
        return;
    }

    if (newPrice < 0) {
        //check if the price is valid
        printf("Invalid new price!");
        return;
    }

    if (!updateEstateService(&ui->service, estateType, address, newSurface, newPrice)) {
        // check if the estate exists
        printf("Estate not found!");
    } else {
        // update the estate
        printf("Estate updated successfully!");
    }
}


void estatesWithStringInAddressUi(EstateUi *ui, char *substring) {
    DynamicArray filteredEstates = estatesWithStringInAddress(&ui->service, substring);

    if (filteredEstates.size == 0) {
        // check if there are any estates with the given substring
        printf("No estates found having '%s' in their address!", substring);
        destroyDynamicArray(&filteredEstates);
        return;
    }

    for (int i = 0; i < filteredEstates.size; i++) {
        //print the estates
        char *type = getType(&filteredEstates.data[i]);
        char *address = getAddress(&filteredEstates.data[i]);
        double surface = getSurface(&filteredEstates.data[i]);
        double price = getPrice(&filteredEstates.data[i]);
        printf("Type: %s, Address: %s, Surface: %.2lf, Price: %.2lf\n", type, address, surface, price);
    }
    destroyDynamicArray(&filteredEstates); // free the memory allocated for the dynamic vector
}

void estatesWithTypeAndSurfaceUi(EstateUi *ui, char *typeStr, double surface) {
    EstateType type;
    // check if the type is valid
    if (strcmp(typeStr, "house") == 0)
        type = HOUSE;
    else if (strcmp(typeStr, "apartment") == 0)
        type = APARTMENT;
    else if (strcmp(typeStr, "penthouse") == 0)
        type = PENTHOUSE;
    else {
        printf("Invalid estate type: %s\n", typeStr);
        return;
    }
    DynamicArray filteredEstates = estatesWithTypeAndSurface(&ui->service, type, surface);
    // check if there are any estates with the given type and surface
    if (filteredEstates.size == 0) {
        printf("No estates found having type '%s' and surface greater than %.2lf!", typeStr, surface);
        destroyDynamicArray(&filteredEstates);
        return;
    }

    for (int i = 0; i < filteredEstates.size; i++) {
        // print the estates
        char *estateType = getType(&filteredEstates.data[i]);
        char *estateAddress = getAddress(&filteredEstates.data[i]);
        double estateSurface = getSurface(&filteredEstates.data[i]);
        double price = getPrice(&filteredEstates.data[i]);
        printf("Type: %s, Address: %s, Surface: %.2lf, Price: %.2lf\n", estateType, estateAddress, estateSurface,
               price);
    }

    destroyDynamicArray(&filteredEstates); // free the memory allocated for the dynamic vector
}

void undoUi(EstateUi *ui) {
    if (undoService(&ui->service)) {
        printf("Undo OK!\n");
    } else {
        printf("Undo failed!\n");
    }
}

void redoUi(EstateUi *ui) {
    if (redoService(&ui->service)) {
        printf("Redo OK!\n");
    } else {
        printf("Redo failed!\n");
    }
}

// function for having at least 10 entries available at application startup
void initialEstates(EstateUi *ui) {
    addInitialEstates(ui, "house", "1 Decembrie", 32, 4000);
    addInitialEstates(ui, "apartment", "Strada Florilor", 65, 12300);
    addInitialEstates(ui, "penthouse", "Strada Primaverii", 75, 1000);
    addInitialEstates(ui, "apartment", "Strada Ploii", 356, 2560);
    addInitialEstates(ui, "house", "Strada Fructelor", 123, 23420);
    addInitialEstates(ui, "apartment", "Strada 1234", 56, 3000);
    addInitialEstates(ui, "penthouse", "Strada Lalelelor", 89, 5000);
    addInitialEstates(ui, "apartment", "Strada Trenului", 65, 813);
    addInitialEstates(ui, "house", "Strada 823", 2111, 3300);
    addInitialEstates(ui, "apartment", "7 Martie", 65, 900);
}

double read_surface(const char *prompt) {
    char buffer[MAX_DIGITS_LENGTH]; //buffer for numeric input
    double value;

    while (1) {
        printf("%s", prompt);
        fgets(buffer, MAX_DIGITS_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; //remove newline character


        char *endptr;
        value = strtod(buffer, &endptr);

        if (endptr != buffer && *endptr == '\0') {
            //valid number check
            return value;
        }
        printf("Invalid surface!\n");
    }
}

double read_price(const char *prompt) {
    char buffer[MAX_DIGITS_LENGTH]; //buffer for numeric input
    double value;

    while (1) {
        printf("%s", prompt);
        fgets(buffer, MAX_DIGITS_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; //remove newline character


        char *endptr;
        value = strtod(buffer, &endptr);

        if (endptr != buffer && *endptr == '\0') {
            //valid number check
            return value;
        }
        printf("Invalid price!\n");
    }
}

void run(EstateUi *ui) {
    initialEstates(ui);
    char option[10];

    double surface, price;
    char type[MAX_TYPE_LENGTH] = {0};
    char address[ADDRESS_LENGTH] = {0};

    while (1) {
        show_menu();
        printf("Enter an option: ");
        fgets(option, 10, stdin);

        int optionLength = strlen(option);

        if (option[optionLength - 1] == '\n') {
            option[optionLength - 1] = '\0';
        }

        if (strcmp(option, "0") == 0) {
            printf("Bye, bye!");
            break;
        }

        if (strcmp(option, "1") == 0) {
            printf("Enter the type: ");
            fgets(type, MAX_TYPE_LENGTH, stdin);
            type[strcspn(type, "\n")] = '\0'; //remove newline


            printf("Enter the address: ");
            fgets(address, ADDRESS_LENGTH, stdin);
            address[strcspn(address, "\n")] = '\0'; // remove newline

            surface = read_surface("Enter the surface: ");
            price = read_price("Enter the price: ");


            addEstateUi(ui, type, address, surface, price);
        } else if (strcmp(option, "2") == 0) {
            printf("Enter the address: ");
            fgets(address, ADDRESS_LENGTH, stdin);
            address[strcspn(address, "\n")] = '\0';

            deleteEstateUi(ui, address);
        } else if (strcmp(option, "3") == 0) {
            printf("Enter the new type: ");
            fgets(type, MAX_TYPE_LENGTH, stdin);
            type[strcspn(type, "\n")] = '\0';

            printf("Enter the address: ");
            fgets(address, ADDRESS_LENGTH, stdin);
            address[strcspn(address, "\n")] = '\0';

            surface = read_surface("Enter the new surface: ");

            price = read_price("Enter the new price: ");

            updateEstateUi(ui, type, address, surface, price);
        } else if (strcmp(option, "4") == 0) {
            printf("Enter the substring: ");
            fgets(address, ADDRESS_LENGTH, stdin);
            address[strcspn(address, "\n")] = '\0';

            estatesWithStringInAddressUi(ui, address);
        } else if (strcmp(option, "5") == 0) {
            printf("Enter the type: ");
            fgets(type, MAX_TYPE_LENGTH, stdin);
            type[strcspn(type, "\n")] = '\0';


            surface = read_surface("Enter the surface: ");

            estatesWithTypeAndSurfaceUi(ui, type, surface);
        } else if (strcmp(option, "6") == 0) {
            undoUi(ui);
        } else if (strcmp(option, "7") == 0) {
            redoUi(ui);
        } else {
            printf("Invalid option!\n");
        }

        fflush(stdin);
    }
}
