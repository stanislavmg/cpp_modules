#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	if (initial_deposit >= 0)
		_amount = initial_deposit;
	else
		_amount = 0;
	Account::_totalAmount += _amount;
	_accountIndex = _nbAccounts++;
	_nbDeposits = _nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t tst = std::time(NULL);
	std::tm	*t = std::localtime(&tst);

	char	buf[256];
	std::strftime(buf, 256, "[%Y%m%d_%H%M%S] ", t);
	std::cout << buf;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit >= 0)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";" 
			<< "deposit:" << deposit << ";";
		_amount += deposit;
		++_nbDeposits;
		std::cout << "amount:" << _amount << ";"
			<< "nb_deposit:" << _nbDeposits << std::endl;
		++Account::_totalNbDeposits;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal >= 0 && withdrawal < _amount)
	{
		this->_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";"
			<< "withdrawals:" << withdrawal << ";";
		_amount -= withdrawal;
		++_nbWithdrawals;
		std::cout << "amount:" << _amount << ";"
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		Account::_totalNbWithdrawals++;
		return (1);
	}
	return (0);
}

int		Account::checkAmount( void ) const
{
	if (_amount > 0)
		return (1);
	return (0);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
} 

