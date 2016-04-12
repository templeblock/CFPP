/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      CFPP-MessagePort.h
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFMessagePortRef wrapper
 */

#ifndef CFPP_MESSAGE_PORT_H
#define CFPP_MESSAGE_PORT_H

namespace CF
{
    class CFPP_EXPORT MessagePort: public Type
    {
        public:
            
            MessagePort( void );
            MessagePort( const MessagePort & value );
            MessagePort( const AutoPointer & value );
            MessagePort( CFTypeRef value );
            MessagePort( CFMessagePortRef value );
            
            #ifdef CFPP_HAS_CPP11
            MessagePort( MessagePort && value );
            #endif
            
            virtual ~MessagePort( void );
            
            MessagePort & operator = ( MessagePort value );
            MessagePort & operator = ( const AutoPointer & value );
            MessagePort & operator = ( CFTypeRef value );
            MessagePort & operator = ( CFMessagePortRef value );
            
            virtual CFTypeID  GetTypeID( void ) const;
            virtual CFTypeRef GetCFObject( void ) const;
            
            friend void swap( MessagePort & v1, MessagePort & v2 );
            
        private:
            
            CFMessagePortRef _cfObject;
    };
}

#endif /* CFPP_MESSAGE_PORT_H */
