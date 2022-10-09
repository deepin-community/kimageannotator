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

#include "ScaleCommand.h"

namespace kImageAnnotator {

kImageAnnotator::ScaleCommand::ScaleCommand(QGraphicsPixmapItem *backgroundImage, const QSize &newSize, kImageAnnotator::AnnotationArea *annotationArea)
{
	mAnnotationArea = annotationArea;
	mBackgroundImage = backgroundImage;
	auto currentSize = backgroundImage->boundingRect().size();
	mWidthScaleFactor = (qreal) newSize.width() / currentSize.width();
	mHeightScaleFactor = (qreal) newSize.height() / currentSize.height();
	mOldImage = new QPixmap(backgroundImage->pixmap());
	mNewImage = new QPixmap(mOldImage->scaled(newSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

ScaleCommand::~ScaleCommand()
{
	delete mOldImage;
	delete mNewImage;
}

void ScaleCommand::undo()
{
	scaleItems(1 / mWidthScaleFactor, 1 / mHeightScaleFactor);
	mBackgroundImage->resetTransform();
	mBackgroundImage->setPixmap(*mOldImage);
	mAnnotationArea->setSceneRect(mBackgroundImage->boundingRect());
}

void ScaleCommand::redo()
{
	scaleItems(mWidthScaleFactor, mHeightScaleFactor);
	mBackgroundImage->resetTransform();
	mBackgroundImage->setPixmap(*mNewImage);
	mAnnotationArea->setSceneRect(mBackgroundImage->boundingRect());
}

void ScaleCommand::scaleItems(qreal widthScaleFactor, qreal heightScaleFactor)
{
	for (auto base : mAnnotationArea->items()) {
		auto item = dynamic_cast<AbstractAnnotationItem *>(base);
		if (item != nullptr) {
			item->scale(widthScaleFactor, heightScaleFactor);
		}
	}
}

} // namespace kImageAnnotator
