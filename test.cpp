/* Test File */

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int SIZE = 4;

string toppings[4] = { "sprinkles", "chocolate chips", "whipped cream", "caramel"};
string stdDrinks[SIZE] = { "Latte", "Americano", "Espresso", "Frappe" };

class StandardDrinkOrder {
public:
	StandardDrinkOrder(int sel) {
		drink = stdDrinks[sel];
	}
	double getPrice;
private:
	string drink;
	double price;
};
class CustomizedDrinkOrder : public StandardDrinkOrder{
public:
	void setSize(char size) {
		this->size = size;
	}
	void setType(string type) {
		this->type = type;
	}
	void setTemp(int temp) {
		this->temperature = temp;
	}
	void setSweetness(int temp) {
		this->temperature = temp;
	}
	void setToppings(int sel) { //gets toppings from global array
		this->toppings = toppings[sel];
	}
private:
	char size;
	string type;
	int temperature;
	int sweetness;
	string toppings;
};
class Customer {
public: 
	Customer(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	void setName(string n) {
		name = n;
	}

private:
	string name;
};
class DrinkOrder {
public:
	DrinkOrder();
	void addDrink(StandardDrinkOrder d) {
		drinks[numDrinks] = d;
		total += d.getPrice;
	}
	double getTotal() {
		return total;
	}
private:
	StandardDrinkOrder drinks[10];
	double total;
	int numDrinks;
};
class Cashier {
public:
	Cashier(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
private: 
	string name;
};
class OrderQueue {
public:

private:
	int numberOfOrders;
};
class Barista {
public:
	string name;
};
class POSGUI{
public:
	void displayTotal(DrinkOrder d1) {

	}
	void displayMenu() {

	}
	void displayInit() {

	}
private:
	string name;
};
int main()
{

}
