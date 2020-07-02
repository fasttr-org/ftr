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

var fs = require('somes/fs');

function read_ftr_version() {
	var str = fs.readFileSync(__dirname + '/../ftr/version.h').toString('utf-8');
	var MAJOR = 0;
	var MINOR = 0;
	var PATCH = 0;
	var mat;

	if ( (mat = /#define\s+FTR_MAJOR_VERSION\s+(\d+)/m.exec(str)) ) {
		MAJOR = parseInt(mat[1]);
	}
	if ( (mat = /#define\s+FTR_MINOR_VERSION\s+(\d+)/m.exec(str)) ) {
		MINOR = parseInt(mat[1]);
	}
	if ( (mat = /#define\s+FTR_PATCH_VERSION\s+(\d+)/m.exec(str)) ) {
		PATCH = parseInt(mat[1]);
	}
	if ( MAJOR == 0 && MINOR == 0 && PATCH == 0 ) {
		throw new Error('Cannot parse ftr version number form ftr/version.h');
	}
	return [MAJOR, MINOR, PATCH];
}

function update_ftr_version() {
	var vers = read_ftr_version().join('.');
	[
		__dirname + '/../libs/ftr/out/ftr/package.json',
		__dirname + '/../libs/ftrp/out/ftrp/package.json',
		__dirname + '/../libs/ftr/package.json',
		__dirname + '/../libs/ftrp/package.json',
	].forEach(e=>{
		var json = fs.readFileSync(e, 'utf-8');
		json = json.replace(/\"version\"\:\s*\"[^\"]+\"/, `"version": "${vers}"`);
		fs.writeFileSync(e, json);
	});
}

exports.read_ftr_version = read_ftr_version;
exports.update_ftr_version = update_ftr_version;
