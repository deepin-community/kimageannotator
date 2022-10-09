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

#include "ResizeCommand.h"

namespace kImageAnnotator {

ResizeCommand::ResizeCommand(AbstractAnnotationItem *item, int handleIndex, QPointF newPos, bool keepAspectRatio)
{
    mItem = item;
    mHandleIndex = handleIndex;
    mNewPos = newPos;
    mOriginalPos = item->pointAt(handleIndex);
    mKeepAspectRatio = keepAspectRatio;
}

void ResizeCommand::undo()
{
	mItem->setPointAt(mOriginalPos, mHandleIndex, false);
}

void ResizeCommand::redo()
{
    mItem->setPointAt(mNewPos, mHandleIndex, mKeepAspectRatio);
}

bool ResizeCommand::mergeWith(const QUndoCommand *command)
{
    const auto resizeCommand = dynamic_cast<const ResizeCommand *>(command);

    if (mItem != resizeCommand->mItem || mHandleIndex != resizeCommand->mHandleIndex) {
        return false;
    }

    mNewPos = resizeCommand->mNewPos;

    return true;
}

int ResizeCommand::id() const
{
    return Id;
}

} // namespace kImageAnnotator
