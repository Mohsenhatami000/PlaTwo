#include "User.h"
User::User(std::int64_t id , const Name& name, const UserName& username, const PhoneNumber& phonenumber, const Email& email,
	       const PasswordHash& pass):u_ID_(id),u_name_(name),u_username_(username),u_phoneNumber_(phonenumber)
	       ,u_email_(email),u_passwordHash_(pass) {

}
std::int64_t User::uID() const noexcept{
	return u_ID_;
}
const Name& User::uName() const noexcept {
	return u_name_;
}
const UserName& User::uUserName() const noexcept {
	return u_username_;
}
const PhoneNumber& User::uPhoneNumber() const noexcept {
	return u_phoneNumber_;
}
const Email& User::uEmail() const noexcept {
	return u_email_;
}
const PasswordHash& User::uPasswordHash() const noexcept {
	return u_passwordHash_;
}
bool User::changeName(const Name& name) {
	if (name == u_name_) {
		return false;
	}
	u_name_ = name;
	return true;
}
bool User::changeUserName(const UserName& username) {
	if (username == u_username_) {
		return false;
	}
	u_username_ = username;
	return true;
}
bool User::changePhoneNumber(const PhoneNumber& phonenumber) {
	if (phonenumber == u_phoneNumber_) {
		return false;
	}
	u_phoneNumber_ = phonenumber;
	return true;
}
bool User::changeEmail(const Email& email) {
	if (email == u_email_) {
		return false;
	}
	u_email_ = email;
	return true;
}
bool User::changePasswordHash(const PasswordHash& pass) {
	//Password is already hashed before reaching domain
	if (pass == u_passwordHash_) {
		return false;
	}
	u_passwordHash_ = pass;
	return true;
}