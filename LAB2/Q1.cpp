// MATEO S PEREZ OLMEDO
// CECS 282 LAB 2 - 1
#include <iostream>
using namespace std;

class Account
{
	private:
		double balance;	//declare our variable that will hold the balance
		const double PENALTY = 20; //and the penalty constant
	public:
		Account(double balance){ //constructor to add the balance to the obj
		this->balance = balance;
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
		
		double get_balance(){ //this getter returns the balance of the obj
			return balance;
		}
};

int main(){
   Account my_account(100);     // Set up my account with $100 
   my_account.deposit(50);
   my_account.withdraw(175);   // Penalty of $20 will apply 
   my_account.withdraw(25);

   cout << "Account balance: " << my_account.get_balance() << "\n";
   
   my_account.withdraw(my_account.get_balance());  // withdraw all
   cout << "Account balance: " << my_account.get_balance() << "\n";
  
   return 0;   
}
