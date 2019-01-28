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

var fs = require('fs');
var shared = null;
var { DelayCall } = require('./delay_call');

function sync_local(self) {
	if (self.m_change) {
		fs.writeFileSync(self.m_path, JSON.stringify(self.m_value, null, 2));
		self.m_change = false;
	}
}

/**
 * @class Storage
 */
class Storage {

	constructor(path = process.cwd() + '/' + '.storage') {
		this.m_path = path;
		this.m_value = {};
		this.m_change = false;
		this.m_sync = new DelayCall(e=>sync_local(this), 100); // 100ms后保存到文件

		if (fs.existsSync(path)) {
			try {
				this.m_value = JSON.parse(fs.readFileSync(path, 'utf-8')) || {};
			} catch(e) {}
		}
	}

	get(key, defaultValue) {
		if (key in this.m_value) {
			return this.m_value[key];
		} else {
			if (defaultValue !== undefined) {
				this.m_value[key] = defaultValue;
				this.m_sync.notice();
				return defaultValue;
			}
		}
	}

	has(key) {
		return key in this.m_value;
	}

	set(key, value) {
		this.m_change = true;
		this.m_value[key] = value;
		this.m_sync.notice();
	}

	del(key) {
		this.m_change = true;
		delete this.m_value[key];
		this.m_sync.notice();
	}

	claer() {
		this.m_change = true;
		this.m_value = {};
		this.m_sync.notice();
	}

	save() {
		sync_local(this);
	}

}

module.exports = {

	Storage: Storage,

	get shared() {
		return shared;
	},

	setShared: function(value) {
		shared = value;
	},

	get: function(key, defaultValue) {
		return shared.get(key, defaultValue);
	},

	has: function(key) {
		return shared.has(key);
	},

	set: function(key, value) {
		return shared.set(key, value);
	},

	del: function(key) {
		return shared.del(key);
	},

	clear: function() {
		return shared.clear();
	},

	save: function() {
		shared.save();
	},

};


