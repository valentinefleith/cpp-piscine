#include "Account.hpp"

Account::Account(int initial_deposit) {
	_accountIndex = 0;
	_amount = initial_deposit;
	_nbDeposits = 1;
	_nbWithdrawals = 0;
}
