import QtQuick 2.12
import QtQuick.Controls 2.12
import QtLocation 5.12
import QtPositioning 5.12

Map {
  id: map_i

  property alias mqi_position: mqi_position

  activeMapType: map_i.supportedMapTypes[5]
  zoomLevel: maximumZoomLevel - 8

  plugin: Plugin {
    id: osm_plaugin
    name: "osm"
  }

  MQIPosition { id: mqi_position }
}
