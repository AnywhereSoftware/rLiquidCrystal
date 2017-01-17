#include "B4RDefines.h"
namespace B4R {
	void B4RLiquidCrystal::Initialize(Byte RS, Byte RW, Byte Enable, ArrayByte* DataPins) {
		if (DataPins->length == 4) {
			lc =  new (backend) LiquidCrystal(RS, RW, Enable, ByteFromArray(DataPins, 0),
				ByteFromArray(DataPins, 1), ByteFromArray(DataPins, 2), ByteFromArray(DataPins, 3));
		} else {
			lc =  new (backend) LiquidCrystal(RS, RW, Enable, ByteFromArray(DataPins, 0),
				ByteFromArray(DataPins, 1), ByteFromArray(DataPins, 2), ByteFromArray(DataPins, 3),
				ByteFromArray(DataPins, 4), ByteFromArray(DataPins, 5), ByteFromArray(DataPins, 6),
				ByteFromArray(DataPins, 7));
		}
	}
	void B4RLiquidCrystal::Begin(Byte NumberOfColumns, Byte NumberOfRows) {
		lc->begin(NumberOfColumns, NumberOfRows);
	}
	void B4RLiquidCrystal::Write(Object* Message) {
		B4RStream::Print(lc, Message);
	}
	void B4RLiquidCrystal::Clear() {
		lc->clear();
	}
	void B4RLiquidCrystal::setBlink(bool blink) {
		if (blink)
			lc->blink();
		else
			lc->noBlink();
	}
	void B4RLiquidCrystal::setCursorOn(bool blink) {
		if (blink)
			lc->cursor();
		else
			lc->noCursor();
	}
	void B4RLiquidCrystal::SetCursor(Byte Column, Byte Row) {
		lc->setCursor(Column, Row);
	}
	void B4RLiquidCrystal::setDisplayOn(bool b) {
		if (b)
			lc->display();
		else
			lc->noDisplay();
	}
}