import QtQuick 2.12
import QtQuick.Controls 2.13
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
ApplicationWindow
{
    objectName: "Window"
    visible: true


    width: 640
    height: 480
    title: qsTr("Hacker: The Game")

    Connections {
        target: appCore
        onSendToQml: {
            age_label.text = age
            skill_label.text = skill
            level_label.text = level
            name_label.text = name
        }
    }
    Connections {
        target: Computer
        onSendToQml_from_computer: {
            console.log(string)
        }
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            Action {
                text: qsTr("Save")
                onTriggered: appCore.savePlayer()
            }
            Action {
                text: qsTr("Close")
                onTriggered: Qt.quit()
            }

        }
    }
    PageIndicator {
        id: indicator
        count: view.count
        currentIndex: view.currentIndex
        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    SwipeView {
        id: view
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        currentIndex: 0
        anchors.fill: parent

        Item {
            id: firstPage

            RowLayout {
                id: rowLayout
                x: 8
                y: 8
                width: 100
                height: 40

                Button {
                    id: pc_button
                    objectName: "pc_button"
                    text: qsTr("Enable")
                    onClicked: {
                        Computer.enable()
                        console.log("enabled pc")
                    }
                }
                Button {
                    id: pc_button_disable
                    objectName: "pc_button_disable"
                    text: qsTr("Disable")
                    onClicked: {
                        Computer.disable()
                        console.log("disabled pc")
                    }
                }

                Button {
                    id: internet_button
                    objectName: "internet_button"
                    text: qsTr("Enable Internet")
                    onClicked: {
                        Computer.enableInternet()
                        console.log("enabled internet")
                    }
                }
                Button {
                    id: internet_button_disable
                    objectName: "internet_button_disable"
                    text: qsTr("Disable Internet")
                    onClicked: {
                        Computer.disableInternet()
                        console.log("disabled internet")

                    }
                }
            }

            Rectangle {
                id: rectangle
                x: 8
                y: 61
                width: 439
                height: 276
                color: "#ffffff"
                radius: 3
                border.color: "#626262"
                border.width: 5

                Frame {
                    id: frame
                    x: 5
                    y: 5
                    width: 429
                    height: 266
                    Rectangle {
                        id: cube
                        x: 0
                        y: 0
                        width: 10
                        height: 10
                        color: "#FFFFFF"
                        border.width: 2
                    }

                    MouseArea {
                        id: mouseArea
                        x: -11
                        y: -11
                        width: 427
                        height: 264
                        cursorShape: Qt.BlankCursor
                        hoverEnabled: true
                        onPositionChanged: {

                            cube.x = mouseArea.mouseX-16
                            cube.y = mouseArea.mouseY-16
                        }
                    }

                }
            }
        }

        Item {
            id: secondPage
            Button {
                id: button
                objectName: "assign_button"
                x: 61
                y: 75
                text: qsTr("Assign")
                onClicked: {
                    appCore.receiveFromQml(textInput.text,
                                           textInput3.text,
                                           textInput2.text,
                                           textInput1.text);
                }
                antialiasing: true
                transformOrigin: Item.Center
            }
            Column {

                id: column
                x: 61
                y: 127
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
            GridLayout {

                id: gridLayout
                x: 61
                y: 5
                width: 285
                height: 64
                TextInput {
                    id: textInput
                    x: 31
                    y: 32
                    width: 80
                    height: 20
                    text: Name
                    readOnly: false
                    font.pixelSize: 12
                }

                TextInput {
                    id: textInput1
                    x: 31
                    y: 32
                    width: 80
                    height: 20
                    text: Level
                    readOnly: false
                    font.pixelSize: 12
                }

                TextInput {
                    id: textInput2
                    x: 31
                    y: 32
                    width: 80
                    height: 20
                    text: Skill
                    readOnly: false
                    font.pixelSize: 12
                }

                TextInput {
                    id: textInput3
                    x: 31
                    y: 32
                    width: 80
                    height: 20
                    text: Age
                    readOnly: false
                    font.pixelSize: 12
                }
            }
        }
    }
}
