#ifndef IEDITPROFILEPRESENTER_H
#define IEDITPROFILEPRESENTER_H

#include "Domain/Entities/User.h"

class IEditProfilePresenter
{
public:
    virtual ~IEditProfilePresenter() = default;
    virtual void LoadEditProfilePage(User user) const = 0;
    virtual void presentValidationError(std::string msg) = 0;
    virtual void presentEditSuccess() = 0;
};

#endif // IEDITPROFILEPRESENTER_H
