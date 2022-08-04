//
// Created by astrea on 8/4/22.
//
#include "dynamicsun.h"
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>

namespace dspace {
DynamicSun::DynamicSun(QWidget *parent)
    : QWidget(parent),
      m_timer(new QTimer(this)),
      m_timerInterval(50),
      m_animationTime(6000),
      m_currentBaseAngle(0),
      m_rotateAngleStep(6),
      m_currentTimerCount(0),
      m_sunRadius(50),
      m_sunLightSize(20, 5),
      m_sunColor(QColor(255, 215, 0)),
      m_sunLightColor(m_sunColor) {
    m_timer->setInterval(m_timerInterval);
    connect(m_timer, &QTimer::timeout, this, &DynamicSun::updateView);
    m_timer->start();
    this->resize(100, 200);
}

void DynamicSun::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    auto margin = qMin(width(), height());
    resize(margin, margin);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    drawSun(&painter);
    drawSunLight(&painter);
}

void DynamicSun::drawSunLight(QPainter *painter) {
    painter->save();
    painter->setBrush(QBrush(m_sunLightColor));
    painter->setPen(QPen(m_sunLightColor));
    auto radius = width() / 4.0;
    auto unit = radius / 10;
    painter->translate(2 * radius, 2 * radius);
    QRectF sunLight(unit + radius, -(unit / 2.0), 7.0 * unit, unit);
    painter->rotate(m_currentBaseAngle);
    for (int i = 0; i < 8; i++) {
        painter->rotate(45);
        painter->drawRoundedRect(sunLight, unit / 4, unit / 4);
    }
    painter->restore();
}

void DynamicSun::drawSun(QPainter *painter) const {
    painter->save();
    auto bound = width();
    auto radius = bound / 4;
    QRectF boundRect(0, 0, 2 * radius, 2 * radius);
    painter->translate(radius, radius);
    painter->setBrush(QBrush(m_sunColor));
    painter->setPen(QPen(m_sunColor));
    painter->drawEllipse(boundRect);
    painter->restore();
}

void DynamicSun::updateView() {
//    qDebug() << "Timeout";
    static int timerCount = m_animationTime / m_timerInterval;
    if (m_currentTimerCount <= timerCount)
    {
        m_currentTimerCount++;
        m_currentBaseAngle += m_rotateAngleStep;
        update();
    }
}

DynamicSun::~DynamicSun() = default;

}
