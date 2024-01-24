// SPDX-License-Identifier: GPL-3.0-only
/*
 *  Prism Launcher - Minecraft Launcher
 *  Copyright (c) 2023 Trial97 <alexandru.tripon97@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include "java/providers/BasicJavaDownloader.h"

class MojangJavaDownloader : public BasicJavaDownloader {
    Q_OBJECT
   public:
    void executeTask() override;

    virtual QString name() const override { return "Mojang"; };
    virtual bool isSupported() const override { return !getOS().isEmpty(); };
   private slots:
    void downloadJavaList();
    void parseManifest(const QJsonArray& versionArray);
    void downloadJava(const QJsonDocument& doc);

   private:
    QString getOS() const;
};