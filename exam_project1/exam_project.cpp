#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LENGTH = 50;
const int MANUFACTURER_LENGTH = 50;
const int CATEGORY_LENGTH = 50;
const int FILE_NAME_LENGTH = 100;
const int INITIAL_CAPACITY = 10;

struct Date
{
    int day;
    int month;
    int year;
};

struct Product
{
    char name[NAME_LENGTH];
    char manufacturer[MANUFACTURER_LENGTH];
    double price;
    char category[CATEGORY_LENGTH];
    Date arrival_date;
    Date expiration_date;
};

enum MenuOption
{
    ADD = 1,
    DELETE,
    REPLACE,
    SEARCH,
    SORT,
    SAVE,
    LOAD,
    EXIT,
    DISPLAY
};

void clear_input_buffer()
{
    cin.ignore(10000, '\n');
}

void input_product_data(Product& p)
{
    clear_input_buffer();
    cout << endl << "Enter the name of the product: ";
    cin.getline(p.name, NAME_LENGTH);

    cout << "Enter the manufacturer of the product: ";
    cin.getline(p.manufacturer, MANUFACTURER_LENGTH);

    cout << "Enter the price of the product: ";
    cin >> p.price;
    clear_input_buffer();

    cout << "Enter the category of the product: ";
    cin.getline(p.category, CATEGORY_LENGTH);

    cout << "Enter the arrival date of the product (day month year): ";
    cin >> p.arrival_date.day >> p.arrival_date.month >> p.arrival_date.year;
    clear_input_buffer();

    cout << "Enter the expiration date of the product (day month year): ";
    cin >> p.expiration_date.day >> p.expiration_date.month >> p.expiration_date.year;
    clear_input_buffer();
}

void print_product_data(const Product& p, int index)
{
    cout << endl << "Product found at index " << index << ":" << endl;
    cout << "Name: " << p.name << endl;
    cout << "Manufacturer: " << p.manufacturer << endl;
    cout << "Price: " << p.price << endl;
    cout << "Category: " << p.category << endl;
    cout << "Arrival Date: " << p.arrival_date.day << "/" << p.arrival_date.month << "/" << p.arrival_date.year << endl;
    cout << "Expiration Date: " << p.expiration_date.day << "/" << p.expiration_date.month << "/" << p.expiration_date.year << endl;
}

void resize_array(Product*& list, int& capacity)
{
    capacity *= 2;
    Product* temp = new Product[capacity];
    for (int i = 0; i < capacity / 2; ++i)
        temp[i] = list[i];
    delete[] list;
    list = temp;
}

void add_product_data(Product*& list, int& count, int& capacity)
{
    if (count == capacity)
        resize_array(list, capacity);

    Product new_product;
    input_product_data(new_product);
    list[count++] = new_product;
    cout << endl << "Product added successfully." << endl;
}

void delete_product_data(Product* list, int& count)
{
    int index;
    cout << endl << "Enter the index of the product to delete: ";
    cin >> index;
    clear_input_buffer();
    if (index < 0 || index >= count) return;

    for (int i = index; i < count - 1; ++i)
        list[i] = list[i + 1];

    count--;
    cout << endl << "Product deleted successfully." << endl;
}

void replace_product_data(Product* list, int count)
{
    int index;
    cout << endl << "Enter the index of the product to replace: ";
    cin >> index;
    clear_input_buffer();
    if (index < 0 || index >= count) return;

    input_product_data(list[index]);
    cout << "Product replaced successfully." << endl;
}

void search_by_name(Product* list, int count)
{
    char name[NAME_LENGTH];
    cout << endl << "Enter the name of the product: ";
    clear_input_buffer();
    cin.getline(name, NAME_LENGTH);
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(list[i].name, name) == 0)
        {
            print_product_data(list[i], i);
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_by_manufacturer(Product* list, int count)
{
    char manufacturer[MANUFACTURER_LENGTH];
    cout << endl << "Enter the manufacturer of the product: ";
    clear_input_buffer();
    cin.getline(manufacturer, MANUFACTURER_LENGTH);
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(list[i].manufacturer, manufacturer) == 0)
        {
            print_product_data(list[i], i);
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_by_price(Product* list, int count)
{
    double price;
    cout << endl << "Enter the price of the product: ";
    cin >> price;
    clear_input_buffer();
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (list[i].price == price)
        {
            print_product_data(list[i], i);
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_by_category(Product* list, int count)
{
    char category[CATEGORY_LENGTH];
    cout << endl << "Enter the category of the product: ";
    clear_input_buffer();
    cin.getline(category, CATEGORY_LENGTH);
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(list[i].category, category) == 0)
        {
            print_product_data(list[i], i);
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_by_arrival_date(Product* list, int count)
{
    Date d;
    cout << endl << "Enter the arrival date (day month year): ";
    cin >> d.day >> d.month >> d.year;
    clear_input_buffer();
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (list[i].arrival_date.day == d.day && list[i].arrival_date.month == d.month && list[i].arrival_date.year == d.year)
        {
            print_product_data(list[i], i);
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void search_by_expiration_date(Product* list, int count)
{
    Date d;
    cout << endl << "Enter the expiration date (day month year): ";
    cin >> d.day >> d.month >> d.year;
    clear_input_buffer();
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (list[i].expiration_date.day == d.day && list[i].expiration_date.month == d.month && list[i].expiration_date.year == d.year)
        {
            print_product_data(list[i], i);
            found = true;
        }
    }
    if (!found) cout << "Product not found." << endl;
}

void sort_by_price(Product* list, int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (list[j].price > list[j + 1].price)
            {
                Product tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    cout << endl << "Products sorted by price." << endl;
}

void sort_by_category(Product* list, int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (strcmp(list[j].category, list[j + 1].category) > 0)
            {
                Product tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    cout << endl << "Products sorted by category." << endl;
}

void save_to_file(Product* list, int count, const char* file_name)
{
    FILE* file = nullptr;
    if (fopen_s(&file, file_name, "wb") != 0 || file == nullptr) return;
    fwrite(&count, sizeof(int), 1, file);
    fwrite(list, sizeof(Product), count, file);
    fclose(file);
    cout << endl << "Products saved to file." << endl;
}

void load_from_file(Product*& list, int& count, int& capacity, const char* file_name)
{
    FILE* file = nullptr;
    if (fopen_s(&file, file_name, "rb") != 0 || file == nullptr) return;
    fread(&count, sizeof(int), 1, file);
    if (count > capacity)
    {
        delete[] list;
        capacity = count;
        list = new Product[capacity];
    }
    fread(list, sizeof(Product), count, file);
    fclose(file);
    cout << endl << "Products loaded from file." << endl;
}

void display_all_products(Product* list, int count)
{
    if (count == 0)
    {
        cout << endl << "No products to display." << endl;
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        print_product_data(list[i], i);
    }
}


int main()
{
    Product* list = new Product[INITIAL_CAPACITY];
    int count = 0;
    int capacity = INITIAL_CAPACITY;
    char file_name[FILE_NAME_LENGTH];

    while (true)
    {
        cout << endl << "========== Warehouse Management System ==========" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Delete a product" << endl;
        cout << "3. Replace a product" << endl;
        cout << "4. Search for a product" << endl;
        cout << "5. Sort products" << endl;
        cout << "6. Save products to file" << endl;
        cout << "7. Load products from file" << endl;
        cout << "8. Exit" << endl;
        cout << "9. Display all products" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch ((MenuOption)choice)
        {
        case DISPLAY:
            display_all_products(list, count);
            break;
        case ADD:
            add_product_data(list, count, capacity);
            break;
        case DELETE:
            delete_product_data(list, count);
            break;
        case REPLACE:
            replace_product_data(list, count);
            break;
        case SEARCH:
        {
            int opt;
            cout << endl << "1. By name" << endl;
            cout << "2. By manufacturer" << endl;
            cout << "3. By price" << endl;
            cout << "4. By category" << endl;
            cout << "5. By arrival date" << endl;
            cout << "6. By expiration date" << endl;
            cout << "Enter your choice: ";
            cin >> opt;
            switch (opt)
            {
            case 1: search_by_name(list, count); break;
            case 2: search_by_manufacturer(list, count); break;
            case 3: search_by_price(list, count); break;
            case 4: search_by_category(list, count); break;
            case 5: search_by_arrival_date(list, count); break;
            case 6: search_by_expiration_date(list, count); break;
            default: cout << endl << "Invalid search option." << endl;
            }
            break;
        }
        case SORT:
        {
            int opt;
            cout << endl << "1. By price" << endl;
            cout << "2. By category" << endl;
            cout << "Enter your choice: ";
            cin >> opt;
            switch (opt)
            {
            case 1: sort_by_price(list, count); break;
            case 2: sort_by_category(list, count); break;
            default: cout << endl << "Invalid sort option." << endl;
            }
            break;
        }
        case SAVE:
            cout << endl << "Enter the filename to save the products to: ";
            clear_input_buffer();
            cin.getline(file_name, FILE_NAME_LENGTH);
            save_to_file(list, count, file_name);
            break;
        case LOAD:
            cout << endl << "Enter the filename to load the products from: ";
            clear_input_buffer();
            cin.getline(file_name, FILE_NAME_LENGTH);
            load_from_file(list, count, capacity, file_name);
            break;
        case EXIT:
            cout << endl << "Exiting the program." << endl;
            delete[] list;
            return 0;
        default:
            cout << endl << "Invalid choice." << endl;
        }
    }
}