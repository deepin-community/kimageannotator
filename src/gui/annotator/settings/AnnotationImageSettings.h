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

#ifndef KIMAGEANNOTATOR_ANNOTATIONIMAGESETTINGS_H
#define KIMAGEANNOTATOR_ANNOTATIONIMAGESETTINGS_H

#include "src/gui/annotator/docks/AbstractAnnotationDockWidgetContent.h"
#include "src/widgets/settingsPicker/ImageEffectPicker.h"

namespace kImageAnnotator {

class AnnotationImageSettings : public AbstractAnnotationDockWidgetContent
{
Q_OBJECT
public:
	explicit AnnotationImageSettings();
	~AnnotationImageSettings() override;
	ImageEffects effect() const;
	void setEffect(ImageEffects effect);
	QString name() const override;

signals:
	void effectChanged(ImageEffects effect);

private:
	QBoxLayout *mMainLayout;
	ImageEffectPicker *mEffectPicker;

	void initGui();
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ANNOTATIONIMAGESETTINGS_H
