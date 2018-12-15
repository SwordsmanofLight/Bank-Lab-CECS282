// MATEO S PEREZ OLMEDO
// CECS 282 LAB 2 - 2
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
				cout << "we will deduce $20 from your balance."<<endl;
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

int main()
{
	char input; //will store variable to tell us if we want to do a custom investment
	double invest = 0;
	double rate = 0;
	cout<<"The current account balance is $10,000.00 and has an annual interest rate of 6%"<<endl;
	cout<<"Would you like to enter your own balace and rate? (Enter Y or N)"<<endl;
	cin >> input;
	if(input == 'Y' || input == 'y'){ //if statement to see if we will do a custom investment
		cout<<"Please enter your initial balance"<<endl;
		cin>>invest;
		cout<<"Please enter the annual interest rate"<<endl;
		cin>>rate;
		Account my_account(invest,rate); //create the account object with the custom variables
		my_account.compound_monthly_rate();//get the monthly rate and time
		cout.precision(2);
		cout<<"It will take "<<my_account.get_months();//dislay the months it will take to double
		cout<<" months to double your investment of $"<<fixed<<invest<<endl;
		
	}
	else{ //else we use our default values given in the instructions
		invest = 10000;
		rate = 6;
		Account my_account(invest,rate); //create the account object with the custom variables
		my_account.compound_monthly_rate();//get the monthly rate and time
		cout.precision(2);
		cout<<"It will take "<<my_account.get_months();//dislay the months it will take to double
		cout<<" months to double your investment of $"<<invest<<endl;
	}
	
	return 0;	
}

