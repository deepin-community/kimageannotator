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

#ifndef KIMAGEANNOTATOR_ANNOTATIONDOCKWIDGET_H
#define KIMAGEANNOTATOR_ANNOTATIONDOCKWIDGET_H

#include <QDockWidget>

#include "AbstractAnnotationDockWidgetContent.h"
#include "AnnotationDockWidgetDragHandle.h"
#include "src/common/provider/ScaledSizeProvider.h"

namespace kImageAnnotator {

class AnnotationDockWidget : public QDockWidget
{
Q_OBJECT
public:
	explicit AnnotationDockWidget(AbstractAnnotationDockWidgetContent *content);
	~AnnotationDockWidget() override;
	void setCollapsed(bool isCollapsed);

private:
	AbstractAnnotationDockWidgetContent *mContent;
	AnnotationDockWidgetDragHandle *mDragHandle;
	QDockWidget::DockWidgetFeatures mVerticalFeatures;
	QDockWidget::DockWidgetFeatures mHorizontalFeatures;
	QSize mSizeBeforeCollapse;

	void resizeToContent();
	
private slots:
	void updateDockLocation(Qt::DockWidgetArea area);
	void setOrientation(Qt::Orientation orientation, QDockWidget::DockWidgetFeatures &features);
	void resizeToDragHandle();
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ANNOTATIONDOCKWIDGET_H
