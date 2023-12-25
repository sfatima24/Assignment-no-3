#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    int productId;
    string productName;
    double price; 
    Product(int id, const string& name, double p) : productId(id), productName(name), price(p) {}
    void displayDetails() const {
        cout << "Product ID: " << productId << "\nProduct Name: " << productName << "\nPrice: $" << price << endl;
    }
};

class ShoppingCart {
private:
    static const int MAX_PRODUCTS = 10;
    Product* products[MAX_PRODUCTS];
    int numProducts;

public:
    
    ShoppingCart() : numProducts(0) {}
    void addProduct(Product* product) {
        if (numProducts < MAX_PRODUCTS) {
            products[numProducts++] = product;
        }
        else {
            cout << "Cart is full. Cannot add more products.\n";
        }
    }

    void displayProducts() const {
        std::cout << "Products in the cart:\n";
        for (int i = 0; i < numProducts; ++i) {
            products[i]->displayDetails();
           cout << "------------------------\n";
        }
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (int i = 0; i < numProducts; ++i) {
            totalCost += products[i]->price;
        }
        return totalCost;
    }
};

class User {
public:
    int userId;
    ShoppingCart* cart;  

    User(int id) : userId(id), cart(nullptr) {}

    void displayDetails() const {
        cout << "User ID: " << userId << endl;
    }
};

int main() {
    Product* product1 = new Product(1, "Laptop", 999.99);
    Product* product2 = new Product(2, "Smartphone", 599.99);
    Product* product3 = new Product(3, "Headphones", 79.99);

    User user1(101);
    User user2(102);

    ShoppingCart cart1;
    ShoppingCart cart2;
    user1.cart = &cart1;
    user2.cart = &cart2;
    cart1.addProduct(product1);
    cart1.addProduct(product2);
    cart2.addProduct(product2);
    cart2.addProduct(product3);
    user1.displayDetails();
    user1.cart->displayProducts();
    cout << "Total cost in the cart: $" << user1.cart->calculateTotalCost() << endl;
    delete product1;
    delete product2;
    delete product3;

    return 0;
}
