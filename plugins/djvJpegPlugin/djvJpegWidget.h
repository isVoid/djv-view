//------------------------------------------------------------------------------
// Copyright (c) 2004-2015 Darby Johnston
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions, and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions, and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the names of the copyright holders nor the names of any
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//------------------------------------------------------------------------------

//! \file djvJpegWidget.h

#ifndef DJV_JPEG_WIDGET_H
#define DJV_JPEG_WIDGET_H

#include <djvJpeg.h>

#include <djvImageIoWidget.h>

class djvIntEditSlider;

//! \addtogroup djvJpegPlugin
//@{

//------------------------------------------------------------------------------
//! \class djvJpegWidget
//!
//! This class provides a JPEG widget.
//------------------------------------------------------------------------------

class djvJpegWidget : public djvImageIoWidget
{
    Q_OBJECT
    
public:

    //! Constructor.

    djvJpegWidget(djvImageIo *, djvGuiContext *);
    
    //! Destructor.
    
    virtual ~djvJpegWidget();

    virtual void resetPreferences();

private Q_SLOTS:

    void pluginCallback(const QString &);
    void qualityCallback(int);

    void pluginUpdate();
    void widgetUpdate();

private:

    djvJpeg::Options   _options;
    djvIntEditSlider * _qualityWidget;
};

//------------------------------------------------------------------------------
//! \class djvJpegWidgetPlugin
//!
//! This class provides a JPEG widget plugin.
//------------------------------------------------------------------------------

class djvJpegWidgetPlugin : public djvImageIoWidgetPlugin
{
public:
    
    djvJpegWidgetPlugin(djvCoreContext *);
    
    virtual djvImageIoWidget * createWidget(djvImageIo *) const;

    virtual QString pluginName() const;
};

//@} // djvJpegPlugin

#endif // DJV_JPEG_WIDGET_H

