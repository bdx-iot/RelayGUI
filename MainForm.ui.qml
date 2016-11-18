import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Window 2.2

Rectangle {
    id: rectangle1

    width: 720//Screen.desktopAvailableWidth
    height: 1280
    property alias connectButton: connectButton
    //Screen.desktopAvailableHeight

    readonly property real dip:1// Screen.devicePixelRatio// Screen.pixelDensity / (96 / 25.4)

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }

        GradientStop {
            position: 0.252
            color: "#ffffff"
        }

        GradientStop {
            position: 0.507
            color: "#000000"
        }

        GradientStop {
            position: 0.863
            color: "#ffffff"
        }

    }

    Button {
        id: connectButton
        height: 400
        text: qsTr("Connect to BLE device")
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.verticalCenter: parent.verticalCenter
        checkable: false
        checked: false
        highlighted: false
    }
}
