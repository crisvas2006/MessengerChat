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
            width: itemContainer.width * 0.7 -itemContainer.border.width*2; height: content.height * 1.5 + sender.height + border.width * 2
/**/        x: model.aux === "true" ? itemContainer.width * 0.28 : itemContainer.width * 0.02;

            radius:height/10;
            color:"#cfcfff";
            border.width: 3//itemContainer/20;
            border.color: "#505070"
            Text{
                id:sender
                x:parent.width/15 + parent.border.width; y:parent.height/10;
                text: model.sender + ":";
                font.pixelSize: itemContainer.width<itemContainer.height ? itemContainer.width *0.035 : itemContainer.height * 0.035;
            }
            Text{
                id:content
                //anchors.fill: parent;
                x:parent.border.width * 2; y:sender.height*1.2 + sender.y;
                text: model.content;
                font.pixelSize: item.width<item.height ? item.width *0.04 : item.height * 0.04;
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                width: parent.width - parent.border.width * 3
            }

        }
    }
    Rectangle{
        id:itemContainer
        width:parent.width * 0.66; height:parent.height * 0.8;
        border.width: width<height? width * 0.02 : height * 0.02;
        border.color: "#909099"
        radius: border.width;
    ListView {
        id:list
        spacing: height * 0.02
        width:parent.width - parent.border.width*2 ; height:parent.height - parent.border.width*2;
        x:parent.border.width; y:parent.border.width;

        //Component.onCompleted: getColors();
        model: getMockModel()
        delegate: messageDelegate
        clip: true

        header: Rectangle{
            width: itemContainer.width; height: itemContainer.height * 0.02;
            //color: "gray"
        }
        footer: Rectangle{
            y:itemContainer.height
            width: parent.width; height: itemContainer.height * 0.03;
            //color:"gray";
        }
    }
    }

    function getMockModel(){
        myModel.append({"sender":"Andrei","content":"Salut","aux":"false"});//,
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        myModel.append({"sender":"Gigi","content":"Esti foarte sociabil azi","aux":"false"});
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        myModel.append({"sender":"Cristi","content":"Nu","aux":"true"});
        return myModel;
    }
}
