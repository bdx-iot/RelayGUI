#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "CBLEDiscover.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //engine
    QQmlApplicationEngine engine;

    //Charger la classe
    CBLEDiscover *bleDiscover = new CBLEDiscover();
    engine.rootContext()->setContextProperty("BLEDiscover", bleDiscover);

    //Charger le QML
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
