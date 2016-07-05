import QtQuick 2.0

Item {
    id:item;
    width:parent.width;
    height:parent.height;
    ListModel{
        id:myModel

    }

    Component {
        id: messageDelegate
        Rectangle{
            width: itemContainer.width -itemContainer.border.width*2 - list.x*2; height: content.height * 1.5 + sender.height + border.width * 2
/**/        x:itemContainer.width * 0.02;

            radius:height/10;
            color:model.aux == "true" ?  "#888888" : "#bbbbbb";
            border.width: 3//itemContainer/20;
            border.color: "#505070"

            Text{
                id:sender
                x:parent.width/15 + parent.border.width; y:parent.height/10;
                text: model.name;
                font.pixelSize: itemContainer.width<itemContainer.height ? itemContainer.width *0.1 : itemContainer.height * 0.1;
            }
            Text{
                id:content
                //anchors.fill: parent;
                x:parent.border.width * 2; y:sender.height*1.2 + sender.y;
                text: model.uname;
                font.pixelSize: itemContainer.width<itemContainer.height ? itemContainer.width *0.07 : itemContainer.height * 0.07;
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                width: parent.width - parent.border.width * 3
            }

        }
    }
    Rectangle{
        id:itemContainer
        width:parent.width * 0.3; height:parent.height * 0.8;
        x:parent.width * 0.7;
        border.width: width<height? width * 0.02 : height * 0.02;
        border.color: "#909099"
        radius: border.width;
        color:"#b9b0a0"
    ListView {
        id:list
        spacing: height * 0.02
        width:parent.width - parent.border.width*2 ; height:parent.height - parent.border.width*2;
        x:parent.border.width; y:parent.border.width;

        //Component.onCompleted: getColors();
        model: getMockModel()
        delegate: messageDelegate
        clip: true
    }
    }

    function getMockModel(){
        myModel.append({"uname":"andrei72","name":"Andrei","aux":"false"});
        myModel.append({"uname":"andrei71","name":"Andrei","aux":"false"});
        myModel.append({"uname":"gigi90","name":"Gigi","aux":"false"});
        myModel.append({"uname":"crisman","name":"Cristi","aux":"true"});
        myModel.append({"uname":"marian95","name":"Marian","aux":"false"});
        myModel.append({"uname":"ioanccc","name":"Ioan","aux":"false"});
        myModel.append({"uname":"razvy88","name":"Razvan","aux":"false"});
        myModel.append({"uname":"toni01","name":"Toni","aux":"false"});
        return myModel;
    }
}
