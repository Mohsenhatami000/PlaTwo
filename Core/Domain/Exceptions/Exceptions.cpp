#include "Exceptions.h"
Exceptions::Exceptions(DomainError error):error_(error){

}
DomainError Exceptions::error() const noexcept{
	return error_;
}
const char* Exceptions::what() const noexcept{
	return "Domain exception";
}