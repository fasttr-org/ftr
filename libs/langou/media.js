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

export requireNative('_media');

import './util';
import { NativeNotification } from './event';

 /**
	* @enum MediaType
	* MEDIA_TYPE_AUDIO
	* MEDIA_TYPE_VIDEO
	* @end
	*/

 /**
	* @enum PlayerStatus
	* PLAYER_STATUS_STOP = 0
	* PLAYER_STATUS_START = 1
	* PLAYER_STATUS_PLAYING = 2
	* PLAYER_STATUS_PAUSED = 3
	* @end
	*/

 /**
	* @enum MultimediaSourceStatus
	* MULTIMEDIA_SOURCE_STATUS_UNINITIALIZED = 0
	* MULTIMEDIA_SOURCE_STATUS_READYING = 1
	* MULTIMEDIA_SOURCE_STATUS_READY = 2
	* MULTIMEDIA_SOURCE_STATUS_WAIT = 3
	* MULTIMEDIA_SOURCE_STATUS_FAULT = 4
	* MULTIMEDIA_SOURCE_STATUS_EOF = 5
	* @end
	*/

 /**
	* @enum AudioChannelMask
	* CH_INVALID
	* CH_FRONT_LEFT
	* CH_FRONT_RIGHT
	* CH_FRONT_CENTER
	* CH_LOW_FREQUENCY
	* CH_BACK_LEFT
	* CH_BACK_RIGHT
	* CH_FRONT_LEFT_OF_CENTER
	* CH_FRONT_RIGHT_OF_CENTER
	* CH_BACK_CENTER
	* CH_SIDE_LEFT
	* CH_SIDE_RIGHT
	* CH_TOP_CENTER
	* CH_TOP_FRONT_LEFT
	* CH_TOP_FRONT_CENTER
	* CH_TOP_FRONT_RIGHT
	* CH_TOP_BACK_LEFT
	* CH_TOP_BACK_CENTER
	* CH_TOP_BACK_RIGHT
	* @end
	*/

	/**
	* @enum VideoColorFormat
	* VIDEO_COLOR_FORMAT_INVALID
	* VIDEO_COLOR_FORMAT_YUV420P
	* VIDEO_COLOR_FORMAT_YUV420SP
	* VIDEO_COLOR_FORMAT_YUV411P
	* VIDEO_COLOR_FORMAT_YUV411SP
	* @end
	*/

 /**
	* @class TrackInfo
	* type {meun MediaType}
	* mime {String}
	* codecId {int}
	* codecTag {uint}
	* format {int}
	* profile {int}
	* level {int}
	* width {uint}
	* height {uint}
	* language {String}
	* bitrate {uint}
	* sampleRate {uint}
	* channelCount {uint}
	* channelLayout {uint64}
	* frameInterval {uint} ms
	* @end
	*/

 /**
	* @class AudioPlayer
	*/
export class AudioPlayer extends exports.AudioPlayer {
	event onWaitBuffer;
	event onReady;
	event onStartPlay;
	event onError;
	event onSourceEOF;
	event onPause;
	event onResume;
	event onStop;
	event onSeek;
}

 /**
	* @class AudioPlayer
	*
	* @constructor([src])
	* @arg [src] {String}
	*
	* @get,set autoPlay {bool}
	* @get sourceStatus {MultimediaSourceStatus}
	* @get status {PlayerStatus}
	* @get,set mute {bool}
	* @get,set volume {uint} 0-100
	* @get,set src {String}
	* @get time {uint64} ms
	* @get duration {uint64} ms
	* @get trackIndex {uint}
	* @get trackCount {uint}
	* @get,set disableWaitBuffer {bool}
	*
	* @func selectTrack(index)
	* @arg index {uint} audio track index
	*
	* @func track([index])
	* @arg [track=curent_track] {uint} default use current track index
	* @ret {object TrackInfo}
	*
	* @func start()
	*
	* @func seek(time)
	* @arg time {uint} ms
	* @ret {bool} success
	*
	* @func pause()
	*
	* @func resume()
	*
	* @func stop()
	*
	* @end
	*/

 /**
	* @class Video
	*/
class Video {
	event onWaitBuffer;
	event onReady;
	event onStartPlay;
	event onError;
	event onSourceEOF;
	event onPause;
	event onResume;
	event onStop;
	event onSeek;
}

 /**
	* @class Video
	* @bases Image
	*
	* @get,set autoPlay {bool}
	* @get sourceStatus {MultimediaSourceStatus}
	* @get status {PlayerStatus}
	* @get,set mute {bool}
	* @get,set volume {uint} 0-100
	* @get,set src {String}
	* @get time {uint64} ms
	* @get duration {uint64} ms
	* @get audioTrackIndex {uint}
	* @get audioTrackCount {uint}
	* @get,set disableWaitBuffer {bool}
	*
	* @func selectAudioTrack(index)
	* @arg index {uint} audio track index
	*
	* @func audioTrack([index])
	* @arg [track=curent_track] {uint} default use current track index
	* @ret {object TrackInfo}
	*
	* @func videoTrack()
	* @ret {object TrackInfo}
	*
	* @func start()
	*
	* @func seek(time)
	* @arg time {uint} ms
	* @ret {bool} success
	*
	* @func pause()
	*
	* @func resume()
	*
	* @func stop()
	* @end
	*/

util.extendClass(exports.Video, Video);
util.extendClass(AudioPlayer, NativeNotification);
