#include "dotsgame.h"

DotsGame::DotsGame(DotsBoard board, Turn turn):IGame(turn), board_(board), hostScore_(0), guestScore_(0){};

bool DotsGame::makeMove(IMove &move){
    if(ruleEngine_.validateMove(move, board_)){
        board_.drawEdge(&move);
        std::vector<std::pair<int, int>> boxes = ruleEngine_.findCompleteBoxes(move, board_);
        updateScore(boxes.size());
        board_.drawBoxes(boxes, currentTurn());
        switchTurn();
    }
}

void DotsGame::updateScore(int amount){
    if(currentTurn() == Turn::Host){
        hostScore_ += amount;
    }
    else if(currentTurn() == Turn::Guest){
        guestScore_ += amount;
    }
}

bool DotsGame::isFinished() const{
    if((hostScore_ + guestScore_) == (board_.height() * board_.width())){
        return true;
    }
    else{
        return false;
    }
}

int DotsGame::hostScore() const{
    return hostScore_;
}

int DotsGame::guestScore() const{
    return guestScore_;
}
std::optional<Turn> DotsGame::winner() const{

    std::optional<Turn> turn;
    if(hostScore_ == guestScore_){
        return turn;
    }
    else if(hostScore_ > guestScore_){
        turn = Turn::Host;
        return turn;
    }
    else{
        turn = Turn::Guest;
        return turn;
    }
}

DotsBoard& DotsGame::board(){
    return board_;
}