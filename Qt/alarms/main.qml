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

    Audio {
        id: alarMusic
        source: "music/alarm.mp3"
    }
    Timer {
        interval: 3000; running: true; repeat: true
        onTriggered: alarMusic.play()
    }


    ListView {
        id: alarmListView
        anchors.fill: parent
        model: AlarmModel { id: alarmModel }
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
        alarmModel: alarmListView.model
    }
}
