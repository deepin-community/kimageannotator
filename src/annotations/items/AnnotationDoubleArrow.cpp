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

#include "AnnotationDoubleArrow.h"

namespace kImageAnnotator {

AnnotationDoubleArrow::AnnotationDoubleArrow(const QPointF &startPosition, const PropertiesPtr &properties) : AnnotationArrow(startPosition, properties)
{

}

AnnotationDoubleArrow::AnnotationDoubleArrow(const AnnotationArrow &other) : AnnotationArrow(other)
{

}

Tools AnnotationDoubleArrow::toolType() const
{
	return Tools::DoubleArrow;
}

void AnnotationDoubleArrow::updateShape()
{
	QLineF shaft(mLine->p2(), mLine->p1());
	shaft.setLength(shaft.length() - 5);
	shaft.setPoints(shaft.p2(), shaft.p1());
	shaft.setLength(shaft.length() - 5);

	auto arrow = AnnotationShapeCreator::createArrowHead(properties()->width() / 2);
	auto startArrowHead = AnnotationShapeCreator::translate(arrow, mLine->p2(), -mLine->angle());
	auto endArrowHead = AnnotationShapeCreator::translate(arrow, mLine->p1(), -mLine->angle() + 180);

	QPainterPath path(shaft.p1());
	path.lineTo(shaft.p2());
	path.addPolygon(startArrowHead);
	path.addPolygon(endArrowHead);
	path.closeSubpath();
	setShape(path);
}

} // namespace kImageAnnotator