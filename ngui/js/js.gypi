{
	'variables': {
		'use_v8%': 0,
	},
	'targets': [{
		'target_name': 'ngui-js',
		'type': '<(library)',
		'include_dirs': [
			'../../out', 
			'../..',
			'../../node/src',
			'../../node/deps/cares/include',
			'../../node/deps/uv/include',
		],
		'dependencies': [
			'ngui-base', 
			'ngui-gui', 
			'node/deps/openssl/openssl.gyp:openssl',
			'node/node.gyp:node', 
			'v8-link/v8-link.gyp:v8-link',
			'v8-link/v8-link.gyp:v8_libplatform-link',
		],
		'direct_dependent_settings': {
			'include_dirs': [ '../..' ],
			'mac_bundle_resources': [
				#'../../node_modules/ngui',
			],
		},
		'defines': [ 'NODE_WANT_INTERNALS=1' ],
		'sources': [
			'../../out/native-core-js.cc',
			'js.h',
			'js.cc',
			'js-1.h',
			'node-1.h',
			'node-2.h',
			'js-class.cc',
			'str.h',
			'str.cc',
			'ngui.h',
			'v8.cc',
			'log.cc',
			# ngui-base
			'binding/base/cb-1.h',
			'binding/base/reader.cc',
			'binding/base/http.cc',
			'binding/base/util.cc',
			'binding/base/keys.cc',
			'binding/base/storage.cc',
			'binding/base/json-1.h',
			'binding/base/json.cc',
			'binding/base/event-1.h',
			'binding/base/event.cc',
			'binding/base/sys.cc',
			'binding/base/fs.cc',
			'binding/base/event.cc',
			# ngui-gui
			'binding/value.cc',
			'binding/ngui.cc',
			'binding/action.cc',
			'binding/action-frame.cc',
			'binding/app.cc',
			'binding/audio-player.cc',
			'binding/video.cc',
			'binding/media.cc',
			'binding/div.cc',
			'binding/display-port.cc',
			'binding/indep.cc',
			'binding/image.cc',
			'binding/layout.cc',
			'binding/box.cc',
			'binding/view.cc',
			'binding/root.cc',
			'binding/span.cc',
			'binding/sprite.cc',
			'binding/hybrid.cc',
			'binding/text-font.cc',
			'binding/text-node.cc',
			'binding/label.cc',
			'binding/limit.cc',
			'binding/panel.cc',
			'binding/button.cc',
			'binding/scroll.cc',
			'binding/css.cc',
			'binding/font.cc',
			'binding/text.cc',
			'binding/input.cc',
			'binding/background.cc',
		],
		'conditions': [
			['v8_enable_inspector==1', { 'defines': [ 'HAVE_INSPECTOR=1' ] }],
			['node_use_openssl=="true"', { 'defines': [ 'HAVE_OPENSSL=1' ] }],
			['node_use_dtrace=="true"', { 'defines': [ 'HAVE_DTRACE=1' ] }],
		],
		'actions': [
			{
				'variables': {
					'native_core_js_files': [
					'binding/base/ext.js',
					'binding/base/keys.js',
					'binding/base/event.js',
					'binding/value.js',
					],
				},
				'action_name': 'gen_core_js_natives',
				'inputs': [
					'../../tools/gen-js-natives.js',
					'<@(native_core_js_files)',
				],
				'outputs': [
					'../../out/native-core-js.h',
					'../../out/native-core-js.cc',
				],
				'action': [
					'<(node)',
					'<@(_inputs)',
					'CORE',
					'wrap',
					'<@(_outputs)',
				],
			},
		],
	}]
}
