import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    Component.onCompleted: theme.inverted = true;

    MainPage {
        id: mainPage
    }
}
