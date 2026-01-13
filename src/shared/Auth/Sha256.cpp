/**
 * MaNGOS is a full featured server for World of Warcraft, supporting
 * the following clients: 1.12.x, 2.4.3, 3.3.5a, 4.3.4a and 5.4.8
 *
 * Copyright (C) 2005-2025 MaNGOS <https://www.getmangos.eu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * World of Warcraft, and all World of Warcraft or Warcraft art, images,
 * and lore are copyrighted by Blizzard Entertainment, Inc.
 */

#include "Auth/Sha256.h"
#include "Common.h"

Sha256Hash::Sha256Hash()
{
    Initialize();
}

Sha256Hash::~Sha256Hash()
{
}

void Sha256Hash::Initialize()
{
    SHA256_Init(&mC);
    memset(mDigest, 0, SHA256_DIGEST_LENGTH);
}

void Sha256Hash::UpdateData(const uint8* dta, int len)
{
    SHA256_Update(&mC, dta, len);
}

void Sha256Hash::UpdateData(const std::string& str)
{
    UpdateData((uint8 const*)str.c_str(), str.length());
}

void Sha256Hash::UpdateData(uint32 data)
{
    UpdateData((uint8 const*)&data, sizeof(uint32));
}

void Sha256Hash::Finalize()
{
    SHA256_Final(mDigest, &mC);
}
