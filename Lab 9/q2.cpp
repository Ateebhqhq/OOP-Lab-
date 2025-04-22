#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;
public:
    MenuItem(string d, double p) : dishName(d), price(p) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string d, double p) : MenuItem(d, p) {}
    void showDetails() override {
        cout << "Appetizer: " << dishName << "Price: " << price << " coins of crispy delight" << endl;
    }
    void prepare() override {
        cout << "Preparing Appetizer: khaana dedo" << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string d, double p) : MenuItem(d, p) {}
    void showDetails() override {
        cout << "Main Course: " << dishName << "Price: " << price << " golden duck" << endl;
    }
    void prepare() override {
        cout << "Preparing Main Course: hqhqhhqq" << endl;
    }
};

int main() {
    MenuItem* m1 = new Appetizer("Mr Beast", 4.75);
    MenuItem* m2 = new MainCourse("Osama bin Laden", 9.11);

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();

    delete m1;
    delete m2;

    return 0;
}
