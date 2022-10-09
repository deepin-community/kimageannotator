/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
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

#include "AnnotationPathProperties.h"

namespace kImageAnnotator {

AnnotationPathProperties::AnnotationPathProperties(const QColor &color, int size) : AnnotationProperties(color, size)
{
}

AnnotationPathProperties::AnnotationPathProperties(const PathPropertiesPtr &other) : AnnotationProperties(other)
{
	mSmootPathEnabled = other->mSmootPathEnabled;
	mSmootFactor = other->mSmootFactor;
}

PropertiesPtr AnnotationPathProperties::clone() const
{
	return PropertiesPtr(new AnnotationPathProperties(*this));
}

bool AnnotationPathProperties::smoothPathEnabled() const
{
	return mSmootPathEnabled;
}

void AnnotationPathProperties::setSmoothPathEnabled(bool enabled)
{
	mSmootPathEnabled = enabled;
}

int AnnotationPathProperties::smoothFactor() const
{
	return mSmootFactor;
}

void AnnotationPathProperties::setSmoothFactor(int factor)
{
	mSmootFactor = factor;
}

}
