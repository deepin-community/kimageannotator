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

#ifndef KIMAGEANNOTATOR_ABSTRACTRECTRESIZEHANDLES_H
#define KIMAGEANNOTATOR_ABSTRACTRECTRESIZEHANDLES_H

#include "AbstractItemResizeHandles.h"
#include "src/annotations/items/AbstractAnnotationRect.h"
#include "src/common/helper/ShapeHelper.h"

namespace kImageAnnotator {

class AbstractRectResizeHandles : public AbstractItemResizeHandles
{
public:
    AbstractRectResizeHandles() = default;
    ~AbstractRectResizeHandles() override = default;
    void update() override;

protected:
    void initCursors() override;
    virtual QRectF getRect() const = 0;
    virtual double getOffset() const = 0;
    virtual QRectF getItemBoundingRect() const = 0;

private:
    void updateRectCursors();
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_ABSTRACTRECTRESIZEHANDLES_H
