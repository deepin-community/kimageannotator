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

#ifndef KIMAGEANNOTATOR_ABSTRACTANNOTATIONDOCKWIDGETCONTENT_H
#define KIMAGEANNOTATOR_ABSTRACTANNOTATIONDOCKWIDGETCONTENT_H

#include <QWidget>
#include <QBoxLayout>
#include <QList>

#include "src/widgets/misc/AbstractExpandingWidget.h"

namespace kImageAnnotator {

class AbstractAnnotationDockWidgetContent : public QWidget
{
public:
	AbstractAnnotationDockWidgetContent() = default;
	~AbstractAnnotationDockWidgetContent() override = default;
	virtual void setOrientation(Qt::Orientation orientation);
	virtual QString name() const = 0;

protected:
	void addExpandingWidget(AbstractExpandingWidget *widget);

private:
	QList<AbstractExpandingWidget*> mExpandingWidget;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ABSTRACTANNOTATIONDOCKWIDGETCONTENT_H
