qt_add_executable(ClientApp
    main.cpp
    Presentation/MainWindow/mainwindow.h Presentation/MainWindow/mainwindow.cpp Presentation/MainWindow/mainwindow.ui
    Presentation/Login/loginpage.h Presentation/Login/loginpage.cpp Presentation/Login/loginpage.ui
    Presentation/SignUp/signuppage.h Presentation/SignUp/signuppage.cpp Presentation/SignUp/signuppage.ui
    Presentation/ResetPassword/resetpasswordpage.h Presentation/ResetPassword/resetpasswordpage.cpp Presentation/ResetPassword/resetpasswordpage.ui
    Presentation/MainMenu/mainmenupage.h Presentation/MainMenu/mainmenupage.cpp Presentation/MainMenu/mainmenupage.ui


)

target_link_libraries(ClientApp
    PRIVATE
        Qt6::Widgets
        Qt6::Network
        Core
)
