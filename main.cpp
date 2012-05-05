#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "chart.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterType<Chart>("Chart", 1, 0, "Chart");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/Charts/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
