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

#ifndef KIMAGEANNOTATOR_DELETECOMMANDTEST_H
#define KIMAGEANNOTATOR_DELETECOMMANDTEST_H

#include <QtTest>

#include "src/annotations/undo/DeleteCommand.h"
#include "src/annotations/core/AnnotationArea.h"
#include "src/annotations/items/AnnotationLine.h"
#include "tests/mocks/MockSettingsProvider.h"
#include "tests/mocks/MockDevicePixelRatioScaler.h"

using kImageAnnotator::DeleteCommand;
using kImageAnnotator::AnnotationArea;
using kImageAnnotator::AnnotationProperties;
using kImageAnnotator::AnnotationLine;
using kImageAnnotator::AbstractAnnotationItem;
using kImageAnnotator::Config;
using kImageAnnotator::PropertiesPtr;

class DeleteCommandTest : public QObject
{
Q_OBJECT

private slots:
	void TestRedo_Should_ApplyOperation();
	void TestUndo_Should_UndoOperation();
};

#endif // KIMAGEANNOTATOR_DELETECOMMANDTEST_H
