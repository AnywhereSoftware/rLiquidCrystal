#pragma once
#include "B4RDefines.h"
//~dependson: <LiquidCrystal.h>
namespace B4R {
	//~Version: 1.00
	//~ShortName: LiquidCrystal
	class B4RLiquidCrystal {
		private:
			uint8_t backend[sizeof(LiquidCrystal)];
		public:
			//~hide
			LiquidCrystal* lc;
			/**
			*Initializes the object. Note that you should also call Begin.
			*RS - RS Pin
			*RW - RW Pin. Pass 255 if not required.
			*Enable - Enable pin.
			*DataPins - Array of bytes with 4 or 8 bytes for the data pins.
			*Example:<code>
			*lcd.Initialize(8, 255, 9, Array As Byte(4, 5, 6, 7))</code>
			*/
			void Initialize(Byte RS, Byte RW, Byte Enable, ArrayByte* DataPins);
			//Sets the number of columns and rows.
			void Begin(Byte NumberOfColumns, Byte NumberOfRows);
			/**
			*Writes the message. The message can be a string, a number or an array of bytes.
			*/
			void Write(Object* Message);
			/**
			*Sets the cursor position.
			*/
			void SetCursor(Byte Column, Byte Row);
			//Clears the screen and sets the cursor to (0,0).
			void Clear();
			//Sets whether the cursor should blink.
			void setBlink(bool b);
			//Sets the cursor state.
			void setCursorOn(bool b);
			//Sets the display state.
			void setDisplayOn(bool b);
	};
}
