#pragma once
#include <string>
struct SignUpRequest
{
	std::string name_;
	std::string username_;
	std::string phoneNumber_;
	std::string email_;
	std::string password_;
	std::string confirmPassword_;

};
