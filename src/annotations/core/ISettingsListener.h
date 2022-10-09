/*
 * Copyright (C) 2019 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
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

#ifndef KIMAGEANNOTATOR_ISETTINGSLISTENER_H
#define KIMAGEANNOTATOR_ISETTINGSLISTENER_H

#include "src/common/enum/Tools.h"
#include "src/common/enum/ImageEffects.h"

namespace kImageAnnotator {

class ISettingsListener
{
public:
	virtual void toolChanged(Tools toolType) = 0;
	virtual void itemSettingsChanged() = 0;
	virtual void numberToolSeedChanged(int numberToolSeed) = 0;
	virtual int numberToolSeed() const = 0;
	virtual void imageEffectChanged(ImageEffects effect) = 0;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ISETTINGSLISTENER_H
