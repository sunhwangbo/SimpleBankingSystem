#include <iostream>
#include <string>>
#include "BankingSystem.h"

using namespace std;

int main(void) {
	BankingSystem bs;
	int status = 0;
	while (status != 5)
	{
		bs.menu();
		cout << "선택:";
		cin >> status;
		switch (status) {
		case 1:
			bs.make();
			break;
		case 2:
			bs.deposit();
			break;
		case 3:
			bs.withdraw();
			break;
		case 4:
			break;
		default:
			cout << "유효하지 않는 값입니다." << endl;
		}
	}

	return 0;
}
void BankingSystem::menu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
int BankingSystem::account_check(int id) {
	for (int i = 0; i < num; i++)
	{
		if (account[i].id == id)
			return i;
	}
	return -1;
}
void BankingSystem::make() {
	int temp;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID:";
	cin >> temp;
	if (account_check(temp) == -1){
		account[num].id = temp;
		cout << "이 름:";
		cin >> account[num].name;
		cout << "입금액:";
		cin >> account[num].balance;
		num++;
	}
	else
	{
		cout << "이미 존재하는 계좌입니다" << endl;
	}
}
void BankingSystem::deposit() {
	int temp;
	int index;
	int balance;
	cout << "[입  금]" << endl;
	cout << "계좌ID:";
	cin >> temp;
	if (index = account_check(temp) != -1)
	{
		cout << "입금액:";
		cin >> balance;
		account[index].balance += balance;
	}
	else {
		cout << "존재하지 않는 계좌입니다" << endl;
	}
}
void BankingSystem::withdraw() {
	int temp;
	int index;
	int balance;
	cout << "[출  금]" << endl;
	cout << "계좌ID:";
	cin >> temp;
	if (index = account_check(temp) != -1)
	{
		cout << "출금액:";
		cin >> balance;
		if (account[index].balance >= balance)
			account[index].balance -= balance;
		else
			cout << "잔액이 부족합니다." << endl;
	}
	else {
		cout << "존재하지 않는 계좌입니다" << endl;
	}
}
void BankingSystem::showAllAccount() {
	for (int i = 0; i < num; i++)
	{
		cout << "계좌ID: " << account[i].id << endl;
		cout << "이 름: " << account[i].name << endl;
		cout << "잔 액: " << account[i].balance << endl;
	}
	cout << endl;
}