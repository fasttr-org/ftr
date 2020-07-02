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

#include "ftr-js/js-1.h"
#include "ftr-js/ftr.h"
#include "ftr/panel.h"
#include "ftr/button.h"

/**
 * @ns ftr::js
 */

JS_BEGIN

/**
 * @class WrapPanel
 */
class WrapPanel: public WrapViewBase {
 public:

	static void constructor(FunctionCall args) {
		JS_ATTACH(args);
		JS_CHECK_APP();
		New<WrapPanel>(args, new Panel());
	}
	
	/**
	 * @get allow_leave {bool}
	 */
	static void allow_leave(Local<JSString> name, PropertyCall args) {
		JS_WORKER(args);
		JS_SELF(Panel);
		JS_RETURN( self->allow_leave() );
	}

	/**
	 * @set allow_leave {bool}
	 */
	static void set_allow_leave(Local<JSString> name, Local<JSValue> value, PropertySetCall args) {
		JS_WORKER(args); GUILock lock;
		JS_SELF(Panel);
		self->set_allow_leave( value->ToBooleanValue(worker) );
	}
	
	/**
	 * @func allow_entry get
	 */
	static void allow_entry(Local<JSString> name, PropertyCall args) {
		JS_WORKER(args);
		JS_SELF(Panel);
		JS_RETURN( self->allow_entry() );
	}
	
	/**
	 * @func set_allow_entry set
	 */
	static void set_allow_entry(Local<JSString> name, Local<JSValue> value, PropertySetCall args) {
		JS_WORKER(args); GUILock lock;
		JS_SELF(Panel);
		self->set_allow_entry( value->ToBooleanValue(worker) );
	}
	
	/**
	 * @get interval_time {uint} ms
	 */
	static void interval_time(Local<JSString> name, PropertyCall args) {
		JS_WORKER(args);
		JS_SELF(Panel);
		JS_RETURN( self->interval_time() );
	}
	
	/**
	 * @set interval_time {uint} ms
	 */
	static void set_interval_time(Local<JSString> name, Local<JSValue> value, PropertySetCall args) {
		JS_WORKER(args); GUILock lock;
		if ( ! value->IsNumber(worker) ) {
			JS_THROW_ERR("* @set intervalTime {uint} ms");
		}
		JS_SELF(Panel);
		int64 num = value->ToNumberValue(worker);
		self->set_interval_time( uint64(1000) * FX_MIN(0, num) );
	}
	
	/**
	 * @get enable_switch {bool}
	 */
	static void enable_select(Local<JSString> name, PropertyCall args) {
		JS_WORKER(args);
		JS_SELF(Panel);
		JS_RETURN( self->enable_select() );
	}
	
	/**
	 * @set enable_switch {bool}
	 */
	static void set_enable_select(Local<JSString> name, Local<JSValue> value, PropertySetCall args) {
		JS_WORKER(args); GUILock lock;
		JS_SELF(Panel);
		self->set_enable_select( value->ToBooleanValue(worker) );
	}
	
	/**
	 * @get is_activity {bool}
	 */
	static void is_activity(Local<JSString> name, PropertyCall args) {
		JS_WORKER(args);
		JS_SELF(Panel);
		JS_RETURN( self->is_activity() );
	}
	
	/**
	 * @get parent_panel {ButtonGroup}
	 */
	static void parent_panel(Local<JSString> name, PropertyCall args) {
		JS_WORKER(args);
		JS_SELF(Panel);
		Panel* panel = self->parent_panel();
		if ( panel ) {
			JS_RETURN( Wrap<Panel>::pack(panel, View::PANEL)->that() );
		} else {
			JS_RETURN_NULL();
		}
	}
	
	static void binding(Local<JSObject> exports, Worker* worker) {
		JS_DEFINE_CLASS(Panel, constructor, {
			JS_SET_CLASS_ACCESSOR(allowLeave, allow_leave, set_allow_leave);
			JS_SET_CLASS_ACCESSOR(allowEntry, allow_entry, set_allow_entry);
			JS_SET_CLASS_ACCESSOR(intervalTime,  interval_time, set_interval_time);
			JS_SET_CLASS_ACCESSOR(enableSelect, enable_select, set_enable_select);
			JS_SET_CLASS_ACCESSOR(isActivity, is_activity);
			JS_SET_CLASS_ACCESSOR(parentPanel, parent_panel);
		}, Div);
		IMPL::js_class(worker)->set_class_alias(JS_TYPEID(Panel), View::PANEL);
	}
};

void binding_panel(Local<JSObject> exports, Worker* worker) {
	WrapPanel::binding(exports, worker);
}

JS_END
