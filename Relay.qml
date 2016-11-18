import QtQuick 2.4
import QtQuick.Window 2.2

RelayForm {
    visible: true
    width: Screen.desktopAvailableWidth
    height: Screen.desktopAvailableHeight

    temperature {
        text: BLEDiscover.temperature + "°C";
    }

    enabled :BLEDiscover.connectionState;

    relay1 {
        checked: BLEDiscover.relay1State;
        font.pointSize:  7;
    }
    relay2 {
        checked: BLEDiscover.relay2State;
        font.pointSize:  7;
    }
    relay2.onClicked: {
        if (relay2.checked == true)
            BLEDiscover.switchRelay2(true)
        else
            BLEDiscover.switchRelay2(false)
    }

    relay1.onClicked:{
        if (relay1.checked == true)
            BLEDiscover.switchRelay1(true)
        else
            BLEDiscover.switchRelay1(false)
    }


}

