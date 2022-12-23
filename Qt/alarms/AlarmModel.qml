import QtQuick 2.11
import QtQml 2.0
import QtMultimedia 5.15

ListModel {
    id: alarmModel

    ListElement {
        hour: 16
        minute: 13
        day: 21
        month: 12
        year: 2022
        activated: true
        label: "Wake up"
        repeat: true
        daysToRepeat: [
            ListElement { dayOfWeek: 0; repeat: false },
            ListElement { dayOfWeek: 1; repeat: false },
            ListElement { dayOfWeek: 2; repeat: false },
            ListElement { dayOfWeek: 3; repeat: false },
            ListElement { dayOfWeek: 4; repeat: false },
            ListElement { dayOfWeek: 5; repeat: false },
            ListElement { dayOfWeek: 6; repeat: false }
        ]
        /*

      */
        /*
        Audio {
            id: playMusic
            source: "music/alarm.wav"
            volume: 1.0
            muted: false
        }


        Timer {
            interval: (minute-Date().getMinutes())*60;
            running: true;
            repeat: true
            onTriggered:  {
                playMusic.play()
            }
        }
        */


    }
    ListElement {
        hour: 6
        minute: 0
        day: 3
        month: 8
        year: 2018
        activated: true
        label: "Wake up"
        repeat: true
        daysToRepeat: [
            ListElement { dayOfWeek: 0; repeat: true },
            ListElement { dayOfWeek: 1; repeat: true },
            ListElement { dayOfWeek: 2; repeat: true },
            ListElement { dayOfWeek: 3; repeat: true },
            ListElement { dayOfWeek: 4; repeat: true },
            ListElement { dayOfWeek: 5; repeat: false },
            ListElement { dayOfWeek: 6; repeat: false }
        ]
    }
    ListElement {
        hour: 7
        minute: 0
        day: 3
        month: 8
        year: 2018
        activated: false
        label: "Exercise"
        repeat: true
        daysToRepeat: [
            ListElement { dayOfWeek: 0; repeat: true },
            ListElement { dayOfWeek: 1; repeat: true },
            ListElement { dayOfWeek: 2; repeat: true },
            ListElement { dayOfWeek: 3; repeat: true },
            ListElement { dayOfWeek: 4; repeat: true },
            ListElement { dayOfWeek: 5; repeat: true },
            ListElement { dayOfWeek: 6; repeat: true }
        ]
    }
    ListElement {
        hour: 5
        minute: 15
        day: 1
        month: 9
        year: 2018
        activated: true
        label: ""
        repeat: false
        daysToRepeat: [
            ListElement { dayOfWeek: 0; repeat: false },
            ListElement { dayOfWeek: 1; repeat: false },
            ListElement { dayOfWeek: 2; repeat: false },
            ListElement { dayOfWeek: 3; repeat: false },
            ListElement { dayOfWeek: 4; repeat: false },
            ListElement { dayOfWeek: 5; repeat: false },
            ListElement { dayOfWeek: 6; repeat: false }
        ]
    }
    ListElement {
        hour: 5
        minute: 45
        day: 3
        month: 9
        year: 2018
        activated: false
        label: ""
        repeat: false
        daysToRepeat: [
            ListElement { dayOfWeek: 0; repeat: false },
            ListElement { dayOfWeek: 1; repeat: false },
            ListElement { dayOfWeek: 2; repeat: false },
            ListElement { dayOfWeek: 3; repeat: false },
            ListElement { dayOfWeek: 4; repeat: false },
            ListElement { dayOfWeek: 5; repeat: false },
            ListElement { dayOfWeek: 6; repeat: false }
        ]
    }
}
