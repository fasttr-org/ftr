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

#ifndef __ftr__textarea__
#define __ftr__textarea__

#include "ftr/input.h"
#include "ftr/scroll.h"

FX_NS(ftr)

/**
 * @class Textarea
 */
class FX_EXPORT Textarea: public Input, public BasicScroll {
	FX_DEFINE_GUI_VIEW(TEXTAREA, Textarea, textarea);
 public:

	typedef ReferenceTraits Traits;
	
	Textarea();
	
	/**
	 * @overwrite
	 */
	// virtual bool is_clip() { return true; }
	virtual BasicScroll* as_basic_scroll() { return this; }
	virtual Object* to_object() { return this; }
	
 protected:
	
	/**
	 * @overwrite
	 */
	virtual void draw(Draw* draw);
	virtual void set_layout_content_offset();
	virtual bool is_multi_line_input();
	virtual Vec2 input_text_offset();
	virtual void set_input_text_offset(Vec2 value);
	virtual void set_draw_visible();
};

FX_END

#endif
