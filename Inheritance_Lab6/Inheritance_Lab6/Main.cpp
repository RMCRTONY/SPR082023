#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "CreditAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <fstream>
#include "Helper.h"



int main() {

	CreditAccount credit;
	SavingsAccount savings;
	CheckingAccount checking;
	
	std::fstream fin;
	fin.open("BankStatement.txt");

	if (fin.is_open()) { //checking, savings, credit
		float tCH, tSA, tCR;
		fin >> tCH;
		checking.Deposit(tCH);
		fin.ignore(INT_MAX, '\n');
		fin >> tSA;
		savings.Deposit(tSA);
		fin.ignore(INT_MAX, '\n');
		fin >> tCR;
		credit.Deposit(tCR);
		fin.close();
	}
	else {
		checking.Deposit(4389.46);
		savings.Deposit(100000);
		credit.Deposit(500000);
	}


	int selection;
	int subSelection;
	bool looper = true;
	bool subLooper;
	while (looper) {
		selection = Helper::PrntMenu("~\n~ Welcome to BNK Credit Union! ~\nSelect the account you would like to access:\n1) Savings\t2) Checking\t3) Credit\t4) Exit");
		subLooper = true;
		switch (selection) {
		case 1:

			while (subLooper) {
				subSelection = Helper::PrntMenu("\nSavings:\n1) Deposit\t2) Withdraw\t3) View\t  4) Main Menu");

				switch (subSelection) {

				case 1:
					float ammount;
					std::cout << "\nEnter the ammount you are depositing: ";
					std::cin >> ammount;
					savings.Deposit(ammount);
					std::cout << "\n$" << ammount << " deposited to savings account!";
					break;

				case 2:
					std::cout << "\nEnter the ammount you are withwrawing: ";
					std::cin >> ammount;
					savings.Withdraw(ammount);
					break;

				case 3:
					std::cout << "\n$" << savings.GetBalance() << " avalilable within savings account.";
					break;
				
				case 4:
					subLooper = false;
					break;
				}
			}
			
			break;
		
		case 2:

			while (subLooper) {
				subSelection = Helper::PrntMenu("\nChecking:\n1) Deposit\t2) Withdraw\t3) View\t  4) Main Menu");

				switch (subSelection) {

				case 1:
					float ammount;
					std::cout << "\nEnter the ammount you are depositing: ";
					std::cin >> ammount;
					checking.Deposit(ammount);
					std::cout << "\n$" << ammount << " deposited to checking account!";
					break;

				case 2:
					
					std::cout << "\nEnter the ammount you are withwrawing: ";
					std::cin >> ammount;
					checking.Withdraw(ammount);
					break;

				case 3:
					std::cout << "\n$" << checking.GetBalance() << " avalilable within checking account.";
					break;

				case 4:
					subLooper = false;
					break;
				}

			}
			
			break;
		
		case 3:

			while (subLooper) {
				subSelection = Helper::PrntMenu("\nCredit:\n1) Deposit\t2) Withdraw\t3) View\t  4) Main Menu");

				switch (subSelection) {

				case 1:
					float ammount;
					std::cout << "\nEnter the ammount you are depositing: ";
					std::cin >> ammount;
					credit.Deposit(ammount);
					std::cout << "\n$" << ammount << " deposited to credit account!";
					break;

				case 2:
					
					std::cout << "\nEnter the ammount you are withwrawing: ";
					std::cin >> ammount;
					credit.Withdraw(ammount);
					break;

				case 3:
					std::cout << "\n$" << credit.GetBalance() << " avalilable within credit account.";
					break;

				case 4:
					subLooper = false;
					break;
				}
			}
			
			break;
		
		case 4:
			looper = false;
			break;
		}

	}

	std::fstream fout; //fstream object 
	fout.open("BankStatement.txt", std::ios_base::out); //open bankStatement, files stored as "checking, savings, credit" in that order

	if (fout.is_open()) {

		fout << checking.GetBalance() << '\n' << savings.GetBalance() << '\n' << credit.GetBalance();

		fout.close();
	}


	return 0;
}

