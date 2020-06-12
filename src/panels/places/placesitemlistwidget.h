/***************************************************************************
 *   Copyright (C) 2012 by Peter Penz <peter.penz19@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef PLACESITEMLISTWIDGET_H
#define PLACESITEMLISTWIDGET_H

#include "kitemviews/kstandarditemlistwidget.h"

#include <QDateTime>
#include <QPointer>

#include <KIO/FileSystemFreeSpaceJob>


// The free space / capacity bar is based on KFilePlacesView.
// https://github.com/KDE/kio/commit/933887dc334f3498505af7a86d25db7faae91019
struct PlaceFreeSpaceInfo
{
    QDateTime lastUpdated;
    KIO::filesize_t used = 0;
    KIO::filesize_t size = 0;
    qreal usedRatio = 0;
    QPointer<KIO::FileSystemFreeSpaceJob> job;
};


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
    bool m_drawCapacityBar;
    PlaceFreeSpaceInfo m_freeSpaceInfo;
};

#endif


