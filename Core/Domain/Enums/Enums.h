#pragma once
enum class DomainError
{
	//Email
	EmailEmpty,
	EmailInvalidFormat,
	//UserName
	UserNameEmpty,
	UserNameInvalidFormat,
	UserNameInvalidLength,
	//PhoneNumber
	PhoneNumberEmpty,
	PhoneNumberInvalidLength,
	PhoneNumberInvalidCharacter,
	PhoneNumberInvalidStart,
	//Name
	NameEmpty,
	NameInvalidLength,
	//password
	PasswordEmpty,
	PasswordInvalidLength,
	PasswordContainSpace,
	PasswordNoUppercase,
	PasswordNoLowercase,
	PasswordNoNumber,
	PasswordNoCharacter,
	//Coordinate
	CoordinateIsNegative,
	//CoordinateEmpty,
	//Room state
	RoomIsClosed,
	RoomIsFull,
	RoomNotHostTwice,
	RoomCanNotStart,
	RoomPlayerNotFound,
	PlayerAlreadyConnected,
	PlayerAlreadyDisconnected,
	HostDisconnected,
	//Match state
	MatchAlreadyStarted,
	MatchIsNotPlaying,
	MatchPaused,
	MatchEneded,
	//Player 
	PlayerNotFound
};
enum class GameType
{
	DotsAndBoxes,
	Mills,
	Fanorona
};
enum class RoomStatus 
{
	Waiting,
	Ready,
	Playing,
	Closed
};
enum class MatchStatus
{
	NotStarted,
	Playing,
	Ended
};
enum class Turn
{
	Host,
	Guest
};
enum class MatchResult 
{
    HostWin,
	GuestWin,
	Draw,
	Abandoned
};
enum class ConnectionState
{
	Connected,
	Disconnected
};