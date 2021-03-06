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

//! \file djvImagePlay2TestLoad.h

#ifndef DJV_IMAGE_PLAY2_TEST_LOAD_H
#define DJV_IMAGE_PLAY2_TEST_LOAD_H

#include <djvFileInfo.h>
#include <djvImage.h>
#include <djvImageIo.h>

#include <QObject>
#include <QOffscreenSurface>
#include <QOpenGLContext>

class djvImagePlay2TestContext;

class QOpenGLTexture;

//------------------------------------------------------------------------------
// djvImagePlay2TestLoad
//------------------------------------------------------------------------------

class djvImagePlay2TestLoad : public QObject
{
    Q_OBJECT

public:

    explicit djvImagePlay2TestLoad(djvImagePlay2TestContext *);
    
    virtual ~djvImagePlay2TestLoad();
    
    bool hasEveryFrame() const;
    
    void setShareContext(QOpenGLContext *);
    
    QOpenGLTexture * frontTexture() const;
    
    QOpenGLTexture * backTexture() const;
    
public Q_SLOTS:

    void start();
    
    void open(const djvFileInfo &);
    
    void read(qint64);
    
    void setEveryFrame(bool);

Q_SIGNALS:

    void fileChanged(const djvImageIoInfo &);

    void imageRead();
    
    void everyFrameChanged(bool);

protected:

    virtual void timerEvent(QTimerEvent *);

private:
    
    void readInternal(qint64);

    djvFileInfo                       _fileInfo;
    QScopedPointer<djvImageLoad>      _imageLoad;
    djvImageIoInfo                    _imageIoInfo;
    djvImage                          _image;
    qint64                            _frame;
    bool                              _everyFrame;
    int                               _accum;
    QScopedPointer<QOffscreenSurface> _surface;
    QOpenGLContext *                  _shareContext;
    QScopedPointer<QOpenGLContext>    _glContext;
    QOpenGLTexture *                  _textures [2];
    QOpenGLTexture *                  _frontTexture;
    QOpenGLTexture *                  _backTexture;
    djvImagePlay2TestContext *        _context;
};

#endif // DJV_IMAGE_PLAY2_TEST_LOAD_H
