import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id:mess
    visible: true
    width: 650
    height: 500
    x:400;
    y:300;
    title: qsTr("Messenger Chat")

    Button {
        anchors.right: parent.right; anchors.rightMargin: 10
        anchors.bottom: parent.bottom; anchors.bottomMargin: 10
        text: "Send"
    }

    MessageView{

    }
    UsersView{

    }


}
