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

#include "MoveCommand.h"

namespace kImageAnnotator {

MoveCommand::MoveCommand(QHash<AbstractAnnotationItem *, QPointF> itemToNewPos)
{
    mNewPos = itemToNewPos;

    for (auto item : itemToNewPos.keys()) {
        mOriginalPos[item] = item->position();
    }
}

void MoveCommand::undo()
{
    moveItems(mOriginalPos);
}

void MoveCommand::redo()
{
    moveItems(mNewPos);
}

bool MoveCommand::mergeWith(const QUndoCommand *command)
{
    const auto moveCommand = dynamic_cast<const MoveCommand *>(command);
    auto mergedNewPos = moveCommand->mNewPos;

    if (mNewPos.keys() != mergedNewPos.keys()) {
        return false;
    }

    mNewPos = mergedNewPos;

    return true;
}

int MoveCommand::id() const
{
    return Id;
}

void MoveCommand::moveItems(QHash<AbstractAnnotationItem *, QPointF> &itemToPos) const
{
    for (auto item : itemToPos.keys()) {
        item->setPosition(itemToPos[item]);
    }
}

} // namespace kImageAnnotator
