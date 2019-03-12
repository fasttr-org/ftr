import { Div, Button } from 'qgr';
import { AudioPlayer, Video } from 'qgr/media';
import { Mynavpage } from './public';
import * as aaaa from 'qgr/path';

// const src_720 = 'http://quickgr.org/media/2017-09-11_15_41_19.mp4';
const src_720 = 'http://quickgr.org/media/piper720p.mp4';
const audio_src = 'http://quickgr.org/media/all_we_know.mp3';

var audio_player = null;

function PlayVideo(evt) {
	StopAudio(evt);
	var v = evt.sender.owner.find('video');
	v.src = src_720;
	v.start();
}

function PlayAudio(evt) {
	StopVideo(evt);
	if ( !audio_player ) {
		audio_player = new AudioPlayer();
	}
	audio_player.src = audio_src;
	audio_player.start();
}

function StopVideo(evt) {
	evt.sender.owner.find('video').stop();
}

function StopAudio(evt) {
	if ( audio_player ) {
		audio_player.stop();
		audio_player = null;
	}
}

function Stop(evt) {
	StopVideo(evt);
	StopAudio(evt);
}

function Seek(evt) {
	if ( audio_player ) {
		audio_player.seek(10000); // 10s
	} else {
		evt.sender.owner.find('video').seek(100000); // 100s
	}
}

export const vx = (
	<Mynavpage title="Media" source=resolve(__filename) onRemoveView=StopAudio>
		<Div width="full">
			<Button class="long_btn" onClick=PlayVideo>Play Video</Button>
			<Button class="long_btn" onClick=PlayAudio>Play Audio</Button>
			<Button class="long_btn" onClick=Stop>Stop</Button>

			<Video 
				id="video" 
				marginTop=10
				borderRadius=20 
				_border="8 #f00" 
				clip=false
				width="full" 
				backgroundColor="#000" 
			/>
		</Div>
	</Mynavpage>
)
