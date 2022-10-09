/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
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

#ifndef KIMAGEANNOTATOR_KIMAGEANNOTATOR_EXPORT_H
#define KIMAGEANNOTATOR_KIMAGEANNOTATOR_EXPORT_H

#include <QtCore/qglobal.h>

#if defined(_WIN32)
	#   define KIMAGEANNOTATOR_EXPORT
#else 
	#if defined(KIMAGEANNOTATOR_LIB)
	#   define KIMAGEANNOTATOR_EXPORT Q_DECL_EXPORT
	#else
	#   define KIMAGEANNOTATOR_EXPORT Q_DECL_IMPORT
	#endif
#endif

#endif // KIMAGEANNOTATOR_KIMAGEANNOTATOR_EXPORT_H