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
 * @file        CFPP-String.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    CoreFoundation++ CFStringRef wrapper
 */

#include <CF++.hpp>

namespace CF
{
    String::String( void ): _cfObject( NULL )
    {
        this->SetValue( "" );
    }
    
    String::String( const AutoPointer & value ): _cfObject( NULL )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFStringRef >( const_cast< void * >( CFRetain( value ) ) );
        }
    }
    
    String::String( CFTypeRef cfObject ): _cfObject( NULL )
    {
        if( cfObject != NULL && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFStringRef >( CFRetain( cfObject ) );
        }
    }
    
    String::String( CFStringRef cfObject ): _cfObject( NULL )
    {
        if( cfObject != NULL && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFStringRef >( CFRetain( cfObject ) );
        }
    }
    
    String::String( const AutoPointer & value, std::string defaultValueIfNULL, CFStringEncoding encoding ): _cfObject( NULL )
    {
        if( value.IsValid() && value.GetTypeID() == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFStringRef >( const_cast< void * >( CFRetain( value ) ) );
        }
        else
        {
            this->SetValue( defaultValueIfNULL, encoding );
        }
    }
    
    String::String( CFTypeRef cfObject, std::string defaultValueIfNULL, CFStringEncoding encoding ): _cfObject( NULL )
    {
        if( cfObject != NULL && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFStringRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetValue( defaultValueIfNULL, encoding );
        }
    }
    
    String::String( CFStringRef cfObject, std::string defaultValueIfNULL, CFStringEncoding encoding ): _cfObject( NULL )
    {
        if( cfObject != NULL && CFGetTypeID( cfObject ) == this->GetTypeID() )
        {
            this->_cfObject = static_cast< CFStringRef >( CFRetain( cfObject ) );
        }
        else
        {
            this->SetValue( defaultValueIfNULL, encoding );
        }
    }
    
    String::String( const std::string & value, CFStringEncoding encoding ): _cfObject( NULL )
    {
        this->SetValue( value, encoding );
    }
    
    String::String( char * value, CFStringEncoding encoding ): _cfObject( NULL )
    {
        if( value == NULL )
        {
            value = const_cast< char * >( "" );
        }
        
        this->SetValue( value, encoding );
    }
    
    String::String( const char * value, CFStringEncoding encoding ): _cfObject( NULL )
    {
        if( value == NULL )
        {
            value = "";
        }
        
        this->SetValue( value, encoding );
    }
    
    String::String( const String & value ): _cfObject( NULL )
    {
        if( value._cfObject != NULL )
        {
            this->_cfObject = static_cast< CFStringRef >( CFRetain( ( value._cfObject ) ) );
        }
    }
    
    #ifdef CFPP_HAS_CPP11
    String::String( String && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = nullptr;
    }
    #endif
    
    String::~String( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
            
            this->_cfObject = NULL;
        }
    }
    
    String & String::operator = ( String value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    String & String::operator = ( const AutoPointer & value )
    {
        return operator =( String( value ) );
    }
    
    String & String::operator = ( CFTypeRef value )
    {
        return operator =( String( value ) );
    }
    
    String & String::operator = ( CFStringRef value )
    {
        return operator =( String( value ) );
    }
    
    String & String::operator = ( const std::string & value )
    {
        return operator =( String( value ) );
    }
    
    String & String::operator = ( char * value )
    {
        return operator =( String( value ) );
    }
    
    String & String::operator = ( const char * value )
    {
        return operator =( String( value ) );
    }
    
    bool String::operator == ( const String & value ) const
    {
        if( this->_cfObject == NULL || value._cfObject == NULL )
        {
            return false;
        }
        
        return ( CFStringCompare( this->_cfObject, value._cfObject, 0 ) == kCFCompareEqualTo ) ? true : false;
    }
    
    bool String::operator == ( CFTypeRef value ) const
    {
        return operator ==( String( value ) );
    }
    
    bool String::operator == ( CFStringRef value ) const
    {
        return operator ==( String( value ) );
    }
    
    bool String::operator == ( const std::string & value ) const
    {
        return operator ==( String( value ) );
    }
    
    bool String::operator == ( char * value ) const
    {
        return operator ==( String( value ) );
    }
    
    bool String::operator == ( const char * value ) const
    {
        return operator ==( String( value ) );
    }
            
    bool String::operator != ( const String & value ) const
    {
        return !operator ==( value );
    }
    
    bool String::operator != ( CFTypeRef value ) const
    {
        return !operator ==( value );
    }
    
    bool String::operator != ( CFStringRef value ) const
    {
        return !operator ==( value );
    }
    
    bool String::operator != ( const std::string & value ) const
    {
        return !operator ==( value );
    }
    
    bool String::operator != ( char * value ) const
    {
        return !operator ==( value );
    }
    
    bool String::operator != ( const char * value ) const
    {
        return !operator ==( value );
    }
            
    String & String::operator += ( const String & value )
    {
        AutoPointer array;
        CFStringRef newString;
        CFStringRef strings[ 2 ];
        
        if( value._cfObject == NULL )
        {
            return *( this );
        }
        
        if( this->_cfObject == NULL )
        {
            this->SetValue( "" );
        }
        
        strings[ 0 ] = this->_cfObject;
        strings[ 1 ] = value._cfObject;
        array        = CFArrayCreate( static_cast< CFAllocatorRef >( NULL ), reinterpret_cast< const void ** >( strings ), 2, NULL );
        newString    = CFStringCreateByCombiningStrings( static_cast< CFAllocatorRef >( NULL ), array.As< CFArrayRef >(), CFSTR( "" ) );
        
        CFRelease( this->_cfObject );
        
        this->_cfObject = newString;
        
        return *( this );
    }
    
    String & String::operator += ( CFStringRef value )
    {
        return operator +=( String( value ) );
    }
    
    String & String::operator += ( const std::string & value )
    {
        return operator +=( String( value ) );
    }
    
    String & String::operator += ( char * value )
    {
        return operator +=( String( value ) );
    }
    
    String & String::operator += ( const char * value )
    {
        return operator +=( String( value ) );
    }
    
    char String::operator [] ( int index ) const
    {
        std::string s;
        
        s = this->GetValue();
        
        if( index < 0 )
        {
            index = static_cast< int >( s.length() ) + index;
        }
        
        if( static_cast< std::size_t >( index ) >= s.length() )
        {
            return 0;
        }
        
        return s.at( static_cast< std::size_t >( index ) );
    }
    
    String::operator std::string () const
    {
        return this->GetValue();
    }
    
    CFTypeID String::GetTypeID( void ) const
    {
        return CFStringGetTypeID();
    }
    
    CFTypeRef String::GetCFObject( void ) const
    {
        return static_cast< CFTypeRef >( this->_cfObject );
    }
            
    bool String::HasPrefix( const String & value ) const
    {
        if( this->_cfObject == NULL || value._cfObject == NULL )
        {
            return false;
        }
        
        return ( CFStringHasPrefix( this->_cfObject, value._cfObject ) ) ? true : false;
    }
    
    bool String::HasPrefix( CFStringRef value ) const
    {
        String s;
        
        s = value;
        
        return this->HasPrefix( s );
    }
    
    bool String::HasPrefix( const std::string & value ) const
    {
        String s;
        
        s = value;
        
        return this->HasPrefix( s );
    }
    
    bool String::HasSuffix( const String & value ) const
    {
        if( this->_cfObject == NULL || value._cfObject == NULL )
        {
            return false;
        }
        
        return ( CFStringHasSuffix( this->_cfObject, value._cfObject ) ) ? true : false;
    }
    
    bool String::HasSuffix( CFStringRef value ) const
    {
        String s;
        
        s = value;
        
        return this->HasSuffix( s );
    }
    
    bool String::HasSuffix( const std::string & value ) const
    {
        String s;
        
        s = value;
        
        return this->HasSuffix( s );
    }
    
    CFIndex String::GetLength( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return 0;
        }
        
        return CFStringGetLength( this->_cfObject );
    }
    
    std::string String::GetValue( CFStringEncoding encoding ) const
    {
        const char * s;
        char       * buf;
        size_t       length;
        std::string  str;
        
        if( this->_cfObject == NULL )
        {
            return "";
        }
        
        s = this->GetCStringValue( encoding );
        
        if( s == NULL )
        {
            length = static_cast< size_t >( CFStringGetMaximumSizeForEncoding( CFStringGetLength( this->_cfObject ), encoding ) );
            buf    = new char [ length + 1 ];
            
            memset( buf, 0, length + 1 );
            CFStringGetCString( this->_cfObject, buf, static_cast< CFIndex >( length + 1 ), encoding );
            
            str = ( buf == NULL ) ? "" : buf;
            
            delete [] buf;
        }
        else
        {
            str = s;
        }
        
        return str;
    }
    
    const char * String::GetCStringValue( CFStringEncoding encoding ) const
    {
        if( this->_cfObject != NULL )
        {
            return CFStringGetCStringPtr( this->_cfObject, encoding );
        }
        
        return NULL;
    }
    
    void String::SetValue( const std::string & value, CFStringEncoding encoding )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
        
        this->_cfObject = CFStringCreateWithCString( static_cast< CFAllocatorRef >( NULL ), value.c_str(), encoding );
    }
    
    String::Iterator String::begin( CFStringEncoding encoding ) const
    {
        return Iterator( this->_cfObject, encoding, this->GetLength() );
    }
    
    String::Iterator String::end( CFStringEncoding encoding ) const
    {
        return Iterator( this->_cfObject, encoding, this->GetLength(), this->GetLength() );
    }
    
    void swap( String & v1, String & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
    }
}
