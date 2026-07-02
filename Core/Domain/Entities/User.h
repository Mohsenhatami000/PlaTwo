#pragma once
#include <string>
#include "ValueObjects/Email.h"
#include "ValueObjects/Name.h"
#include "ValueObjects/PhoneNumber.h"
#include "ValueObjects/UserName.h"
#include "ValueObjects/PasswordHash.h"
class User 
{
private:
	//std::int64_t u_ID;
	Name u_name_;
	UserName u_username_;
	PhoneNumber u_phoneNumber_;
	Email u_email_;
	PasswordHash u_passwordHash_;
	
public:
	User(const Name& name , const UserName& username , const PhoneNumber& phonenumber , const Email& email , 
		const PasswordHash& pass);
	void changeName(const Name& name);
	void changeUserName(const UserName& username);
	void changephoneNumber(const PhoneNumber& phonenumber);
	void changeEmail(const Email& email);
	void changePasswordHash(const PasswordHash& newpass);
};