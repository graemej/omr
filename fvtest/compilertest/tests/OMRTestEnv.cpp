/*******************************************************************************
 *
 * (c) Copyright IBM Corp. 2000, 2016
 *
 *  This program and the accompanying materials are made available
 *  under the terms of the Eclipse Public License v1.0 and
 *  Apache License v2.0 which accompanies this distribution.
 *
 *      The Eclipse Public License is available at
 *      http://www.eclipse.org/legal/epl-v10.html
 *
 *      The Apache License v2.0 is available at
 *      http://www.opensource.org/licenses/apache2.0.php
 *
 * Contributors:
 *    Multiple authors (IBM Corp.) - initial implementation and documentation
 *******************************************************************************/

#ifdef MS_WINDOWS
#undef BYTE
#include "windows.h"
#define PATH_MAX MAXPATHLEN
#else
#include <dlfcn.h>
#endif
#include <errno.h>
#include "OMRTestEnv.hpp"

extern "C" bool initializeTestJit(TR_RuntimeHelper *helperIDs, void **helperAddresses, int32_t numHelpers, char *options);
extern "C" void shutdownJit();

void
TestCompiler::OMRTestEnv::SetUp()
   {
   initialize("-Xjit");
   }

void
TestCompiler::OMRTestEnv::TearDown()
   {
   shutdown();
   }

void
TestCompiler::OMRTestEnv::initialize(char *options)
   {
   initializeTestJit(0, 0, 0, options);
   }

void
TestCompiler::OMRTestEnv::shutdown()
   {
   shutdownJit();
   }
