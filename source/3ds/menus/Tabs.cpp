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

#include "Common.hpp"
#include "Tabs.hpp"


void Tabs::Draw() {
	for (uint8_t Idx = 0; Idx < 6; Idx++) {
		if (Idx == (uint8_t)this->ActiveTab) Gui::Draw_Rect(this->TabPos[Idx].x, this->TabPos[Idx].y, this->TabPos[Idx].w, this->TabPos[Idx].h, TABS_SELECTED);
		else Gui::Draw_Rect(this->TabPos[Idx].x, this->TabPos[Idx].y, this->TabPos[Idx].w, this->TabPos[Idx].h, TABS_UNSELECTED);
	}

	UU::App->GData->DrawSpriteBlend(sprites_info_idx, this->TabPos[0].x, this->TabPos[0].y);
	UU::App->GData->DrawSpriteBlend(sprites_download_idx, this->TabPos[1].x, this->TabPos[1].y);
	UU::App->GData->DrawSpriteBlend(sprites_queue0_idx, this->TabPos[2].x, this->TabPos[2].y);
	UU::App->GData->DrawSpriteBlend(sprites_search_idx, this->TabPos[3].x, this->TabPos[3].y);
	UU::App->GData->DrawSpriteBlend(sprites_sort_idx, this->TabPos[4].x, this->TabPos[4].y);
	UU::App->GData->DrawSpriteBlend(sprites_settings_idx, this->TabPos[5].x, this->TabPos[5].y);

	Gui::Draw_Rect(40, 0, 1, 240, BAR_OUTLINE);
};


void Tabs::Handler() {
	/* TODO: Handle active tab. */

	
	/* Tab Handler. */
	if (UU::App->Down & KEY_TOUCH) {
		for (uint8_t Idx = 0; Idx < 6; Idx++) {
			if (UU::App->Touched(this->TabPos[Idx])) {
				this->ActiveTab = (Tabs::Tab)Idx;
				break;
			}
		}
	}

	if (UU::App->Repeat & KEY_R) {
		if (this->ActiveTab != Tab::Settings) {
			this->LastTab = this->ActiveTab;

			uint8_t T = (uint8_t)this->ActiveTab + 1;
			this->ActiveTab = (Tab)T;
		}
	}

	if (UU::App->Repeat & KEY_L) {
		if (this->ActiveTab != Tab::EntryInfo) {
			this->LastTab = this->ActiveTab;

			uint8_t T = (uint8_t)this->ActiveTab - 1;
			this->ActiveTab = (Tab)T;
		}
	}
};