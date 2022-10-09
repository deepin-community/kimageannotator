/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
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

#include "SelectionHandlerTest.h"

void SelectionHandlerTest::TestSetWidth_Should_EmitSelectionChangedSignal()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	QSignalSpy spy(&selectionHandler, &SelectionHandler::selectionChanged);

	// act
	selectionHandler.setWidth(30);

	// assert
	QCOMPARE(spy.count(), 1);
}

void SelectionHandlerTest::TestSetHeight_Should_EmitSelectionChangedSignal()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	QSignalSpy spy(&selectionHandler, &SelectionHandler::selectionChanged);

	// act
	selectionHandler.setHeight(30);

	// assert
	QCOMPARE(spy.count(), 1);
}

void SelectionHandlerTest::TestSetPositionX_Should_EmitSelectionChangedSignal()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	QSignalSpy spy(&selectionHandler, &SelectionHandler::selectionChanged);

	// act
	selectionHandler.setPositionY(30);

	// assert
	QCOMPARE(spy.count(), 1);
}

void SelectionHandlerTest::TestSetPositionY_Should_EmitSelectionChangedSignal()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	QSignalSpy spy(&selectionHandler, &SelectionHandler::selectionChanged);

	// act
	selectionHandler.setPositionX(30);

	// assert
	QCOMPARE(spy.count(), 1);
}

void SelectionHandlerTest::TestResetSelection_Should_SetSelectionToProvidedRect()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	auto sceneRect = QRectF(0, 0, 500, 500);
	annotationArea.setSceneRect(sceneRect);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	selectionHandler.setWidth(400);
	QVERIFY(selectionHandler.selection() != sceneRect);

	// act
	selectionHandler.resetSelection(sceneRect, sceneRect);

	// assert
	QCOMPARE(selectionHandler.selection(), sceneRect);
}

void SelectionHandlerTest::TestIsInMotion_Should_ReturnTrue_WhenClickedOnSelection()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	auto sceneRect = QRectF(0, 0, 500, 500);
	auto position = QPointF(150, 150);
	annotationArea.setSceneRect(sceneRect);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	selectionHandler.resetSelection(sceneRect, sceneRect);
	selectionHandler.grab(position);

	// act
	auto isInMotion = selectionHandler.isInMotion();

	// assert
	QCOMPARE(isInMotion, true);
}

void SelectionHandlerTest::TestIsInMotion_Should_ReturnTrue_WhenClickedOnHandle()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	auto sceneRect = QRectF(0, 0, 500, 500);
	auto position = QPointF(2, 2);
	annotationArea.setSceneRect(sceneRect);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	selectionHandler.grab(position);

	// act
	auto isInMotion = selectionHandler.isInMotion();

	// assert
	QCOMPARE(isInMotion, true);
}

void SelectionHandlerTest::TestIsInMotion_Should_ReturnFalse_WhenClickedOutsideSelectionAndHandle()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	auto sceneRect = QRectF(0, 0, 500, 500);
	auto position = QPointF(400, 400);
	annotationArea.setSceneRect(sceneRect);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	selectionHandler.setWidth(200);
	selectionHandler.grab(position);

	// act
	auto isInMotion = selectionHandler.isInMotion();

	// assert
	QCOMPARE(isInMotion, false);
}

void SelectionHandlerTest::TestSelectionHandles_Should_ReturnEightItems()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);

	// act
	auto handles = selectionHandler.selectionHandles();

	// assert
	QCOMPARE(handles.length(), 8);
}

void SelectionHandlerTest::TestRestrictResize_Should_KeepCurrentSelection_When_NewSelectionHasNegativeWidthAndRestrictionDisabled()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	selectionHandler.setRestrictionEnabled(false);
	auto selectionBefore = selectionHandler.selection();

	// act
	selectionHandler.setWidth(-30);

	// assert
	auto selectionAfter = selectionHandler.selection();
	QCOMPARE(selectionBefore, selectionAfter);
	QVERIFY(selectionAfter.width() >= 0);
}

void SelectionHandlerTest::TestRestrictResize_Should_KeepCurrentSelection_When_NewSelectionHasNegativeHeightAndRestrictionDisabled()
{
	// arrange
	MockDefaultParameters parameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	auto selectionRestrictor = new MockSelectionRestrictor();
	AnnotationArea annotationArea(&parameters.config, &parameters.settingsProvider, scalerMock, &parameters.zoomValueProvider, nullptr);
	SelectionHandler selectionHandler(selectionRestrictor);
	selectionHandler.init(&annotationArea);
	selectionHandler.setRestrictionEnabled(false);
	auto selectionBefore = selectionHandler.selection();

	// act
	selectionHandler.setHeight(-30);

	// assert
	auto selectionAfter = selectionHandler.selection();
	QCOMPARE(selectionBefore, selectionAfter);
	QVERIFY(selectionAfter.height() >= 0.0);
}

QTEST_MAIN(SelectionHandlerTest)
