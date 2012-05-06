import QtQuick 1.1
import com.nokia.meego 1.0
import Line 1.0

Page {
    Line {
        id: diagonalLine
        width: 500
        height: 60
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 20

        smooth: true
        value: 12

        Behavior on value { PropertyAnimation { duration: 500; easing.type: Easing.Linear; } }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log('val1', diagonalLine.value)
                if (diagonalLine.value == 12)
                    diagonalLine.value = 4;
                else
                    diagonalLine.value = 12;
                console.log('val2', diagonalLine.value)
            }
        }
    }

    Line {
        id: diagonalLine2
        width: 500
        height: 60
        anchors.top: diagonalLine.bottom
        anchors.left: parent.left
        anchors.margins: 20

        smooth: true
        type: 2
        value: 14

        Behavior on value { NumberAnimation { duration: 1000 } }

        MouseArea {
            anchors.fill: parent
            onClicked: {

            }
        }
    }

    Line {
        id: diagonalLine3
        width: 500
        height: 60
        anchors.top: diagonalLine2.bottom
        anchors.left: parent.left
        anchors.margins: 20

        smooth: true
        type: 3
        value: 11

        Behavior on value { NumberAnimation { duration: 1000 } }

        MouseArea {
            anchors.fill: parent
            onClicked: {

            }
        }
    }

}
