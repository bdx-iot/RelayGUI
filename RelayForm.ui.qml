import QtQuick 2.4
import QtQuick.Controls 2.0
import QtQuick.Extras 1.4
import QtGraphicalEffects.private 1.0
import QtQuick.Window 2.2

Item {
    id: item1
    width: 720
    height: 1280
    property alias temperature: temperature
    property alias relay2: relay2
    property alias relay1: relay1

    Rectangle {
        id: rectangle1
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.left: parent.left
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#ffffff"
            }

            GradientStop {
                position: 1
                color: "#f7f6f6"
            }

            GradientStop {
                position: 1
                color: "#493a3a"
            }

            GradientStop {
                position: 1
                color: "#ffffff"
            }

            GradientStop {
                position: 0.342
                color: "#ffffff"
            }

            GradientStop {
                position: 0.309
                color: "#fbfbfb"
            }




        }
        antialiasing: true

        Switch {
            id: relay1
            x: 294
            width: 162
            height: 46
            text: qsTr("Relay 1")
            anchors.top: label2.bottom
            anchors.topMargin: 235
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            antialiasing: true
            scale: 4.4

        }

        Switch {
            id: relay2
            x: 294
            y: 1006
            width: 162
            height: 46
            text: qsTr("Relay 2")
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            smooth: true
            antialiasing: true
            scale: 4.4
        }

        Text {
            id: temperature
            width: 534
            height: 100
            text: "0"
            font.family: "Tahoma"
            anchors.top: label1.bottom
            anchors.topMargin: 69
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            scale: 1
            font.pixelSize: 70
        }

        Label {
            id: label1
            x: 187
            y: 110
            width: 362
            height: 56
            text: qsTr("Temperature")
            font.underline: false
            font.family: "Courier"
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 35
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        Label {
            id: label2
            x: 187
            y: 459
            width: 346
            height: 53
            text: qsTr("Relays")
            anchors.horizontalCenterOffset: 0
            font.family: "Courier"
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 35
        }
    }
}
