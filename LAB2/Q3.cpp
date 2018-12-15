// MATEO S PEREZ OLMEDO
// CECS 282 LAB 2 - 3
#include <iostream>
using namespace std;


class Account
{
	private:
		double balance;				//declare and initialize some variables we will
		const double PENALTY = 20;	//need later in the functions
		double doubleInvestment;
		double annualInterestRate;
		double monthlyInterestRate;
		int month = 0;
	public:
		Account(double balance){ //constructor to add the balance to the obj
		this->balance = balance;
		}
		
		Account(double balance, double annualInterestRate){ //contructor that
		this->balance = balance;							//takes in 2 variables
		this->annualInterestRate = annualInterestRate;		//for the compound interest
		this->monthlyInterestRate = (annualInterestRate/12)/100;//and sets up the monthly
		this->doubleInvestment = balance*2;					//rate and investment x 2
		}
				
		void deposit(double money){ //this method adds the money variable to the 
			balance += money;		//total balance
		}
		
		void withdraw(double money){ //this method withdraws money from the total
			if (money > balance){	//balance and if you withdraw more than you have
				balance -= PENALTY;	//it takes away $20
				cout << "You tried to withdraw more money than you had, ";
				cout << "we will deduce 20$ from your balance."<<endl;
			}
			else{
				balance -= money;
			}
		}	
		
		void compound_monthly_rate(){ //find the months to get the double
			while(balance < doubleInvestment){//of the investments
				balance += balance * monthlyInterestRate;
				month++;
			}
		}
		
		double get_balance(){ //this getter returns the balance of the obj
			return balance;
		}
		
		int get_months(){	//this getter returns the amount of months to double
			return month;	//the invstment
		}
};

class Bank
{
	private:
		const string SAVE = "S";//create variables that will be used to compare
		const string CHECK = "C";//to see wich type of account is used
		Account savings; //create the account obj
		Account checkings;

	public:
		
	Bank() : savings(0), checkings(0){ //pass in the objs parameters
	}
	void deposit(double amount, string account){ 
		if (account == SAVE){ //if the string passed is an S we do the 
			savings.deposit(amount);//opertation on the savings account
		}
		else{ //if it is a C we do it on the checkings
			checkings.deposit(amount);
		}
	}
	
	void withdraw(double amount, string account){
		if (account == SAVE){//if the string passed is an S we do the 
			savings.withdraw(amount);//opertation on the savings account
		}
		else{//if it is a C we do it on the checkings
			checkings.withdraw(amount);
		}
	}
	
	void transfer(double amount, string account){
		if (account == SAVE){//if the string passed is an S we do the 
			if(savings.get_balance() < amount){//opertation on the savings account
				savings.withdraw(amount); // if the amount withdrawn exceeds the balance
			}								//we withdraw $20
			else{
				checkings.deposit(amount);
				savings.withdraw(amount);
			}
		}
		else{//if it is a C we do it on the checkings
			if(checkings.get_balance() < amount){// if the amount withdrawn exceeds the balance
				checkings.withdraw(amount);//we withdraw $20
			}
			else{
				savings.deposit(amount);
				checkings.withdraw(amount);
			}
		}
	}
	
	void print_balances(){//this method prints out the two balances
		cout.precision(2);
		cout << "Checkings account balance: $" << fixed << checkings.get_balance() << endl; 
		cout << "Savings account balance: $" << fixed << savings.get_balance() << endl;
	}
};

int main(){
Bank my_bank;
cout << "Inital bank balances: \n";
my_bank.print_balances(); /* set up empty accounts */

cout << "Adding some money to accounts: \n";
my_bank.deposit(1000, "S"); /* deposit $1000 to savings */
my_bank.deposit(2000, "C"); /* deposit $2000 to checking */
my_bank.print_balances();

cout << "Taking out $1500 from checking,and moving $200 from";
cout << " savings to checking.\n";
my_bank.withdraw(1500, "C"); /* withdraw $1500 from checking */
my_bank.transfer(200, "S"); /* transfer $200 from savings */ 
my_bank.print_balances();

cout << "Trying to transfer $900 from Checking.\n";
my_bank.transfer(900,"C");
my_bank.print_balances();

cout << "trying to transfer $900 from Savings.\n";
my_bank.transfer(900,"S");
my_bank.print_balances();

return 0; 
}
