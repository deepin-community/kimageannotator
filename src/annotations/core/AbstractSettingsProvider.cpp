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

#include "AbstractSettingsProvider.h"

namespace kImageAnnotator {

AbstractSettingsProvider::AbstractSettingsProvider() :
	mSettingsListener(nullptr),
	mZoomValueProvider(nullptr)
{

}

void AbstractSettingsProvider::toolChanged(Tools tool)
{
	if(mSettingsListener != nullptr) {
		mSettingsListener->toolChanged(tool);
	}
}

void AbstractSettingsProvider::numberToolSeedChanged(int numberToolSeed)
{
	if(mSettingsListener != nullptr) {
		mSettingsListener->numberToolSeedChanged(numberToolSeed);
	}
}

void AbstractSettingsProvider::itemSettingChanged()
{
	if(mSettingsListener != nullptr) {
		mSettingsListener->itemSettingsChanged();
	}
}

void AbstractSettingsProvider::setActiveListener(ISettingsListener *settingsListener)
{
	mSettingsListener = settingsListener;
	if(mSettingsListener != nullptr) {
		updateNumberToolSeed(mSettingsListener->numberToolSeed());
	}
}

void AbstractSettingsProvider::setActiveZoomValueProvider(ZoomValueProvider *zoomValueProvider)
{
	mZoomValueProvider = zoomValueProvider;
	if(mZoomValueProvider != nullptr) {
		updateZoomLevel(mZoomValueProvider->zoomValue());
	}
}

void AbstractSettingsProvider::effectChanged(ImageEffects effect)
{
	if(mSettingsListener != nullptr) {
		mSettingsListener->imageEffectChanged(effect);
	}
}

void AbstractSettingsProvider::zoomValueChanged(double value)
{
	if(mZoomValueProvider != nullptr) {
		mZoomValueProvider->setZoomValue(value);
	}
}

} // namespace kImageAnnotator
