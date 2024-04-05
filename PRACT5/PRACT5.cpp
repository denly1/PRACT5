#include <iostream>
#include <cstdlib> // Для использования system("cls") или system("clear")
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Средства успешно внесены." << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Средства успешно сняты." << endl;
        }
        else {
            cout << "Недостаточно средств на счете." << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        double monthlyInterestRate = interestRate / 12;
        return balance * monthlyInterestRate;
    }

    void setInterestRate(double rate) {
        interestRate = rate;
        cout << "Процентная ставка обновлена." << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Перевод успешно выполнен." << endl;
        return true;
    }
    else {
        cout << "Недостаточно средств на счете для перевода." << endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    BankAccount account1(12345, 1000);
    BankAccount account2(54321, 500);

    int choice;
    double amount;
    while (true) {
        system("cls"); // Очистка экрана перед выводом меню
        cout << "Выберите действие:" << endl;
        cout << "1. Внести средства на счет." << endl;
        cout << "2. Снять средства со счета." << endl;
        cout << "3. Получить баланс." << endl;
        cout << "4. Получить сумму процентов." << endl;
        cout << "5. Обновить процентную ставку." << endl;
        cout << "6. Получить номер банковского счета." << endl;
        cout << "7. Перевести средства с одного счета на другой." << endl;
        cout << "0. Выйти из программы." << endl;
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите сумму для внесения: ";
            cin >> amount;
            account1.deposit(amount);
            break;
        case 2:
            cout << "Введите сумму для снятия: ";
            cin >> amount;
            account1.withdraw(amount);
            break;
        case 3:
            cout << "Баланс на счете: " << account1.getBalance() << endl;
            break;
        case 4:
            cout << "Сумма процентов на счете: " << account1.getInterest() << endl;
            break;
        case 5:
            cout << "Введите новую процентную ставку: ";
            cin >> amount;
            account1.setInterestRate(amount);
            break;
        case 6:
            cout << "Номер банковского счета: " << account1.getAccountNumber() << endl;
            break;
        case 7:
            cout << "Введите сумму для перевода: ";
            cin >> amount;
            transfer(account1, account2, amount);
            break;
        case 0:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Неверный выбор." << endl;
            break;
        }
        cout << "Нажмите любую клавишу для продолжения...";
        cin.ignore(); // Очистка буфера ввода
        cin.get(); // Ожидание ввода пользователя перед очисткой экрана
    }

    return 0;
}
