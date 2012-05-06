import QtQuick 1.1
import com.nokia.meego 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage

    platformStyle: PageStackWindowStyle {
        background: "image://theme/meegotouch-emptystate-background-portrait"
        backgroundFillMode: Image.Stretch
    }

    //Component.onCompleted: theme.inverted = true;

    MainPage {
        id: mainPage
    }

    LinePage {
        id: linePage
    }
}
