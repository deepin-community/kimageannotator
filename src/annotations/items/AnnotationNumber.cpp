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

#include "AnnotationNumber.h"

namespace kImageAnnotator {

AnnotationNumber::AnnotationNumber(const QPointF &centerPosition, const TextPropertiesPtr &properties)	: AbstractAnnotationRect(centerPosition, properties)
{
	mRect->moveCenter(centerPosition);
}

AnnotationNumber::AnnotationNumber(const AnnotationNumber &other) : AbstractAnnotationRect(other), BaseAnnotationNumber(other)
{
	updateShape();
}

void AnnotationNumber::addPoint(const QPointF &position, bool modified)
{
	Q_UNUSED(position);
	Q_UNUSED(modified);

	// Nothing to do here
}

Tools AnnotationNumber::toolType() const
{
	return Tools::Number;
}

QPainterPath AnnotationNumber::shape() const
{
	auto path = AbstractAnnotationItem::shape();
	path.addRect(*mRect);
	return path;
}

TextPropertiesPtr AnnotationNumber::textProperties() const
{
	return AbstractAnnotationItem::properties().staticCast<AnnotationTextProperties>();
}

void AnnotationNumber::updateShape()
{
	QPainterPath path;
	path.addEllipse(*mRect);
	setShape(path);
}

void AnnotationNumber::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	AbstractAnnotationRect::paint(painter, option, widget);

	painter->setFont(textProperties()->font());
	painter->setPen(properties()->textColor());
	painter->drawText(boundingRect(), Qt::AlignCenter, numberString());
}

void AnnotationNumber::updateProperties(const PropertiesPtr &properties)
{
	AbstractAnnotationItem::updateProperties(properties);
	updateRect();
}

void AnnotationNumber::updateRect()
{
	prepareGeometryChange();
	BaseAnnotationNumber::updateRect(mRect, textProperties()->font());
	updateShape();
}

} // namespace kImageAnnotator
