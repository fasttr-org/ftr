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

import { Scroll, Text, _CVD } from 'ftr';
import { Mynavpage, Page } from './public';
import { Navbar, Toolbar } from 'ftr/nav';
import * as reader from 'ftr/reader';
import {Event} from 'ftr/event';

function foreground(evt: Event<void, Page>) {
	var navpage = evt.sender;
	navpage.title = 'Source';
	var text = reader.readFileSync((navpage.prevPage as Page).source, 'utf8');
	navpage.find<Text>('text').value = text;
}

export default ()=>(
	<Mynavpage 
		navbar={<Navbar backgroundColor="#333" backTextColor="#fff" titleTextColor="#fff" />}
		toolbar={<Toolbar hidden={true} />}
		backgroundColor="#333" onForeground={foreground}>
		<Scroll width="full" height="full" bounceLock={0}>
			<Text width="full" id="text" textColor="#fff" textSize={12} margin={5} />
		</Scroll>
	</Mynavpage>
)
