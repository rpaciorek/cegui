/************************************************************************
	filename: 	CEGUIMouseCursor.cpp
	created:	21/2/2004
	author:		Paul D Turner
	
	purpose:	Implements MouseCursor class
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
#include "CEGUIMouseCursor.h"
#include "CEGUIExceptions.h"
#include "CEGUILogger.h"
#include "CEGUISystem.h"
#include "CEGUIRenderer.h"
#include "CEGUIImagesetManager.h"
#include "CEGUIImageset.h"
#include "CEGUIImage.h"

// Start of CEGUI namespace section
namespace CEGUI
{
/*************************************************************************
	Static Data Definitions
*************************************************************************/
// singleton instance pointer
template<> MouseCursor* Singleton<MouseCursor>::ms_Singleton	= NULL;


/*************************************************************************
	Event name constants
*************************************************************************/
const utf8	MouseCursor::EventImageChanged[]	= "ImageChanged";


/*************************************************************************
	constructor
*************************************************************************/
MouseCursor::MouseCursor(void)
{
	// default constraint is to whole screen
	d_constraints = System::getSingleton().getRenderer()->getRect();

	// mouse defaults to middle of the constrained area
	d_position.d_x = d_constraints.getWidth() / 2;
	d_position.d_y = d_constraints.getHeight() / 2;
	d_position.d_z = 1.0f;

	// mouse defaults to visible
	d_visible = true;

	// no default image though
	d_cursorImage = NULL;

	// add events
	addMouseCursorEvents();

	Logger::getSingleton().logEvent((utf8*)"CEGUI::MouseCursor singleton created.");
}


/*************************************************************************
	Destructor
*************************************************************************/
MouseCursor::~MouseCursor(void)
{
	Logger::getSingleton().logEvent((utf8*)"CEGUI::MouseCursor singleton destroyed.");
}


/*************************************************************************
	Set the current mouse cursor image
*************************************************************************/
void MouseCursor::setImage(const Image* image)
{
	d_cursorImage = image;
	MouseCursorEventArgs args(this);
	args.image = image;
	onImageChanged(args);
}


/*************************************************************************
	Set the current mouse cursor image
*************************************************************************/
void MouseCursor::setImage(const String& imageset, const String& image_name)
{
	setImage(&ImagesetManager::getSingleton().getImageset(imageset)->getImage(image_name));
}


/*************************************************************************
	Draw the mouse cursor
*************************************************************************/
void MouseCursor::draw(void) const
{
	if (d_visible && (d_cursorImage != NULL))
	{
		d_cursorImage->draw(d_position, System::getSingleton().getRenderer()->getRect());
	}

}


/*************************************************************************
	Set the current mouse cursor position
*************************************************************************/
void MouseCursor::setPosition(const Point& position)
{
	d_position.d_x = position.d_x;
	d_position.d_y = position.d_y;
	constrainPosition();
}


/*************************************************************************
	Offset the mouse cursor position by the deltas specified in 'offset'.
*************************************************************************/
void MouseCursor::offsetPosition(const Point& offset)
{
	d_position.d_x += offset.d_x;
	d_position.d_y += offset.d_y;
	constrainPosition();
}


/*************************************************************************
	Checks the mouse cursor position is within the current 'constrain'
	Rect and adjusts as required.
*************************************************************************/
void MouseCursor::constrainPosition(void)
{
	if (d_position.d_x >= d_constraints.d_right)
		d_position.d_x = d_constraints.d_right -1;

	if (d_position.d_y >= d_constraints.d_bottom)
		d_position.d_y = d_constraints.d_bottom -1;

	if (d_position.d_y < d_constraints.d_top)
		d_position.d_y = d_constraints.d_top;

	if (d_position.d_x < d_constraints.d_left)
		d_position.d_x = d_constraints.d_left;
}


/*************************************************************************
	Set the area that the mouse cursor is constrained to.
*************************************************************************/
void MouseCursor::setConstraintArea(const Rect* area)
{
	Rect renderer_area = System::getSingleton().getRenderer()->getRect();

	if (area == NULL)
	{
		d_constraints = renderer_area;
	}
	else
	{
		d_constraints = area->getIntersection(renderer_area);
	}

	constrainPosition();
}


/*************************************************************************
	Return the current mouse cursor position in display resolution
	independant values.	
*************************************************************************/
Point MouseCursor::getDisplayIndependantPosition(void) const
{
	Size dsz(System::getSingleton().getRenderer()->getSize());

	return Point(d_position.d_x / (dsz.d_width - 1.0f), d_position.d_y / (dsz.d_height - 1.0f));
}


/*************************************************************************
	Add MouseCursor events
*************************************************************************/
void MouseCursor::addMouseCursorEvents(void)
{
	// mouse cursor events
	addEvent(EventImageChanged);
}


//////////////////////////////////////////////////////////////////////////
/*************************************************************************

	Begin event triggers section

*************************************************************************/
//////////////////////////////////////////////////////////////////////////

void MouseCursor::onImageChanged(MouseCursorEventArgs& e)
{
	fireEvent(EventImageChanged, e);
}


MouseCursor& MouseCursor::getSingleton(void)
{
	return Singleton<MouseCursor>::getSingleton();
}


MouseCursor* MouseCursor::getSingletonPtr(void)
{
	return Singleton<MouseCursor>::getSingletonPtr();
}

} // End of  CEGUI namespace section