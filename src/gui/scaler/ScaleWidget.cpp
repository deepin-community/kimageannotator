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

#include "ScaleWidget.h"

namespace kImageAnnotator {

kImageAnnotator::ScaleWidget::ScaleWidget() :
	mAnnotationArea(nullptr),
	mView(new QGraphicsView),
	mMainLayout(new QVBoxLayout(this))
{
	initGui();
}

ScaleWidget::~ScaleWidget()
{
	delete mView;
}

void ScaleWidget::activate(AnnotationArea *annotationArea)
{
	Q_ASSERT(annotationArea != nullptr);

	mAnnotationArea = annotationArea;
	mView->setScene(annotationArea);
	showDialog();
}

void ScaleWidget::initGui()
{
	mMainLayout->addWidget(mView);
	setLayout(mMainLayout);
}

void ScaleWidget::showDialog()
{
	auto sceneSize = mAnnotationArea->sceneRect().size();
	ScaleDialog scaleDialog(sceneSize.toSize(), this);
	connect(&scaleDialog, &ScaleDialog::finished, this, &ScaleWidget::scale);
	scaleDialog.exec();

	emit closing();
}

void ScaleWidget::scale(const QSize &newSize)
{
	mAnnotationArea->scale(newSize);
}

} // namespace kImageAnnotator
