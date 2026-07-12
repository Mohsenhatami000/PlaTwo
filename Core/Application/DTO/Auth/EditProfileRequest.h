#ifndef EDITPROFILEREQUEST_H
#define EDITPROFILEREQUEST_H

#include <string>
struct EditProfileRequest
{
    std::string name_;
    std::string username_;
    std::string phoneNumber_;
    std::string email_;
    std::string currentPassword_;
    std::string newPassword_;
    std::string confirmPassword_;
};

#endif // EDITPROFILEREQUEST_H
