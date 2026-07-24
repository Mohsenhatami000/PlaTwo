#include "dotspage.h"
#include "Domain/Games/Dots & Boxes/dotsmove.h"
#include "Presentation/Dots & Boxes/ui_dotspage.h"
#include "Domain/Games/Dots & Boxes/dotsgame.h"
#include <QString>
#include <cmath>
#include <QMessageBox>


DotsPage::DotsPage(Match &match, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DotsPage)
    , match_(match)
{
    ui->setupUi(this);
}

DotsPage::~DotsPage()
{
    delete ui;
}

void DotsPage::CreatePoints(){

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());
    int width = game->board().width();
    int height = game->board().height();

    QRect r = rect();
    int widgetWidth = r.width();
    int widgetHeight = r.height();
    int margin = 10;
    int xSpacing = (widgetWidth - (2 * margin)) / (width + 1);
    int ySpacing = (widgetHeight - (2 * margin)) / (height + 1); // x and y spacing should be the same ig, must be checked in debugging!

    for(int i = 1 ; i <= height + 1 ; i++){
        for(int j = 1 ; j <= width + 1 ; j++){
            points_[i][j].setX(margin + (i * xSpacing));
            points_[i][j].setY(margin + (j * ySpacing));
        }
    }
}


void DotsPage::paintEvent(QPaintEvent *e){

    QPainter painter;

    CreatePoints();
    drawPoints(painter);
    drawHorizontalLines(painter);
    drawVerticalLines(painter);
    drawBoxes(painter);

}

void DotsPage::drawPoints(QPainter &painter){

    QPen pointsPen; // set style and color
    painter.setPen(pointsPen);

    for(auto rows : points_){
        for(auto point : rows){
            painter.drawPoint(point);
        }
    }
}

void DotsPage::drawHorizontalLines(QPainter &painter){

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());

    QPen linePen; // set style and color
    painter.setPen(linePen);

    int width = game->board().width();
    int height = game->board().height();

    for(int i = 0 ; i < height + 1 ; i++){
        for(int j = 0 ; j < width ; j++){
            if(game->board().lineX()[i][j]){
                painter.drawLine(points_[i][j], points_[i][j + 1]);
            }
        }
    }
}

void DotsPage::drawVerticalLines(QPainter &painter){

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());

    QPen linePen; // set style and color
    painter.setPen(linePen);

    int width = game->board().width();
    int height = game->board().height();

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width + 1 ; j++){
            if(game->board().lineY()[i][j]){
                painter.drawLine(points_[i][j], points_[i + 1][j]);
            }
        }
    }
}

void DotsPage::drawBoxes(QPainter &painter){

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());

    QPen boxPen; // set style and color
    painter.setPen(boxPen);

    int width = game->board().width();
    int height = game->board().height();

    QString hostL = QString::fromStdString(match_.host().pUserName().userNameValue());
    QString guestL = QString::fromStdString(match_.guest().pUserName().userNameValue());

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(game->board().boxes()[i][j]){
                QRect box(points_[i][j], points_[i + 1][j + 1]);
                if(game->board().boxes()[i][j] == 1){
                    painter.drawText(box, Qt::AlignCenter, hostL);
                }
                else{
                    painter.drawText(box, Qt::AlignCenter, guestL);
                }
            }
        }
    }
}


void DotsPage::mousePressEvent(QMouseEvent *e){
    QPoint clicked = e->pos();

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());

    int width = game->board().width();
    int height = game->board().height();

    // click on horizontal lines
    for(int i = 0 ; i < height + 1 ; i++){
        for(int j = 0 ; j < width ; j++){
            if(std::abs(clicked.y() - points_[i][j].y()) < 10){ // assumed 10 pixels, must be checked in debugging
                if((clicked.x() > points_[i][j].x()) && (clicked.x() < points_[i][j + 1].x())){
                    DotsMove dotMove(i, j, Direction::Horizontal);
                    IMove &move = dotMove;
                    if(match_.game()->makeMove(move)){
                        update();
                    }
                }
            }
        }
    }

    // click on vertical line
    for(int i = 0 ; i < width + 1; i++){
        for(int j = 0 ; j < height ; j++){
            if(std::abs(clicked.x() - points_[j][i].x()) < 10){
                if(clicked.y() > points_[j][i].y() && clicked.y() < points_[j + 1][i].y()){
                    DotsMove dotMove(j, i, Direction::Vertical);
                    IMove &move = dotMove;
                    if(match_.game()->makeMove(move)){
                        update();
                    }
                }
            }
        }
    }
}

void DotsPage::mouseMoveEvent(QMouseEvent *e){
    QPoint hovered = e->pos();

    QPainter painter;
    QPen pen; // set style and color
    painter.setPen(pen);

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());

    int width = game->board().width();
    int height = game->board().height();

    // hover on horizontal lines
    for(int i = 0 ; i < height + 1 ; i++){
        for(int j = 0 ; j < width ; j++){
            if(std::abs(hovered.y() - points_[i][j].y()) < 10){ // assumed 10 pixels, must be checked in debugging
                if((hovered.x() > points_[i][j].x()) && (hovered.x() < points_[i][j + 1].x())){
                    Hovered newHover{i, j, Direction::Horizontal};
                    if(hovered_ != newHover){
                        update();
                        hovered_ = newHover;
                        painter.drawLine(points_[i][j], points_[i][j + 1]);
                    }

                }
            }
        }
    }

    // hover on vertical line
    for(int i = 0 ; i < width + 1; i++){
        for(int j = 0 ; j < height ; j++){
            if(std::abs(hovered.x() - points_[j][i].x()) < 10){
                if(hovered.y() > points_[j][i].y() && hovered.y() < points_[j + 1][i].y()){
                    Hovered newHover{j, i, Direction::Vertical};
                    if(hovered_ != newHover){
                        update();
                        hovered_ = newHover;
                        painter.drawLine(points_[j][i], points_[j + 1][i]);
                    }
                }
            }
        }
    }
}

void DotsPage::updateBoard(){
    update();
}


void DotsPage::showResults(){

    DotsGame *game = dynamic_cast<DotsGame*>(match_.game());

    if(match_.isEnded()){
        if(game->winner().has_value()){
            if(game->winner().value() == Turn::Host){
                std::string str = (match_.host().pUserName().userNameValue() + "is the Winner!");
                QMessageBox::information(this, "Game Result", QString::fromStdString(str));
            }
            else{
                std::string str = (match_.guest().pUserName().userNameValue() + "is the Winner!");
                QMessageBox::information(this, "Game Result", QString::fromStdString(str));
            }
        }
        else{
            std::string str = ("The match was drawn!");
            QMessageBox::information(this, "Game Result", QString::fromStdString(str));
        }
    }
}


















