#ifndef DOTSPAGE_H
#define DOTSPAGE_H

#include <QWidget>
#include <QtGui>
#include "Domain/Entities/Match.h"


struct Hovered{
    int x;
    int y;
    Direction direction;

    bool operator!=(const Hovered &other){
        if(x == other.x && y == other.y && direction == other.direction){
            return false;
        }
        else{
            return true;
        }
    }

};


namespace Ui {
class DotsPage;
}

class DotsPage : public QWidget
{
    Q_OBJECT

public:
    explicit DotsPage(Match &match, QWidget *parent = nullptr);
    ~DotsPage();
    void updateBoard();

private:
    Ui::DotsPage *ui;
    Match &match_;
    std::vector<std::vector<QPoint>> points_;
    Hovered hovered_;


protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void CreatePoints();
    void drawPoints(QPainter &painter);
    void drawHorizontalLines(QPainter &painter);
    void drawVerticalLines(QPainter &painter);
    void drawBoxes(QPainter &painter);
    void showResults();
};

#endif // DOTSPAGE_H
