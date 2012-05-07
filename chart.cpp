#include "chart.h"

Chart::Chart(QDeclarativeItem *parent) :
    QDeclarativeItem(parent)
{
    //! Important, otherwise the paint method is never called
    setFlag(QGraphicsItem::ItemHasNoContents, false);

    currentHightlight = 1;

    for ( int i = 0; i < 2; i++) {
    pointsX.append(2);
    pointsX.append(2.1);
    pointsX.append(2.4);
    pointsX.append(2.2);
    pointsX.append(2.5);
    pointsX.append(2.7);
    pointsX.append(2.9);
    pointsX.append(2.94);
    pointsX.append(2.76);
    pointsX.append(2.77);
    pointsX.append(2.81);
    pointsX.append(2.84);

    pointsY.append(4);
    pointsY.append(4.1);
    pointsY.append(4.4);
    pointsY.append(4.2);
    pointsY.append(4.5);
    pointsY.append(4.7);
    pointsY.append(16.9);
    pointsY.append(4.94);
    pointsY.append(4.76);
    pointsY.append(4.77);
    pointsY.append(4.81);
    pointsY.append(4.84);

    pointsZ.append(-2);
    pointsZ.append(-2.1);
    pointsZ.append(-2.4);
    pointsZ.append(-2.2);
    pointsZ.append(-2.5);
    pointsZ.append(-2.7);
    pointsZ.append(-2.9);
    pointsZ.append(-2.94);
    pointsZ.append(-2.76);
    pointsZ.append(-2.77);
    pointsZ.append(-2.81);
    pointsZ.append(-2.84);
    }
    updateChart();
}

void Chart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //! Color and width
    QPen penX(QColor("#5BB600"), 2);
    QPen penY(QColor("#5B00B6"), 2);
    QPen penZ(QColor("#B6005B"), 2);
    QPen horizontalLinePen(QColor("#303335"), 2);
    QPen hightlightColumn(QColor("#8D18BE"), 2);

    if(smooth() == true) {
        painter->setRenderHint(QPainter::Antialiasing, true);
    }

    //! Highlight column
    painter->setPen(hightlightColumn);
    painter->drawLine((currentHightlight-1) * spacer, 0, (currentHightlight-1) * spacer, height());

    //! Paint everything between ((currentHightlight-1) * spacer) - 220
    //! and ((currentHightlight-1) * spacer) + 220
    //! Our values:
    int begin = (((currentHightlight-1) * spacer) - 220) / spacer;
    int end = (((currentHightlight-1) * spacer) + 220) / spacer;

    begin++;
    end++;

    if (end > pointsX.length())
        end = pointsX.length();

    if (begin < 1)
        begin = 1;

    //! Draw horizontal line
    painter->setPen(horizontalLinePen);
    painter->drawLine((begin-1) * spacer, (this->height() / 2) - 1, (end-1) * spacer, (this->height() / 2) - 1);

    painter->setPen(penX);

    for (int i = begin; i < end; i++) {
            painter->drawLine((i - 1) * spacer, convertValues(pointsX.at(i - 1)), i * spacer, convertValues(pointsX.at(i)));
    }

    painter->setPen(penY);

    for (int i = begin; i < end; i++) {
            painter->drawLine((i - 1) * spacer, convertValues(pointsY.at(i - 1)), i * spacer, convertValues(pointsY.at(i)));
    }

    painter->setPen(penZ);

    for (int i = begin; i < end; i++) {
            painter->drawLine((i - 1) * spacer, convertValues(pointsZ.at(i - 1)), i * spacer, convertValues(pointsZ.at(i)));
    }
}

int Chart::convertValues(double value)
{
    int maxValue = this->height() / 2;
    int currValue = (maxValue * value) / 22;

    return maxValue - currValue;
}

void Chart::updateChart()
{
    //! Number of all points
    number = pointsX.size() - 1;
    //! Empty space between colored columns
    calcWidth = 440;
    spacer = calcWidth / number;

    if (spacer < 4)
        spacer = 4;

    calcWidth = number * spacer;
    this->setWidth(calcWidth);

    update(0, 0, this->width(), this->height());
}

int Chart::getSpacer()
{
    return spacer;
}

void Chart::addPoint(int y, int lineType)
{
    if (y > 22)
        y = 22;

    //! Line type: 1 - X, 2 - Y, 3 - Z
    switch (lineType) {
    case 1:
        pointsX.append(y);
        break;
    case 2:
        pointsY.append(y);
        break;
    case 3:
        pointsZ.append(y);
        break;
    default:
        qDebug() << "Unsupported line type [chart]";
    }
}

void Chart::setCurrentHightlight(int column)
{
    //! Number of all points
    int number = pointsX.size();

    if (column <= number) {
        if (column == 0)
            column = 1;
        currentHightlight = column;
        update((currentHightlight-1) * spacer, 0, (currentHightlight-1) * spacer, height());
    }
}
