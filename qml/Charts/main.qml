import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: linePage

    Component.onCompleted: theme.inverted = true;

    MainPage {
        id: mainPage
    }

    LinePage {
        id: linePage
    }
}
