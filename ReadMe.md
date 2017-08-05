# Dolphin (Zren)

This is a fork of the Dolphin file browser that patches in a couple of features.

![](https://i.imgur.com/6ESZLS9.png)

* Sort hidden files and folders last  
  Eg: The hidden folder `.git` would be at the bottom of the file list after all the non-hidden files.  
  [[Bug #333219](https://bugs.kde.org/show_bug.cgi?id=333219)] Mentions the issue is a WontFix since 0.1% users probably want it.
* Closing split view will close the inactive view by default instead of needing to configure it.  
  https://phabricator.kde.org/D18040
* Left/Right panels will extend to the bottom when there's a bottom panel (more room for bookmarks while the terminal is visible).  
  Need to reset the your panel/layout for this to take effect (see install instructions).
* Adds a new panel that looks like a toolbar with the back/forward/up buttons, a change "view mode" dropdown button.
  The panel is the same height as the address bar, so you don't need to use an entire 50px row or column for a couple of buttons.
  The buttons are not configurable like a toolbar unfortunately.
* Added a few "View Modes" which will toggle "Preview" automatically, and "Zoom" to specific sizes which are familiar to Windows users.  
  Huge Icons, Large Icons, and Tiled view mode presets.
* ~~When a folder is a mount point (usb/hard drive/partition), show a capacity bar in the "Size" column instead of the number of files it contains.~~  
  Removed this feature for now. Instead we only show a capacity bar in the "places" sidebar.
* In the Places panel, moved devices above the recently saved and search but below bookmarks.
* ~~Select child folder when going up~~  
  [[Bug #315471](https://bugs.kde.org/show_bug.cgi?id=315471)] closed as invalid (because you should be going "back").  
  [[Bug #377392](https://bugs.kde.org/show_bug.cgi?id=377392)] should be a duplicate, but contains a patch by the creator.


This fork isn't always up to date with KDE/Dolphin's master branch. To see what is missing, [compare the branches](https://github.com/Zren/dolphin/compare/zren...KDE:master).


## Install from source (to `/usr/local/bin`)

```
sudo apt-get build-dep dolphin
wget https://github.com/Zren/dolphin/archive/zren.zip dolphin-zren.zip
unzip dolphin-zren.zip dolphin-zren
rm dolphin-zren.zip
cd dolphin-zren
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
chmod +x ./bin/dolphin
```

You can test if everything went well by running:

```
./bin/dolphin
```

If it ran okay you can copy the binary to `/usr/local/bin`.

```
sudo cp ./bin/dolphin /usr/local/bin/dolphin
```

Lastly, upon the first install, we need to reset the panels/layout so that we can make left/right panels extend to the bottom of the window when the bottom panel (terminal) is visible. We need to close all dolphin windows first.

```
killall dolphin
kwriteconfig5 --file ~/.config/dolphinrc --group MainWindow --key State ''
```

Sorry you had to do that. I wasn't able to find a way to update the "state" after it was initially created so we had to reset it.



### Update (when installed from source)

Just delete the old directory and redo the install instructions.



### Uninstall (when installed from source)

```
sudo rm /usr/local/bin/dolphin
```




# Dolphin (KDE)

See http://dolphin.kde.org for information about Dolphin.

