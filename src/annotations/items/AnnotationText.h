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

#ifndef KIMAGEANNOTATOR_ANNOTATIONTEXT_H
#define KIMAGEANNOTATOR_ANNOTATIONTEXT_H

#include "AbstractAnnotationRect.h"
#include "src/annotations/items/interfaces/EditableItem.h"
#include "src/annotations/items/text/AnnotationTextHandler.h"
#include "src/annotations/properties/AnnotationTextProperties.h"

namespace kImageAnnotator {

class AnnotationText : public AbstractAnnotationRect, public EditableItem
{
Q_OBJECT
public:
	AnnotationText(const QPointF &startPosition, const TextPropertiesPtr &properties);
	AnnotationText(const AnnotationText &other);
	~AnnotationText() override = default;
	void finish() override;
	Tools toolType() const override;
	QPainterPath shape() const override;
	void enableEditing() override;
	void disableEditing() override;
	TextPropertiesPtr textProperties() const;

protected:
	void updateShape() override;
	void focusOutEvent(QFocusEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;
	void inputMethodEvent(QInputMethodEvent *event) override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *style, QWidget *widget) override;

private:
	AnnotationTextHandler mTextHandler;

	void connectSlots();
	void setupFlags();

private slots:
	void escape();
	void refresh();
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ANNOTATIONTEXT_H
