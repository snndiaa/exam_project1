#include <iostream>
#include <cstring>
using namespace std;

const int PRODUCTS = 100;
const int NAME_LENGTH = 50;
const int MANUFACTURER_LENGTH = 50;
const int CATEGORY_LENGTH = 50;
const int FILENAME_LENGTH = 100;

struct Date {
    int day;
    int month;
    int year;
};

struct Product {
    char name[NAME_LENGTH];
    char manufacturer[MANUFACTURER_LENGTH];
    double price;
    char category[CATEGORY_LENGTH];
    Date arrival_date;
    Date expiration_date;
};

void add_product(Product products[], int& num_products) {
    if (num_products == PRODUCTS) return;

    Product new_product;

    cout << "\nEnter the name of the product: ";
    cin.getline(new_product.name, NAME_LENGTH);

    cout << "Enter the manufacturer of the product: ";
    cin.getline(new_product.manufacturer, MANUFACTURER_LENGTH);

    cout << "Enter the price of the product: ";
    cin >> new_product.price;
    cin.ignore();

    cout << "Enter the category of the product: ";
    cin.getline(new_product.category, CATEGORY_LENGTH);

    cout << "Enter the arrival date of the product (day month year): ";
    cin >> new_product.arrival_date.day >> new_product.arrival_date.month >> new_product.arrival_date.year;
    cin.ignore();

    cout << "Enter the expiration date of the product (day month year): ";
    cin >> new_product.expiration_date.day >> new_product.expiration_date.month >> new_product.expiration_date.year;
    cin.ignore();

    products[num_products++] = new_product;

    cout << "\nProduct added successfully." << endl;
}

void delete_product(Product products[], int delete_ind, int& num_products) {
    if (delete_ind < 0 || delete_ind >= num_products) return;

    for (int i = delete_ind; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;
    cout << "\nProduct deleted successfully." << endl;
}

void replace_product(Product products[], int replace_ind, int num_products) {
    if (replace_ind < 0 || replace_ind >= num_products) return;

    Product new_product;

    cout << "\nEnter the name of the product: ";
    cin.getline(new_product.name, NAME_LENGTH);

    cout << "Enter the manufacturer of the product: ";
    cin.getline(new_product.manufacturer, MANUFACTURER_LENGTH);

    cout << "Enter the price of the product: ";
    cin >> new_product.price;
    cin.ignore();

    cout << "Enter the category of the product: ";
    cin.getline(new_product.category, CATEGORY_LENGTH);

    cout << "Enter the arrival date of the product (day month year): ";
    cin >> new_product.arrival_date.day >> new_product.arrival_date.month >> new_product.arrival_date.year;
    cin.ignore();

    cout << "Enter the expiration date of the product (day month year): ";
    cin >> new_product.expiration_date.day >> new_product.expiration_date.month >> new_product.expiration_date.year;
    cin.ignore();

    products[replace_ind] = new_product;
    cout << "Product replaced successfully." << endl;
}

void search_product_by_name(const Product products[], int num_products, const char* name) {
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            cout << "\nProduct found at index " << i << ":\n";
            cout << "Name: " << products[i].name << "\nManufacturer: " << products[i].manufacturer << "\nPrice: " << products[i].price << "\nCategory: " << products[i].category << "\nArrival Date: " << products[i].arrival_date.day << "/" << products[i].arrival_date.month << "/" << products[i].arrival_date.year << "\nExpiration Date: " << products[i].expiration_date.day << "/" << products[i].expiration_date.month << "/" << products[i].expiration_date.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_product_by_manufacturer(const Product products[], int num_products, const char* manufacturer) {
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].manufacturer, manufacturer) == 0) {
            cout << "\nProduct found at index " << i << ":\n";
            cout << "Name: " << products[i].name << "\nManufacturer: " << products[i].manufacturer << "\nPrice: " << products[i].price << "\nCategory: " << products[i].category << "\nArrival Date: " << products[i].arrival_date.day << "/" << products[i].arrival_date.month << "/" << products[i].arrival_date.year << "\nExpiration Date: " << products[i].expiration_date.day << "/" << products[i].expiration_date.month << "/" << products[i].expiration_date.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_product_by_price(const Product products[], int num_products, double price) {
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (products[i].price == price) {
            cout << "\nProduct found at index " << i << ":\n";
            cout << "Name: " << products[i].name << "\nManufacturer: " << products[i].manufacturer << "\nPrice: " << products[i].price << "\nCategory: " << products[i].category << "\nArrival Date: " << products[i].arrival_date.day << "/" << products[i].arrival_date.month << "/" << products[i].arrival_date.year << "\nExpiration Date: " << products[i].expiration_date.day << "/" << products[i].expiration_date.month << "/" << products[i].expiration_date.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_product_by_category(const Product products[], int num_products, const char* category) {
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].category, category) == 0) {
            cout << "\nProduct found at index " << i << ":\n";
            cout << "Name: " << products[i].name << "\nManufacturer: " << products[i].manufacturer << "\nPrice: " << products[i].price << "\nCategory: " << products[i].category << "\nArrival Date: " << products[i].arrival_date.day << "/" << products[i].arrival_date.month << "/" << products[i].arrival_date.year << "\nExpiration Date: " << products[i].expiration_date.day << "/" << products[i].expiration_date.month << "/" << products[i].expiration_date.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_product_by_arrival_date(const Product products[], int num_products, const Date arrival_date) {
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (products[i].arrival_date.day == arrival_date.day &&
            products[i].arrival_date.month == arrival_date.month &&
            products[i].arrival_date.year == arrival_date.year) {
            cout << "\nProduct found at index " << i << ":\n";
            cout << "Name: " << products[i].name << "\nManufacturer: " << products[i].manufacturer << "\nPrice: " << products[i].price << "\nCategory: " << products[i].category << "\nArrival Date: " << products[i].arrival_date.day << "/" << products[i].arrival_date.month << "/" << products[i].arrival_date.year << "\nExpiration Date: " << products[i].expiration_date.day << "/" << products[i].expiration_date.month << "/" << products[i].expiration_date.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_product_by_expiration_date(const Product products[], int num_products, const Date expiration_date) {
    bool found = false;
    for (int i = 0; i < num_products; i++) {
        if (products[i].expiration_date.day == expiration_date.day &&
            products[i].expiration_date.month == expiration_date.month &&
            products[i].expiration_date.year == expiration_date.year) {
            cout << "\nProduct found at index " << i << ":\n";
            cout << "Name: " << products[i].name << "\nManufacturer: " << products[i].manufacturer << "\nPrice: " << products[i].price << "\nCategory: " << products[i].category << "\nArrival Date: " << products[i].arrival_date.day << "/" << products[i].arrival_date.month << "/" << products[i].arrival_date.year << "\nExpiration Date: " << products[i].expiration_date.day << "/" << products[i].expiration_date.month << "/" << products[i].expiration_date.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void sort_products_by_price(Product products[], int num_products) {
    for (int i = 0; i < num_products - 1; i++) {
        for (int j = 0; j < num_products - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                Product tmp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = tmp;
            }
        }
    }
    cout << "\nProducts sorted by price." << endl;
}

void sort_products_by_category(Product products[], int num_products) {
    for (int i = 0; i < num_products - 1; i++) {
        for (int j = 0; j < num_products - i - 1; j++) {
            if (strcmp(products[j].category, products[j + 1].category) > 0) {
                Product tmp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = tmp;
            }
        }
    }
    cout << "\nProducts sorted by category." << endl;
}

void save_products_to_file(const Product products[], int num_products, const char* filename) {
    FILE* file = nullptr;
    if (fopen_s(&file, filename, "wb") != 0 || file == nullptr) return;
    fwrite(&num_products, sizeof(int), 1, file);
    fwrite(products, sizeof(Product), num_products, file);
    fclose(file);
    cout << "\nProducts saved to file." << endl;
}

void load_products_from_file(Product products[], int& num_products, const char* filename) {
    FILE* file = nullptr;
    if (fopen_s(&file, filename, "rb") != 0 || file == nullptr) return;
    fread(&num_products, sizeof(int), 1, file);
    fread(products, sizeof(Product), num_products, file);
    fclose(file);
    cout << "\nProducts loaded from file." << endl;
}

int main() {
    Product products[PRODUCTS];
    int num_products = 0;
    char filename[FILENAME_LENGTH];

    while (true) {
        cout << "\n========== Warehouse Management System ==========\n";
        cout << "1. Add a product\n2. Delete a product\n3. Replace a product\n4. Search for a product\n5. Sort products\n6. Save products to file\n7. Load products from file\n8. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            add_product(products, num_products);
            break;
        case 2: {
            int delete_ind;
            cout << "\nEnter the index of the product to delete: ";
            cin >> delete_ind;
            cin.ignore();
            delete_product(products, delete_ind, num_products);
            break;
        }
        case 3: {
            int replace_ind;
            cout << "\nEnter the index of the product to replace: ";
            cin >> replace_ind;
            cin.ignore();
            replace_product(products, replace_ind, num_products);
            break;
        }
        case 4: {
            cout << "\n========== Search Options ==========\n";
            cout << "1. By name\n2. By manufacturer\n3. By price\n4. By category\n5. By arrival date\n6. By expiration date\n";
            cout << "Enter your choice: ";
            int search_choice;
            cin >> search_choice;
            cin.ignore();

            switch (search_choice) {
            case 1: {
                char name[NAME_LENGTH];
                cout << "\nEnter the name of the product: ";
                cin.getline(name, NAME_LENGTH);
                search_product_by_name(products, num_products, name);
                break;
            }
            case 2: {
                char manufacturer[MANUFACTURER_LENGTH];
                cout << "\nEnter the manufacturer of the product: ";
                cin.getline(manufacturer, MANUFACTURER_LENGTH);
                search_product_by_manufacturer(products, num_products, manufacturer);
                break;
            }
            case 3: {
                double price;
                cout << "\nEnter the price of the product: ";
                cin >> price;
                cin.ignore();
                search_product_by_price(products, num_products, price);
                break;
            }
            case 4: {
                char category[CATEGORY_LENGTH];
                cout << "\nEnter the category of the product: ";
                cin.getline(category, CATEGORY_LENGTH);
                search_product_by_category(products, num_products, category);
                break;
            }
            case 5: {
                Date d;
                cout << "\nEnter the arrival date (day month year): ";
                cin >> d.day >> d.month >> d.year;
                cin.ignore();
                search_product_by_arrival_date(products, num_products, d);
                break;
            }
            case 6: {
                Date d;
                cout << "\nEnter the expiration date (day month year): ";
                cin >> d.day >> d.month >> d.year;
                cin.ignore();
                search_product_by_expiration_date(products, num_products, d);
                break;
            }
            default:
                cout << "\nInvalid search option." << endl;
                break;
            }
            break;
        }
        case 5: {
            cout << "\n========== Sort Options ==========\n";
            cout << "1. By price\n2. By category\n";
            cout << "Enter your choice: ";
            int sort_choice;
            cin >> sort_choice;
            cin.ignore();

            switch (sort_choice) {
            case 1:
                sort_products_by_price(products, num_products);
                break;
            case 2:
                sort_products_by_category(products, num_products);
                break;
            default:
                cout << "\nInvalid sort option." << endl;
                break;
            }
            break;
        }
        case 6: {
            cout << "\nEnter the filename to save the products to: ";
            cin.getline(filename, FILENAME_LENGTH);
            save_products_to_file(products, num_products, filename);
            break;
        }
        case 7: {
            cout << "\nEnter the filename to load the products from: ";
            cin.getline(filename, FILENAME_LENGTH);
            load_products_from_file(products, num_products, filename);
            break;
        }
        case 8:
            cout << "\nExiting the program." << endl;
            return 0;
        default:
            cout << "\nInvalid choice." << endl;
            break;
        }
    }
}

