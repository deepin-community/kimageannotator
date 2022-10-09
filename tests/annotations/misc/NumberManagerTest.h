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

#ifndef KIMAGEANNOTATOR_NUMBERMANAGERTEST_H
#define KIMAGEANNOTATOR_NUMBERMANAGERTEST_H

#include <QtTest>
#include <src/annotations/misc/NumberManager.h>

using kImageAnnotator::NumberManager;
using kImageAnnotator::AnnotationNumber;
using kImageAnnotator::AnnotationTextProperties;
using kImageAnnotator::TextPropertiesPtr;
using kImageAnnotator::NumberUpdateMode;

#include "src/annotations/misc/NumberManager.h"

class NumberManagerTest : public QObject
{
Q_OBJECT

private slots:
	void TestAddItem_Should_AssignCorrectNumbers_When_UpdateAllNumbersModeSelected();
	void TestAddItem_Should_AssignCorrectNumbers_When_UpdateOnlyNewNumbers();
	void TestUpdateNumbers_Should_BeTriggered_When_ItemIsHiddenAndUpdateAllNumbersModeSelected();
	void TestUpdateNumbers_Should_NotBeTriggered_When_ItemIsHiddenAndUpdateOnlyNewNumbersModeSelected();
	void TestNumberSeedChanged_Should_TriggerUpdateOfAllNumber_When_UpdateAllNumbersModeSelected();
	void TestNumberSeedChanged_Should_NotTriggerUpdateOfAllNumber_When_UpdateOnlyNewNumbersModeSelected();
	void TestNumberSeedChanged_Should_AffectOnlyNewItems_When_UpdateOnlyNewNumbersModeSelected();
};

#endif // KIMAGEANNOTATOR_NUMBERMANAGERTEST_H
