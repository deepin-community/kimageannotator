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

#ifndef KIMAGEANNOTATOR_ANNOTATIONITEMSELECTOR_H
#define KIMAGEANNOTATOR_ANNOTATIONITEMSELECTOR_H

#include <QGraphicsWidget>

#include "src/annotations/items/AbstractAnnotationItem.h"
#include "src/annotations/core/ZoomValueProvider.h"

namespace kImageAnnotator {

class AnnotationItemSelector : public QGraphicsWidget
{
public:
	explicit AnnotationItemSelector(ZoomValueProvider *zoomValueProvider);
	~AnnotationItemSelector() override;
	QRectF boundingRect() const override;
	void handleSelectionOrShowSelectionRectAt(const QPointF &pos, QList<AbstractAnnotationItem *> *items, bool isModifying);
	void extendSelectionRectWhenShown(const QPointF &pos);
	void finishSelectionRectWhenShown(QList<AbstractAnnotationItem *> *items);
	void handleSelectionAt(const QPointF &pos, QList<AbstractAnnotationItem *> *items, bool modifying);
	void clearSelection();
	QList<AbstractAnnotationItem *> selectedItems() const;
	bool isSelecting() const;
	void refresh();
	void update();
	void selectItem(AbstractAnnotationItem *item);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	QRectF mSelectionRect;
	QRectF mSelectedItemsBoundingRect;
	QList<AbstractAnnotationItem *> *mSelectedItems;
	bool mShowSelectionRect;
	QPen mSelectionPen;

	void initSelectionRectAt(const QPointF &position);
	void updateSelectionRect(const QPointF &position);
	void selectItemAt(const QPointF &position, QList<AbstractAnnotationItem *> *items);
	void toggleItemSelectionAt(const QPointF &position, QList<AbstractAnnotationItem *> *items);
	void selectItemsUnderRect(QList<AbstractAnnotationItem *> *items);
	void unselectItem(AbstractAnnotationItem *item);
	AbstractAnnotationItem *findItemAt(const QPointF &position, QList<AbstractAnnotationItem *> *items);
	void applyZoomValue(double value);
};

} // namespace kImageAnnotator

#endif // KIMAGEANNOTATOR_ANNOTATIONITEMSELECTOR_H
