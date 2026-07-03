#pragma once
#include <exception>
#include "Domain/Enums/Enums.h"
class Exceptions : public std::exception
{
private:
	DomainError error_;

public:
	explicit Exceptions(DomainError error);
	DomainError error() const noexcept;
	const char* what() const noexcept override;
};