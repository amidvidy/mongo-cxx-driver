/*    Copyright 2014 MongoDB Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "mongo/client/exceptions.h"

#ifdef _WIN32
#include "Windows.h"
#include "DbgHelp.h"
#include <cstdlib>
#include <cstdio>

namespace {
    void printStack( void )
    {
        unsigned int   i;
        void         * stack[ 100 ];
        unsigned short frames;
        SYMBOL_INFO  * symbol;
        HANDLE         process;

        process = GetCurrentProcess();
        SymInitialize( process, NULL, TRUE );
        frames               = CaptureStackBackTrace( 0, 100, stack, NULL );
        symbol               = ( SYMBOL_INFO * )calloc( sizeof( SYMBOL_INFO ) + 256 * sizeof( char ), 1 );
        symbol->MaxNameLen   = 255;
        symbol->SizeOfStruct = sizeof( SYMBOL_INFO );

        for( i = 0; i < frames; i++ )
            {
                SymFromAddr( process, ( DWORD64 )( stack[ i ] ), 0, symbol );

                std::printf( "%i: %s - 0x%0X\n", frames - i - 1, symbol->Name, symbol->Address );
            }

        std::free( symbol );
    }
}

#endif

namespace mongo {

    namespace {
        const char kName[] = "OperationException";
    }

    OperationException::OperationException(const BSONObj& errorObj)
        : _lastError(errorObj)
        , _errorString(std::string(kName) + ": " + errorObj.toString()) {
           std::cout << "CONSTRUCTING OPERATION EXCEPTION!!! YOU DUN GOOFED" << std::endl;
           std::cout << "======= HAVE A STACKTRACE MY FRIEND ===========================" << std::endl;
           printStack();
           std::cout << "======= HOPE THAT HELPED ========================================" << std::endl;
    }    

    OperationException::~OperationException() throw() {
    }

    const char* OperationException::what() const throw() {
        return _errorString.c_str();
    }

} // namespace mongo
