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

#ifndef __qgr__utils__android_jni__
#define __qgr__utils__android_jni__

#include "qgr/utils/util.h"

#if XX_ANDROID

#include <jni.h>

XX_NS(qgr)

/**
 * @class JNI
 */
class XX_EXPORT JNI {
 public:

	/**
	 * @class ScopeENV
	 */
	class XX_EXPORT ScopeENV {
		XX_HIDDEN_ALL_COPY(ScopeENV);
	 public:
		ScopeENV();
		~ScopeENV();
		inline bool is_null() const { return m_env == NULL; }
		inline JNIEnv* operator*() const { return m_env; }
		inline JNIEnv* operator->() const { return m_env; }
	 private:
		JNIEnv* m_env;
		bool    m_is_attach;
		// @end
	};

	/**
	 * @class MethodInfo
	 */
	class XX_EXPORT MethodInfo {
	 public:
		MethodInfo(cchar* clazz, cchar* method, cchar* param_code, bool is_static = false);
		MethodInfo(jclass clazz, cchar* method, cchar* param_code, bool is_static = false);
		inline jclass clazz() const { return m_clazz; }
		inline jmethodID method() const { return m_method; }
	 private:
		jclass      m_clazz;
		jmethodID   m_method;
		// @end
	};

	/**
	 * @func find_clazz
	 * */
	static jclass find_clazz(cchar* clazz);

	/**
	 * @func find_method
	 * */
	inline static jmethodID find_method(jclass clazz, cchar* method, cchar* param_code) {
		return MethodInfo(clazz, method, param_code).method();
	}

	/**
	 * @func find_static_method
	 * */
	inline static jmethodID find_static_method(jclass clazz, cchar* method, cchar* param_code) {
		return MethodInfo(clazz, method, param_code, true).method();
	}

	/**
	 * @func find_method
	 * */
	inline static jmethodID find_method(cchar* clazz, cchar* method, cchar* param_code) {
		return MethodInfo(clazz, method, param_code).method();
	}

	/**
	 * @func find_static_method
	 * */
	static jmethodID find_static_method(cchar* clazz, cchar* method, cchar* param_code) {
		return MethodInfo(clazz, method, param_code, true).method();
	}

	/**
	 * @func jvm
	 */
	static JavaVM* jvm();

	/**
	 * @func jstring_to_string
	 */
	static String jstring_to_string(jstring jstr, JNIEnv* env = NULL);
};

XX_END

#endif
#endif