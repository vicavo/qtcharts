/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd
** All rights reserved.
** For any questions to The Qt Company, please use contact form at http://qt.io
**
** This file is part of the Qt Charts module.
**
** Licensees holding valid commercial license for Qt may use this file in
** accordance with the Qt License Agreement provided with the Software
** or, alternatively, in accordance with the terms contained in a written
** agreement between you and The Qt Company.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.io
**
****************************************************************************/

import QtQuick 2.0

Rectangle {
    id: button
    height: 25
    width: 140
    color: unpressedColor
    radius: 5
    property color unpressedColor: "#afafaf"

    property string text: "button"
    signal clicked

    Text {
        id: buttonText
        anchors.centerIn: parent
        text: button.text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            button.clicked();
        }
        onPressedChanged: {
            if (pressed) {
                button.color = "#efefef";
            } else {
                button.color = unpressedColor;
            }
        }
        onPressAndHold: {
            repeatTimer.start();
        }
        onReleased: {
            repeatTimer.stop();
        }
    }

    Timer {
        id: repeatTimer
        interval: 140
        repeat: true
        triggeredOnStart: false
        running: false
        onTriggered: {
            button.clicked();
        }
    }
}