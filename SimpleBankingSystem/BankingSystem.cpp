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
		cout << "����:";
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
			cout << "��ȿ���� �ʴ� ���Դϴ�." << endl;
		}
	}

	return 0;
}
void BankingSystem::menu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
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
	cout << "[���°���]" << endl;
	cout << "����ID:";
	cin >> temp;
	if (account_check(temp) == -1){
		account[num].id = temp;
		cout << "�� ��:";
		cin >> account[num].name;
		cout << "�Աݾ�:";
		cin >> account[num].balance;
		num++;
	}
	else
	{
		cout << "�̹� �����ϴ� �����Դϴ�" << endl;
	}
}
void BankingSystem::deposit() {
	int temp;
	int index;
	int balance;
	cout << "[��  ��]" << endl;
	cout << "����ID:";
	cin >> temp;
	if (index = account_check(temp) != -1)
	{
		cout << "�Աݾ�:";
		cin >> balance;
		account[index].balance += balance;
	}
	else {
		cout << "�������� �ʴ� �����Դϴ�" << endl;
	}
}
void BankingSystem::withdraw() {
	int temp;
	int index;
	int balance;
	cout << "[��  ��]" << endl;
	cout << "����ID:";
	cin >> temp;
	if (index = account_check(temp) != -1)
	{
		cout << "��ݾ�:";
		cin >> balance;
		if (account[index].balance >= balance)
			account[index].balance -= balance;
		else
			cout << "�ܾ��� �����մϴ�." << endl;
	}
	else {
		cout << "�������� �ʴ� �����Դϴ�" << endl;
	}
}
void BankingSystem::showAllAccount() {
	for (int i = 0; i < num; i++)
	{
		cout << "����ID: " << account[i].id << endl;
		cout << "�� ��: " << account[i].name << endl;
		cout << "�� ��: " << account[i].balance << endl;
	}
	cout << endl;
}