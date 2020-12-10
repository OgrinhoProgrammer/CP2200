#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class Account
{
private:
	string name;
	string address;
	int accountNumber;
	double accountBalance;
	long int randMax = 900000000;
	long int randMin = 100000000;

public:
	Account()
	{
		name = "";
		address = "";

		srand((unsigned)time(NULL));

		accountNumber = rand() % (randMax - randMin) + randMin;

		accountBalance = 0.0;
	}

	Account(string customerName, string customerAddress, double customerAccountBalance)
	{
		name = customerName;
		address = customerAddress;

		accountBalance = customerAccountBalance;

		srand((unsigned)time(NULL));
		accountNumber = rand() % (randMax - randMin) + randMin;
	}

	void setName(string);
	void setAdress(string);
	void setAccountNumber(int);
	void setAccountBalance(double);

	string getName();
	string getAddress();
	
	int getAccountNumber();
	double getAccountBalance();

	double deposit(Account[], int, int, double);
	double withdraw(Account[], int, int, double);
	int searchAccount(Account[], int, int);
	void print();

};

void Account::setName(string customerName)
{
	name = customerName;
}

void Account::setAdress(string customerAdress)
{
	address = customerAdress;
}

void Account::setAccountNumber(int costumerAccountNumber)
{
	accountNumber = costumerAccountNumber;
}

void Account::setAccountBalance(double costumerAccountBalance)
{
	accountBalance = costumerAccountBalance;
}

string Account::getName()
{
	return name;
}

string Account::getAddress()
{
	return address;
}

int Account::getAccountNumber()
{
	return accountNumber;
}

double Account::getAccountBalance()
{
	return accountBalance;
}

double Account::deposit(Account customer[], int size, int index, double customerDeposit)
{
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			customer[i].setAccountBalance(customer[i].accountBalance += customerDeposit);
			return customer[i].accountBalance;
		}
	}
	return 0;
}

double Account::withdraw(Account customer[], int size, int index, double withdraw)
{
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			if (customer[i].accountBalance >= withdraw)
			{
				customer[i].setAccountBalance(customer[i].accountBalance -= withdraw);
				return customer[i].accountBalance;
			}

			else
				cout << "The amount was higher than the balance!\n\n";
		}

		return 0;
	}

}

int Account::searchAccount(Account acc[], int size, int customerAccountNumber)
{
	for (int i = 0; i < size; i++)
	{
		if (acc[i].accountNumber == customerAccountNumber)
			return i;
	}

	return -1;
}


void::Account::print()
{
	srand((unsigned)time(NULL));

	string menu = "1. Add a new customer account\n2. Find and display the account information\n3. Quit\n\n";
	string menuAccountInfo = "1. Change address\n2. Deposit\n3. Withdraw.\n4. Quit\n\n";

	int choice;

	const int size = 500;
	Account *customer = new Account[size];
	int newCostumer = 0;

	string customerName;
	string customerAddress;
	double customerAccountBalance = 0;

	while (true)
	{
		cout << menu;
		cin >> choice;
		cout << endl;
		cin.ignore();

		if (choice == 1)
		{

			for (int i = 0; i  < size; i++)
			{
				if (i == newCostumer)
				{
					cout << "Name: ";
					getline(cin, customerName);
					customer[i].setName(customerName);

					cout << endl;

					cout << "Address: ";
					getline(cin, customerAddress);
					customer[i].setAdress(customerAddress);

					long int randMax = 900000000;
					long int randMin = 100000000;

					customer[i].setAccountNumber(rand() % (randMax - randMin) + randMin);

					cout << endl;
					break;
				}
			}

			cout << "Would you like to deposit?\n";
			cout << "1. Yes\n2. No\n\n";
			cin >> choice;

			if (choice == 1)
			{
				for (int i = 0; i < size; i++)
				{
					if (i == newCostumer)
					{
						cout << "How much would you like to deposit? ";
						cin >> customerAccountBalance;
						customer[i].setAccountBalance(customerAccountBalance);
					}

				}
			}

			if (choice == 1 || choice == 2)
			{
				for (int i = 0; i < size; i++)
				{
					if (i == newCostumer)
					{
						cout << "\nThe registration was successful!\n" <<
						"\nName: " << customer[i].getName() <<
						"\nAddress: " << customer[i].getAddress() <<
						"\nAccount Number: " << customer[i].getAccountNumber() <<
						"\nBalance: " << '$' << fixed << setprecision(2) << customer[i].getAccountBalance() << "\n\n";

						newCostumer++;
						break;
					}
				}
			}	

			else 
			{
				cout << "Invalid output!" << endl;
				break;
			}
		}

		else if (choice == 2)
		{
			cout << menuAccountInfo;
			cin >> choice;

			if (choice == 1)
			{
				cout << "Your account number: ";
				cin >> choice;
				int search = searchAccount(customer, size, choice);

				for (int i = 0; i < size; i++)
				{
					if (search != -1)
					{
						cout << "Welcome back!\n";
						cout << "Your address is " << customer[search].getAddress() << "\n\n";
						cout << "What is the new address? ";
						cin.ignore();
						getline(cin, customerAddress);
						customer[search].setAdress(customerAddress);

						cout << endl;
						cout << "Your address now is " << customer[search].getAddress() << "\n\n";

						break;
					}

					else
					{
						cout << "Account number does not exist in our system!\n\n";
						break;
					}
				}

			}

			if (choice == 2)
			{
				cout << "Your account number: ";
				cin >> choice;
				int search = searchAccount(customer, size, choice);
				for (int i = 0; i < size; i++)
				{
					if (search != -1)
					{
						cout << "Your balance is " << customer[search].getAccountBalance() << "\n\n";
						cout << "How much would you like to deposit? ";
						cin >> customerAccountBalance;

						deposit(customer, size, search, customerAccountBalance);


						cout << endl;
						cout << "Your balance now is $" << customer[search].getAccountBalance() << "\n\n";

						break;
					}
				}
			}

			if (choice == 3)
			{
				double withdrawCash;

				cout << "Your account number: ";
				cin >> choice;
				int search = searchAccount(customer, size, choice);
				for (int i = 0; i < size; i++)
				{
					if (search != -1)
					{
						cout << "Your balance is " << customer[search].getAccountBalance() << "\n\n";
						cout << "How much would you like to withdraw? ";
						cin >> withdrawCash;

						withdraw(customer, size, search, withdrawCash);


						cout << endl;
						cout << "Your balance now is $" << customer[search].getAccountBalance() << "\n\n";

						break;
					}
				}

			}


			if (choice == 4)
				exit(0);
		}

		else if (choice == 3)
			exit(0);

		else
			cout << "Invalid choice!\n\n";
	}


}

int main()
{
	const int SIZE = 500;
	Account* customers = new Account[SIZE];
	
	Account customer2("Kevin", "1718 Quentin Rd", 2000);

	for (int i = 0; i < SIZE; i++)
	{
		customers[i].print();
	}


	delete[] customers;

	return 0;
}
