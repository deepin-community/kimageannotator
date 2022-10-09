/*
 * Copyright (C) 2021 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "RotateCommandTest.h"

#include "tests/mocks/MockDefaultParameters.h"

void RotateCommandTest::Redo_Should_RotatePixmapByProvidedAngel()
{
	// arrange
	auto oldSize = QSizeF(100, 50);
	auto newSize = QSizeF(50, 100);
	auto angel = 90;
	QPixmap pixmap(oldSize.toSize());
	QGraphicsPixmapItem image(pixmap);

	MockDefaultParameters defaultParameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	AnnotationArea annotationArea(&defaultParameters.config, &defaultParameters.settingsProvider, scalerMock, &defaultParameters.zoomValueProvider, nullptr);
	RotateCommand rotateCommand(&image, angel, &annotationArea);

	// act
	rotateCommand.redo();

	// assert
	QCOMPARE(image.boundingRect().size(), newSize);
	QCOMPARE(annotationArea.sceneRect().size(), newSize);
}

void RotateCommandTest::Redo_Should_TrimPixmapAndRemoveTransparentPart_WhenRotatedBy45DegreeTwice()
{
	// arrange
	auto oldSize = QSizeF(100, 50);
	auto newSize = QSizeF(50, 100) + QSize(3, 3); // Rotating by non 90° multipliers creates fuzzy edges due to antialiasing.
	auto angel = 45;
	QPixmap pixmap(oldSize.toSize());
	pixmap.fill(Qt::green);
	QGraphicsPixmapItem image(pixmap);

	MockDefaultParameters defaultParameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	AnnotationArea annotationArea(&defaultParameters.config, &defaultParameters.settingsProvider, scalerMock, &defaultParameters.zoomValueProvider, nullptr);
	RotateCommand rotate1Command(&image, angel, &annotationArea);
	rotate1Command.redo();
	RotateCommand rotate2Command(&image, angel, &annotationArea);

	// act
	rotate2Command.redo();

	// assert
	QCOMPARE(image.boundingRect().size(), newSize);
	QCOMPARE(annotationArea.sceneRect().size(), newSize);
}

void RotateCommandTest::Undo_Should_RevertBackToInitialImage()
{
	// arrange
	auto oldSize = QSizeF(100, 50);
	auto angel = 90;
	QPixmap pixmap(oldSize.toSize());
	QGraphicsPixmapItem image(pixmap);

	MockDefaultParameters defaultParameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	AnnotationArea annotationArea(&defaultParameters.config, &defaultParameters.settingsProvider, scalerMock, &defaultParameters.zoomValueProvider, nullptr);
	RotateCommand rotateCommand(&image, angel, &annotationArea);
	rotateCommand.redo();
	QVERIFY(image.pixmap().toImage() != pixmap.toImage());

	// act
	rotateCommand.undo();

	// assert
	QCOMPARE(image.pixmap().toImage(), pixmap.toImage());
	QCOMPARE(image.boundingRect().size(), oldSize);
	QCOMPARE(annotationArea.sceneRect().size(), oldSize);
}

QTEST_MAIN(RotateCommandTest)
