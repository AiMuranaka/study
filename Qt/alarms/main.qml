import QtQuick 2.11
import QtQuick.Controls 2.4
import QtMultimedia 5.15
import QtQuick.Controls.Material 2.4
import QtQuick.Layouts 1.11
import QtQuick.Window 2.11
import Qt.labs.calendar 1.0

ApplicationWindow {
    id: window
    width: 400
    height: 500
    visible: true

    Text {
        text: "Click Me!";
        font.pointSize: 24;
        width: 150; height: 50;

        Audio {
            id: playMusic
            source: "music/alarm.wav"
            volume: 1.0
            muted: false
        }
        MouseArea {
            id: playArea
            anchors.fill: parent
            onClicked: { playMusic.play() }
        }
    }
/*
    }
    Timer {
        interval: 3000; running: true; repeat: true
        onTriggered: test.text = "test"
    }
    Text {
        id: test
    }
*/

    ListView {
        id: alarmListView
        anchors.fill: parent
//        model: AlarmModel { id: alarmModel }
        delegate: AlarmDelegate {}
    }

    RoundButton {
        id: addAlarmButton
        text: "+"
        anchors.bottom: alarmListView.bottom
        anchors.bottomMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: alarmDialog.open()
    }

    AlarmDialog {
        id: alarmDialog
        x: Math.round((parent.width - width) / 2)
        y: Math.round((parent.height - height) / 2)
//        alarmModel: alarmListView.model
    }
}
