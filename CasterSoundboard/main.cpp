/*
 *
 *
 * Copyright 2013 Oscar Cerna
 *
 * This file is part of CasterSoundboard. An application for playing hot-keyed sounds.
 * For more information, please visit http://sourceforge.net/projects/castersb.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU LESSER GENERAL PUBLIC LICENSE
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU LESSER GENERAL PUBLIC LICENSE for more details.
 *
 * You should have received a copy of the GNU LESSER GENERAL PUBLIC LICENSE
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include "MainWindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>


int main(int argc, char *argv[])
{
    // START APPLICATION
    QApplication a(argc, argv);
    QApplication::setOrganizationName("CasterSoundboard");
    QApplication::setApplicationName("CasterSoundboard");

    // PARSE OPTIONS
    QCommandLineParser parser;
    parser.setApplicationDescription("A soundboard for hot-keying and playing back sounds. (For podcasting)");
    parser.addHelpOption();
    //parser.addVersionOption();
    parser.addOptions({
        {{"c", "config"},
                QApplication::translate("cloptions",
                                        "Use an alternate config file <configFile>."),
                QApplication::translate("cloptions", "configFile")
        }
        });
    parser.addPositionalArgument("profiles",
                                 QCoreApplication::translate("cloptions",
                                               "Sound Board profiles to open."),
                                 "[profiles...]");

    parser.process(a);
    
    // CREATE MAIN WINDOW
    MainWindow *w = new MainWindow(parser.value("config"), parser.positionalArguments());
    // SET MAIN WINDOW SIZE
    //w->resize(1000, 500);
    // SHOW MAIN WINDOW
    w->show();
    // END APPLICATION
    return a.exec();
}
