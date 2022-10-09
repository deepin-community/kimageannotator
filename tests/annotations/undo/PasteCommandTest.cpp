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

#include "PasteCommandTest.h"

#include "src/annotations/undo/PasteCommand.h"
#include "src/annotations/core/AnnotationArea.h"
#include "src/annotations/items/AnnotationLine.h"
#include "src/annotations/core/AnnotationPropertiesFactory.h"
#include "tests/mocks/MockDefaultParameters.h"

using kImageAnnotator::PasteCommand;
using kImageAnnotator::AnnotationArea;
using kImageAnnotator::AbstractAnnotationItem;
using kImageAnnotator::AnnotationLine;
using kImageAnnotator::AnnotationProperties;
using kImageAnnotator::Config;
using kImageAnnotator::AnnotationItemFactory;
using kImageAnnotator::PropertiesPtr;
using kImageAnnotator::AnnotationPropertiesFactory;

void PasteCommandTest::TestRedo_Should_AddPastedItemsToAnnotationAreaAtGivenPosition()
{
	// arrange
	auto offset = QPointF(10, 10);
	auto position = QPointF(50, 50);
	MockDefaultParameters mockParameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	AnnotationPropertiesFactory propertiesFactory(&mockParameters.config, &mockParameters.settingsProvider);
	AnnotationArea annotationArea(&mockParameters.config, &mockParameters.settingsProvider, scalerMock, &mockParameters.zoomValueProvider, nullptr);
	AnnotationItemFactory itemFactory(&propertiesFactory, &mockParameters.settingsProvider, &mockParameters.config);
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 1));
	QLineF line(10, 10, 20, 20);
	auto item = new AnnotationLine(line.p1(), properties);
	item->addPoint(line.p2(), false);
	QHash<AbstractAnnotationItem *, QPointF> itemsWithOffset;
	itemsWithOffset[item] = offset;
	PasteCommand pasteCommand(itemsWithOffset, position, &itemFactory, &annotationArea);
	QVERIFY(dynamic_cast<AnnotationLine *>(annotationArea.items().last()) == nullptr);

	// act
	pasteCommand.redo();

	// assert
	auto lastItem = dynamic_cast<AnnotationLine *>(annotationArea.items().last());
	QVERIFY(lastItem != nullptr);
	QCOMPARE(lastItem->position(), position + offset);
}

void PasteCommandTest::TestUndo_Should_RemovePastedItemsFromAnnotationArea()
{
	// arrange
	auto offset = QPointF(10, 10);
	auto position = QPointF(50, 50);
	MockDefaultParameters mockParameters;
	auto scalerMock = new MockDevicePixelRatioScaler();
	AnnotationPropertiesFactory propertiesFactory(&mockParameters.config, &mockParameters.settingsProvider);
	AnnotationArea annotationArea(&mockParameters.config, &mockParameters.settingsProvider, scalerMock, &mockParameters.zoomValueProvider, nullptr);
	AnnotationItemFactory itemFactory(&propertiesFactory, &mockParameters.settingsProvider, &mockParameters.config);
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 1));
	QLineF line(10, 10, 20, 20);
	auto item = new AnnotationLine(line.p1(), properties);
	item->addPoint(line.p2(), false);
	QHash<AbstractAnnotationItem *, QPointF> itemsWithOffset;
	itemsWithOffset[item] = offset;
	PasteCommand pasteCommand(itemsWithOffset, position, &itemFactory, &annotationArea);
	pasteCommand.redo();
	QVERIFY(dynamic_cast<AnnotationLine *>(annotationArea.items().last()) != nullptr);

	// act
	pasteCommand.undo();

	// arrange
	QVERIFY(dynamic_cast<AnnotationLine *>(annotationArea.items().last()) == nullptr);
}

QTEST_MAIN(PasteCommandTest);
