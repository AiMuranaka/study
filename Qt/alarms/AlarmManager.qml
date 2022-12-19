import QtQuick 2.0
import QtMultimedia 5.15

Item{

    Audio {
        id: alarMusic
        source: "music/alarm.mp3"
    }
    Timer {
        interval: 3000; running: true; repeat: true
        onTriggered: alarMusic.play()
    }
}


