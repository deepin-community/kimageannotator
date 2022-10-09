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

#ifndef KIMAGEANNOTATOR_KEYHELPERTEST_H
#define KIMAGEANNOTATOR_KEYHELPERTEST_H

#include <QtTest>
#include <QKeyEvent>

#include "src/common/helper/KeyHelper.h"

using kImageAnnotator::KeyHelper;

class KeyHelperTest : public QObject
{
Q_OBJECT
private slots:
	void TestKeyPress_Should_EmitUndoSignal_When_ControlAndZKeyArePressed();
	void TestKeyPress_Should_EmitRedoSignal_When_ControlAndShiftAndZKeyArePressed();
	void TestKeyRelease_Should_EmitSignal_When_DeleteKeyReleased();
	void TestKeyRelease_Should_EmitSignal_When_EscapeKeyReleased();
	void TestIsControlPressed_ShouldReturnTrue_When_ControlWasPressed();
	void TestIsControlPressed_ShouldReturnFalse_When_ControlWasReleased();
	void TestIsShiftPressed_Should_ReturnTrue_When_ShiftWasPressed();
	void TestIsShiftPressed_Should_ReturnFalse_When_ShiftWasReleased();
	void TestKeyReleased_Should_EmitReturnReleased_When_ReturnWasReleased();
	void TestKeyReleased_Should_EmitEnterReleased_When_EnterWasReleased();
};

#endif // KIMAGEANNOTATOR_KEYHELPERTEST_H
