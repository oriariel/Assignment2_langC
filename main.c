#include "stdio.h"
#include "myBank.h"
bool BankIsOpen = true;

int main() {
	char act;
	while (BankIsOpen == true) {
		printf("Transaction type?\n");
		scanf("%c", &act);
		switch (act)
		{
		case 'O': {
			double money;
			printf("Initial deposit?:\n");
			if (scanf(" %lf", &money) == 1) {
				if (money >= 0) {
					NewAccount(money);
				}
				else {
					printf("Please enter a positive amount\n");
				}
			}
			else
			{
				printf("The number you have entered is no valid number, Please try again\n");
			}
			break;
		}
		case 'B': {
			int accountId;
			printf("Please enter your account id\n");
			if (scanf(" %d", &accountId) == 1) {
				if ((901 <= accountId) && (accountId <= 950)) {
					ChecktheBalance(accountId);
				}
				else {
					printf("You have entered a wrong account id, please try again\n");
					break;
				}
			}
			else
			{
				printf("The number or account are invalid, please try again\n");
			}
			break;
		}
		case 'D': {
			int accountId; double money;
			printf("Please enter your account id\n");
			if (scanf(" %d", &accountId) == 1) {
				if ((901 <= accountId && accountId <= 950)) {
					printf("Please insert the amount you want to deposite\n");
					if (scanf("%lf", &money) == 1) {
						if (money >= 0) {
							DepositMoney(accountId, money);
						}
						else {
							printf("You can only deposite a postive number\n");
						}
					}
				}
				else {
					printf("You have entered a wrong account id, please try again\n");
					break;
				}
			}
			else {
				printf("The number or account or amount of deposite you have entered is wrong, please try again\n");
			}
			break;
		}
		case 'W': {
			int accountId; 
			double money;
			printf("Please enter your account id\n");
			if (scanf(" %d", &accountId) == 1) {
				if ((901 <= accountId && accountId =< 950)) {
					printf("Please insert the amount of money you want to withdraw\n");
					if (scanf(" %lf", &money) == 1) {
						if (money >= 0) {
							DepositMoney(accountId, -1 * money); //why -1?
						}
						else {
							printf("Please enter a positive amount\n");
						}
					}
				}
				else {
					printf("You have entered a wrong account id, please try again\n");
					break;
				}
			}
			else {
				printf("The number or account or amount of withdraw you have entered is wrong, please try again\n");
			}
			break;
		}
		case 'C': {
			int accountId;
			printf("Please enter your account id\n");
			if (scanf(" %d", &accountId) == 1) {
				if ((901 <= accountId && accountId = < 950)) {
					ClosetheAccount(accountId);
				}
				else {
					printf("You have entered a wrong account id, please try again\n");
					break;
				}
			}
			break;
		}
		case 'I': {
			double pre;
			printf("Please enter you interest rate:\n");
			if (scanf(" %lf", &pre) == 1) {
				if (pre >= 0) {
					pre = (pre / 100) + 1;
					InterestRate(pre);
				}
				else {
					printf("You have entered a wrong account id, please try again\n");
				}
			}
			else {
				printf("You have enteres an invalid precent, please try again\n");
			}
			break;
		}
		case 'P': {
			BankAccountsStatus();
			break;
		}
		case 'E': {
			Exit();
			BankIsOpen = false;
			break;
		}
		default: {
			printf("You have entered an invalid action, please try again\n");
		}
		}
		if (BankIsOpen == false) {
			printf("We are sorry but the bank is closed.\n");
		}
	}
}