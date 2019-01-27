/* ***** BEGIN LICENSE BLOCK *****
 * Distributed under the BSD license:
 *
 * Copyright (c) 2015, xuewen.chu
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of xuewen.chu nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL xuewen.chu BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***** END LICENSE BLOCK ***** */

#include "shark/js/js.h"
#include "shark/app.h"
#include "shark/utils/fs.h"

using namespace shark;

#define USE_REMOTE 1
#define IP_REMOTE "127.0.0.1"
#define USE_INSPECT 0

void test_demo(int argc, char **argv) {
#if USE_REMOTE
# if USE_INSPECT
	js::start("--inspect-brk=0.0.0.0:9229 http://" IP_REMOTE ":1026/demo/examples");
# else
	js::start("http://" IP_REMOTE ":1026/demo/examples --dev");
# endif
#else
# if USE_INSPECT
	js::start("--inspect-brk=0.0.0.0:9229 examples");
# else
	js::start("examples --dev");
# endif
#endif
}

extern "C" {

#if XX_ANDROID
#include <shark/utils/android-jni.h>

	JNIEXPORT extern void
	Java_org_shark_examples_MainActivity_test(JNIEnv *env, jclass clazz, jint count) {
		LOG("Java_org_shark_examples_MainActivity_test");
	}

#endif
}

