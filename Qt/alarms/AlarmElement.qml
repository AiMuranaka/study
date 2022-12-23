import QtQuick 2.0
import QtMultimedia 5.15

Timer{

    Audio {
        id: playMusic
        source: "music/alarm.wav"
        volume: 1.0
        muted: false
    }
    Timer {
        interval: 3000; running: true; repeat: true
        onTriggered:  {
            playMusic.play()
        }
    }

}


