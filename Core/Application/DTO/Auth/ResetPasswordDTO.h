#pragma once
#include <string>
struct ResetPasswordRequest
{
	std::string phoneNumber_;
	std::string newpass_;
	std::string newpassconfirm_;
};