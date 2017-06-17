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

#ifndef BUTTONGROUPPANEL_H
#define BUTTONGROUPPANEL_H

#include <panels/panel.h>

class QBoxLayout;
class QWidget;
class QToolButton;
class QAction;

/**
 * @brief Shows the terminal which is synchronized with the URL of the
 *        active view.
 */
class ButtonGroupPanel : public Panel
{
    Q_OBJECT

public:
    ButtonGroupPanel(QWidget* parent = nullptr);
    virtual ~ButtonGroupPanel();

    QToolButton* appendAction(QAction* action);
    void appendSpacer();

protected:
    virtual bool urlChanged() Q_DECL_OVERRIDE;
    virtual void showEvent(QShowEvent* event) Q_DECL_OVERRIDE;

private:
    QBoxLayout* m_layout;
    int m_size = 34;
};

#endif // BUTTONGROUPPANEL_H
