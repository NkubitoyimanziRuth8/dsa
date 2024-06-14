#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Struct to represent an inventory item
struct InventoryItem {
    int item_id;
    string item_name;
    int item_quantity;
    string item_registration_date;

    // Constructor to initialize an InventoryItem
    InventoryItem(int id, const string& name, int quantity, const string& reg_date)
        : item_id(id), item_name(name), item_quantity(quantity), item_registration_date(reg_date) {}
};

// Functor to compare InventoryItem by item_name for sorting
struct CompareItemByName {
    bool operator()(const InventoryItem& a, const InventoryItem& b) const {
        return a.item_name < b.item_name;
    }
};

// Global vector to store inventory items
vector<InventoryItem> inventory;

// Function to add a new item to the inventory
void addItem(int id, const string& name, int quantity, const string& reg_date) {
    InventoryItem item(id, name, quantity, reg_date);
    inventory.push_back(item);
}

// Function to list all items in the inventory
void listInventoryItems() {
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
        return;
    }

    // Sort inventory by item_name using a function object
    sort(inventory.begin(), inventory.end(), CompareItemByName());

    // Display items
    cout << setw(10) << "Item ID" << setw(20) << "Item Name" << setw(10) << "Quantity" << setw(15) << "Reg Date" << endl;
    for (vector<InventoryItem>::const_iterator it = inventory.begin(); it != inventory.end(); ++it) {
        cout << setw(10) << it->item_id << setw(20) << it->item_name << setw(10) << it->item_quantity
             << setw(15) << it->item_registration_date << endl;
    }
}

// Function to show help information
void showHelp() {
    cout << "Commands syntaxes:" << endl;
    cout << "itemadd <item_id> <item_name> <quantity> <registration_date>" << endl;
    cout << "itemslist" << endl;
    cout << "help" << endl;
    cout << "exit" << endl;
}

int main() {
    string command;
    cout << "Inventory Management System" << endl;
    cout << "Type 'help' for commands." << endl;

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "itemadd") {
            int id, quantity;
            string name, reg_date;
            cin >> id >> name >> quantity >> reg_date;
            addItem(id, name, quantity, reg_date);
            cout << "Item added to inventory." << endl;
        } else if (command == "itemslist") {
            listInventoryItems();
        } else if (command == "help") {
            showHelp();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command. Type 'help' for commands." << endl;
        }
    }

    cout << "Program exited." << endl;

    return 0;
}

