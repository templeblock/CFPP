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
 * @file        Test-CFPP-Dictionary.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Unit tests for CF::Dictionary
 */

#include <CF++.hpp>
#include <GoogleMock/GoogleMock.h>

using namespace testing;

TEST( CFPP_Dictionary, CTOR )
{
    CF::Dictionary d;
    
    ASSERT_TRUE( d.IsValid() );
    ASSERT_EQ( d.GetCount(), 0 );
}

TEST( CFPP_Dictionary, CTOR_CFIndex )
{
    CF::Dictionary d( 100 );
    
    ASSERT_TRUE( d.IsValid() );
    ASSERT_EQ( d.GetCount(), 0 );
}

TEST( CFPP_Dictionary, CTOR_AutoPointer )
{
    CF::Dictionary d1( CF::AutoPointer( CFDictionaryCreateMutable( NULL, 10, NULL, NULL ) ) );
    CF::Dictionary d2( CF::AutoPointer( CFUUIDCreate( NULL ) ) );
    CF::Dictionary d3( CF::AutoPointer( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Dictionary, CTOR_CFType )
{
    CF::Dictionary d1( static_cast< CFTypeRef >( CF::Dictionary().GetCFObject() ) );
    CF::Dictionary d2( static_cast< CFTypeRef >( NULL ) );
    CF::Dictionary d3( static_cast< CFTypeRef >( CF::Boolean().GetCFObject() ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Dictionary, CTOR_CFDictionary )
{
    CF::Dictionary d1( static_cast< CFDictionaryRef >( CF::Dictionary().GetCFObject() ) );
    CF::Dictionary d2( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d3( static_cast< CFDictionaryRef >( CF::Boolean().GetCFObject() ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

#ifdef CFPP_HAS_CPP11
TEST( CFPP_Dictionary, CTOR_STDInitializerList )
{
    CF::Dictionary d
    (
        {
            CF::Pair( "foo", "bar" ),
            CF::Pair( "bar", "foo" )
        }
    );
    
    ASSERT_TRUE( d.IsValid() );
    ASSERT_EQ( d.GetCount(), 2 );
    
    ASSERT_TRUE( CF::String( d[ "foo" ] ) == "bar" );
    ASSERT_TRUE( CF::String( d[ "bar" ] ) == "foo" );
}
#endif

TEST( CFPP_Dictionary, CCTOR )
{
    CF::Dictionary d1;
    
    d1 << CF::Pair( "foo", "bar" );
    d1 << CF::Pair( "bar", "foo" );
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_EQ( d1.GetCount(), 2 );
    
    {
        CF::Dictionary d2( d1 );
        
        ASSERT_TRUE( d1.IsValid() );
        ASSERT_TRUE( d2.IsValid() );
        ASSERT_EQ( d1.GetCount(), 2 );
        ASSERT_EQ( d2.GetCount(), 2 );
    }
}

#ifdef CFPP_HAS_CPP11
TEST( CFPP_Dictionary, MCTOR )
{
    CF::Dictionary d1;
    
    d1 << CF::Pair( "foo", "bar" );
    d1 << CF::Pair( "bar", "foo" );
    
    ASSERT_TRUE( d1.IsValid() );
    ASSERT_EQ( d1.GetCount(), 2 );
    
    {
        CF::Dictionary d2( std::move( d1 ) );
        
        ASSERT_FALSE( d1.IsValid() );
        ASSERT_TRUE(  d2.IsValid() );
        ASSERT_EQ( d2.GetCount(), 2 );
    }
}
#endif

TEST( CFPP_Dictionary, OperatorAssignDictionary )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d3( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d4;
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
    ASSERT_TRUE(  d4.IsValid() );
    
    d3 = d1;
    d4 = d2;
    
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_FALSE( d4.IsValid() );
}

TEST( CFPP_Dictionary, OperatorAssignAutoPointer )
{
    CF::Dictionary d1( static_cast< CFTypeRef >( NULL ) );
    CF::Dictionary d2;
    CF::Dictionary d3;
    
    ASSERT_FALSE( d1.IsValid() );
    ASSERT_TRUE(  d2.IsValid() );
    ASSERT_TRUE(  d3.IsValid() );
    
    d1 = CF::AutoPointer( CFDictionaryCreateMutable( NULL, 0, NULL, NULL ) );
    d2 = CF::AutoPointer( CFUUIDCreate( NULL ) );
    d3 = CF::AutoPointer( NULL );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
}

TEST( CFPP_Dictionary, OperatorAssignCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d3( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d4;
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
    ASSERT_TRUE(  d4.IsValid() );
    
    d3 = static_cast< CFTypeRef >( d1 );
    d4 = static_cast< CFTypeRef >( d2 );
    
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_FALSE( d4.IsValid() );
}

TEST( CFPP_Dictionary, OperatorAssignCFDictionary )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d3( static_cast< CFDictionaryRef >( NULL ) );
    CF::Dictionary d4;
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
    ASSERT_TRUE(  d4.IsValid() );
    
    d3 = static_cast< CFDictionaryRef >( d1 );
    d4 = static_cast< CFDictionaryRef >( d2 );
    
    ASSERT_TRUE(  d3.IsValid() );
    ASSERT_FALSE( d4.IsValid() );
}

TEST( CFPP_Dictionary, OperatorPlusEqual )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.AddValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.AddValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    
    d1 += CF::Pair( CF::String( "foo" ), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1 += CF::Pair( CF::String( "foo" ) , CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
}

TEST( CFPP_Dictionary, OperatorLeftShift )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.SetValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.SetValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    
    d1 << CF::Pair( CF::String( "foo" ), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1 << CF::Pair( CF::String( "foo" ) , CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
}

TEST( CFPP_Dictionary, OperatorSubscriptCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2;
    CF::Dictionary d3( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_TRUE(  d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( d1.GetCount() == 1 );
    ASSERT_TRUE( d2.GetCount() == 0 );
    
    ASSERT_NO_FATAL_FAILURE( d2[ static_cast< CFTypeRef >( CF::String( "bar" ).GetCFObject() ) ] );
    ASSERT_NO_FATAL_FAILURE( d3[ static_cast< CFTypeRef >( CF::String( "bar" ).GetCFObject() ) ] );
    ASSERT_NO_THROW( d2[ static_cast< CFTypeRef >( CF::String( "bar" ).GetCFObject() ) ] );
    ASSERT_NO_THROW( d3[ static_cast< CFTypeRef >( CF::String( "bar" ).GetCFObject() ) ] );
    
    ASSERT_TRUE( d1[ static_cast< CFTypeRef >( CF::String( "foo" ).GetCFObject() ) ] != NULL );
    ASSERT_TRUE( d1[ static_cast< CFTypeRef >( CF::String( "bar" ).GetCFObject() ) ] == NULL );
    ASSERT_TRUE( d2[ static_cast< CFTypeRef >( CF::String( "foo" ).GetCFObject() ) ] == NULL );
    ASSERT_TRUE( d3[ static_cast< CFTypeRef >( CF::String( "foo" ).GetCFObject() ) ] == NULL );
    
    ASSERT_EQ( CFGetTypeID( d1[ static_cast< CFTypeRef >( CF::String( "foo" ).GetCFObject() ) ] ), CFStringGetTypeID() );
}

TEST( CFPP_Dictionary, OperatorSubscriptCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2;
    CF::Dictionary d3( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_TRUE(  d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE(  d1.GetCount() == 1 );
    ASSERT_TRUE(  d2.GetCount() == 0 );
    
    ASSERT_NO_FATAL_FAILURE( d2[ "bar" ] );
    ASSERT_NO_FATAL_FAILURE( d3[ "bar" ] );
    ASSERT_NO_THROW( d2[ "bar" ] );
    ASSERT_NO_THROW( d3[ "bar" ] );
    
    ASSERT_TRUE( d1[ "foo" ] != NULL );
    ASSERT_TRUE( d1[ "bar" ] == NULL );
    ASSERT_TRUE( d2[ "foo" ] == NULL );
    ASSERT_TRUE( d3[ "foo" ] == NULL );
    
    ASSERT_EQ( CFGetTypeID( d1[ "foo" ] ), CFStringGetTypeID() );
}

TEST( CFPP_Dictionary, OperatorSubscriptString )
{
    CF::Dictionary d1;
    CF::Dictionary d2;
    CF::Dictionary d3( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_TRUE(  d2.IsValid() );
    ASSERT_FALSE( d3.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE(  d1.GetCount() == 1 );
    ASSERT_TRUE(  d2.GetCount() == 0 );
    
    ASSERT_NO_FATAL_FAILURE( d2[ CF::String( "bar" ) ] );
    ASSERT_NO_FATAL_FAILURE( d3[ CF::String( "bar" ) ] );
    ASSERT_NO_THROW( d2[ CF::String( "bar" ) ] );
    ASSERT_NO_THROW( d3[ CF::String( "bar" ) ] );
    
    ASSERT_TRUE( d1[ CF::String( "foo" ) ] != NULL );
    ASSERT_TRUE( d1[ CF::String( "bar" ) ] == NULL );
    ASSERT_TRUE( d2[ CF::String( "foo" ) ] == NULL );
    ASSERT_TRUE( d3[ CF::String( "foo" ) ] == NULL );
    
    ASSERT_EQ( CFGetTypeID( d1[ CF::String( "foo" ) ] ), CFStringGetTypeID() );
}

TEST( CFPP_Dictionary, GetTypeID )
{
    CF::Dictionary d;
    
    ASSERT_EQ( d.GetTypeID(), CFDictionaryGetTypeID() );
}

TEST( CFPP_Dictionary, GetCFObject )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFDictionaryRef >( NULL ) );
    
    ASSERT_TRUE( d1.GetCFObject() != NULL );
    ASSERT_TRUE( d2.GetCFObject() == NULL );
    ASSERT_EQ( CFGetTypeID( d1.GetCFObject() ), CFDictionaryGetTypeID() );
}

TEST( CFPP_Dictionary, ContainsKeyCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( CF::String( "hello, world" ), CF::String( "foo" ) );
    d1 << CF::Pair( CF::Number( 42 ), CF::String( "bar" ) );
    
    ASSERT_TRUE(  d1.ContainsKey( CF::String( "hello, world" ).GetCFObject() ) );
    ASSERT_TRUE(  d1.ContainsKey( CF::Number( 42 ).GetCFObject() ) );
    ASSERT_FALSE( d2.ContainsKey( CF::String( "hello, world" ).GetCFObject() ) );
    ASSERT_FALSE( d2.ContainsKey( CF::Number( 42 ).GetCFObject() ) );
    ASSERT_FALSE( d1.ContainsKey( CF::String( "hello, universe" ).GetCFObject() ) );
    ASSERT_FALSE( d1.ContainsKey( CF::Number( 43 ).GetCFObject() ) );
}

TEST( CFPP_Dictionary, ContainsKeyCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( CF::String( "hello, world" ), CF::String( "foo" ) );
    d1 << CF::Pair( CF::Number( 42 ), CF::String( "bar" ) );
    
    ASSERT_TRUE(  d1.ContainsKey( "hello, world" ) );
    ASSERT_FALSE( d2.ContainsKey( "hello, world" ) );
    ASSERT_FALSE( d1.ContainsKey( "hello, universe" ) );
}

TEST( CFPP_Dictionary, ContainsKeyString )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( CF::String( "hello, world" ), CF::String( "foo" ) );
    d1 << CF::Pair( CF::Number( 42 ), CF::String( "bar" ) );
    
    ASSERT_TRUE(  d1.ContainsKey( CF::String( "hello, world" ) ) );
    ASSERT_FALSE( d2.ContainsKey( CF::String( "hello, world" ) ) );
    ASSERT_FALSE( d1.ContainsKey( CF::String( "hello, universe" ) ) );
}

TEST( CFPP_Dictionary, ContainsValue )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    d1 << CF::Pair( "bar", CF::Number( 42 ) );
    
    ASSERT_TRUE(  d1.ContainsValue( CF::String( "hello, world" ) ) );
    ASSERT_TRUE(  d1.ContainsValue( CF::Number( 42 ) ) );
    ASSERT_FALSE( d2.ContainsValue( CF::String( "hello, world" ) ) );
    ASSERT_FALSE( d2.ContainsValue( CF::Number( 42 ) ) );
    ASSERT_FALSE( d1.ContainsValue( CF::String( "hello, universe" ) ) );
    ASSERT_FALSE( d1.ContainsValue( CF::Number( 43 ) ) );
}

TEST( CFPP_Dictionary, RemoveAllValues )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( CF::String( "hello, world" ), CF::String( "foo" ) );
    d1 << CF::Pair( CF::Number( 42 ), CF::String( "bar" ) );
    d1 << CF::Pair( CF::String( "hello, universe" ), CF::String( "foobar" ) );
    
    d2 << CF::Pair( CF::String( "hello, world" ), CF::String( "foo" ) );
    d2 << CF::Pair( CF::Number( 42 ), CF::String( "bar" ) );
    d2 << CF::Pair( CF::String( "hello, universe" ), CF::String( "foobar" ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_TRUE(  d1.GetCount() == 3 );
    
    d1.RemoveAllValues();
    d2.RemoveAllValues();
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_TRUE(  d1.GetCount() == 0 );
    
    d1.RemoveAllValues();
    d2.RemoveAllValues();
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    ASSERT_TRUE(  d1.GetCount() == 0 );
}

TEST( CFPP_Dictionary, GetCount )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_TRUE( d1.GetCount() == 0 );
    ASSERT_TRUE( d2.GetCount() == 0 );
    
    d1 << CF::Pair( "foo", "hello, world" );
    d2 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_TRUE( d1.GetCount() == 1 );
    ASSERT_TRUE( d2.GetCount() == 0 );
    
    d1.RemoveAllValues();
    d2.RemoveAllValues();
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_TRUE( d1.GetCount() == 0 );
    ASSERT_TRUE( d2.GetCount() == 0 );
}

TEST( CFPP_Dictionary, GetValueCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_TRUE( d1.GetValue( CF::String( "foo" ).GetCFObject() ) == NULL );
    ASSERT_TRUE( d2.GetValue( CF::String( "foo" ).GetCFObject() ) == NULL );
    
    d1 << CF::Pair( CF::String( "foo" ), CF::String( "hello, world" ) );
    d1 << CF::Pair( CF::String( "bar" ), CF::String( "hello, world" ) );
    d1 << CF::Pair( CF::Number( 42 ),    CF::String( "hello, world" ) );
    
    ASSERT_TRUE( d1.GetValue( CF::String( "foo" ).GetCFObject() ) != NULL );
    ASSERT_TRUE( d1.GetValue( CF::String( "bar" ).GetCFObject() ) != NULL );
    ASSERT_TRUE( d1.GetValue( CF::Number( 42 ).GetCFObject() )    != NULL );
}

TEST( CFPP_Dictionary, GetValueCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_TRUE( d1.GetValue( "foo" ) == NULL );
    ASSERT_TRUE( d2.GetValue( "foo" ) == NULL );
    
    d1 << CF::Pair( CF::String( "foo" ), CF::String( "hello, world" ) );
    d1 << CF::Pair( CF::String( "bar" ), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( d1.GetValue( "foo" ) != NULL );
    ASSERT_TRUE( d1.GetValue( "bar" ) != NULL );
}

TEST( CFPP_Dictionary, GetValueString )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_TRUE( d1.GetValue( CF::String( "foo" ) ) == NULL );
    ASSERT_TRUE( d2.GetValue( CF::String( "foo" ) ) == NULL );
    
    d1 << CF::Pair( CF::String( "foo" ), CF::String( "hello, world" ) );
    d1 << CF::Pair( CF::String( "bar" ), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( d1.GetValue( CF::String( "foo" ) ) != NULL );
    ASSERT_TRUE( d1.GetValue( CF::String( "bar" ) ) != NULL );
}

TEST( CFPP_Dictionary, AddValueCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.AddValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.AddValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, world" ) ) );
    
    d1.AddValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.AddValue( CF::String( "foo" ).GetCFObject() , CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
}

TEST( CFPP_Dictionary, AddValueCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.AddValue( "foo", CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.AddValue( "foo", CF::String( "hello, world" ) ) );
    
    d1.AddValue( "foo", CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.AddValue( "foo", CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
}

TEST( CFPP_Dictionary, AddValueString )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.AddValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.AddValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    
    d1.AddValue( CF::String( "foo" ), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.AddValue( CF::String( "foo" ) , CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
}

TEST( CFPP_Dictionary, RemoveValueCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( d1[ "foo" ] != NULL );
    
    d1.RemoveValue( CF::String( "foo" ).GetCFObject() );
    
    ASSERT_TRUE( d1[ "foo" ] == NULL );
    
    ASSERT_NO_FATAL_FAILURE( d1.RemoveValue( CF::String( "foo" ).GetCFObject() ) );
    ASSERT_NO_FATAL_FAILURE( d2.RemoveValue( CF::String( "foo" ).GetCFObject() ) );
    ASSERT_NO_THROW( d1.RemoveValue( CF::String( "foo" ).GetCFObject() ) );
    ASSERT_NO_THROW( d2.RemoveValue( CF::String( "foo" ).GetCFObject() ) );
}

TEST( CFPP_Dictionary, RemoveValueCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( d1[ "foo" ] != NULL );
    
    d1.RemoveValue( "foo" );
    
    ASSERT_TRUE( d1[ "foo" ] == NULL );
    
    ASSERT_NO_FATAL_FAILURE( d1.RemoveValue( "foo" ) );
    ASSERT_NO_FATAL_FAILURE( d2.RemoveValue( "foo" ) );
    ASSERT_NO_THROW( d1.RemoveValue( "foo" ) );
    ASSERT_NO_THROW( d2.RemoveValue( "foo" ) );
}

TEST( CFPP_Dictionary, RemoveValueString )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( d1[ "foo" ] != NULL );
    
    d1.RemoveValue( CF::String( "foo" ) );
    
    ASSERT_TRUE( d1[ "foo" ] == NULL );
    
    ASSERT_NO_FATAL_FAILURE( d1.RemoveValue( CF::String( "foo" ) ) );
    ASSERT_NO_FATAL_FAILURE( d2.RemoveValue( CF::String( "foo" ) ) );
    ASSERT_NO_THROW( d1.RemoveValue( CF::String( "foo" ) ) );
    ASSERT_NO_THROW( d2.RemoveValue( CF::String( "foo" ) ) );
}

TEST( CFPP_Dictionary, ReplaceValueCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.ReplaceValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
    
    ASSERT_NO_FATAL_FAILURE( d1.ReplaceValue( CF::String( "foo" ).GetCFObject(), CF::String( "bar" ) ) );
    ASSERT_NO_FATAL_FAILURE( d2.ReplaceValue( CF::String( "foo" ).GetCFObject(), CF::String( "bar" ) ) );
    ASSERT_NO_THROW( d1.ReplaceValue( CF::String( "foo" ).GetCFObject(), CF::String( "bar" ) ) );
    ASSERT_NO_THROW( d2.ReplaceValue( CF::String( "foo" ).GetCFObject(), CF::String( "bar" ) ) );
}

TEST( CFPP_Dictionary, ReplaceValueCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.ReplaceValue( "foo", CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
    
    ASSERT_NO_FATAL_FAILURE( d1.ReplaceValue( "foo", CF::String( "bar" ) ) );
    ASSERT_NO_FATAL_FAILURE( d2.ReplaceValue( "foo", CF::String( "bar" ) ) );
    ASSERT_NO_THROW( d1.ReplaceValue( "foo", CF::String( "bar" ) ) );
    ASSERT_NO_THROW( d2.ReplaceValue( "foo", CF::String( "bar" ) ) );
}

TEST( CFPP_Dictionary, ReplaceValueString )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    d1 << CF::Pair( "foo", "hello, world" );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.ReplaceValue( CF::String( "foo" ), CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
    
    ASSERT_NO_FATAL_FAILURE( d1.ReplaceValue( CF::String( "foo" ), CF::String( "bar" ) ) );
    ASSERT_NO_FATAL_FAILURE( d2.ReplaceValue( CF::String( "foo" ), CF::String( "bar" ) ) );
    ASSERT_NO_THROW( d1.ReplaceValue( CF::String( "foo" ), CF::String( "bar" ) ) );
    ASSERT_NO_THROW( d2.ReplaceValue( CF::String( "foo" ), CF::String( "bar" ) ) );
}

TEST( CFPP_Dictionary, SetValueCFType )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.SetValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.SetValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, world" ) ) );
    
    d1.SetValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.SetValue( CF::String( "foo" ).GetCFObject(), CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
}

TEST( CFPP_Dictionary, SetValueCChar )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.SetValue( "foo", CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.SetValue( "foo", CF::String( "hello, world" ) ) );
    
    d1.SetValue( "foo", CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.SetValue( "foo", CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
}

TEST( CFPP_Dictionary, SetValueString )
{
    CF::Dictionary d1;
    CF::Dictionary d2( static_cast< CFArrayRef >( NULL ) );
    
    ASSERT_TRUE(  d1.IsValid() );
    ASSERT_FALSE( d2.IsValid() );
    
    ASSERT_NO_FATAL_FAILURE( d2.SetValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    ASSERT_NO_THROW( d2.SetValue( CF::String( "foo" ), CF::String( "hello, world" ) ) );
    
    d1.SetValue( CF::String( "foo" ), CF::String( "hello, world" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, world" );
    
    d1.SetValue( CF::String( "foo" ), CF::String( "hello, universe" ) );
    
    ASSERT_TRUE( CF::String( d1[ "foo" ] ) == "hello, universe" );
}

TEST( CFPP_Dictionary, Swap )
{
    CF::Dictionary d1;
    CF::Dictionary d2;
    
    d1 << CF::Pair( "hello", "world" );
    d1 << CF::Pair( "foo",   "bar" );
    
    ASSERT_EQ( d1.GetCount(), 2 );
    ASSERT_EQ( d2.GetCount(), 0 );
    
    swap( d1, d2 );
    
    ASSERT_EQ( d1.GetCount(), 0 );
    ASSERT_EQ( d2.GetCount(), 2 );
}
