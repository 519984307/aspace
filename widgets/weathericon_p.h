#pragma once
#include "weathericon.h"
#include <QPixmap>
#include <QString>

BEGIN_USER_NAMESPACE
class WeatherIconPrivate {
public:
    WeatherIconPrivate(WeatherIcon *q);
    ~WeatherIconPrivate();


private:
    Q_DECLARE_PUBLIC(WeatherIcon)
    double                  m_scaleFactor;
    WeatherIcon             *q_ptr;
    QString                 m_iconPath;
    WeatherIcon::IconType   m_iconType;
    QByteArray              m_svgData;

};
END_USER_NAMESPACE