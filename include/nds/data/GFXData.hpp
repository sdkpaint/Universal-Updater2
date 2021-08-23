/*
*   This file is part of Universal-Updater
*   Copyright (C) 2019-2021 Universal-Team
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#ifndef _UNIVERSAL_UPDATER_GFX_DATA_HPP
#define _UNIVERSAL_UPDATER_GFX_DATA_HPP

#include "gui.hpp"
#include "image.hpp"
#include "sprites.hpp"

#include <string>
#include <vector>

/* For now hardcoded; TODO: Themes. */
#define BAR_COLOR		0x10
#define BAR_OUTLINE 	0x11
#define BG_COLOR		0x12
#define TEXT_COLOR		0x13
#define TABS_SELECTED	0x14
#define TABS_UNSELECTED	0x15
#define TAB_ICON_COLOR	0x16


class GFXData {
public:
	GFXData();
	~GFXData();

	void DrawTop();
	void DrawBottom();
	void DrawSprite(const int Idx, const int X, const int Y);
	void DrawSpriteBlend(const int Idx, const int X, const int Y, int Color = TAB_ICON_COLOR);
private:
	std::vector<Image> Sprites;

	bool top = false;
};

#endif