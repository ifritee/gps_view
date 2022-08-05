import QtQuick 2.12
import QtLocation 5.12
import QtPositioning 5.12

MapQuickItem {
  id: marker_i

  property alias main_item: main_item
  property alias main_image: main_image

  visible: true
  anchorPoint.x: main_item.width / 2
  anchorPoint.y: main_item.height / 2

  sourceItem: Rectangle {
    id: main_item
    width: 48
    height: width
    color: "transparent"

    Image {
      id: main_image
      width: 22
      height: 32
      source: "qrc:/img/position.png"
      anchors {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
      }
    }
  }
}
