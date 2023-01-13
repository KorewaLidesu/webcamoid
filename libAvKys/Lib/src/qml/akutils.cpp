/* Webcamoid, webcam capture application.
 * Copyright (C) 2021  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#include <QColor>
#include <QQmlEngine>

#include "akutils.h"

AkUtils::AkUtils():
    QObject()
{

}

AkUtils::AkUtils(const AkUtils &other):
    QObject()
{
    Q_UNUSED(other)
}

QColor AkUtils::fromRgba(QRgb color)
{
    return {qRed(color),
            qGreen(color),
            qBlue(color),
            qAlpha(color)};
}

QRgb AkUtils::toRgba(const QColor &color)
{
    return color.rgba();
}

void AkUtils::registerTypes()
{
    qmlRegisterSingletonType<AkUtils>("Ak", 1, 0, "AkUtils",
                                        [] (QQmlEngine *qmlEngine,
                                            QJSEngine *jsEngine) -> QObject * {
        Q_UNUSED(qmlEngine)
        Q_UNUSED(jsEngine)

        return new AkUtils();
    });
}

#include "moc_akutils.cpp"
