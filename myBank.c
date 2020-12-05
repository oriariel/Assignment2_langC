#include "myBank.h"

double BankAccount[Rows][Columns] = { {0} };
void NewAccount(double money) {
	for (int i = 0; i < Columns; i++) {
		if (BankAccount[activeAccount][i] == 0) {
			BankAccount[activeAccount][i] = 1;
			BankAccount[balanceAccount][i] = money;
			printf("Welcome to our bank, your new Account has been created successfully, your account id is:%d, your balance is:%0.2lf\n", biggestAccountNum+ i, BankAccount[balanceAccount][i]);
			break;
		}
		if (i == 49) {
			printf("We are sorry our bank is full.\n");
		}
	}
}
void ChecktheBalance(int accountId) {
	if (BankAccount[activeAccount][accountId - biggestAccountNum] == 1) {
		printf("Account balance is: %.2lf\n", BankAccount[balanceAccount][accountId - biggestAccountNum]);
	}
	else {
		printf("We are sorry, your account is currently closed and has zero balance.\n");
	}
}
void DepositMoney(int accountId, double money) {
	if (money + BankAccount[balanceAccount][accountId - biggestAccountNum] >= 0) {
		if (BankAccount[activeAccount][accountId - biggestAccountNum] == 1) {
			double temp = 0;
			temp = BankAccount[balanceAccount][accountId - biggestAccountNum] + money;
			BankAccount[balanceAccount][accountId - biggestAccountNum] = temp;
		//	BankAccount[bank_balance][accountId - biggestAccountNum] not sure
			printf("your recent balance is:%.2lf\n", temp);
		}
		else {
			printf("We are sorry you can't deposit to a closed account\n");
		}
	}
	else {
		printf("You can't deposite insufficient funds, please try again\n");
	}
}
void ClosetheAccount(int accountId) {
	if (BankAccount[activeAccount][accountId - biggestAccountNum] == 1) {
		BankAccount[activeAccount][accountId - biggestAccountNum] = 0;
		BankAccount[balanceAccount][accountId - biggestAccountNum] = 0;
		printf("The account number: %d has been closed.\n", accountId);
	}
	else {
		printf("The account id you enterd has already been closed.\n");
	}
}
void InterestRate(double precent) {
	bool flag = false;
	for (int i = 0; i < Columns; i++) {
		if (BankAccount[activeAccount][i] == 1) {
			double ans = 0;
			ans = BankAccount[bank_balance][i];
			ans = ans * precent;
			BankAccount[balanceAccount][i] = ans;
			flag = true;
		}
	}
	if (flag == true) {
		printf("interest rate has been applied to all accounts\n");
	}
	else {
		printf("no open accounts to apply the interest rate\n");
	}
}
void BankAccountsStatus() {
	bool flag = false;
	for (int i = 0; i < Columns; i++) {
		if (BankAccount[activeAccount][i] == 1) {
			printf("account id:%d has a balance of:%.2lf\n", biggestAccountNum + i, BankAccount[balanceAccount][i]);
			flag = true;
		}
	}
	if (flag == false) {
		printf("The bank has no open accounts\n");
	}
}
void Exit() {
	for (int i = 0; i < Columns; i++) {
		if (BankAccount[activeAccount][i] == 1) {
			BankAccount[activeAccount][i] = 0;
			BankAccount[balanceAccount][i] = 0;
		}
	}
	printf("All the accounts have been closed.\n");
}