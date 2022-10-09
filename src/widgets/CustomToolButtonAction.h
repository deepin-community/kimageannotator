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

#ifndef KIMAGEANNOTATOR_CUSTOMTOOLBUTTONMENU_H
#define KIMAGEANNOTATOR_CUSTOMTOOLBUTTONMENU_H

#include <QWidgetAction>
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>

#include "src/common/provider/ScaledSizeProvider.h"

namespace kImageAnnotator {

class CustomToolButtonAction : public QWidgetAction
{
public:
	explicit CustomToolButtonAction(QObject *parent);
	~CustomToolButtonAction() override;
	void updateDefaultWidget();

private:
	QLabel *mImage;
	QLabel *mText;
	QHBoxLayout *mLayout;
	QWidget *mMenuItem;

	void initDefaultWidget();
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_CUSTOMTOOLBUTTONMENU_H
