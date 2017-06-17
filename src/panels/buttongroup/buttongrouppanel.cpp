/***************************************************************************
 *   Copyright (C) 2007-2010 by Peter Penz <peter.penz19@gmail.com>        *
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

#include "buttongrouppanel.h"

#include <QKeySequence>
#include <QAction>
#include <QHBoxLayout>
#include <QToolButton>
#include <QShowEvent>
#include <QSpacerItem>
#include <QSizePolicy>

ButtonGroupPanel::ButtonGroupPanel(QWidget* parent) :
    Panel(parent),
    m_layout(0)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    m_layout = new QHBoxLayout(this);
    m_layout->setMargin(0);
    m_layout->setSpacing(0);

    // https://api.kde.org/frameworks/kio/html/classKUrlComboBox.html
    int urlComboBoxHeight = 34;
    m_size = urlComboBoxHeight;
    setMinimumHeight(m_size);
    setMaximumHeight(m_size);
}

ButtonGroupPanel::~ButtonGroupPanel()
{
}

bool ButtonGroupPanel::urlChanged()
{
    return true;
}

void ButtonGroupPanel::showEvent(QShowEvent* event)
{
    Panel::showEvent(event);
}

QToolButton* ButtonGroupPanel::appendAction(QAction* action)
{   
    // Use same stype as in QToolbarLayout
    // https://github.com/qt/qtbase/blob/6bceb4a8a9292ce9f062a38d6fe143460b54370e/src/widgets/widgets/qtoolbarlayout.cpp#L725
    QToolButton *button = new QToolButton();
    button->setFixedSize(m_size, m_size);
    button->setAutoRaise(true); // Only show frame on hover
    button->setFocusPolicy(Qt::NoFocus);
    button->setDefaultAction(action);
    button->setPopupMode(QToolButton::InstantPopup); // Don't add dropdown arrow
    m_layout->addWidget(button, 0, Qt::AlignTop);
    return button;
}

void ButtonGroupPanel::appendSpacer()
{
    m_layout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::MinimumExpanding));
}
