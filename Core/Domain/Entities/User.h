#pragma once
#include <cstdint>
#include "Domain/ValueObjects/Email.h"
#include "Domain/ValueObjects/Name.h"
#include "Domain/ValueObjects/PhoneNumber.h"
#include "Domain/ValueObjects/UserName.h"
#include "Domain/ValueObjects/PasswordHash.h"
class User
{
private:
	std::int64_t u_ID_;
	Name u_name_;
	UserName u_username_;
	PhoneNumber u_phoneNumber_;
	Email u_email_;
	PasswordHash u_passwordHash_;

public:
	User(std::int64_t id, const Name& name, const UserName& username, const PhoneNumber& phonenumber, const Email& email,
		const PasswordHash& pass);
	std::int64_t uID() const noexcept;
	const Name& uName() const noexcept;
	const UserName& uUserName() const noexcept;
	const PhoneNumber& uPhoneNumber() const noexcept;
	const Email& uEmail() const noexcept;
	const PasswordHash& uPasswordHash() const noexcept;
	bool changeName(const Name& name);
	bool changeUserName(const UserName& username);
	bool changePhoneNumber(const PhoneNumber& phonenumber);
	bool changeEmail(const Email& email);
	bool changePasswordHash(const PasswordHash& newpass);

};