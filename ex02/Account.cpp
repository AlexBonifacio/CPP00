#include "Account.hpp"
#include <ctime> //std::time_t
#include <iostream> //std::cout
#include <iomanip> //std::setw

using std::cout;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() : 
	_accountIndex(_nbAccounts),
	_amount(_totalAmount),
	_nbDeposits(0),
	_nbWithdrawals(0)
{}

Account::Account(int initial_deposit) : 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	cout 	<< " index:" << _accountIndex 
			<< ";amount:" << _amount 
			<< ";created" 
			<< '\n'; 
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
	_displayTimestamp();
	cout 	<< " index:" << _accountIndex 
			<< ";amount:" << _amount 
			<< ";closed" 
			<< '\n';
}



int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << " accounts:" << getNbAccounts() << ";";
	cout << "total:" << getTotalAmount() << ";";
	cout << "deposits:" << getNbDeposits() << ";";
	cout << "withdrawals:" << getNbWithdrawals();
	cout << '\n';
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout << " index:" << _accountIndex;
	cout << ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	cout << ";deposit:" << deposit;
	cout << ";amount:" << _amount;
	cout << ";nb_deposits:" << _nbDeposits;
	cout << '\n';
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << " index:" << _accountIndex;
	cout << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		cout << ";withdrawal:refused";
		cout << '\n';
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << ";withdrawal:" << withdrawal;
	cout << ";amount:" << _amount;
	cout << ";nb_withdrawals:" << _nbWithdrawals;
	cout << '\n';
	_totalAmount -= withdrawal;
	return true;
}

int Account::checkAmount(void) const
{
	_displayTimestamp();
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	cout 	<< " index:" << _accountIndex 
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals;	
	cout << '\n';
}

// tm_year = years since 1900
// tm_mon = months since January [0,11]
// tm_mday = day of the month [1,31]
// tm_hour = hours since midnight [0,23]
// tm_min = minutes after the hour [0,59]
void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(NULL);
	std::tm *now = std::localtime(&time);

	std::cout << '['
			  << (now->tm_year + 1900) // NOLINT (magic number)
			  << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
			  << std::setw(2) << now->tm_mday << '_'
			  << std::setw(2) << now->tm_hour
			  << std::setw(2) << now->tm_min
			  << std::setw(2) << now->tm_sec
			  << ']';
}
