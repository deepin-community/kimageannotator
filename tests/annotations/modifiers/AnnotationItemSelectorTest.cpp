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

#include "AnnotationItemSelectorTest.h"

#include "tests/mocks/MockZoomValueProvider.h"

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_SelectItem_When_ItemUnderProvidedPosition()
{
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	AnnotationLine line(p1, properties);
	line.addPoint(p2, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);

	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(0, 5), &items, false);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 1);
	QCOMPARE(results.first(), &line);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_NotSelectItem_When_ItemNotUnderProvidedPosition()
{
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	AnnotationLine line(p1, properties);
	line.addPoint(p2, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);

	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(0, -5), &items, false);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 0);
	QCOMPARE(results.contains(&line), false);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_UnselectAllItems_When_ProvidedPositionNotOverAnyItem()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(15, 15);
	QPointF p4(20, 20);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p4 + QPointF(5, 5));
	selector.finishSelectionRectWhenShown(&items);
	QCOMPARE(selector.selectedItems().count(), 2);

	selector.handleSelectionOrShowSelectionRectAt(QPointF(0, 0), &items, false);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 0);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_NotUnselectAnyItem_When_ProvidedPositionIsOverSelectedItem()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(15, 15);
	QPointF p4(20, 20);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p4 + QPointF(5, 5));
	selector.finishSelectionRectWhenShown(&items);
	QCOMPARE(selector.selectedItems().count(), 2);

	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(0, 5), &items, false);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 2);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_UnselectItemsNotUnderPosition_When_ProvidedPositionIsOverNotSelectedItem()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(12, 12);
	QPointF p3(15, 15);
	QPointF p4(20, 20);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p2 + QPointF(1, 1));
	selector.finishSelectionRectWhenShown(&items);
	QCOMPARE(selector.selectedItems().count(), 1);
	QCOMPARE(selector.selectedItems().contains(&line1), true);
	QCOMPARE(selector.selectedItems().contains(&line2), false);

	selector.handleSelectionOrShowSelectionRectAt(p3 + QPointF(2, 2), &items, false);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 1);
	QCOMPARE(results.contains(&line1), false);
	QCOMPARE(results.contains(&line2), true);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_NotShowRect_When_InitialPositionNotOnItem()
{
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	AnnotationLine line(p1, properties);
	line.addPoint(p2, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);

	selector.handleSelectionOrShowSelectionRectAt(QPointF(2, 2), &items, false);

	QCOMPARE(selector.selectedItems().count(), 0);
	QCOMPARE(selector.isSelecting(), true);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_ShowRect_When_InitialPositionOnItem()
{
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	AnnotationLine line(p1, properties);
	line.addPoint(p2, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);

	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(0, 5), &items, false);

	QCOMPARE(selector.selectedItems().count(), 1);
	QCOMPARE(selector.isSelecting(), false);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_UnselectItem_When_WhenCtrlPressedAndItemUnderProvidedPositionWasSelected()
{
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 1));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	AnnotationLine line(p1, properties);
	line.addPoint(p2, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1, &items, false);
	QCOMPARE(selector.selectedItems().first(), &line);

	selector.handleSelectionOrShowSelectionRectAt(p1, &items, true);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 0);
}

void AnnotationItemSelectorTest::TestHandleSelectionRectAt_Should_SelectItem_When_WhenCtrlPressedAndItemUnderProvidedPositionWasNotSelected()
{
	auto properties = PropertiesPtr(new AnnotationProperties(Qt::red, 1));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	AnnotationLine line(p1, properties);
	line.addPoint(p2, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	QCOMPARE(selector.selectedItems().count(), 0);

	selector.handleSelectionOrShowSelectionRectAt(p1, &items, true);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 1);
	QCOMPARE(results.first(), &line);
}

void AnnotationItemSelectorTest::TestFinishSelectionRectWhenShown_Should_SelectItems_When_ItemsWithinSelectionRect()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(15, 15);
	QPointF p4(20, 20);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);

	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p4 + QPointF(5, 5));
	selector.finishSelectionRectWhenShown(&items);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 2);
	QCOMPARE(results.contains(&line1), true);
	QCOMPARE(results.contains(&line2), true);
}

void AnnotationItemSelectorTest::TestFinishSelectionRectWhenShown_Should_SelectOnlyItemWithinSelectionRect()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(25, 25);
	QPointF p4(30, 30);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);

	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p2 + QPointF(5, 5));
	selector.finishSelectionRectWhenShown(&items);

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 1);
	QCOMPARE(results.contains(&line1), true);
	QCOMPARE(results.contains(&line2), false);
}

void AnnotationItemSelectorTest::TestClearSelection_Should_UnselectAllSelectedItems()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(15, 15);
	QPointF p4(20, 20);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p4 + QPointF(5, 5));
	selector.finishSelectionRectWhenShown(&items);
	QCOMPARE(selector.selectedItems().count(), 2);
	QCOMPARE(selector.selectedItems().contains(&line1), true);
	QCOMPARE(selector.selectedItems().contains(&line2), true);

	selector.clearSelection();

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 0);
}

void AnnotationItemSelectorTest::TestBoundRect_Should_ReturnRectCoveringSelectedItems_When_ItemsSelected()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(25, 25);
	QPointF p4(30, 30);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p4);
	selector.finishSelectionRectWhenShown(&items);

	auto boundingRect = selector.boundingRect();

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 2);
	QCOMPARE(results.contains(&line1), true);
	QCOMPARE(results.contains(&line2), true);
	QCOMPARE(boundingRect, line1.boundingRect().united(line2.boundingRect()));
}

void AnnotationItemSelectorTest::TestRefresh_Should_UpdateBoundingRect_When_CalledAfterItemsHaveBeenMoved()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(25, 25);
	QPointF p4(30, 30);
	QPointF p5(50, 50);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(p1 + QPointF(-5, -5), &items, false);
	selector.extendSelectionRectWhenShown(p4);
	selector.finishSelectionRectWhenShown(&items);
	line1.setPosition(p5);
	QVERIFY(selector.boundingRect() != line1.boundingRect().united(line2.boundingRect()));

	selector.refresh();

	auto boundingRect = selector.boundingRect();
	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 2);
	QCOMPARE(results.contains(&line1), true);
	QCOMPARE(results.contains(&line2), true);
	QCOMPARE(boundingRect, line1.boundingRect().united(line2.boundingRect()));
}

void AnnotationItemSelectorTest::TestUpdate_Should_UnselectItemsThatAreNotVisible()
{
	auto properties1 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	auto properties2 = PropertiesPtr(new AnnotationProperties(Qt::red, 3));
	QPointF p1(10, 10);
	QPointF p2(10, 20);
	QPointF p3(25, 25);
	QPointF p4(30, 30);
	AnnotationLine line1(p1, properties1);
	AnnotationLine line2(p3, properties2);
	line1.addPoint(p2, false);
	line2.addPoint(p4, false);
	QList<AbstractAnnotationItem *> items;
	items.append(&line1);
	items.append(&line2);
	MockZoomValueProvider zoomValueProvider;
	AnnotationItemSelector selector(&zoomValueProvider);
	selector.handleSelectionOrShowSelectionRectAt(QPointF(0, 0), &items, false);
	selector.extendSelectionRectWhenShown(p4);
	selector.finishSelectionRectWhenShown(&items);
	QCOMPARE(selector.selectedItems().count(), 2);
	line2.hide();

	selector.update();

	auto results = selector.selectedItems();
	QCOMPARE(results.count(), 1);
	QCOMPARE(results.contains(&line1), true);
	QCOMPARE(results.contains(&line2), false);
}

QTEST_MAIN(AnnotationItemSelectorTest);
