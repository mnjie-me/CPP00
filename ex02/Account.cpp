/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mari-cruz <mari-cruz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:59:16 by mari-cruz         #+#    #+#             */
/*   Updated: 2025/12/10 18:31:43 by mari-cruz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";total:" << _amount
	<< ";created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";total:" << _amount
	<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << p_amount
	<< ";deposit;" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits;" << _nbDeposits
	<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;
	if ((_amount -= withdrawal) < 0)
	{
		_displayTimestamp();
		_amount = p_amount;
		std::cout << p_amount
		<< ";withdrawal:refused" << std::endl;
		return (false);	
	}
	else
	{
		p_amount -= withdrawal;
		_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << p_amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return (true);
	}
}

int Account::checkAmount(void)const
{
	return (_amount);
}

void Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< "amount:" << checkAmount()
	<< ";deposits;" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	char buf[20];
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", std::localtime(&t));
	std::cout << "[" << buf << "]"; 
}



