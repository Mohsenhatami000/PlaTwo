#include "User.h"
User::User(const Name& name, const UserName& username, const PhoneNumber& phonenumber, const Email& email,
	       const PasswordHash& pass):u_name_(name),u_username_(username),u_phoneNumber_(phonenumber)
	       ,u_email_(email),u_passwordHash_(pass) {

}
void User::changeName(const Name& name) {
	u_name_ = name;
}
void User::changeUserName(const UserName& username) {
	u_username_ = username;
}
void User::changephoneNumber(const PhoneNumber& phonenumber) {
	u_phoneNumber_ = phonenumber;
}
void User::changeEmail(const Email& email) {
	u_email_ = email;
}
void User::changePasswordHash(const PasswordHash& pass) {
	//Hashing Proccess happens in useCases
	u_passwordHash_ = pass;
}