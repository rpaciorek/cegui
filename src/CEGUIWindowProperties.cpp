/************************************************************************
	filename: 	CEGUIWindowProperties.cpp
	created:	5/7/2004
	author:		Paul D Turner
	
	purpose:	Implementation of available window base class properties
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://crayzedsgui.sourceforge.net)
    Copyright (C)2004 Paul D Turner (crayzed@users.sourceforge.net)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "CEGUIWindowProperties.h"
#include "CEGUIWindow.h"
#include "CEGUIFont.h"
#include "CEGUIPropertyHelper.h"
#include "CEGUIExceptions.h"
#include <cstdlib>
#include <cstdio>

// Start of CEGUI namespace section
namespace CEGUI
{
// Start of WindowProperties namespace section
namespace WindowProperties
{

String RelativeMinSize::get(const void* receiver) const
{
	CEGUI::Size msz(static_cast<const Window*>(receiver)->getMinimumSize());

	if (static_cast<const Window*>(receiver)->getMetricsMode() == Absolute)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 /= dsz.d_width;
		msz.d_height /= dsz.d_height;
	}

	return PropertyHelper::sizeToString(msz);
}


void RelativeMinSize::set(void* receiver, const String& value)
{
	CEGUI::Size msz(PropertyHelper::stringToSize(value));

	if (static_cast<Window*>(receiver)->getMetricsMode() == Absolute)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 *= dsz.d_width;
		msz.d_height *= dsz.d_height;
	}

	static_cast<Window*>(receiver)->setMinimumSize(msz);
}


String RelativeMaxSize::get(const void* receiver) const
{
	CEGUI::Size msz(static_cast<const Window*>(receiver)->getMaximumSize());

	if (static_cast<const Window*>(receiver)->getMetricsMode() == Absolute)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 /= dsz.d_width;
		msz.d_height /= dsz.d_height;
	}

	return PropertyHelper::sizeToString(msz);
}


void RelativeMaxSize::set(void* receiver, const String& value)
{
	CEGUI::Size msz(PropertyHelper::stringToSize(value));

	if (static_cast<Window*>(receiver)->getMetricsMode() == Absolute)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 *= dsz.d_width;
		msz.d_height *= dsz.d_height;
	}

	static_cast<Window*>(receiver)->setMaximumSize(msz);
}


String AbsoluteMinSize::get(const void* receiver) const
{
	CEGUI::Size msz(static_cast<const Window*>(receiver)->getMinimumSize());

	if (static_cast<const Window*>(receiver)->getMetricsMode() == Relative)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 *= dsz.d_width;
		msz.d_height *= dsz.d_height;
	}

	return PropertyHelper::sizeToString(msz);
}


void AbsoluteMinSize::set(void* receiver, const String& value)
{
	CEGUI::Size msz(PropertyHelper::stringToSize(value));

	if (static_cast<Window*>(receiver)->getMetricsMode() == Relative)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 /= dsz.d_width;
		msz.d_height /= dsz.d_height;
	}

	static_cast<Window*>(receiver)->setMinimumSize(msz);
}


String AbsoluteMaxSize::get(const void* receiver) const
{
	CEGUI::Size msz(static_cast<const Window*>(receiver)->getMaximumSize());

	if (static_cast<const Window*>(receiver)->getMetricsMode() == Relative)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 *= dsz.d_width;
		msz.d_height *= dsz.d_height;
	}

	return PropertyHelper::sizeToString(msz);
}


void AbsoluteMaxSize::set(void* receiver, const String& value)
{
	CEGUI::Size msz(PropertyHelper::stringToSize(value));

	if (static_cast<Window*>(receiver)->getMetricsMode() == Relative)
	{
		CEGUI::Size dsz(System::getSingleton().getRenderer()->getSize());

		msz.d_width	 /= dsz.d_width;
		msz.d_height /= dsz.d_height;
	}

	static_cast<Window*>(receiver)->setMaximumSize(msz);
}


String MetricsMode::get(const void* receiver) const
{
	return PropertyHelper::metricsModeToString(static_cast<const Window*>(receiver)->getMetricsMode());
}


void MetricsMode::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setMetricsMode(PropertyHelper::stringToMetricsMode(value));
}


String ID::get(const void* receiver) const
{
	return PropertyHelper::uintToString(static_cast<const Window*>(receiver)->getID());
}


void ID::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setID(PropertyHelper::stringToUint(value));
}


String Alpha::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getAlpha());
}


void Alpha::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setAlpha(PropertyHelper::stringToFloat(value));
}


String Font::get(const void* receiver) const
{
	const CEGUI::Font* fnt = static_cast<const Window*>(receiver)->getFont();

	if (fnt != NULL)
	{
		return fnt->getName();
	}
	else
	{
		return String();
	}

}


void Font::set(void* receiver, const String& value)
{
	try
	{
		static_cast<Window*>(receiver)->setFont(value);
	}
	catch (UnknownObjectException)
	{ }
}


String Text::get(const void* receiver) const
{
	return static_cast<const Window*>(receiver)->getText();
}


void Text::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setText(value);
}


String MouseCursorImage::get(const void* receiver) const
{
	const Image* img = static_cast<const Window*>(receiver)->getMouseCursor();

	if (img != NULL)
	{
		return PropertyHelper::imageToString(img);
	}
	else
	{
		return String();
	}

}


void MouseCursorImage::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setMouseCursor(PropertyHelper::stringToImage(value));
}


String ClippedByParent::get(const void* receiver) const
{
	return PropertyHelper::boolToString(static_cast<const Window*>(receiver)->isClippedByParent());
}


void ClippedByParent::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setClippedByParent(PropertyHelper::stringToBool(value));
}


String InheritsAlpha::get(const void* receiver) const
{
	return PropertyHelper::boolToString(static_cast<const Window*>(receiver)->inheritsAlpha());
}


void InheritsAlpha::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setInheritsAlpha(PropertyHelper::stringToBool(value));
}


String AlwaysOnTop::get(const void* receiver) const
{
	return PropertyHelper::boolToString(static_cast<const Window*>(receiver)->isAlwaysOnTop());
}


void AlwaysOnTop::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setAlwaysOnTop(PropertyHelper::stringToBool(value));
}


String Disabled::get(const void* receiver) const
{
	return PropertyHelper::boolToString(static_cast<const Window*>(receiver)->isDisabled());
}


void Disabled::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setEnabled(!PropertyHelper::stringToBool(value));
}


String Visible::get(const void* receiver) const
{
	return PropertyHelper::boolToString(static_cast<const Window*>(receiver)->isVisible());
}


void Visible::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setVisible(PropertyHelper::stringToBool(value));
}


String RestoreOldCapture::get(const void* receiver) const
{
	return	PropertyHelper::boolToString(static_cast<const Window*>(receiver)->restoresOldCapture());
}


void RestoreOldCapture::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setRestoreCapture(PropertyHelper::stringToBool(value));
}


String DestroyedByParent::get(const void* receiver) const
{
	return PropertyHelper::boolToString(static_cast<const Window*>(receiver)->isDestroyedByParent());
}


void DestroyedByParent::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setDestroyedByParent(PropertyHelper::stringToBool(value));
}


String Width::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getWidth());
}


void Width::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setWidth(PropertyHelper::stringToFloat(value));
}


String RelativeWidth::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getRelativeWidth());
}


void RelativeWidth::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setWidth(Relative, PropertyHelper::stringToFloat(value));
}


String AbsoluteWidth::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getAbsoluteWidth());
}


void AbsoluteWidth::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setWidth(Absolute, PropertyHelper::stringToFloat(value));
}


String Height::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getHeight());
}


void Height::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setHeight(PropertyHelper::stringToFloat(value));
}


String RelativeHeight::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getRelativeHeight());
}


void RelativeHeight::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setHeight(Relative, PropertyHelper::stringToFloat(value));
}


String AbsoluteHeight::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getAbsoluteHeight());
}


void AbsoluteHeight::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setHeight(Absolute, PropertyHelper::stringToFloat(value));
}


String Size::get(const void* receiver) const
{
	return PropertyHelper::sizeToString(static_cast<const Window*>(receiver)->getSize());
}


void Size::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setSize(PropertyHelper::stringToSize(value));
}


String RelativeSize::get(const void* receiver) const
{
	return PropertyHelper::sizeToString(static_cast<const Window*>(receiver)->getRelativeSize());
}


void RelativeSize::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setSize(Relative, PropertyHelper::stringToSize(value));
}


String AbsoluteSize::get(const void* receiver) const
{
	return PropertyHelper::sizeToString(static_cast<const Window*>(receiver)->getAbsoluteSize());
}


void AbsoluteSize::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setSize(Absolute, PropertyHelper::stringToSize(value));
}


String XPosition::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getXPosition());
}


void XPosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setXPosition(PropertyHelper::stringToFloat(value));
}


String RelativeXPosition::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getRelativeXPosition());
}


void RelativeXPosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setXPosition(Relative, PropertyHelper::stringToFloat(value));
}


String AbsoluteXPosition::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getAbsoluteXPosition());
}


void AbsoluteXPosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setXPosition(Absolute, PropertyHelper::stringToFloat(value));
}


String YPosition::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getYPosition());
}


void YPosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setYPosition(PropertyHelper::stringToFloat(value));
}


String RelativeYPosition::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getRelativeYPosition());
}


void RelativeYPosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setYPosition(Relative, PropertyHelper::stringToFloat(value));
}


String AbsoluteYPosition::get(const void* receiver) const
{
	return PropertyHelper::floatToString(static_cast<const Window*>(receiver)->getAbsoluteYPosition());
}


void AbsoluteYPosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setYPosition(Absolute, PropertyHelper::stringToFloat(value));
}


String Position::get(const void* receiver) const
{
	return PropertyHelper::pointToString(static_cast<const Window*>(receiver)->getPosition());
}


void Position::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setPosition(PropertyHelper::stringToPoint(value));
}


String RelativePosition::get(const void* receiver) const
{
	return PropertyHelper::pointToString(static_cast<const Window*>(receiver)->getRelativePosition());
}


void RelativePosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setPosition(Relative, PropertyHelper::stringToPoint(value));
}


String AbsolutePosition::get(const void* receiver) const
{
	return PropertyHelper::pointToString(static_cast<const Window*>(receiver)->getAbsolutePosition());
}


void AbsolutePosition::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setPosition(Absolute, PropertyHelper::stringToPoint(value));
}


String Rect::get(const void* receiver) const
{
	return PropertyHelper::rectToString(static_cast<const Window*>(receiver)->getRect());
}


void Rect::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setAreaRect(PropertyHelper::stringToRect(value));
}


String RelativeRect::get(const void* receiver) const
{
	return PropertyHelper::rectToString(static_cast<const Window*>(receiver)->getRelativeRect());
}


void RelativeRect::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setRect(Relative, PropertyHelper::stringToRect(value));
}


String AbsoluteRect::get(const void* receiver) const
{
	return PropertyHelper::rectToString(static_cast<const Window*>(receiver)->getAbsoluteRect());
}


void AbsoluteRect::set(void* receiver, const String& value)
{
	static_cast<Window*>(receiver)->setRect(Absolute, PropertyHelper::stringToRect(value));
}

} // End of  WindowProperties namespace section

} // End of  CEGUI namespace section
