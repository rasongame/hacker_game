﻿import QtQuick 2.0
import QtQuick.Controls 1.0
ApplicationWindow
{
    objectName: "Window"
    visible: true
    width: 640
    height: 480
    title: qsTr("Hacker: The Game")
    Connections {
        target: appCore

        onSendToQml:{
            console.log(string)
        }
    }
        Grid {
        id: grid
        x: 61
        y: 32
        width: 400
        height: 24

        TextInput {
            id: textInput
            x: 31
            y: 32
            width: 80
            height: 20
            text: Name
            font.pixelSize: 12
        }

        TextInput {
            id: textInput1
            x: 31
            y: 32
            width: 80
            height: 20
            text: Level
            font.pixelSize: 12
        }

        TextInput {
            id: textInput2
            x: 31
            y: 32
            width: 80
            height: 20
            //            text: qsTr("Age")
            text: Skill
            font.pixelSize: 12
        }

        TextInput {
            id: textInput3
            x: 31
            y: 32
            width: 80
            height: 20
            text: Age
            //            text: qsTr("Skill")
            font.pixelSize: 12
        }
    }

    Button {
        id: button
        objectName: "assign_button"
        x: 61
        y: 75
        text: qsTr("Assign")
        onClicked:
            appCore.receiveFromQml(name_label.text)
        antialiasing: true
        transformOrigin: Item.Center
    }

    Column {
        id: column
        x: 54
        y: 148
        width: 200
        height: 400

        Label {
            id: name_label
            text: Name

        }

        Label {
            id: skill_label
            text: Skill
        }

        Label {
            id: age_label
            text: Age
        }

        Label {
            id: level_label
            text: Level
        }
    }
}
