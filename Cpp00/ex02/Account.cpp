#include "Account.hpp"

#include <__ostream/basic_ostream.h>

#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_amount)
    : _accountIndex(_nbAccounts),
      _amount(initial_amount),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    _totalAmount += initial_amount;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
              << std::endl;
}

void Account::makeDeposit(int deposit_value) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;

    _amount += deposit_value;
    _nbDeposits++;
    _totalNbDeposits++;

    std::cout << ";deposit:" << deposit_value << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";withdrawal:";

    if (withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

    return true;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(nullptr);
    std::tm* ltm = std::localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year << std::setw(2) << std::setfill('0')
              << ltm->tm_mon + 1 << std::setw(2) << std::setfill('0')
              << ltm->tm_mday << "_" << std::setw(2) << std::setfill('0')
              << ltm->tm_hour << std::setw(2) << std::setfill('0')
              << ltm->tm_min << std::setw(2) << std::setfill('0') << ltm->tm_sec
              << "] ";
}

void Account::displayAccountsInfos(void) {
    if (getNbAccounts() > 0) {
        _displayTimestamp();
        std::cout << "accounts" << getNbAccounts()
                  << ";total:" << getTotalAmount()
                  << ";deposits:" << getNbDeposits()
                  << ";withdrawals:" << getNbWithdrawals() << std::endl;
    }
}
