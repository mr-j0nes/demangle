/**
 * simple.hpp - 
 * @author: Jonathan Beard
 * @version: Fri Sep 12 10:28:33 2014
 * 
 * Copyright 2014 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cstdlib>
#include "demangle.hpp"
#include <typeinfo>
#include <iostream>

struct foobar
{
    /** random stuff for fun **/
    int a;
    int b = 12;
};


int main()
{  
    /**
     * looks a bit funny, but injects the namespace where and when 
     * needed. 
     */
    foobar f;
    std::string output = 
#ifdef INJECT_NAMESPACE
    DEMANGLE_NAMESPACE::
#endif
    demangle( typeid( f ).name() );
    if( output.compare( "foobar" ) != 0 /** if they're not equal **/ )
    {
        return( EXIT_FAILURE );
    }
    return( EXIT_SUCCESS );
}