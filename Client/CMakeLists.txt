qt_add_executable(ClientApp
    main.cpp
    Presentation/MainWindow/mainwindow.h Presentation/MainWindow/mainwindow.cpp Presentation/MainWindow/mainwindow.ui
)

target_link_libraries(ClientApp
    PRIVATE
        Qt6::Widgets
        Qt6::Network
        Core
)
