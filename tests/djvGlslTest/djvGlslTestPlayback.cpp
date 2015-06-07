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

//! \file djvGlslTestPlayback.cpp

#include <djvGlslTestPlayback.h>

#include <djvMath.h>

//------------------------------------------------------------------------------
// djvGlslTestPlayback
//------------------------------------------------------------------------------

djvGlslTestPlayback::djvGlslTestPlayback(QObject * parent) :
    QObject(parent),
    _start   (0),
    _end     (0),
    _frame   (0),
    _playback(STOP),
    _timerId (0)
{
    playbackUpdate();
}

djvGlslTestPlayback::~djvGlslTestPlayback()
{
    if (_timerId)
    {
        killTimer(_timerId);
        
        _timerId = 0;
    }
}

qint64 djvGlslTestPlayback::start() const
{
    return _start;
}

qint64 djvGlslTestPlayback::end() const
{
    return _end;
}

qint64 djvGlslTestPlayback::frame() const
{
    return _frame;
}

const djvSpeed & djvGlslTestPlayback::speed() const
{
    return _speed;
}

djvGlslTestPlayback::PLAYBACK djvGlslTestPlayback::playback() const
{
    return _playback;
}

void djvGlslTestPlayback::setPlayback(PLAYBACK playback)
{
    if (playback == _playback)
        return;
        
    _playback = playback;
    
    playbackUpdate();
    
    Q_EMIT playbackChanged(_playback);
}

void djvGlslTestPlayback::setRange(qint64 start, qint64 end)
{
    if (start == _start && end == _end)
        return;
    
    _start = start;
    _end   = end;
    
    Q_EMIT rangeChanged(_start, _end);
}
    
void djvGlslTestPlayback::setFrame(qint64 frame)
{
    qint64 f = djvMath::wrap<qint64>(frame, _start, _end);
    
    if (f == _frame)
        return;
    
    _frame = f;
    
    Q_EMIT frameChanged(_frame);
}

void djvGlslTestPlayback::setSpeed(const djvSpeed & speed)
{
    if (speed == _speed)
        return;
    
    _speed = speed;
    
    playbackUpdate();

    Q_EMIT speedChanged(_speed);
}

void djvGlslTestPlayback::timerEvent(QTimerEvent *)
{
    //DJV_DEBUG("djvGlslTestPlayback::timerEvent");
    //DJV_DEBUG_PRINT("frame = " << _frame);
    
    int inc = 0;
    
    switch (_playback)
    {
        case FORWARD: inc =  1; break;
        case REVERSE: inc = -1; break;
        
        default: break;
    }
    
    setFrame(_frame + inc);
}

void djvGlslTestPlayback::playbackUpdate()
{
    if (_timerId)
    {
        killTimer(_timerId);
        
        _timerId = 0;
    }
    
    switch (_playback)
    {
        case FORWARD:
        case REVERSE:
        
            _timerId = startTimer(1000 * 1 / djvSpeed::speedToFloat(_speed));
            
            break;
        
        default: break;
    }
}
