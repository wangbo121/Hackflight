/*
   realboard.hpp : Board subclass for real (hardware) boards

   This file is part of Hackflight.

   Hackflight is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "board.hpp"
#include "datatypes.hpp"

namespace hf {

    class RealBoard : public Board {

        private:

            const uint32_t ledFlashMilli = 1000;
            const uint32_t ledFlashCount = 20;

        protected:

            virtual void     delayMilliseconds(uint32_t msec) { (void)msec; } 
            virtual void     ledSet(bool is_on) { (void)is_on; }

            void init(void)
            {
                // Flash LED
                uint32_t pauseMilli = ledFlashMilli / ledFlashCount;
                ledSet(false);
                for (uint8_t i = 0; i < ledFlashCount; i++) {
                    ledSet(true);
                    delayMilliseconds(pauseMilli);
                    ledSet(false);
                    delayMilliseconds(pauseMilli);
                }
                ledSet(false);
            }

            void showArmedStatus(bool armed)
            {
                // Set LED to indicate armed
                ledSet(armed);
            }

    }; // class RealBoard

} // namespace hf
