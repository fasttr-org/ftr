Qgr
===============

A GUI typesetting display engine and cross platform GUI application development framework based on NodeJS/OpenGL

Goal: developing GUI applications on this basis can take into account both the simplicity and speed of developing WEB applications, as well as the performance and experience of Native applications.

* Only `iOS` and `Android` systems are supported for the time being, this does not include `AndroidTV`, because `TV` applications are very different from mobile applications

* From here, [`Go API Index`](http://qgr1.org/doc/) can go to `API Documents Index`

| ![Screenshot](http://qgr1.org/img/0x0ss.jpg) | ![Screenshot](http://qgr1.org/img/0x0ss_3.jpg) | ![Screenshot](http://qgr1.org/img/0x0ss_4.jpg) |
|--|--|--|


# Simple Examples

This is a simple program to display Hello world on the screen

```jsx
import { GUIApplication, Root } from 'qgr'
new GUIApplication().start(
	<Root>hello world!</Root>
)
```

You can get a more detailed [`Examples`]

# Start Usage

If you've never used Qgr before, you can start from here and build your Qgr program step by step.

## Install qgr-tools

First, you need to install the toolkit provided by `Qgr`

* Install `qgr-tools` using nodejs `npm` 

* Open `Terminal` and execute the following command：

```sh
# shell
$ sudo npm install -g qgr-tools

```
	
* Running `qgr-tools` requires dependency on `nodejs` and `python2.7`

* And now do not support the `windows` system, you need to use it under `mac`

## Create new project

Create a new `Qgr` project using the following `shell` command：

```sh
# shell
$ mkdir myproject
$ cd myproject
$ qgr init
```

## Build project

This step compresses and packages the JavaScript code and resource files inside the project,
If this is a new project, you can skip this step and go directly to the next step

```js
# shell
$ qgr build
```

## Export project

This step exports [`Xcode`] or [`Android Studio`] project，because you eventually publish the program that be a `.apk` or `.ipa`

```js
# shell
# export xcode ios project
$ qgr export ios
# export android studio project
$ qgr export android
```

After exporting the project, next you can open it using [`Xcode`] and [`Android Studio`]

## Qgr test http server

`qgr-tools` provides a test http server, each time you change the `js` or `jsx` code, you don't have to reinstall every time.

Execute the following code to start it：

```js
# shell
$ qgr
```

# Downloads

* Examples demo [`Android APK`] Install package

* Project [`Source code`] from `Github`


[`Examples`]: https://github.com/louis-tru/qgr/tree/master/demo
[`Xcode`]: https://developer.apple.com/library/content/documentation/IDEs/Conceptual/AppDistributionGuide/ConfiguringYourApp/ConfiguringYourApp.html
[`Android Studio`]: https://developer.android.com/studio/projects/create-project.html
[`Android APK`]: https://github.com/louis-tru/qgr/releases/download/v0.1.0/examples-release.apk
[`NPM`]: https://www.npmjs.com/package/qgr-tools
[`Source code`]: https://github.com/louis-tru/qgr

<script>
	<!--
	var language = (navigator.browserLanguage || navigator.language).toLowerCase();
	var isLanguageCn = language.indexOf('cn') >= 0;
	var isPageCn = location.href.indexOf('README-cn') >=0;
	var isHtml = typeof src == 'string'; // html page will have a src variable

	if ( isLanguageCn ) { // cn
		if ( !isPageCn ) { // goto to cn
			location.href = isHtml ? 'README-cn.html' : 'README-cn.md';
		}
	} else { // en
		if ( isPageCn ) { // goto to en
			location.href = isHtml ? 'README.html' : 'README.md';
		}
	}
	-->
</script>
