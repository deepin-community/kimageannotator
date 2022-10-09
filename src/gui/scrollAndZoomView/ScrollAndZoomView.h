/*
 * Copyright (C) 2021 Damir Porobic <damir.porobic@gmx.com>
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

#ifndef KIMAGEANNOTATOR_SCROLLANDZOOMVIEW_H
#define KIMAGEANNOTATOR_SCROLLANDZOOMVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QGuiApplication>

#include "ViewZoomer.h"
#include "src/common/helper/KeyHelper.h"

namespace kImageAnnotator {

class ScrollAndZoomView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit ScrollAndZoomView(QWidget *parent);
	~ScrollAndZoomView() override;
	ZoomValueProvider *zoomValueProvider() const;

protected:
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void wheelEvent(QWheelEvent *event) override;

private:
	ViewZoomer *mViewZoomer;
	bool mIsDragging;
	QPoint mLastPosition;
	KeyHelper mKeyHelper;

	void scrollTo(const QPoint &pos);
	void scrollByDelta(QScrollBar *scrollBar, int delta) const;
	void enableDragging(const QPoint &pos);
	void disableDragging();
	void setDragCursorEnabled(bool enabled) const;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_SCROLLANDZOOMVIEW_H
