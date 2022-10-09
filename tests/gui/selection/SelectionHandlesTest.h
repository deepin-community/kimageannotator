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

#ifndef KIMAGEANNOTATOR_SELECTIONHANDLESTEST_H
#define KIMAGEANNOTATOR_SELECTIONHANDLESTEST_H

#include <QtTest>

#include "src/gui/selection/SelectionHandles.h"

using kImageAnnotator::SelectionHandles;
using kImageAnnotator::Constants::ResizeHandleSize;

class SelectionHandlesTest : public QObject
{
Q_OBJECT
private slots:
	void TestIsHandleGrabbed_Should_ReturnTrue_When_ClickedOnHandle();
	void TestIsHandleGrabbed_Should_ReturnFalse_When_ClickedOutsideHandle();
	void TestGrabbedIndex_Should_ReturnIndexOfHandle_When_ClickedOnHandle();
	void TestGrabbedIndex_Should_ReturnMinusOne_When_ClickedOutsideHandle();
	void TestGrabOffset_Should_ReturnClickOffsetForHandle();
	void TestUpdateHandles_Should_PositionHandlesOnCorrectPlaces();
};

#endif // KIMAGEANNOTATOR_SELECTIONHANDLESTEST_H
