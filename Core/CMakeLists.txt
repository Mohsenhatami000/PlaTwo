add_library(Core STATIC
    Domain/Entities/authenticateduser.h Domain/Entities/authenticateduser.cpp
    Domain/Interfaces/Services/isessioncontext.h Domain/Interfaces/Services/isessioncontext.cpp
    Application/UseCases/Login/loginusecase.h Application/UseCases/Login/loginusecase.cpp
    Domain/Interfaces/Services/iloginpresenter.h Domain/Interfaces/Services/iloginpresenter.cpp
    Application/UseCases/SignUp/SignUpUseCase.h  Application/UseCases/SignUp/SignUpUseCase.cpp
    Domain/Interfaces/Services/ISignupPresenter.h )

target_sources(Core PRIVATE

    Domain/Entities/User.cpp
    Domain/Entities/User.h

    Domain/Entities/Player.cpp
    Domain/Entities/Player.h

    Domain/Entities/Room.cpp
    Domain/Entities/Room.h

    Domain/Entities/Match.cpp
    Domain/Entities/Match.h

    Domain/Entities/History.cpp
    Domain/Entities/History.h

    Domain/Entities/GameSession.cpp
    Domain/Entities/GameSession.h


    Domain/ValueObjects/Coordinate.cpp
    Domain/ValueObjects/Coordinate.h

    Domain/ValueObjects/Email.cpp
    Domain/ValueObjects/Email.h

    Domain/ValueObjects/Name.cpp
    Domain/ValueObjects/Name.h

    Domain/ValueObjects/PasswordHash.cpp
    Domain/ValueObjects/PasswordHash.h

    Domain/ValueObjects/Password.cpp
    Domain/ValueObjects/Password.h

    Domain/ValueObjects/PhoneNumber.cpp
    Domain/ValueObjects/PhoneNumber.h

    Domain/ValueObjects/UserName.cpp
    Domain/ValueObjects/UserName.h


    Domain/Exceptions/Exceptions.cpp
    Domain/Exceptions/Exceptions.h

    Domain/Interfaces/Repositories/IGameRepository.cpp
    Domain/Interfaces/Repositories/IGameRepository.h

    Domain/Interfaces/Repositories/IHistoryRepository.cpp
    Domain/Interfaces/Repositories/IHistoryRepository.h

    Domain/Interfaces/Repositories/IRoomRepository.cpp
    Domain/Interfaces/Repositories/IRoomRepository.h

    Domain/Interfaces/Repositories/IUserRepository.cpp
    Domain/Interfaces/Repositories/IUserRepository.h


    Domain/Interfaces/Services/IHasher.cpp
    Domain/Interfaces/Services/IHasher.h

    Domain/Interfaces/Services/INetworkGateway.cpp
    Domain/Interfaces/Services/INetworkGateway.h

    Domain/Interfaces/Services/ISerializer.cpp
    Domain/Interfaces/Services/ISerializer.h

    Domain/Enums/Enums.h

    Shared/Constants/Constants.h
)

target_include_directories(Core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

