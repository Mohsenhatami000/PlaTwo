#pragma once
enum class DomainError
{
	//Email
	EmailEmpty,
	EmailInvalidFormat,
	//UserName
	UserNameEmpty,
	UserNameInvalidFormat,
	UserNameInvalidLength,
	//PhoneNumber
	PhoneNumberEmpty,
	PhoneNumberInvalidLength,
	PhoneNumberInvalidCharacter,
	PhoneNumberInvalidStart,
	//Name
	NameEmpty,
	NameInvalidLength,
	//password
	PasswordEmpty,
	PasswordInvalidLength,
	PasswordContainSpace,
	PasswordNoUppercase,
	PasswordNoLowercase,
	PasswordNoNumber,
	PasswordNoCharacter
};