#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define biggestAccountNum 950
#define lowestAccountNum 901
#define Rows 2
#define Columns 50
#define activeAccount 0
#define balanceAccount 1

void NewAccount(double money);
void ChecktheBalance(int accountId);
void void DepositMoney(int accountId, double money);
void ClosetheAccount(int accountId);
void InterestRate(double precent);
void BankAccountsStatus();
void Exit();
