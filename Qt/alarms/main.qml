import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}

ListView {
    id: alarmListView
    anchors.fill: parent
    model: AlarmModel {}
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
