/**********************************************************************************************
    Copyright (C) 2018 Oliver Eichler oliver.eichler@gmx.de

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**********************************************************************************************/

#include "helpers/CDraw.h"
#include "helpers/CSettings.h"
#include "helpers/CWptIconManager.h"
#include "setup/IAppSetup.h"

#include <QtWidgets>

CWptIconManager * CWptIconManager::pSelf = nullptr;
const char * CWptIconManager::wptDefault = "://icons/waypoints/32x32/Default.png";

CWptIconManager::CWptIconManager(QObject *parent)
{
    pSelf = this;

    init();
}

CWptIconManager::~CWptIconManager()
{
    qDebug()<< "CWptIconManager::~CWptIconManager()";
    removeNumberedBullets();
}

void CWptIconManager::removeNumberedBullets()
{
    for(const QString& filename : mapNumberedBullets)
    {
        QFile::remove(filename);
    }
    mapNumberedBullets.clear();
}

void CWptIconManager::init()
{
    wptIcons.clear();

    wptIcons["Default"]             = icon_t(wptDefault, 16, 16);
    wptIcons["City (Capitol)"]      = icon_t("://icons/waypoints/32x32/CityCapitol.png", 16, 16);
    wptIcons["City (Large)"]        = icon_t("://icons/waypoints/32x32/CityLarge.png", 16, 16);
    wptIcons["City (Medium)"]       = icon_t("://icons/waypoints/32x32/CityMedium.png", 16, 16);
    wptIcons["City (Small)"]        = icon_t("://icons/waypoints/32x32/CitySmall.png", 16, 16);
    wptIcons["Residence"]           = icon_t("://icons/waypoints/32x32/Residence.png", 16, 16);
    wptIcons["Flag, Red"]           = icon_t("://icons/waypoints/32x32/FlagRed.png", 0, 32);
    wptIcons["Flag, Blue"]          = icon_t("://icons/waypoints/32x32/FlagBlue.png", 0, 32);
    wptIcons["Flag, Green"]         = icon_t("://icons/waypoints/32x32/FlagGreen.png", 0, 32);
    wptIcons["Pin, Red"]            = icon_t("://icons/waypoints/32x32/PinRed.png", 0, 32);
    wptIcons["Pin, Blue"]           = icon_t("://icons/waypoints/32x32/PinBlue.png", 0, 32);
    wptIcons["Pin, Green"]          = icon_t("://icons/waypoints/32x32/PinGreen.png", 0, 32);
    wptIcons["Block, Red"]          = icon_t("://icons/waypoints/32x32/BoxRed.png", 16, 16);
    wptIcons["Block, Blue"]         = icon_t("://icons/waypoints/32x32/BoxBlue.png", 16, 16);
    wptIcons["Block, Green"]        = icon_t("://icons/waypoints/32x32/BoxGreen.png", 16, 16);
    wptIcons["Blue Diamond"]        = icon_t("://icons/waypoints/32x32/DiamondBlue.png", 16, 16);
    wptIcons["Green Diamond"]       = icon_t("://icons/waypoints/32x32/DiamondGreen.png", 16, 16);
    wptIcons["Red Diamond"]         = icon_t("://icons/waypoints/32x32/DiamondRed.png", 16, 16);
    wptIcons["Parking Area"]        = icon_t("://icons/cache/32x32/parking.png", 16, 16);
    wptIcons["Trailhead"]           = icon_t("://icons/cache/32x32/trailhead.png", 16, 16);
    wptIcons["Waypoint"]            = icon_t("://icons/waypoints/32x32/Waypoint.png", 16, 16);
    wptIcons["1st Category"]         = icon_t("://icons/waypoints/32x32/1stCategory.png", 16, 16);
    wptIcons["2nd Category"]         = icon_t("://icons/waypoints/32x32/2ndCategory.png", 16, 16);
    wptIcons["3rd Category"]         = icon_t("://icons/waypoints/32x32/3rdCategory.png", 16, 16);
    wptIcons["4th Category"]         = icon_t("://icons/waypoints/32x32/4thCategory.png", 16, 16);
    wptIcons["Danger"]              = icon_t("://icons/waypoints/32x32/Danger.png", 16, 16);
    wptIcons["First Aid"]            = icon_t("://icons/waypoints/32x32/FirstAid.png", 16, 16);
    wptIcons["Food"]                = icon_t("://icons/waypoints/32x32/Food.png", 16, 16);
    wptIcons["Generic"]             = icon_t("://icons/waypoints/32x32/Generic.png", 16, 16);
    wptIcons["Hors Category"]        = icon_t("://icons/waypoints/32x32/HorsCategory.png", 16, 16);
    wptIcons["Left"]                = icon_t("://icons/waypoints/32x32/Left.png", 16, 16);
    wptIcons["Right"]               = icon_t("://icons/waypoints/32x32/Right.png", 16, 16);
    wptIcons["Sprint"]              = icon_t("://icons/waypoints/32x32/Sprint.png", 16, 16);
    wptIcons["Straight"]            = icon_t("://icons/waypoints/32x32/Straight.png", 16, 16);
    wptIcons["Summit"]              = icon_t("://icons/waypoints/32x32/Summit.png", 16, 16);
    wptIcons["Valley"]              = icon_t("://icons/waypoints/32x32/Valley.png", 16, 16);
    wptIcons["Water"]               = icon_t("://icons/waypoints/32x32/Water.png", 16, 16);
    wptIcons["LeftFork"]            = icon_t("://icons/waypoints/32x32/LeftFork.png", 16, 16);
    wptIcons["RightFork"]           = icon_t("://icons/waypoints/32x32/RightFork.png", 16, 16);
    wptIcons["MiddleFork"]          = icon_t("://icons/waypoints/32x32/MiddleFork.png", 16, 16);
    wptIcons["SlightLeft"]          = icon_t("://icons/waypoints/32x32/SlightLeft.png", 16, 16);
    wptIcons["SharpLeft"]           = icon_t("://icons/waypoints/32x32/SharpLeft.png", 16, 16);
    wptIcons["SlightRight"]         = icon_t("://icons/waypoints/32x32/SlightRight.png", 16, 16);
    wptIcons["SharpRight"]          = icon_t("://icons/waypoints/32x32/SharpRight.png", 16, 16);
    wptIcons["UTurn"]               = icon_t("://icons/waypoints/32x32/UTurn.png", 16, 16);
    wptIcons["Start"]               = icon_t("://icons/waypoints/32x32/Start.png", 16, 16);
    wptIcons["End"]                 = icon_t("://icons/waypoints/32x32/End.png", 16, 16);

    setWptIconByName("Traditional Cache", "://icons/geocaching/icons/traditional.png");
    setWptIconByName("Multi-cache", "://icons/geocaching/icons/multi.png");
    setWptIconByName("Unknown Cache", "://icons/geocaching/icons/unknown.png");
    setWptIconByName("Wherigo Cache", "://icons/geocaching/icons/wherigo.png");
    setWptIconByName("Event Cache", "://icons/geocaching/icons/event.png");
    setWptIconByName("Earthcache", "://icons/geocaching/icons/earth.png");
    setWptIconByName("Letterbox Hybrid", "://icons/geocaching/icons/letterbox.png");
    setWptIconByName("Virtual Cache", "://icons/geocaching/icons/virtual.png");
    setWptIconByName("Webcam Cache", "://icons/geocaching/icons/webcam.png");

    SETTINGS;
    QDir dirIcon(cfg.value("Paths/externalWptIcons", IAppSetup::getPlatformInstance()->userDataPath("WaypointIcons")).toString());


    QStringList filenames = dirIcon.entryList(QString("*.bmp *.png").split(" "), QDir::Files);

    for(const QString &filename : filenames)
    {
        QFileInfo fi(filename);
        QString name = fi.completeBaseName();
        setWptIconByName(name, dirIcon.filePath(filename));
    }
}

void CWptIconManager::setWptIconByName(const QString& name, const QString& filename)
{
    QPixmap icon(filename);
    wptIcons[name] = icon_t(filename, icon.width()>>1, icon.height()>>1);
}


void CWptIconManager::setWptIconByName(const QString& name, const QPixmap& icon)
{
    SETTINGS;
    QDir dirIcon(cfg.value("Paths/externalWptIcons", IAppSetup::getPlatformInstance()->userDataPath("WaypointIcons")).toString());
    QString filename = dirIcon.filePath(name + ".png");

    icon.save(filename);
    wptIcons[name] = icon_t(filename, icon.width()>>1, icon.height()>>1);
}

QPixmap CWptIconManager::loadIcon(const QString& path)
{
    QFileInfo finfo(path);
    if(finfo.completeSuffix() != "bmp")
    {
        return QPixmap(path);
    }
    else
    {
        QImage img = QPixmap(path).toImage().convertToFormat(QImage::Format_Indexed8);
        img.setColor(0, qRgba(0, 0, 0, 0));
        return QPixmap::fromImage(img);
    }
}


QPixmap CWptIconManager::getWptIconByName(const QString& name, QPointF &focus, QString * src)
{
    QPixmap icon;
    QString path;

    if(wptIcons.contains(name))
    {
        focus   = wptIcons[name].focus;
        path    = wptIcons[name].path;
    }
    else
    {
        focus   = wptIcons["Default"].focus;
        path    = wptIcons["Default"].path;
    }

    if(path.isEmpty())
    {
        path = wptDefault;
    }

    if(src)
    {
        *src = path;
    }

    icon = loadIcon(path);

    // Limit icon size to 22 pixel max.
    if(icon.width() > 22 || icon.height() > 22)
    {
        qreal s;
        if(icon.width() > icon.height())
        {
            s = 22.0/icon.width();
        }
        else
        {
            s = 22.0/icon.height();
        }

        focus = focus * s;
        icon  = icon.scaled(icon.size()*s, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    return icon;
}

QString CWptIconManager::selectWptIcon(QWidget * parent)
{
    QString icon;

    QMenu * menu = getWptIconMenu("", nullptr, "", parent);
    QAction * action = menu->exec(QCursor::pos());

    if(action != nullptr)
    {
        icon = action->property("iconName").toString();
    }

    return icon;
}

static bool keyLessThanAlpha(const QString&  s1, const QString&  s2)
{
    static QCollator collator;
    // this will set collator to natural sorting mode (instead of lexical)
    collator.setNumericMode(true);
    return collator.compare(s1, s2) < 0;
}

QMenu * CWptIconManager::getWptIconMenu(const QString& title, QObject * obj, const char * slot, QWidget * parent)
{
    QMenu * menu = new QMenu(title, parent);
    menu->setIcon(QIcon("://icons/waypoints/32x32/PinBlue.png"));

    const QMap<QString, icon_t>& wptIcons = getWptIcons();
    QStringList keys = wptIcons.keys();

    qSort(keys.begin(), keys.end(), keyLessThanAlpha);

    for(const QString &key : keys)
    {
        const QString& icon = wptIcons[key].path;
        QPixmap pixmap      = loadIcon(icon);

        QAction * action = menu->addAction(pixmap, key);
        action->setProperty("iconName", key);
        if(obj != nullptr)
        {
            QAction::connect(action, SIGNAL(triggered(bool)), obj, slot);
        }
    }

    return menu;
}

QString CWptIconManager::getNumberedBullet(qint32 n)
{
    const QFont& font = CMainWindow::self().getMapFont();
    if(mapNumberedBullets.contains(n) && (lastFont == font))
    {
        return mapNumberedBullets[n];
    }

    if(lastFont != font)
    {
        removeNumberedBullets();
        lastFont = font;
    }

    const QString& filename = QDir::temp().absoluteFilePath(QString("Bullet%1.png").arg(n));
    mapNumberedBullets[n] = filename;

    const QPixmap& pixmap = CDraw::number(n, Qt::black);
    pixmap.save(filename);

    return filename;
}
