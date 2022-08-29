/* Test File */

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

const int SIZE = 4;

string toppings[4] = { "sprinkles", "chocolate chips", "whipped cream", "caramel"};
string stdDrinks[SIZE] = { "Espresso", "Americano", "Latte", "Frappe" };

class StandardDrinkOrder {
public:
	StandardDrinkOrder() {
		drink = "";
		price = 0.00;
	}
	StandardDrinkOrder(int sel) {
		drink = stdDrinks[sel];
		price = sel * 1.00;
	}
	double getPrice() {
		return price;
	}
	void setPrice(double newPrice) {
		price = newPrice;
	}
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
	DrinkOrder() {
		total = 0;
		numDrinks = 0;
	}
	void addDrink(StandardDrinkOrder d) {
		drinkArray[numDrinks] = d;
		total += d.getPrice();
	}
	double getTotal() {
		return total;
	}
	int numDrinks;
private:
	StandardDrinkOrder drinkArray[10];
	double total;
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
	int getNumOfOrders() {
		return numberOfOrders;
	}
	void displayOrder() {

	}
	void incNumOrders() {
		numberOfOrders++;
	}
	void addOrder(DrinkOrder orderToQueue) {
		queue[numberOfOrders] = orderToQueue;
		incNumOrders();
	}	
private:
	int numberOfOrders;
	DrinkOrder queue[10];
};
class Barista {
public:
	string name;
};
/*class POSGUI {//I'm not sure how to implement this the way I want it....thinking emoji
public:
	void displayTotal(DrinkOrder d1) {

	}
	void displayMenu() {

	}
	void displayInit() {

	}
private:
	string name;
};*/
void displaySplashScreen() {
	for (int i = 0; i < 5; i++) {
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	}
	cout << setw(9) << " " << "Welcome to Cafe au Lait" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	}
}
void displayMenu() {
	cout << "\n\n\n\nMake a Selection for a drink" << endl;
	cout << "1. Latte\t2. Espresso\t 3. Americano\t4. Mocha Frappe\n";

}
void orderSelect() {//maybe into a fucntion in the GUI"POS Class

}
void paymentScreen(DrinkOrder d1 , OrderQueue q1) {
	cout << "The total for the order is $" << d1.getTotal() << endl;
	cout << "Did you want to pay with (1)Cash Or (2)Credit? Enter Selection: " << endl;
	int sel;
	cin >> sel;
	if (sel == 1) {
		double cashGiven;
		cout << "Enter Cash Amount: $";
		cin >> cashGiven;
		if (cashGiven < d1.getTotal()) {
			cout << "\nNot enough cash given, can not complete purchase.";
		}
		else {
			cout << "\nYour change will be $" << cashGiven - d1.getTotal() << endl;
			q1.addOrder(d1);
		}
	}
	if (sel == 2) {
		cout << "Amount being charged to your card is $" << d1.getTotal() << endl;
		cout << "Please wait for Credit Card processor..." << endl; //okay here I will have a file that says success, failure, sucess for cc payments
		//if (ccpayment == "success") {
		//	cout << "hooray" << endl;
		//}
		//if (ccpayment != "success") {
		//	cout << "Card Declined" << endl;
		//}
	}

}
int main()
{
	displaySplashScreen();
	cout << "Enter any character to Start order ";
	char blank;
	cin >> blank;
	DrinkOrder d1;
	OrderQueue q1;
	displayMenu();

	char orderSel = 'y';
	for (int i = 0; i < 3; i++) {
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	}
	while (d1.numDrinks < 10 && orderSel != 'n'){
		int drinkSel; //3
		cin >> drinkSel;
		StandardDrinkOrder beverage(drinkSel);
		d1.addDrink(beverage);
		cout << "Can I get you any more drinks? (y/n)";
		cin >> orderSel;
		displayMenu();
	}
	for (int i = 0; i < 3; i++) {
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
	}
	paymentScreen(d1,q1);
	//cout << "Total: $" << d1.getTotal();

}
