#pragma once

#include <QWidget>

class QTimeZone;
class ANMEAString;
class UNMEAZDAString;
class UNMEARMCString;
class UNMEAGGAString;

namespace Ui {
  class WGeneralData;
}

/**
 * @class WGeneralData
 * @brief Maint data GUI widget (time and position)
 * @author Nikishin E. V.
 * @date 31.07.2022 */
class WGeneralData : public QWidget
{
  Q_OBJECT

public:
  /** @brief Constructor */
  explicit WGeneralData(QWidget *parent = nullptr);
  /** @brief Destructor */
  virtual ~WGeneralData();
  /** @brief Set data for view screen */
  void setViewData_v(ANMEAString * );

private:
  Ui::WGeneralData *ui; ///< @brief GUI view
  QTimeZone * _TimeZone_po; ///< @brief Time zone

  /** @brief view ZDA (date and time) data */
  void viewZDAData(const UNMEAZDAString &);
  /** @brief view RMC (date and time) data */
  void viewRMCData(const UNMEARMCString &);
  /** @brief view GGA (date and time) data */
  void viewGGAData(const UNMEAGGAString &);
};

