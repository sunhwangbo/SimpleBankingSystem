#pragma once

#ifndef __BankingSystem__
#define __BankingSystem__

typedef	struct {
	int id;
	char name[10];
	int balance;
}Account;

class BankingSystem {

// variable
public:
	int num = 0;
	Account account[100];
// func
public:
	void make();
	void menu();
	void deposit();
	void withdraw();
	int account_check(int);
	void showAllAccount();
};

#endif