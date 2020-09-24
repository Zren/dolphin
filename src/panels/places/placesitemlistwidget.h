/*
 * SPDX-FileCopyrightText: 2012 Peter Penz <peter.penz19@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef PLACESITEMLISTWIDGET_H
#define PLACESITEMLISTWIDGET_H

#include "kitemviews/kstandarditemlistwidget.h"

/**
 * @brief Extends KStandardItemListWidget to interpret the hidden
 *        property of the PlacesModel and use the right text color.
*/
class PlacesItemListWidget : public KStandardItemListWidget
{
    Q_OBJECT

public:
    PlacesItemListWidget(KItemListWidgetInformant* informant, QGraphicsItem* parent);
    ~PlacesItemListWidget() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    void polishEvent() override;

protected:
    bool isHidden() const override;
    QPalette::ColorRole normalTextColorRole() const override;
    void updateCapacityBar();
    void resetCapacityBar();

private:
    bool m_isMountPoint;
    bool m_drawCapacityBar;
    qreal m_capacityBarRatio;
};

#endif


