qt_add_executable(ClientApp
    main.cpp
    Presentation/MainWindow/mainwindow.h Presentation/MainWindow/mainwindow.cpp Presentation/MainWindow/mainwindow.ui
    Presentation/Login/loginpage.h Presentation/Login/loginpage.cpp Presentation/Login/loginpage.ui
    Presentation/SignUp/signuppage.h Presentation/SignUp/signuppage.cpp Presentation/SignUp/signuppage.ui
    Presentation/ResetPassword/resetpasswordpage.h Presentation/ResetPassword/resetpasswordpage.cpp Presentation/ResetPassword/resetpasswordpage.ui
    Presentation/MainMenu/mainmenupage.h Presentation/MainMenu/mainmenupage.cpp Presentation/MainMenu/mainmenupage.ui
    Presentation/EditProfile/editprofilepage.h Presentation/EditProfile/editprofilepage.cpp Presentation/EditProfile/editprofilepage.ui
    Presentation/GameMenu/gamemenupage.h Presentation/GameMenu/gamemenupage.cpp Presentation/GameMenu/gamemenupage.ui
    Presentation/Lobby/lobbypage.h Presentation/Lobby/lobbypage.cpp Presentation/Lobby/lobbypage.ui
    Presentation/Login/QtLoginpresenter.h Presentation/Login/QtLoginpresenter.cpp
    Presentation/SignUp/QTSignupPresenter.h     Presentation/SignUp/QTSignupPresenter.cpp 
    Presentation/ResetPassword/QTResetPasswordPresenter.h     Presentation/ResetPassword/QTResetPasswordPresenter.cpp

)

target_link_libraries(ClientApp
    PRIVATE
        Qt6::Widgets
        Qt6::Network
        Core
        Infrastructure
)
