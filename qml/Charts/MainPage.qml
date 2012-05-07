import QtQuick 1.1
import com.nokia.meego 1.0
import Chart 1.0

Page {
    id: master

    property int spacer: 0

    Flickable {
        id: flickable
        anchors.fill: parent

        contentHeight: diagonalLine.height
        contentWidth: diagonalLine.width
        contentX: -master.width / 2
        interactive: false

        Chart {
            id: diagonalLine
            height: 200
            smooth: true

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    diagonalLine.addPoint(16.5443, 1)
                    diagonalLine.addPoint(19.343, 1)
                    diagonalLine.addPoint(14.21, 1)
                    diagonalLine.addPoint(11.41, 2)
                    diagonalLine.addPoint(6.36, 2)
                    diagonalLine.addPoint(2.46, 2)
                    diagonalLine.addPoint(-9.75, 3)
                    diagonalLine.addPoint(-9.93, 3)
                    diagonalLine.addPoint(-10.21, 3)
                    timer.inc = 1;
                    flickable.contentX = -master.width / 2
                    master.spacer = diagonalLine.getSpacer();
                    timer.start();
                }
            }
        }
    }

    Timer {
        id: timer
        running: false
        repeat: true
        interval: 1000
        property int inc: 1
        onTriggered: {
            diagonalLine.setCurrentHightlight(inc);
            inc++;
            if (inc > 2)
                flickable.contentX = flickable.contentX + spacer;
        }
    }

}
