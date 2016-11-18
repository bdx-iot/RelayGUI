import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4

Window {
    visible: true

    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight

    MainForm {
        connectButton.onClicked: {
            BLEDiscover.start();
            pageLoader.source = "Relay.qml"
        }
        connectButton {
            font.pointSize:  25;
        }

        anchors.fill: parent

        Loader { id: pageLoader }
    }
}
