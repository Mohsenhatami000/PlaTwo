#ifndef QTEDITPROFILEPRESENTER_H
#define QTEDITPROFILEPRESENTER_H

#include "../EditProfile/editprofilepage.h"
#include "Domain/Interfaces/Services/ieditprofilepresenter.h"

class QtEditProfilePresenter : public QObject, public IEditProfilePresenter
{
    Q_OBJECT
    EditProfilePage *editProfilePage_;

public:
    QtEditProfilePresenter(EditProfilePage *editProfilePage);
    void LoadEditProfilePage(User user) const override;
    void presentValidationError(std::string msg) override;
    void presentEditSuccess() override;
signals:
    void saveChangesRequested();
};

#endif // QTEDITPROFILEPRESENTER_H
