{
	'targets': [
	{
		'target_name': 'ngui-base',
		'type': '<(library)',
		'dependencies': [ 
			'ngui/base/minizip.gyp:minizip',
			'node/deps/openssl/openssl.gyp:openssl',
			'node/deps/uv/uv.gyp:libuv',
			'node/deps/http_parser/http_parser.gyp:http_parser',
			'depe/sqlite-amalgamation/sqlite3.gyp:sqlite3',
		],
		'direct_dependent_settings': {
			'include_dirs': [ '../..', ],
			'mac_bundle_resources': [
				#'cacert.pem',
			],
		},
		'include_dirs': [
			'../../depe/rapidjson/include',
			'../..',
		],
		'sources': [
			'../../Makefile',
			'../../README.md',
			'../../configure',
			'../../tools/configure.js',
			'../../tools/install-android-toolchain',
			'../version.h',
			'../errno.h',
			'cacert.pem',
			# src
			'container.h',
			'object.h',
			'object.cc',
			'array.h',
			'array.h.inl',
			'codec.h',
			'env.h',
			'error.h',
			'event.h',
			'http.h',
			'fs.h',
			'handle.h',
			'buffer.h',
			'json.h',
			'iterator.h',
			'list.h',
			'list.h.inl',
			'map.h',
			'map.h.inl',
			'string.h',
			'string.h.inl',
			'string.cc',
			'string-builder.h',
			'string-builder.h.inl',
			'string-builder.cc',
			'util.h',
			'zlib.h',
			'array.cc.inl',
			'array.cc',
			'codec.cc',
			'error.cc',
			'http.cc',
			'http-uri.cc',
			'http-helper.cc',
			'fs.cc',
			'fs-file.cc',
			'fs-sync.cc',
			'fs-async.cc',
			'fs-search.cc',
			'fs-reader.cc',
			'buffer.cc',
			'json.cc',
			'map.cc',
			'util.cc',
			'zlib.cc',
			'loop.h',
			'loop-1.h',
			'loop.cc',
			'loop-private.cc',
			'jsx.h',
			'jsx.cc',
			'macros.h',
			'net.h',
			'net.cc',
			'uv-1.h',
			'cb.h',
			'cb.cc',
			'date.cc',
			'http-cookie.h',
			'http-cookie.cc',
			'localstorage.h',
			'localstorage.cc',
		],
		'conditions': [
			['os=="android"', {
				'sources':[
					'../../android/android.h',
					'../../android/android.cc',
					'android-jni.h',
					'android-jni.cc',
					'android-log.h',
					'android-log.cc',
					'_android.cc',
				],
				'link_settings': { 
					'libraries': [ 
						'-latomic', 
						'-llog', 
						'-landroid',
					],
				},
			}],
			['os=="linux"', {
				'sources': [
					'_linux.cc',
				],
			}],
			['os=="ios"', {
				'dependencies': [ 
					'depe/reachability/reachability.gyp:reachability', 
				],
				'sources': [
					'_mac.mm',
				],
			}],
			['os=="osx"', {
				'dependencies': [ 
					'depe/reachability/reachability.gyp:reachability', 
				],
				'sources':[
					'_mac.mm',
				],
			}],
		]
	},],
}
