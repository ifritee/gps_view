import QtQuick 2.12
import QtQuick.Controls 2.12

WMapLocationForm {
  id: form_i

  QtObject {
    id: private_i
    property int recvCounter: 0
  }

  Connections {
    target: maplocation

    function onPosition(coord) {
      if ((private_i.recvCounter++) % 25 === 0) {
        form_i.center = coord;
      }
      mqi_position.coordinate = coord;
    }
  }
}
