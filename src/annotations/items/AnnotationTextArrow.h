/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef KIMAGEANNOTATOR_ANNOTATIONTEXTARROW_H
#define KIMAGEANNOTATOR_ANNOTATIONTEXTARROW_H

#include "AnnotationTextPointer.h"

namespace kImageAnnotator {

class AnnotationTextArrow : public AnnotationTextPointer
{
Q_OBJECT
public:
	AnnotationTextArrow(const QPointF &startPosition, const TextPropertiesPtr &properties);
	AnnotationTextArrow(const AnnotationTextArrow &other);
	~AnnotationTextArrow() override = default;
	Tools toolType() const override;

protected:
	void updateShape() override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *style, QWidget *widget) override;

private:
	QPainterPath mArrowShape;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ANNOTATIONTEXTARROW_H
