/************************************************************************
	filename: 	TLButton.h
	created:	11/5/2004
	author:		Paul D Turner
	
	purpose:	Interface to Taharez look button widget
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
#ifndef _TLButton_h_
#define _TLButton_h_

#include "TLModule.h"
#include "elements/CEGUIPushButton.h"
#include "CEGUIWindowFactory.h"
#include "CEGUIRenderableImage.h"

#include "TLButtonProperties.h"


#if defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable : 4251)
#endif


// Start of CEGUI namespace section
namespace CEGUI
{
/*!
\brief
	Button class for the TaharezLook GUI scheme
*/
class TAHAREZLOOK_API TLButton : public PushButton
{
public:
	/*************************************************************************
		Constants
	*************************************************************************/
	// type name for this widget
	static const utf8	WidgetTypeName[];				//!< The unique typename of this widget

	static const utf8	ImagesetName[];					//!< Name of the imageset to use for rendering.
	static const utf8	LeftNormalImageName[];			//!< Name of the image to use for the left end of the button (normal).
	static const utf8	MiddleNormalImageName[];		//!< Name of the image to use for the middle of the button (normal).
	static const utf8	RightNormalImageName[];			//!< Name of the image to use for the right end of the button (normal).
	static const utf8	LeftHighlightImageName[];		//!< Name of the image to use for the left end of the button (hover / highlighted).
	static const utf8	MiddleHighlightImageName[];		//!< Name of the image to use for the middle of the button (hover / highlighted).
	static const utf8	RightHighlightImageName[];		//!< Name of the image to use for the right end of the button (hover / highlighted).
	static const utf8	LeftPushedImageName[];			//!< Name of the image to use for the left end of the button (pushed state).
	static const utf8	MiddlePushedImageName[];		//!< Name of the image to use for the middle of the button (pushed state).
	static const utf8	RightPushedImageName[];			//!< Name of the image to use for the right end of the button (pushed state).
	static const utf8	MouseCursorImageName[];			//!< Name of the image to use for the mouse cursor.

	/*************************************************************************
		Construction and Destruction
	*************************************************************************/
	/*!
	\brief
		Constructor for Taharez Look Button objects.

	\param type
		String object that specifies a type for this window, usually provided by a factory class.

	\param name
		String object that specifies a unique name that will be used to identify the new Window object
	*/
	TLButton(const String& type, const String& name);


	/*!
	\brief
		Destructor for TLButton objects.
	*/
	virtual ~TLButton(void);

	
	/*************************************************************************
		Accessors
	*************************************************************************/
	/*!
	\brief
		return whether or not rendering of the standard imagery is enabled.

	\return
		true if the standard button imagery will be rendered, false if no standard rendering will be performed.
	*/
	bool	isStandardImageryEnabled(void) const	{return d_useStandardImagery;}


	/*!
	\brief
		Return whether of not custom button image areas are auto-scaled to the size of the button.

	\return
		true if client specified custom image areas are re-sized when the button size changes.  false if image areas will
		remain unchanged when the button is sized.
	*/
	bool	isCustomImageryAutoSized(void) const	{return d_autoscaleImages;}


	/*************************************************************************
		Manipulators
	*************************************************************************/
	/*!
	\brief
		set whether or not to render the standard imagery for the button

	\param setting
		true to have the standard button imagery drawn, false to have no standard imagery drawn.

	\return
		Nothing.
	*/
	void	setStandardImageryEnabled(bool setting);


	/*!
	\brief
		Set whether to auto re-size custom image areas when the button is sized.

	\param setting
		true to have custom image areas auto-sized.  false to have system leave image areas untouched.

	\return
		Nothing.
	*/
	void	setCustomImageryAutoSized(bool setting);

	/*!
	\brief
		set the details of the image to render for the button in the normal state.

	\param image
		RenderableImage object with all the details for the image.  Note that an internal copy of the Renderable image is made and
		ownership of \a image remains with client code.  If this parameter is NULL, rendering of an image for this button state is
		disabled.

	\return
		Nothing.
	*/
	void	setNormalImage(const RenderableImage* image);


	/*!
	\brief
		set the details of the image to render for the button in the highlighted state.

	\param image
		RenderableImage object with all the details for the image.  Note that an internal copy of the Renderable image is made and
		ownership of \a image remains with client code.  If this parameter is NULL, rendering of an image for this button state is
		disabled.

	\return
		Nothing.
	*/
	void	setHoverImage(const RenderableImage* image);


	/*!
	\brief
		set the details of the image to render for the button in the pushed state.

	\param image
		RenderableImage object with all the details for the image.  Note that an internal copy of the Renderable image is made and
		ownership of \a image remains with client code.  If this parameter is NULL, rendering of an image for this button state is
		disabled.

	\return
		Nothing.
	*/
	void	setPushedImage(const RenderableImage* image);


	/*!
	\brief
		set the details of the image to render for the button in the disabled state.

	\param image
		RenderableImage object with all the details for the image.  Note that an internal copy of the Renderable image is made and
		ownership of \a image remains with client code.  If this parameter is NULL, rendering of an image for this button state is
		disabled.

	\return
		Nothing.
	*/
	void	setDisabledImage(const RenderableImage* image);

   /*!
   \brief
      get the offset that is used to shift of the text in the x-direction
      this is useful if the button-images are not symmetrical and the
      text shouldn't be completely centered

   \return
      the offset relative to the button-size
   */
   float   getTextXOffset() const;

   /*!
   \brief
      set the offset to use for a shift of the text in the x-direction
      this is useful if the button-images are not symmetrical and the
      text shouldn't be completely centered

   \param offset
      The offset to use. This is relative to the button-width

   \return
      Nothing.
   */
   void   setTextXOffset(float offset);


protected:
	/*************************************************************************
		Overridden Event Handling Functions
	*************************************************************************/
	virtual void	onSized(WindowEventArgs& e);


	/*************************************************************************
		Implementation Rendering Functions
	*************************************************************************/
	/*!
	\brief
		render the button in the normal state.
	*/
	virtual void	drawNormal(float z);

	/*!
	\brief
		render the button in the hover / highlighted state.
	*/
	virtual void	drawHover(float z);

	/*!
	\brief
		render the button in the pushed state.
	*/
	virtual void	drawPushed(float z);

	/*!
	\brief
		render the button in the disabled state
	*/
	virtual void	drawDisabled(float z);


	/*************************************************************************
		Implementation Data
	*************************************************************************/
	// flags stating which imagery is to be rendered and how.
	bool	d_autoscaleImages;				//!< when true custom images will be scaled to the same size as the button
	bool	d_useStandardImagery;			//!< true if button standard imagery should be drawn.
	bool	d_useNormalImage;				//!< true if an image should be drawn for the normal state.
	bool	d_useHoverImage;				//!< true if an image should be drawn for the highlighted state.
	bool	d_usePushedImage;				//!< true if an image should be drawn for the pushed state.
	bool	d_useDisabledImage;				//!< true if an image should be drawn for the disabled state.

	// custom button renderable image objects
	RenderableImage		d_normalImage;		//!< RenderableImage used when rendering an image in the normal state.
	RenderableImage		d_hoverImage;		//!< RenderableImage used when rendering an image in the highlighted state.
	RenderableImage		d_pushedImage;		//!< RenderableImage used when rendering an image in the pushed state.
	RenderableImage		d_disabledImage;	//!< RenderableImage used when rendering an image in the disabled state.

	// standard button rendering images
	const Image*	d_leftSectionNormal;			//!< Image to use when rendering the button left section (normal state).
	const Image*	d_middleSectionNormal;			//!< Image to use when rendering the button middle section (normal state).
	const Image*	d_rightSectionNormal;			//!< Image to use when rendering the button right section (normal state).
	const Image*	d_leftSectionHover;				//!< Image to use when rendering the button left section (hover state).
	const Image*	d_middleSectionHover;			//!< Image to use when rendering the button middle section (hover state).
	const Image*	d_rightSectionHover;			//!< Image to use when rendering the button right section (hover state).
	const Image*	d_leftSectionPushed;			//!< Image to use when rendering the button left section (pushed state).
	const Image*	d_middleSectionPushed;			//!< Image to use when rendering the button middle section (pushed state).
	const Image*	d_rightSectionPushed;			//!< Image to use when rendering the button right section (pushed state).

   //text-offset
   float d_textXOffset;		//!< offset applied to the x co-ordinate of the text label.

private:
   static TLButtonProperties::NormalImage d_normalImageProperty;
   static TLButtonProperties::PushedImage d_pushedImageProperty;
   static TLButtonProperties::HoverImage  d_hoverImageProperty;
   static TLButtonProperties::UseStandardImagery d_useStandardImageryProperty;
   static TLButtonProperties::TextXOffset d_textXOffsetProperty;

   void addTLButtonProperties(void);
};


/*!
\brief
	Factory class for producing TLButton objects
*/
class TAHAREZLOOK_API TLButtonFactory : public WindowFactory
{
public:
	/*************************************************************************
		Construction and Destruction
	*************************************************************************/
	TLButtonFactory(void) : WindowFactory(TLButton::WidgetTypeName) { }
	~TLButtonFactory(void){}


	/*!
	\brief
		Create a new Window object of whatever type this WindowFactory produces.

	\param name
		A unique name that is to be assigned to the newly created Window object

	\return
		Pointer to the new Window object.
	*/
	Window*	createWindow(const String& name);


	/*!
	\brief
		Destroys the given Window object.

	\param window
		Pointer to the Window object to be destroyed.

	\return
		Nothing.
	*/
	virtual void	destroyWindow(Window* window)	 { if (window->getType() == d_type) delete window; }
};


} // End of  CEGUI namespace section


#if defined(_MSC_VER)
#	pragma warning(pop)
#endif

#endif	// end of guard _TLButton_h_