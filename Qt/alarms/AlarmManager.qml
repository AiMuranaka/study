import QtQuick 2.0

Item{
    /*
    property var locale: Qt.locale()
    property string dateTimeString: "Tue 2013-09-17 10:56:06"

    Component.onCompleted: {
        print(Date.fromLocaleString(locale, dateTimeString, "ddd yyyy-MM-dd hh:mm:ss"));
    }
*/

    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: time.text = Date().toString()
    }

    Text { id: time }

}


