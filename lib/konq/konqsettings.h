/*  This file is part of the KDE project
    Copyright (C) 1997 David Faure <faure@kde.org>
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
*/ 


#ifndef __konq_settings_h__
#define __konq_settings_h__

class KConfig;
#include <qcolor.h>
#include <qstring.h>

/** The class KonqSettings holds the general settings for konqueror/kdesktop.
 * There is no 'local' (per-URL) instance of it.
 * All those settings can only be changed in kcmkonq.
 *
 * For further customization, we could have one instance for
 * all HTML views, one for all FileManager views, and one for the desktop.
 * (TODO in kcmkonq/kcmkdesktop, using different groups/files : 
 *  currently KFM HTML Defaults, KFM FM Defaults)
 *
 * <vapor>
 * Or even one for icon view and one for tree view, ...
 * But then all that has to be done in kcmkonq as well.
 * </vapor>
 */

class KonqSettings
{
protected:
  /** @internal
   * Constructs a KonqSettings instance from a config file.
   * Set the group before calling.
   * (done by defaultFMSettings and defaultHTMLSettings)
   */
  KonqSettings( KConfig * config );

  /** Called by constructor and reparseConfiguration */
  void init( KConfig * config );

  /** Destructor. Don't delete any instance by yourself. */
  virtual ~KonqSettings();

public:
    
  /**
   * A static instance of KonqSettings, holding the values for KDesktop
   */
  static inline KonqSettings * defaultDesktopSettings();
  /**
   * A static instance of KonqSettings, holding the values for FileManager
   */
  static inline KonqSettings * defaultFMSettings();
  /**
   * A static instance of KonqSettings, holding the values for HTML
   */
  static inline KonqSettings * defaultHTMLSettings();

  /**
   * Reparse the configuration to update the already-created instances
   * TODO : will have to be called on slotConfigure
   */
  static void reparseConfiguration();


  // Behaviour settings
  bool singleClick() { return m_bSingleClick; }
  int autoSelect() { return m_iAutoSelect; }
  bool changeCursor() { return m_bChangeCursor; }
  bool underlineLink() { return m_underlineLink; }

  // Font settings
  const char* stdFontName() { return m_strStdFontName; }
  const char* fixedFontName() { return m_strFixedFontName; }
  int fontSize() { return m_iFontSize; }

  // Color settings
  const QColor& bgColor() { return m_bgColor; }
  const QColor& textColor() { return m_textColor; }
  const QColor& linkColor() { return m_linkColor; }
  const QColor& vLinkColor() { return m_vLinkColor; }

  // Autoload images (only means something for HMTL configuration)
  bool autoLoadImages() { return m_bAutoLoadImages; }

protected:
  // The three instances
  static KonqSettings * s_pSettings[3];

  static KonqSettings * getInstance( int nr );
  
  bool m_bSingleClick;
  int m_iAutoSelect;  
  bool m_bChangeCursor;
  bool m_underlineLink;

  QString m_strStdFontName;
  QString m_strFixedFontName;
  int m_iFontSize;  
  
  QColor m_bgColor;
  QColor m_textColor;
  QColor m_linkColor;
  QColor m_vLinkColor;

  bool m_bAutoLoadImages;

private:
  // There is no default constructor. Use the provided ones.
  KonqSettings();
  // No copy constructor either. What for ?
  KonqSettings( const KonqSettings &);
};

#endif
